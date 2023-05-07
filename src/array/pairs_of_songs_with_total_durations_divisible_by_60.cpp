// 总持续时间可被 60 整除的歌曲
// https://leetcode.cn/problems/pairs-of-songs-with-total-durations-divisible-by-60
// INLINE  ../../images/array/pairs_of_songs_with_total_durations_divisible_by_60.jpeg
#include <headers.hpp>

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        vector<int> remainders(60, 0);
        for (int t : time) {
            if (t % 60 == 0) {
                count += remainders[0];
            } else {
                count += remainders[60 - t % 60];
            }
            ++remainders[t % 60];
        }
        return count;
    }
};