#pragma once

#include <iostream>

using namespace std;

/**
 * @brief 索引最大堆
 *
 * @tparam Item
 */
template <typename Item> class IndexMaxHeap {
private:
  Item *data;   // 存放元素的数组
  int *indexes; // 索引数组
  int *reverse; // 反向索引数组
  int count;    // 元素个数
  int capacity; // 容量

  /**
   * @brief 上浮
   *
   * @param k 要上浮的元素的索引
   */
  void shiftUp(int k) {
    while (k > 1 && data[indexes[k / 2]] < data[indexes[k]]) { // k > 1 有父节点
      swap(indexes[k / 2], indexes[k]); // 交换父节点和子节点
      reverse[indexes[k / 2]] = k / 2;  // 更新反向索引数组
      reverse[indexes[k]] = k;          // 更新反向索引数组
      k /= 2;                           // k指向父节点
    }
  }

  /**
   * @brief 下沉
   *
   * @param k 要下沉的元素的索引
   */
  void shiftDown(int k) {
    while (2 * k <= count) { // 有左孩子就有孩子
      int j = 2 * k;         // 在此轮循环中,data[k]和data[j]交换位置
      if (j + 1 <= count &&
          data[indexes[j + 1]] > data[indexes[j]]) // 有右孩子且右孩子大于左孩子
        j += 1; // data[j]是data[2*k]和data[2*k+1]中的最大值
      if (data[indexes[k]] >=
          data[indexes[j]]) // 如果data[k]大于等于data[j],就不用交换了
        break;
      swap(indexes[k], indexes[j]); // 否则交换
      reverse[indexes[k]] = k;      // 更新反向索引数组
      reverse[indexes[j]] = j;      // 更新反向索引数组
      k = j;                        // k指向交换后的位置
    }
  }

public:
  IndexMaxHeap(int capacity) {
    this->capacity = capacity;       // 容量
    indexes = new int[capacity + 1]; // 索引数组
    reverse = new int[capacity + 1]; // 反向索引数组
    for (int i = 0; i <= capacity; i++)
      reverse[i] = 0; // 初始时所有元素都没有在堆中

    data = new Item[capacity + 1]; // 索引从1开始
    count = 0;
  }

  IndexMaxHeap(Item arr[], int n) { // Heapify
    data = new Item[n + 1];
    indexes = new int[n + 1];
    reverse = new int[n + 1];
    for (int i = 0; i <= n; i++)
      reverse[i] = 0; // 初始时所有元素都没有在堆中
    capacity = n;
    for (int i = 0; i < n; i++)
      data[i + 1] = arr[i];
    count = n;
    for (int i = count / 2; i >= 1; i--)
      shiftDown(i);
  }

  ~IndexMaxHeap() {
    delete[] data;
    delete[] indexes;
    delete[] reverse;
  }

  /**
   * @brief 获取堆中元素个数
   *
   * @return int
   */
  int size() { return count; }

  /**
   * @brief 判断堆是否为空
   *
   * @return true
   * @return false
   */
  bool isEmpty() { return count == 0; }

  /**
   * @brief 插入元素
   *
   * @param item
   */
  void insert(int i, Item item) { // 传入的i对用户来说，是从0索引的
    assert(count + 1 <= this->capacity);
    assert(i + 1 >= 1 && i + 1 <= capacity);

    i += 1;
    data[i] = item;
    indexes[count + 1] = i;
    reverse[i] = count + 1;

    count++;
    shiftUp(count);
  }

  /**
   * @brief 取出最大元素
   *
   * @return Item
   */
  Item extractMax() {
    assert(count > 0);

    Item ret = data[indexes[1]];

    swap(indexes[1], indexes[count]);
    reverse[indexes[1]] = 1;     // 更新反向索引数组
    reverse[indexes[count]] = 0; // 更新反向索引数组
    count--;
    shiftDown(1);
    return ret;
  }

  /**
   * @brief 取出最大元素的索引
   *
   * @return int
   */
  int extractMaxIndex() {
    assert(count > 0);
    int ret = indexes[1] - 1;
    swap(indexes[1], indexes[count]);
    reverse[indexes[1]] = 1;     // 更新反向索引数组
    reverse[indexes[count]] = 0; // 更新反向索引数组
    count--;
    shiftDown(1);
    return ret;
  }

  /**
   * @brief 获取最大元素
   *
   * @param i 传入的i对用户来说，是从0索引的
   * @return true
   * @return false
   */
  bool contain(int i) {
    assert(i + 1 >= 1 && i + 1 <= capacity);
    return reverse[i + 1] != 0;
  }

  /**
   * @brief Get the Item object
   *
   * @param i
   * @return Item
   */
  Item getItem(int i) {
    assert(contain(i));
    return data[i + 1];
  }

  /**
   * @brief 将最大索引堆中索引为i的元素修改为newItem
   * 注释部分 n + logn 优化后 -> logn
   * @param i
   * @param newItem
   */
  void change(int i, Item newItem) {
    assert(contain(i));

    i += 1;
    data[i] = newItem;

    // 找到indexes[j] = i, j表示data[i]在堆中的位置
    // 之后shiftUp(j), 再shiftDown(j)
    // for (int j = 1; j <= count; j++) { // O(n)
    //   if (indexes[j] == i) {
    //     shiftUp(j);   // O(logn)
    //     shiftDown(j); // O(logn)
    //     return;
    //   }
    // }
    int j = reverse[i]; // O(1)
    shiftUp(j);         // O(logn)
    shiftDown(j);       // O(logn)
  }

public:
  // 以树状打印整个堆结构
  void testPrint() {

    // 我们的testPrint只能打印100个元素以内的堆的树状信息
    if (size() >= 100) {
      cout << "This print function can only work for less than 100 int";
      return;
    }

    // 我们的testPrint只能处理整数信息
    if (typeid(Item) != typeid(int)) {
      cout << "This print function can only work for int item";
      return;
    }

    cout << "The max heap size is: " << size() << endl;
    cout << "Data in the max heap: ";
    for (int i = 1; i <= size(); i++) {
      // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
      assert(data[i] >= 0 && data[i] < 100);
      cout << data[i] << " ";
    }
    cout << endl;
    cout << endl;

    int n = size();
    int max_level = 0;
    int number_per_level = 1;
    while (n > 0) {
      max_level += 1;
      n -= number_per_level;
      number_per_level *= 2;
    }

    int max_level_number = int(pow(2, max_level - 1));
    int cur_tree_max_level_number = max_level_number;
    int index = 1;
    for (int level = 0; level < max_level; level++) {
      string line1 = string(max_level_number * 3 - 1, ' ');

      int cur_level_number =
          min(count - int(pow(2, level)) + 1, int(pow(2, level)));
      bool isLeft = true;
      for (int index_cur_level = 0; index_cur_level < cur_level_number;
           index++, index_cur_level++) {
        putNumberInLine(data[index], line1, index_cur_level,
                        cur_tree_max_level_number * 3 - 1, isLeft);
        isLeft = !isLeft;
      }
      cout << line1 << endl;

      if (level == max_level - 1)
        break;

      string line2 = string(max_level_number * 3 - 1, ' ');
      for (int index_cur_level = 0; index_cur_level < cur_level_number;
           index_cur_level++)
        putBranchInLine(line2, index_cur_level,
                        cur_tree_max_level_number * 3 - 1);
      cout << line2 << endl;

      cur_tree_max_level_number /= 2;
    }
  }

private:
  void putNumberInLine(int num, string &line, int index_cur_level,
                       int cur_tree_width, bool isLeft) {

    int sub_tree_width = (cur_tree_width - 1) / 2;
    int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
    assert(offset + 1 < line.size());
    if (num >= 10) {
      line[offset + 0] = '0' + num / 10;
      line[offset + 1] = '0' + num % 10;
    } else {
      if (isLeft)
        line[offset + 0] = '0' + num;
      else
        line[offset + 1] = '0' + num;
    }
  }

  void putBranchInLine(string &line, int index_cur_level, int cur_tree_width) {

    int sub_tree_width = (cur_tree_width - 1) / 2;
    int sub_sub_tree_width = (sub_tree_width - 1) / 2;
    int offset_left =
        index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
    assert(offset_left + 1 < line.size());
    int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width +
                       1 + sub_sub_tree_width;
    assert(offset_right < line.size());

    line[offset_left + 1] = '/';
    line[offset_right + 0] = '\\';
  }
};
