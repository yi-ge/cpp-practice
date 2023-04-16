#include <array/online_majority_element_in_subarray.cpp>

TEST(子数组中占绝大多数的元素, MajorityChecker) {
  // 示例 1：
  // 输入:
  // ["MajorityChecker", "query", "query", "query"]
  // [[[1, 1, 2, 2, 1, 1]], [0, 5, 4], [0, 3, 3], [2, 3, 2]]
  // 输出：
  // [null, 1, -1, 2]

  // 解释：
  // MajorityChecker majorityChecker = new MajorityChecker([1,1,2,2,1,1]);
  // majorityChecker.query(0,5,4); // 返回 1
  // majorityChecker.query(0,3,3); // 返回 -1
  // majorityChecker.query(2,3,2); // 返回 2

  vector<int> arr = {1, 1, 2, 2, 1, 1};
  MajorityChecker *obj = new MajorityChecker(arr);
  EXPECT_EQ(obj->query(0, 5, 4), 1);
  EXPECT_EQ(obj->query(0, 3, 3), -1);
  EXPECT_EQ(obj->query(2, 3, 2), 2);
}
