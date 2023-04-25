// 按身高排序
// https://leetcode.cn/problems/sort-the-people
// INLINE  ../../images/sort/sort_the_people.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
    vector<pair<int, string>> people;
    for (int i = 0; i < names.size(); ++i) {
      people.emplace_back(heights[i], names[i]);
    }
    sort(people.begin(), people.end(), greater<pair<int, string>>());
    vector<string> result;
    for (auto &p : people) {
      result.push_back(p.second);
    }
    return result;
  }
};