#include <array/maximum_points_you_can_obtain_from_cards.cpp>

TEST(可获得的最大点数, maxScore) {
  Solution solution;
  // 示例 1：
  // 输入：cardPoints = [1,2,3,4,5,6,1], k = 3
  // 输出：12
  // 解释：第一次行动，不管拿哪张牌，你的点数总是 1
  // 。但是，先拿最右边的卡牌将会最大化你的可获得点数。最优策略是拿右边的三张牌，最终点数为
  // 1 + 6 + 5 = 12 。
  vector<int> cardPoints1 = {1, 2, 3, 4, 5, 6, 1};
  int k1 = 3;
  int expected1 = 12;
  EXPECT_EQ(solution.maxScore(cardPoints1, k1), expected1);

  // 示例 2：
  // 输入：cardPoints = [2,2,2], k = 2
  // 输出：4
  // 解释：无论你拿起哪两张卡牌，可获得的点数总是 4 。
  vector<int> cardPoints2 = {2, 2, 2};
  int k2 = 2;
  int expected2 = 4;
  EXPECT_EQ(solution.maxScore(cardPoints2, k2), expected2);

  // 示例 3：
  // 输入：cardPoints = [9,7,7,9,7,7,9], k = 7
  // 输出：55
  // 解释：你必须拿起所有卡牌，可以获得的点数为所有卡牌的点数之和。
  vector<int> cardPoints3 = {9, 7, 7, 9, 7, 7, 9};
  int k3 = 7;
  int expected3 = 55;
  EXPECT_EQ(solution.maxScore(cardPoints3, k3), expected3);

  // 示例 4：
  // 输入：cardPoints = [1,1000,1], k = 1
  // 输出：1
  // 解释：你无法拿到中间那张卡牌，所以可以获得的最大点数为 1 。
  vector<int> cardPoints4 = {1, 1000, 1};
  int k4 = 1;
  int expected4 = 1;
  EXPECT_EQ(solution.maxScore(cardPoints4, k4), expected4);

  // 示例 5：
  // 输入：cardPoints = [1,79,80,1,1,1,200,1], k = 3
  // 输出：202
  vector<int> cardPoints5 = {1, 79, 80, 1, 1, 1, 200, 1};
  int k5 = 3;
  int expected5 = 202;
  EXPECT_EQ(solution.maxScore(cardPoints5, k5), expected5);
}
