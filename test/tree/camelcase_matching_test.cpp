#include <tree/camelcase_matching.cpp>

TEST(驼峰式匹配, camelMatch) {
  // 示例 1：
  // 输入：queries =
  // ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern =
  // "FB" 输出：[true,false,true,true,false] 示例： "FooBar" 可以这样生成："F" +
  // "oo" + "B" + "ar"。 "FootBall" 可以这样生成："F" + "oot" + "B" + "all".
  // "FrameBuffer" 可以这样生成："F" + "rame" + "B" + "uffer".
  Solution solution;
  vector<string> queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer",
                            "ForceFeedBack"};
  string pattern = "FB";
  vector<bool> expected_output1 = {true, false, true, true, false};
  EXPECT_EQ(solution.camelMatch(queries, pattern), expected_output1);

  // 示例：
  // 示例 2：
  // 示例 2：
  // 输入：queries =
  // ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern =
  // "FoBa" 输出：[true,false,true,false,false] 解释： "FooBar"
  // 可以这样生成："Fo" + "o" + "Ba" + "r". "FootBall" 可以这样生成："Fo" + "ot"
  // + "Ba" + "ll".
  vector<string> queries2 = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer",
                             "ForceFeedBack"};
  string pattern2 = "FoBa";
  vector<bool> expected_output2 = {true, false, true, false, false};
  EXPECT_EQ(solution.camelMatch(queries2, pattern2), expected_output2);

  // 示例 3：
  // 输出：queries =
  // ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern =
  // "FoBaT" 输入：[false,true,false,false,false] 解释： "FooBarTest"
  // 可以这样生成："Fo" + "o" + "Ba" + "r" + "T" + "est".
  vector<string> queries3 = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer",
                             "ForceFeedBack"};
  string pattern3 = "FoBaT";
  vector<bool> expected_output3 = {false, true, false, false, false};
  EXPECT_EQ(solution.camelMatch(queries3, pattern3), expected_output3);
}
