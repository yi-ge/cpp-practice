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
  vector<int> heapSort(vector<int> &nums) {
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
};