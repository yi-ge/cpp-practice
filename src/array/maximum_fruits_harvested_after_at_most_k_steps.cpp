// 摘水果
// https://leetcode.cn/problems/maximum-fruits-harvested-after-at-most-k-steps
// INLINE ../../images/array/maximum_fruits_harvested_after_at_most_k_steps.jpeg
// 参考官方题解。
#include <headers.hpp>

class Solution {
public:
  int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
    int left = 0; // 窗口左边界
    int right = 0; // 窗口右边界
    int n = fruits.size(); // 水果数量
    int sum = 0; // 窗口内水果数量总和
    int ans = 0; // 最大收获量

    auto step = [&](int left, int right) -> int { // 计算从窗口左边界到右边界的步数
      if (fruits[right][0] <= startPos) { // 右边界在起点左侧
        return startPos - fruits[left][0];
      } else if (fruits[left][0] >= startPos) { // 左边界在起点右侧
        return fruits[right][0] - startPos;
      } else { // 起点在左右边界之间
        return min(abs(startPos - fruits[right][0]), abs(startPos - fruits[left][0])) + fruits[right][0] - fruits[left][0];
      }
    };
    // 每次固定住窗口右边界
    while (right < n) {
      sum += fruits[right][1]; // 将右边界的水果加入窗口
      // 移动左边界，使得窗口内步数不超过 k
      while (left <= right && step(left, right) > k) {
        sum -= fruits[left][1]; // 将左边界的水果从窗口中移除
        left++; // 左边界右移
      }
      ans = max(ans, sum); // 更新最大收获量
      right++; // 右边界右移
    }
    return ans;
  }
};