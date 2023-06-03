// 使数组严格递增
// https://leetcode.cn/problems/make-array-strictly-increasing
// INLINE  ../../images/sort/make_array_strictly_increasing.jpeg
// 看官方题解
#include <headers.hpp>

constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
  int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
    sort(arr2.begin(), arr2.end()); // 对 arr2 排序
    arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end()); // 去重
    int n = arr1.size();
    int m = arr2.size();
    vector<vector<int>> dp(n + 1, vector<int>(min(m, n) + 1, INF)); // 定义状态数组
    dp[0][0] = -1; // 初始化
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= min(i, m); j++) {
        /* 如果当前元素大于序列的最后一个元素 */
        if (arr1[i - 1] > dp[i - 1][j]) {
          dp[i][j] = arr1[i - 1]; // 直接将当前元素加入序列
        }
        if (j > 0 && dp[i - 1][j - 1] != INF) {
          /* 查找严格大于 dp[i - 1][j - 1] 的最小元素 */
          auto it =
              upper_bound(arr2.begin() + j - 1, arr2.end(), dp[i - 1][j - 1]);
          if (it != arr2.end()) {
            dp[i][j] = min(dp[i][j], *it); // 将找到的元素加入序列
          }
        }
        if (i == n && dp[i][j] != INF) {
          return j; // 返回最小的可以使数组严格递增的操作次数
        }
      }
    }
    return -1; // 无法使数组严格递增
  }
};