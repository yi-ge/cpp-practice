// 分数加减运算
// https://leetcode.cn/problems/fraction-addition-and-subtraction
// INLINE  ../images/math/fraction_addition_and_subtraction.jpeg
// 解题思路：参考官方题解，此题我也是参考题解的。
#include <headers.hpp>
#include <numeric>

class Solution
{
public:
  string fractionAddition(string expression)
  {
    long long x = 0, y = 1; // 初始化分子和分母
    int index = 0, n = expression.size();
    while (index < n) {
        // 读取分子
        long long x1 = 0, sign = 1; // 初始化分子和符号
        if (expression[index] == '-' || expression[index] == '+') { // 判断符号
            sign = expression[index] == '-' ? -1 : 1;
            index++;
        }
        while (index < n && isdigit(expression[index])) { // 读取分子
            x1 = x1 * 10 + expression[index] - '0';
            index++;
        }
        x1 = sign * x1; // 根据符号确定最终分子
        index++;

        // 读取分母
        long long y1 = 0;
        while (index < n && isdigit(expression[index])) { // 读取分母
            y1 = y1 * 10 + expression[index] - '0';
            index++;
        }

        x = x * y1 + x1 * y; // 通分后相加
        y *= y1; // 更新分母
    }
    if (x == 0) { // 特殊情况，分子为0
        return "0/1";
    }
    long long g = gcd(abs(x), y); // 获取最大公约数，C17+ 需要引入 numeric 库
    return to_string(x / g) + "/" + to_string(y / g); // 输出最简分数
  }
};