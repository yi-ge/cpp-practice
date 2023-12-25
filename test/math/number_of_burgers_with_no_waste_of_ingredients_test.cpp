#include <math/number_of_burgers_with_no_waste_of_ingredients.cpp>

TEST(不浪费原料的汉堡制作方案, numOfBurgers) {
  Solution solution;
  // 示例 1：
  // 输入：tomatoSlices = 16, cheeseSlices = 7
  // 输出：[1,6]
  // 解释：制作 1 个巨无霸汉堡和 6 个小皇堡需要 4*1 + 2*6 = 16 片番茄和 1 + 6 =
  // 7 片奶酪。不会剩下原料。
  int tomatoSlices = 16;
  int cheeseSlices = 7;
  vector<int> result = solution.numOfBurgers(tomatoSlices, cheeseSlices);
  vector<int> except = {1, 6};
  EXPECT_EQ(result, except);

  // 示例 2：
  // 输入：tomatoSlices = 17, cheeseSlices = 4
  // 输出：[]
  // 解释：只制作小皇堡和巨无霸汉堡无法用光全部原料。
  tomatoSlices = 17;
  cheeseSlices = 4;
  result = solution.numOfBurgers(tomatoSlices, cheeseSlices);
  except = {};
  EXPECT_EQ(result, except);

  // 示例 3：
  // 输入：tomatoSlices = 4, cheeseSlices = 17
  // 输出：[]
  // 解释：制作 1 个巨无霸汉堡会剩下 16 片奶酪，制作 2 个小皇堡会剩下 15
  // 片奶酪。
  tomatoSlices = 4;
  cheeseSlices = 17;
  result = solution.numOfBurgers(tomatoSlices, cheeseSlices);
  except = {};

  // 示例 4：
  // 输入：tomatoSlices = 0, cheeseSlices = 0
  // 输出：[0,0]
  tomatoSlices = 0;
  cheeseSlices = 0;
  result = solution.numOfBurgers(tomatoSlices, cheeseSlices);
  except = {0, 0};

  // 示例 5：
  // 输入：tomatoSlices = 2, cheeseSlices = 1
  // 输出：[0,1]
  tomatoSlices = 2;
  cheeseSlices = 1;
  result = solution.numOfBurgers(tomatoSlices, cheeseSlices);
  except = {0, 1};
}
