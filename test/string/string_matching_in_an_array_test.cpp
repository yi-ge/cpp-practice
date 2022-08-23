#include <string/string_matching_in_an_array.cpp>

TEST(数组中的字符串匹配, stringMatching)
{
  // 示例 1：
  // 输入：words = ["mass","as","hero","superhero"]
  // 输出：["as","hero"]
  // 解释："as" 是 "mass" 的子字符串，"hero" 是 "superhero" 的子字符串。
  // ["hero","as"] 也是有效的答案。
  Solution solution;
  vector<string> words = {"mass", "as", "hero", "superhero"};
  vector<string> actionVec = {"as", "hero"};
  EXPECT_THAT(solution.stringMatching(words), ::testing::ContainerEq(actionVec));

  // 示例 2：
  // 输入：words = ["leetcode","et","code"]
  // 输出：["et","code"]
  // 解释："et" 和 "code" 都是 "leetcode" 的子字符串。
  vector<string> words2 = {"leetcode", "et", "code"};
  vector<string> actionVec2 = {"et", "code"};
  EXPECT_THAT(solution.stringMatching(words2), ::testing::ContainerEq(actionVec2));

  // 示例 3：
  // 输入：words = ["blue","green","bu"]
  // 输出：[]
  vector<string> words3 = {"blue", "green", "bu"};
  vector<string> actionVec3 = {};
  EXPECT_THAT(solution.stringMatching(words3), ::testing::ContainerEq(actionVec3));
}
