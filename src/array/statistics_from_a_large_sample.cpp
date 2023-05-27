// 大样本统计
// https://leetcode.cn/problems/statistics-from-a-large-sample
// INLINE  ../../images/array/statistics_from_a_large_sample.jpeg
// 参考官方题解
#include <headers.hpp>

class Solution {
public:
  vector<double> sampleStats(vector<int> &count) {
    int n = count.size();
    int total = accumulate(count.begin(), count.end(), 0);
    double mean = 0.0;
    double median = 0.0;
    int minnum = 256;
    int maxnum = 0;
    int mode = 0;

    int left = (total + 1) / 2;
    int right = (total + 2) / 2;
    int cnt = 0;
    int maxfreq = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum += (long long)count[i] * i;
      if (count[i] > maxfreq) {
        maxfreq = count[i];
        mode = i;
      }
      if (count[i] > 0) {
        if (minnum == 256) {
          minnum = i;
        }
        maxnum = i;
      }
      if (cnt < right && cnt + count[i] >= right) {
        median += i;
      }
      if (cnt < left && cnt + count[i] >= left) {
        median += i;
      }
      cnt += count[i];
    }
    mean = (double)sum / total;
    median = median / 2.0;
    return {(double)minnum, (double)maxnum, mean, median, (double)mode};
  }
};