#include <sort/mice_and_cheese.cpp>

TEST(老鼠和奶酪, miceAndCheese) {
  Solution solution;
  // 示例 1：
  // 输入：reward1 = [1,1,3,4], reward2 = [4,4,1,1], k = 2
  // 输出：15
  // 解释：这个例子中，第一只老鼠吃掉第 2 和 3 块奶酪（下标从 0
  // 开始），第二只老鼠吃掉第 0 和 1 块奶酪。 总得分为 4 + 4 + 3 + 4 = 15 。 15
  // 是最高得分。
  vector<int> reward1 = {1, 1, 3, 4};
  vector<int> reward2 = {4, 4, 1, 1};
  int k = 2;
  EXPECT_EQ(solution.miceAndCheese(reward1, reward2, k), 15);

  // 示例 2：
  // 输入：reward1 = [1,1], reward2 = [1,1], k = 2
  // 输出：2
  // 解释：这个例子中，第一只老鼠吃掉第 0 和 1 块奶酪（下标从 0
  // 开始），第二只老鼠不吃任何奶酪。 总得分为 1 + 1 = 2 。 2 是最高得分。
  reward1 = {1, 1};
  reward2 = {1, 1};
  k = 2;
  EXPECT_EQ(solution.miceAndCheese(reward1, reward2, k), 2);
}
