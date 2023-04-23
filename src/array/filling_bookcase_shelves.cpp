// 填充书架
// https://leetcode.cn/problems/filling-bookcase-shelves
// INLINE  ../../images/array/filling_bookcase_shelves.jpeg
#include <headers.hpp>

class Solution {
public:
  int minHeightShelves(vector<vector<int>> &books, int shelfWidth) {
    int n = books.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      int width = books[i - 1][0];
      int height = books[i - 1][1];
      dp[i] = dp[i - 1] + height;
      for (int j = i - 1; j > 0 && width + books[j - 1][0] <= shelfWidth; j--) {
        height = max(height, books[j - 1][1]);
        width += books[j - 1][0];
        dp[i] = min(dp[i], dp[j - 1] + height);
      }
    }
    return dp[n];
  }
};