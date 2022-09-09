// 文件夹操作日志搜集器
// https://leetcode.cn/problems/crawler-log-folder
// INLINE  ../../images/stack/crawler_log_folder.jpeg
#include <headers.hpp>

class Solution {
public:
  int minOperations(vector<string> &logs) {
    int res = 0;
    for (int i = 0; i < logs.size(); i++) {
      if (logs[i] == "../") {
        if (res > 0) {
          res--;
        }
      } else if (logs[i] == "./") {
        continue;
      } else {
        res++;
      }
    }

    return res;
  }
};