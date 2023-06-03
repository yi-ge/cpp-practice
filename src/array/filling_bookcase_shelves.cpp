// 填充书架
// https://leetcode.cn/problems/filling-bookcase-shelves
// INLINE  ../../images/array/filling_bookcase_shelves.jpeg
#include <headers.hpp>

class Solution {
public:
  int minHeightShelves(vector<vector<int>> &books, int shelfWidth) {
    int n = books.size();
    vector<int> dp(n + 1, INT_MAX);
    // dp[i]表示放置i本书时的最小高度
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      int width = books[i - 1][0];
      int height = books[i - 1][1];
      // 首先考虑将第i本书单独放置在一层
      dp[i] = dp[i - 1] + height;
      // 从i-1本书开始往前遍历，尝试将第j到第i本书一起放置在一层
      for (int j = i - 1; j > 0 && width + books[j - 1][0] <= shelfWidth; j--) {
        // 更新该层的高度为最高的一本书的高度
        height = max(height, books[j - 1][1]);
        // 更新该层的宽度为放置的所有书的总宽度
        width += books[j - 1][0];
        // 更新dp[i]为更小的值
        dp[i] = min(dp[i], dp[j - 1] + height);
      }
    }
    return dp[n];
  }
};