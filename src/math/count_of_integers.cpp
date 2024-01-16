// 统计整数数目
// https://leetcode.cn/problems/count-of-integers
// INLINE  ../../images/math/count_of_integers.jpeg

#include <headers.hpp>

class Solution {
public:
  int count(string num1, string num2, int min_sum, int max_sum) {
    const int mod = 1000000007;
    int m = num2.length();
    std::vector<int> up_limit, down_limit;
    for (char c : num2)
      up_limit.push_back(c - '0');
    num1 = std::string(std::max(0, m - static_cast<int>(num1.length())), '0') +
           num1;
    for (char c : num1)
      down_limit.push_back(c - '0');

    std::function<int(int, long long, bool, bool, bool)> f;
    std::unordered_map<long long, int> memo;

    f = [&](int i, long long s, bool valid, bool dlimit, bool ulimit) -> int {
      if (i == m) {
        return valid && min_sum <= s && s <= max_sum ? 1 : 0;
      }
      long long key =
          i + 1001LL * (s + 1001LL * (valid + 2LL * (dlimit + 2LL * ulimit)));
      if (memo.count(key))
        return memo[key];
      int down = dlimit ? down_limit[i] : 0;
      int up = ulimit ? up_limit[i] : 9;
      int ans = 0;
      for (int d = down; d <= up; ++d) {
        ans = (ans + f(i + 1, (s + d) % mod, valid || d != 0,
                       dlimit && d == down, ulimit && d == up)) %
              mod;
      }
      return memo[key] = ans;
    };

    return f(0, 0, false, true, true);
  }
};