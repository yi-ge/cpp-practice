// 受标签影响的最大值
// https://leetcode.cn/problems/largest-values-from-labels
// INLINE  ../../images/sort/largest_values_from_labels.jpeg
#include <headers.hpp>

class Solution {
public:
  int largestValsFromLabels(vector<int> &values, vector<int> &labels,
                            int numWanted, int useLimit) {
    vector<pair<int, int>> v;
    for (int i = 0; i < values.size(); ++i) {
      v.push_back({values[i], labels[i]});
    }
    sort(v.begin(), v.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           return a.first > b.first;
         });
    unordered_map<int, int> m;
    int res = 0;
    for (int i = 0; i < v.size(); ++i) {
      if (m[v[i].second] < useLimit) {
        res += v[i].first;
        ++m[v[i].second];
        --numWanted;
      }
      if (numWanted == 0) {
        break;
      }
    }
    return res;
  }
};