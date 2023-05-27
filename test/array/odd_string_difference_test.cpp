#include <array/odd_string_difference.cpp>

TEST(差值数组不同的字符串, oddString) {
  Solution solution;
  // 示例 1：
  // 输入：words = ["adc","wzy","abc"]
  // 输出："abc"
  // 解释：
  // - "adc" 的差值整数数组是 [3 - 0, 2 - 3] = [3, -1] 。
  // - "wzy" 的差值整数数组是 [25 - 22, 24 - 25]= [3, -1] 。
  // - "abc" 的差值整数数组是 [1 - 0, 2 - 1] = [1, 1] 。
  // 不同的数组是 [1, 1]，所以返回对应的字符串，"abc"。
  vector<string> words = {"adc", "wzy", "abc"};
  string result = solution.oddString(words);
  EXPECT_EQ(result, "abc");

  // 示例 2：
  // 输入：words = ["aaa","bob","ccc","ddd"]
  // 输出："bob"
  // 解释：除了 "bob" 的差值整数数组是 [13, -13]
  // 以外，其他字符串的差值整数数组都是 [0, 0] 。
  vector<string> words2 = {"aaa", "bob", "ccc", "ddd"};
  string result2 = solution.oddString(words2);
  EXPECT_EQ(result2, "bob");
}
