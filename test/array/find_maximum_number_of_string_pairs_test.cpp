#include <array/find_maximum_number_of_string_pairs.cpp>

TEST(最大字符串配对数目, maximumNumberOfStringPairs) {
  Solution solution;
  // 示例 1：
  // 输入：words = ["cd","ac","dc","ca","zz"]
  // 输出：2
  // 解释：在此示例中，我们可以通过以下方式匹配 2 对字符串：
  // - 我们将第 0 个字符串与第 2 个字符串匹配，因为 word[0] 的反转字符串是 "dc"
  // 并且等于 words[2]。
  // - 我们将第 1 个字符串与第 3 个字符串匹配，因为 word[1] 的反转字符串是 "ca"
  // 并且等于 words[3]。 可以证明最多匹配数目是 2 。
  vector<string> words = {"cd", "ac", "dc", "ca", "zz"};
  EXPECT_EQ(solution.maximumNumberOfStringPairs(words), 2);

  // 示例 2：
  // 输入：words = ["ab","ba","cc"]
  // 输出：1
  // 解释：在此示例中，我们可以通过以下方式匹配 1 对字符串：
  // - 我们将第 0 个字符串与第 1 个字符串匹配，因为 words[1] 的反转字符串 "ab"
  // 与 words[0] 相等。 可以证明最多匹配数目是 1 。
  words = {"ab", "ba", "cc"};
  EXPECT_EQ(solution.maximumNumberOfStringPairs(words), 1);

  // 示例 3：
  // 输入：words = ["aa","ab"]
  // 输出：0
  // 解释：这个例子中，无法匹配任何字符串。
  words = {"aa", "ab"};
  EXPECT_EQ(solution.maximumNumberOfStringPairs(words), 0);
}
