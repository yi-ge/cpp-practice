#include <string/minimum_number_of_frogs_croaking.cpp>

TEST(数青蛙, minNumberOfFrogs) {
  // 示例 1：
  // 输入：croakOfFrogs = "croakcroak"
  // 输出：1
  // 解释：一只青蛙 “呱呱” 两次
  Solution solution;
  string croakOfFrogs = "croakcroak";
  EXPECT_EQ(solution.minNumberOfFrogs(croakOfFrogs), 1);

  // 示例 2：
  // 输入：croakOfFrogs = "crcoakroak"
  // 输出：2
  // 解释：最少需要两只青蛙，“呱呱” 声用黑体标注
  // 第一只青蛙 "crcoakroak"
  // 第二只青蛙 "crcoakroak"
  EXPECT_EQ(solution.minNumberOfFrogs("crcoakroak"), 2);

  // 示例 3：
  // 输入：croakOfFrogs = "croakcrook"
  // 输出：-1
  // 解释：给出的字符串不是 "croak" 的有效组合。
  EXPECT_EQ(solution.minNumberOfFrogs("croakcrook"), -1);
}
