// 堆排序

#include <headers.hpp>
#include <max_heap.hpp>

class Solution {
public:
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
  vector<int> heapSort(vector<int> &nums) {
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