// 按身高排序
// https://leetcode.cn/problems/sort-the-people
// INLINE  ../../images/sort/sort_the_people.jpeg
#include <headers.hpp>

class Solution {
public:
  // 给定一组名字和身高，按照身高从高到低的顺序排序，并返回名字的排列结果
  vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
    // 保存身高和名字的对应关系
    vector<pair<int, string>> people;
    for (int i = 0; i < names.size(); ++i) {
      // 将身高和名字组成一个 pair 并加入 people 中
      people.emplace_back(heights[i], names[i]);
    }
    // 按照身高从高到低的顺序排序
    sort(people.begin(), people.end(), greater<pair<int, string>>());
    vector<string> result;
    // 取出已排好序的名字并保存到 result 中
    for (auto &p : people) {
      result.push_back(p.second);
    }
    // 返回名字的排列结果
    return result;
  }
};