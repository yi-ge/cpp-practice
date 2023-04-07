#include <math/smallest_sufficient_team.cpp>

TEST(最小的必要团队, smallestSufficientTeam) {
  // 示例 1：
  // 输入：req_skills = ["java","nodejs","reactjs"], people =
  // [["java"],["nodejs"],["nodejs","reactjs"]] 输出：[0,2]
  vector<string> req_skills1 = {"java", "nodejs", "reactjs"};
  vector<vector<string>> people1 = {
      {"java"}, {"nodejs"}, {"nodejs", "reactjs"}};
  vector<int> expected_output1 = {0, 2};
  Solution solution;
  EXPECT_EQ(solution.smallestSufficientTeam(req_skills1, people1),
            expected_output1);

  // 示例 2：
  // 输入：req_skills = ["algorithms","math","java","reactjs","csharp","aws"],
  // people =
  // [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
  // 输出：[1,2]
  vector<string> req_skills2 = {"algorithms", "math",   "java",
                                "reactjs",    "csharp", "aws"};
  vector<vector<string>> people2 = {
      {"algorithms", "math", "java"},
      {"algorithms", "math", "reactjs"},
      {"java", "csharp", "aws"},
      {"reactjs", "csharp"},
      {"csharp", "math"},
      {"aws", "java"},
  };
  vector<int> expected_output2 = {1, 2};
  EXPECT_EQ(solution.smallestSufficientTeam(req_skills2, people2),
            expected_output2);
}
