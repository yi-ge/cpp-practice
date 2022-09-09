#include <stack/crawler_log_folder.cpp>

TEST(文件夹操作日志搜集器, minOperations) {
  // 示例 1：
  // 输入：logs = ["d1/","d2/","../","d21/","./"]
  // 输出：2
  // 解释：执行 "../" 操作变更文件夹 2 次，即可回到主文件夹
  Solution solution;
  vector<string> logs = {"d1/", "d2/", "../", "d21/", "./"};
  EXPECT_EQ(solution.minOperations(logs), 2);

  // 示例 2：
  // 输入：logs = ["d1/","d2/","./","d3/","../","d31/"]
  // 输出：3
  vector<string> logs2 = {"d1/", "d2/", "./", "d3/", "../", "d31/"};
  EXPECT_EQ(solution.minOperations(logs2), 3);

  // 示例 3：
  // 输入：logs = ["d1/","../","../","../"]
  // 输出：0
  vector<string> logs3 = {"d1/", "../", "../", "../"};
  EXPECT_EQ(solution.minOperations(logs3), 0);

  // 示例 4：
  // 输入：logs = ["./","wz4/","../","mj2/","../","../","ik0/","il7/"]
  // 输出：2
  vector<string> logs4 = {"./",  "wz4/", "../",  "mj2/",
                          "../", "../",  "ik0/", "il7/"};
  EXPECT_EQ(solution.minOperations(logs4), 2);
}
