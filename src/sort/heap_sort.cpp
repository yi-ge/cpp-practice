// 堆排序

#include <headers.hpp>
#include <max_heap.hpp>

template <typename T> void __shiftDown(T arr[], int n, int k) {
  while (2 * k + 1 < n) {
    int j = 2 * k + 1; // 在此轮循环中，arr[k]和arr[j]交换位置
    if (j + 1 < n && arr[j + 1] > arr[j]) {
      j += 1;
    }
    if (arr[k] >= arr[j]) {
      break;
    }
    swap(arr[k], arr[j]);
    k = j;
  }
}

template <typename T> void heapSort(T arr[], int n) {
  // heapify
  // 从(最后一个元素的索引-1)/2开始
  // 最后一个元素的索引 = n-1
  for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
    __shiftDown(arr, n, i);
  }

  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    __shiftDown(arr, i, 0);
  }
}

class Solution {
public:
  vector<int> heapSort(vector<int> &nums) {
    ::heapSort(&nums[0], nums.size());
    return nums;
  }
  /**
   * @brief 堆排序
   * nlogn
   * @param nums
   * @return vector<int>
   */
  vector<int> heapSort1(vector<int> &nums) {
    MaxHeap<int> maxHeap = MaxHeap<int>(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      maxHeap.insert(nums[i]);
    }

    // 从小到大排序，extractMax得到的是从大到小
    vector<int> res = vector<int>(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--) {
      res[i] = maxHeap.extractMax();
    }
    return res;
  }
  /**
   * @brief 堆排序 (Heapify)
   * Heapify的算法复杂度：将n个元素逐个插入到一个空堆中，算法复杂度是O(nlogn)
   * Heapify的过程，算法复杂度是O(n)
   * 堆排序的整体算法复杂度是O(nlogn)
   * @param nums
   * @return vector<int>
   */
  vector<int> heapSort2(vector<int> &nums) {
    int n = nums.size();
    int arr[n];
    for (int i = 0; i < n; i++) {
      arr[i] = nums[i];
    }
    MaxHeap<int> maxHeap = MaxHeap<int>(arr, n);

    // 从小到大排序，extractMax得到的是从大到小
    vector<int> res = vector<int>(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--) {
      res[i] = maxHeap.extractMax();
    }
    return res;
  }
};