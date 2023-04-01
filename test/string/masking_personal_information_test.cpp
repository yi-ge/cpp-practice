#include <string/masking_personal_information.cpp>

TEST(隐藏个人信息, maskPII) {
  // 示例 1：
  // 输入：s = "LeetCode@LeetCode.com"
  // 输出："l*****e@leetcode.com"
  // 解释：s 是一个电子邮件地址。
  // 名字和域名都转换为小写，名字的中间用 5 个 * 替换。
  string s = "LeetCode@LeetCode.com";
  Solution solution;
  EXPECT_EQ(solution.maskPII(s), "l*****e@leetcode.com");

  // 示例 2：
  // 输入：s = "AB@qq.com"
  // 输出："a*****b@qq.com"
  // 解释：s 是一个电子邮件地址。
  // 名字和域名都转换为小写，名字的中间用 5 个 * 替换。
  // 注意，尽管 "ab" 只有两个字符，但中间仍然必须有 5 个 * 。
  s = "AB@qq.com";
  EXPECT_EQ(solution.maskPII(s), "a*****b@qq.com");

  // 示例 3：
  // 输入：s = "1(234)567-890"
  // 输出："***-***-7890"
  // 解释：s 是一个电话号码。
  // 共计 10 位数字，所以本地号码为 10 位数字，国家代码为 0 位数字。
  // 因此，隐藏后的电话号码应该是 "***-***-7890" 。
  s = "1(234)567-890";
  EXPECT_EQ(solution.maskPII(s), "***-***-7890");

  // 示例 4：
  // 输入：s = "86-(10)12345678"
  // 输出："+**-***-***-5678"
  s = "86-(10)12345678";
  EXPECT_EQ(solution.maskPII(s), "+**-***-***-5678");
}
