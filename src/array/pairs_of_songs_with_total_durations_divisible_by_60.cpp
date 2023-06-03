// 总持续时间可被 60 整除的歌曲
// https://leetcode.cn/problems/pairs-of-songs-with-total-durations-divisible-by-60
// INLINE  ../../images/array/pairs_of_songs_with_total_durations_divisible_by_60.jpeg
#include <headers.hpp>

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0; // 计数器，记录符合条件的歌曲组合数
        vector<int> remainders(60, 0); // 定义一个长度为60的数组，记录余数出现的次数
        for (int t : time) { // 遍历歌曲时间数组
            if (t % 60 == 0) { // 如果当前歌曲时间能被60整除
                count += remainders[0]; // 则将余数为0的歌曲组合数累加到计数器中
            } else { // 否则
                count += remainders[60 - t % 60]; // 将余数为(60-t%60)的歌曲组合数累加到计数器中
            }
            ++remainders[t % 60]; // 将当前歌曲时间的余数出现次数加1
        }
        return count; // 返回符合条件的歌曲组合数
    }
};