#include <sort/car_pooling.cpp>

TEST(拼车, carPooling) {
  Solution solution;

  // 示例 1：
  // 输入：trips = [[2,1,5],[3,3,7]], capacity = 4
  // 输出：false
  vector<vector<int>> trips1 = {{2, 1, 5}, {3, 3, 7}};
  int capacity1 = 4;
  EXPECT_EQ(solution.carPooling(trips1, capacity1), false);

  // 示例 2：
  // 输入：trips = [[2,1,5],[3,3,7]], capacity = 5
  // 输出：true
  vector<vector<int>> trips2 = {{2, 1, 5}, {3, 3, 7}};
  int capacity2 = 5;
  EXPECT_EQ(solution.carPooling(trips2, capacity2), true);
}
