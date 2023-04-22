// 困于环中的机器人
// https://leetcode.cn/problems/robot-bounded-in-circle
// INLINE  ../../images/math/robot_bounded_in_circle.jpeg
#include <headers.hpp>

class Solution {
public:
  bool isRobotBounded(string instructions) {
    int x = 0, y = 0, direction = 0;

    for (char c : instructions) {
      switch (c) {
      case 'G':
        if (direction == 0) {
          ++y;
        } else if (direction == 1) {
          ++x;
        } else if (direction == 2) {
          --y;
        } else if (direction == 3) {
          --x;
        }
        break;
      case 'L':
        direction = (direction + 3) % 4;
        break;
      case 'R':
        direction = (direction + 1) % 4;
        break;
      }
    }

    return (x == 0 && y == 0) || direction != 0;
  }
};