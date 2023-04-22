#include <math/robot_bounded_in_circle.cpp>

TEST(困于环中的机器人, isRobotBounded) {
  Solution solution;
  // 示例 1：
  // 输入：instructions = "GGLLGG"
  // 输出：true
  // 解释：机器人最初在(0,0)处，面向北方。
  // “G”:移动一步。位置:(0,1)方向:北。
  // “G”:移动一步。位置:(0,2).方向:北。
  // “L”:逆时针旋转90度。位置:(0,2).方向:西。
  // “L”:逆时针旋转90度。位置:(0,2)方向:南。
  // “G”:移动一步。位置:(0,1)方向:南。
  // “G”:移动一步。位置:(0,0)方向:南。
  // 重复指令，机器人进入循环:(0,0)——>(0,1)——>(0,2)——>(0,1)——>(0,0)。
  // 在此基础上，我们返回true。
  std::string instructions1 = "GGLLGG";
  EXPECT_TRUE(solution.isRobotBounded(instructions1));

  // 示例 2：
  // 输入：instructions = "GG"
  // 输出：false
  // 解释：机器人最初在(0,0)处，面向北方。
  // “G”:移动一步。位置:(0,1)方向:北。
  // “G”:移动一步。位置:(0,2).方向:北。
  // 重复这些指示，继续朝北前进，不会进入循环。
  // 在此基础上，返回false。
  std::string instructions2 = "GG";
  EXPECT_FALSE(solution.isRobotBounded(instructions2));

  // 示例 3：
  // 输入：instructions = "GL"
  // 输出：true
  // 解释：机器人最初在(0,0)处，面向北方。
  // “G”:移动一步。位置:(0,1)方向:北。
  // “L”:逆时针旋转90度。位置:(0,1).方向:西。
  // “G”:移动一步。位置:(- 1,1)方向:西。
  // “L”:逆时针旋转90度。位置:(- 1,1)方向:南。
  // “G”:移动一步。位置:(- 1,0)方向:南。
  // “L”:逆时针旋转90度。位置:(- 1,0)方向:东方。
  // “G”:移动一步。位置:(0,0)方向:东方。
  // “L”:逆时针旋转90度。位置:(0,0)方向:北。
  // 重复指令，机器人进入循环:(0,0)——>(0,1)——>(- 1,1)——>(- 1,0)——>(0,0)。
  // 在此基础上，我们返回true。
  std::string instructions3 = "GL";
  EXPECT_TRUE(solution.isRobotBounded(instructions3));

  // 示例 4：测试字符“R”的分支。
  std::string instructions4 = "GRGRGRGR";
  EXPECT_TRUE(solution.isRobotBounded(instructions4));

  // 示例 5：测试字符“L”和“R”组合的分支。
  std::string instructions5 = "GLRGLRGLR";
  EXPECT_FALSE(solution.isRobotBounded(instructions5));

  // 示例 6：测试空字符串。
  std::string instructions6 = "";
  EXPECT_TRUE(solution.isRobotBounded(instructions6));

  // 示例 7：测试无效字符。
  std::string instructions7 = "GGLLGGX";
  EXPECT_TRUE(solution.isRobotBounded(instructions7));
}
