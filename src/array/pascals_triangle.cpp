// 杨辉三角
// https://leetcode-cn.com/problems/pascals-triangle
// INLINE  ../../images/array/pascals_triangle.jpeg

#include <headers.hpp>

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ret(numRows); // 创建一个二维vector，其中第一维长度为numRows，第二维长度为i+1
    for (int i = 0; i < numRows; ++i) { // 循环numRows次，每次处理一行
      ret[i].resize(i + 1); // 第i行的长度为i+1
      ret[i][0] = ret[i][i] = 1; // 第i行的第一个和最后一个元素都是1
      for (int j = 1; j < i; ++j) { // 处理第i行的第1~i-1个元素
        ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1]; // 第i行第j个元素等于第i-1行第j个元素和第i-1行第j-1个元素之和
      }
    }
    return ret; // 返回二维vector
  }
};