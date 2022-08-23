// 分数加减运算
// https://leetcode.cn/problems/fraction-addition-and-subtraction
// INLINE  ../images/math/fraction_addition_and_subtraction.jpeg
#include <headers.hpp>

class Solution
{
public:
  string fractionAddition(string expression)
  {
    long long numerator = 0;   // 分子
    long long denominator = 1; // 分母
    int index = 0, n = expression.size();
    while (index < n)
    {
      // 读取分子
      long long denominator1 = 0, sign = 1;
      if (expression[index] == '-' || expression[index] == '+')
      {
        sign = expression[index] == '-' ? -1 : 1;
        index++;
      }
      while (index < n && isdigit(expression[index]))
      {
        denominator1 = denominator1 * 10 + expression[index] - '0';
        index++;
      }
      denominator1 = sign * denominator1;
      index++;

      // 读取分母
      long long numerator1 = 0;
      while (index < n && isdigit(expression[index]))
      {
        numerator1 = numerator1 * 10 + expression[index] - '0';
        index++;
      }

      denominator = denominator * numerator1 + denominator1 * numerator;
      numerator *= numerator1;
    }
    if (denominator == 0)
    {
      return "0/1";
    }
    long long g = gcd(abs(denominator), numerator); // 获取最大公约数
    return to_string(denominator / g) + "/" + to_string(numerator / g);
  }
};