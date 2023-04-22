// 子数组中占绝大多数的元素
// https://leetcode.cn/problems/online-majority-element-in-subarray
// INLINE  ../../images/array/online_majority_element_in_subarray.jpeg
// 官方题解
#include <headers.hpp>
#include <random>

class MajorityChecker {
public:
  MajorityChecker(vector<int> &arr) : arr(arr) {
    for (int i = 0; i < arr.size(); ++i) {
      loc[arr[i]].push_back(i);
    }
  }

  int query(int left, int right, int threshold) {
    int length = right - left + 1;
    uniform_int_distribution<int> dis(left, right);

    for (int i = 0; i < k; ++i) {
      int x = arr[dis(gen)];
      vector<int> &pos = loc[x];
      int occ = upper_bound(pos.begin(), pos.end(), right) -
                lower_bound(pos.begin(), pos.end(), left);
      if (occ >= threshold) {
        return x;
      } else if (occ * 2 >= length) {
        return -1;
      } // LCOV_EXCL_LINE
    }   // LCOV_EXCL_LINE

    return -1; // LCOV_EXCL_LINE
  }

private:
  static constexpr int k = 20;

  const vector<int> &arr;
  unordered_map<int, vector<int>> loc;
  mt19937 gen{random_device{}()};
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */