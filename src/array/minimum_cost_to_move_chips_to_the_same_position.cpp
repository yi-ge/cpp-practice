// 玩筹码
// https://leetcode.cn/problems/minimum-cost-to-move-chips-to-the-same-position
// INLINE  ../images/array/minimum_cost_to_move_chips_to_the_same_position.jpeg
// 解题思路
// 这题的难点在于如何理解题目。
// 数组元素代表对应位置有1个筹码，而不是对应位置筹码的个数。
// 例如 position [1, 2]
// 代表 1 这个位置有一个筹码，2 这个位置也有一个筹码。
// 例如 position [3, 3]
// 代表 3 这个位置有 2 个筹码。
// 给筹码移动位置是有代价的，只不过代价可能是 0 。
// 将小球从 a 移动到 b 的成本取决于两位置距离的"奇偶性"，距离为偶数时成本固定为 0 ，距离为奇数时成本固定为 1 。
// 将所有小球移动到同一个位置，这个位置可以任选。假设有10个小球，均匀分布在1-10的位置上。
// 任选一点，由于一个数不是偶数就是奇数，因此有几乎一半的位置距离这个点是奇数，也有几乎一半的位置距离这个点是偶数。
// 例如选择点5，则1距离5有4个单位，2距离5有3个单位，3距离5有2个单位，4距离5有1个单位。
// 6距离5有1个单位，7距离5有2个单位，8距离5有3个单位，9距离5有4个单位，10距离5有5个单位。
// 其中有5个奇数4个偶数。因此成本为5。
// 但是如果我们选择另外一点，那么就可能有4个奇数5个偶数，因此成本为4。
// 因此我们只需要判断是移到奇数位需要的成本少，还是偶数需要的成本少。

#include <headers.hpp>

class Solution
{
public:
  int minCostToMoveChips(vector<int> &position)
  {
    int even = 0, odd = 0;
    for (int &i : position)
    {
      if (i & 1) // 等同于 n % 2 != 0
        ++odd;
      else
        ++even;
    }
    return min(odd, even);
  }
};