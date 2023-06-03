// 强整数
// https://leetcode.cn/problems/powerful-integers
// INLINE  ../../images/map/powerful_integers.jpeg
#include <headers.hpp>

class Solution {
public:
  vector<int> powerfulIntegers(int x, int y, int bound) {
    unordered_set<int> result; // 使用 unordered_set 存储结果，可以去重
    int value1 = 1;            // 初始化 x 的幂为 1
    for (int i = 0; i < 21; i++) { // 因为 x 和 y 的范围都在 [1, 100]，所以 x^20
                                   // 和 y^20 足够大，可以作为循环终止条件
      int value2 = 1;                // 初始化 y 的幂为 1
      for (int j = 0; j < 21; j++) { // 同理，y 的幂也是如此
        int value = value1 + value2; // 计算两数幂之和
        if (value <= bound) { // 如果和小于等于 bound，加入到结果集合中
          result.emplace(value);
        } else { // 如果和大于 bound，跳出循环
          break;
        }
        value2 *= y; // 计算下一个 y 的幂
      }
      if (value1 > bound) { // 如果 x 的幂已经大于 bound，跳出循环
        break;
      }
      value1 *= x; // 计算下一个 x 的幂
    }
    return vector<int>(result.begin(),
                       result.end()); // 将结果集合转换为 vector 返回
  }
};