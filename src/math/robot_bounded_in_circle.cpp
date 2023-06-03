// 困于环中的机器人
// https://leetcode.cn/problems/robot-bounded-in-circle
// INLINE  ../../images/math/robot_bounded_in_circle.jpeg
#include <headers.hpp>

class Solution {
public:
  bool isRobotBounded(string instructions) {
    int x = 0, y = 0, direction = 0; // 设定机器人的坐标和朝向
    
    // 遍历指令
    for (char c : instructions) {
      switch (c) {
      case 'G': // 前进一格
        if (direction == 0) { // 朝上
          ++y;
        } else if (direction == 1) { // 朝右
          ++x;
        } else if (direction == 2) { // 朝下
          --y;
        } else if (direction == 3) { // 朝左
          --x;
        }
        break;
      case 'L': // 左转
        direction = (direction + 3) % 4; // 顺时针旋转90度，相当于逆时针旋转270度
        break;
      case 'R': // 右转
        direction = (direction + 1) % 4; // 逆时针旋转90度，相当于顺时针旋转270度
        break;
      }
    }

    // 如果机器人回到原点或者不朝上，则机器人在有限的指令内不可能回到原点
    return (x == 0 && y == 0) || direction != 0;
  }
};