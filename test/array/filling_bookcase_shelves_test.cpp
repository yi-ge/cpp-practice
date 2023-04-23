#include <array/filling_bookcase_shelves.cpp>

TEST(填充书架, minHeightShelves) {
  // 示例 1：
  Solution solution;
  vector<vector<int>> books = {{1, 1}, {2, 3}, {2, 3}, {1, 1},
                               {1, 1}, {1, 1}, {1, 2}};
  int shelfWidth = 4;
  EXPECT_EQ(solution.minHeightShelves(books, shelfWidth), 6);

  // 示例 2:
  // 输入: books = [[1,3],[2,4],[3,2]], shelfWidth = 6
  // 输出: 4
  vector<vector<int>> books2 = {{1, 3}, {2, 4}, {3, 2}};
  int shelfWidth2 = 6;
  EXPECT_EQ(solution.minHeightShelves(books2, shelfWidth2), 4);
}
