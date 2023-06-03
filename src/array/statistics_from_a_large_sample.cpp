// 大样本统计
// https://leetcode.cn/problems/statistics-from-a-large-sample
// INLINE  ../../images/array/statistics_from_a_large_sample.jpeg
// 参考官方题解
#include <headers.hpp>

class Solution {
public:
  vector<double> sampleStats(vector<int> &count) {
    int n = count.size();
    int total = accumulate(count.begin(), count.end(), 0); // 计算总数
    double mean = 0.0; // 平均数
    double median = 0.0; // 中位数
    int minnum = 256; // 最小值
    int maxnum = 0; // 最大值
    int mode = 0; // 众数

    int left = (total + 1) / 2; // 中位数左侧的数的个数
    int right = (total + 2) / 2; // 中位数右侧的数的个数
    int cnt = 0; // 已经遍历过的数的个数
    int maxfreq = 0; // 最大频数
    long long sum = 0; // 所有数的和
    for (int i = 0; i < n; i++) {
      sum += (long long)count[i] * i; // 计算所有数的和
      if (count[i] > maxfreq) { // 如果当前数的频数大于最大频数，则更新众数
        maxfreq = count[i];
        mode = i;
      }
      if (count[i] > 0) { // 更新最小值和最大值
        if (minnum == 256) {
          minnum = i;
        }
        maxnum = i;
      }
      if (cnt < right && cnt + count[i] >= right) { // 如果右侧的数已经包含中位数，则累加右侧的数
        median += i;
      }
      if (cnt < left && cnt + count[i] >= left) { // 如果左侧的数已经包含中位数，则累加左侧的数
        median += i;
      }
      cnt += count[i]; // 更新已经遍历过的数的个数
    }
    mean = (double)sum / total; // 计算平均数
    median = median / 2.0; // 计算中位数
    return {(double)minnum, (double)maxnum, mean, median, (double)mode}; // 返回结果
  }
};