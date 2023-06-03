// 文件夹操作日志搜集器
// https://leetcode.cn/problems/crawler-log-folder
// INLINE  ../../images/stack/crawler_log_folder.jpeg

#include <headers.hpp>

class Solution {
public:
  int minOperations(vector<string> &logs) {
    int res = 0;
    for (int i = 0; i < logs.size(); i++) {
      if (logs[i] == "../") { // 如果当前操作是返回上一级目录
        if (res > 0) {        // 如果当前目录不是根目录
          res--;              // 则返回上一级目录
        }
      } else if (logs[i] == "./") { // 如果当前操作是停留在当前目录
        continue;                   // 直接跳过，不做处理
      } else { // 如果当前操作是进入下一级目录
        res++; // 进入下一级目录
      }
    }

    return res; // 返回需要的操作次数
  }
};