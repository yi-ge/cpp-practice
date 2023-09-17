#pragma once

#include <iostream>

using namespace std;

/**
 * @brief 最大堆
 *
 * @tparam Item
 */
template <typename Item> class MaxHeap {
private:
  Item *data;   // 存放元素的数组
  int count;    // 元素个数
  int capacity; // 容量

  /**
   * @brief 上浮
   *
   * @param k 要上浮的元素的索引
   */
  void shiftUp(int k) {
    while (k > 1 && data[k / 2] < data[k]) { // k > 1 有父节点
      swap(data[k / 2], data[k]);            // 交换父节点和子节点
      k /= 2;                                // k指向父节点
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
      if (j + 1 <= count && data[j + 1] > data[j]) // 有右孩子且右孩子大于左孩子
        j += 1; // data[j]是data[2*k]和data[2*k+1]中的最大值
      if (data[k] >= data[j]) // 如果data[k]大于等于data[j],就不用交换了
        break;
      swap(data[k], data[j]); // 否则交换
      k = j;                  // k指向交换后的位置
    }
  }

public:
  MaxHeap(int capacity) {
    this->capacity = capacity;     // 容量
    data = new Item[capacity + 1]; // 索引从1开始
    count = 0;
  }

  MaxHeap(Item arr[], int n) { // Heapify
    data = new Item[n + 1];
    capacity = n;
    for (int i = 0; i < n; i++)
      data[i + 1] = arr[i];
    count = n;
    for (int i = count / 2; i >= 1; i--)
      shiftDown(i);
  }

  ~MaxHeap() { delete[] data; }

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
  void insert(Item item) {
    assert(count + 1 <= this->capacity);
    data[count + 1] = item;
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
    Item ret = data[1];
    swap(data[1], data[count]);
    count--;
    shiftDown(1);
    return ret;
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
