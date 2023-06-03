// 子数组中占绝大多数的元素
// https://leetcode.cn/problems/online-majority-element-in-subarray
// INLINE  ../../images/array/online_majority_element_in_subarray.jpeg
// 官方题解

#include <headers.hpp>
#include <random>

class MajorityChecker {
public:
  // 构造函数，将数组中每个元素的位置存储到哈希表中
  MajorityChecker(vector<int> &arr) : arr(arr) {
    for (int i = 0; i < arr.size(); ++i) {
      loc[arr[i]].push_back(i);
    }
  }

  // 查询函数，随机从[left, right]范围内选择k个数，统计每个数在子数组中出现的次数，如果有数出现次数超过threshold，则返回该数，否则返回-1
  int query(int left, int right, int threshold) {
    int length = right - left + 1;
    uniform_int_distribution<int> dis(left, right);

    for (int i = 0; i < k; ++i) {
      int x = arr[dis(gen)]; // 随机选择一个数
      vector<int> &pos = loc[x]; // 获取该数在数组中出现的位置
      int occ = upper_bound(pos.begin(), pos.end(), right) - // 统计该数在子数组中出现的次数
                lower_bound(pos.begin(), pos.end(), left);
      if (occ >= threshold) { // 如果该数在子数组中出现的次数超过threshold，则返回该数
        return x;
      } else if (occ * 2 >= length) { // 如果该数在子数组中出现的次数小于threshold，但是在子数组中占比超过1/2，则返回-1
        return -1;
      } // LCOV_EXCL_LINE
    }   // LCOV_EXCL_LINE

    return -1; // LCOV_EXCL_LINE
  }

private:
  static constexpr int k = 20; // 随机选择数的个数

  const vector<int> &arr; // 存储原始数组
  unordered_map<int, vector<int>> loc; // 哈希表，存储每个数在数组中出现的位置
  mt19937 gen{random_device{}()}; // 随机数生成器
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */