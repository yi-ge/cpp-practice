// 不浪费原料的汉堡制作方案
// https://leetcode.cn/problems/number-of-burgers-with-no-waste-of-ingredients
// INLINE  ../../images/math/number_of_burgers_with_no_waste_of_ingredients.jpeg

#include <headers.hpp>

class Solution {
public:
  vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    vector<int> result;
    if (tomatoSlices % 2 != 0) {
      return result;
    }
    int jumbo = tomatoSlices / 2 - cheeseSlices;
    int small = cheeseSlices - jumbo;
    if (jumbo < 0 || small < 0) {
      return result;
    }
    result.push_back(jumbo);
    result.push_back(small);
    return result;
  }
};