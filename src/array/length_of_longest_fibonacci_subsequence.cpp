// 最长的斐波那契子序列的长度
// https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence
// INLINE  ../../images/array/length_of_longest_fibonacci_subsequence.jpeg
// 解题思路：见代码，常规暴力法优化查找时间。

#include <headers.hpp>

class Solution {
public:
  int lenLongestFibSubseq(vector<int> &arr) {
    int maxLen = 0;
    // 以空间换时间。因为序列已经排好序，因此把所有数值放到Map降低第三个数查找的时间复杂度。
    unordered_set<int>
        set; // 如果用二分查找则第三个数是O(log n)，用Set则为O(1)。
    int len = arr.size();
    for (int i = 0; i < len; i++) {
      set.emplace(arr[i]);
    }
    for (int i = 0; i < len - 2; i++) {
      for (int j = i + 1; j < len - 1; j++) {
        int first = arr[i];         // 第一个数
        int second = arr[j];        // 第二个数
        int third = first + second; // 第三个数
        int currentLen =
            2; // 按题目规定，长度至少为3，如果前两个数已经确定，则长度至少为2。
        while (set.find(third) != set.end()) { // 第三个数在序列中
          currentLen++;                        // 长度加1
          first = second;                      // 第一个数变为第二个数
          second = third;                      // 第二个数变为第三个数
          third = first + second; // 第三个数变为新的第一个数加第二个数的和
        }
        maxLen = max(currentLen, maxLen); // 更新最长长度
      }
    }
    return maxLen >= 3 ? maxLen
                       : 0; // 按题目规定，长度至少为3，如果一个不存在，返回0。
  }
};