// 二进制字符串前缀一致的次数
// https://leetcode.cn/problems/number-of-times-binary-string-is-prefix-aligned
// INLINE  ../../images/array/number_of_times_binary_string_is_prefix_aligned.jpeg

#include <headers.hpp>

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int right = 0;
        int res = 0;
        for (int i = 0; i < flips.size(); ++i) {
            right = max(right, flips[i]);
            if (right == i + 1) {
                ++res;
            }
        }
        return res;
    }
};