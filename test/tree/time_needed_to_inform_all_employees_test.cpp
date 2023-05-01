#include <tree/time_needed_to_inform_all_employees.cpp>
TEST(通知所有员工所需的时间, numOfMinutes) {
  // 示例 1：
  // 输入：n = 1, headID = 0, manager = [-1], informTime = [0]
  // 输出：0
  // 解释：公司总负责人是该公司的唯一一名员工。
  Solution solution;
  int n = 1;
  int headID = 0;
  vector<int> manager = {-1};
  vector<int> informTime = {0};
  EXPECT_EQ(solution.numOfMinutes(n, headID, manager, informTime), 0);

  // 示例 2：
  // 输入：n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime =
  // [0,0,1,0,0,0] 输出：1 解释：id = 2
  // 的员工是公司的总负责人，也是其他所有员工的直属负责人，他需要 1
  // 分钟来通知所有员工。 上图显示了公司员工的树结构。
  n = 6;
  headID = 2;
  manager = {2, 2, -1, 2, 2, 2};
  informTime = {0, 0, 1, 0, 0, 0};
  EXPECT_EQ(solution.numOfMinutes(n, headID, manager, informTime), 1);
}
