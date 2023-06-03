// 受标签影响的最大值
// https://leetcode.cn/problems/largest-values-from-labels
// INLINE  ../../images/sort/largest_values_from_labels.jpeg
#include <headers.hpp>

class Solution {
public:
  // 求出从values中选numWanted个数的最大值，其中每个数有对应的标签labels，
  // 每个标签最多只能使用useLimit次
  int largestValsFromLabels(vector<int> &values, vector<int> &labels,
                            int numWanted, int useLimit) {
    // 将values和labels组合成pair放到vector中
    vector<pair<int, int>> v;
    for (int i = 0; i < values.size(); ++i) {
      v.push_back({values[i], labels[i]});
    }
    // 根据values中的大小进行排序
    sort(v.begin(), v.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           return a.first > b.first;
         });
    // 使用unordered_map记录每个标签已经使用的次数
    unordered_map<int, int> m;
    int res = 0;
    // 遍历排序后的vector
    for (int i = 0; i < v.size(); ++i) {
      // 如果当前标签还可以使用
      if (m[v[i].second] < useLimit) {
        // 记录当前选中的数的和
        res += v[i].first;
        // 将当前标签的使用次数加1
        ++m[v[i].second];
        // 将还需要选的数量减1
        --numWanted;
      }
      // 如果已经选够了numWanted个数，则直接退出循环
      if (numWanted == 0) {
        break;
      }
    }
    // 返回选中数的和
    return res;
  }
};