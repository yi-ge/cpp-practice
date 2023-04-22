#include <string/longest_chunked_palindrome_decomposition.cpp>

TEST(段式回文, longestDecomposition) {
  // 示例 1：
  // 输入：text = "ghiabcdefhelloadamhelloabcdefghi"
  // 输出：7
  // 解释：我们可以把字符串拆分成
  // "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)"。
  Solution solution;
  string text = "ghiabcdefhelloadamhelloabcdefghi";
  EXPECT_EQ(solution.longestDecomposition(text), 7);

  // 示例 2：
  // 输入：text = "merchant"
  // 输出：1
  // 解释：我们可以把字符串拆分成 "(merchant)"。
  text = "merchant";
  EXPECT_EQ(solution.longestDecomposition(text), 1);

  // 示例 3：
  // 输入：text = "antaprezatepzapreanta"
  // 输出：11
  // 解释：我们可以把字符串拆分成
  // "(a)(nt)(a)(pre)(za)(tpe)(za)(pre)(a)(nt)(a)"。
  text = "antaprezatepzapreanta";
  EXPECT_EQ(solution.longestDecomposition(text), 11);
}
