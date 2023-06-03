// 统计共同度过的日子数
// https://leetcode.cn/problems/count-days-spent-together
// INLINE  ../../images/math/count_days_spent_together.jpeg
// 分别计算出每个日子是一年中的第几天后求差
// https://leetcode.cn/problems/count-days-spent-together/solution/tong-ji-gong-tong-du-guo-de-ri-zi-shu-by-1iwp/
#include <headers.hpp>

class Solution {
public:
  int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob,
                        string leaveBob) {
    vector<int> datesOfMonths = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31}; // 每个月对应的天数，注意二月份是28天
    vector<int> prefixSum(1, 0); // 统计到每个月的天数的前缀和
    for (int date : datesOfMonths) {
      prefixSum.emplace_back(prefixSum.back() + date);
    }

    int arriveAliceDay = calculateDayOfYear(
        arriveAlice, prefixSum); // 计算爱丽丝到达的那天是这一年的第几天
    int leaveAliceDay = calculateDayOfYear(
        leaveAlice, prefixSum); // 计算爱丽丝离开的那天是这一年的第几天
    int arriveBobDay = calculateDayOfYear(
        arriveBob, prefixSum); // 计算鲍勃到达的那天是这一年的第几天
    int leaveBobDay = calculateDayOfYear(
        leaveBob, prefixSum); // 计算鲍勃离开的那天是这一年的第几天
    return max(
        0,
        min(leaveAliceDay, leaveBobDay) - max(arriveAliceDay, arriveBobDay) +
            1); // 计算两人共同在一起的天数，即离开时间的最小值减去到达时间的最大值再加1
  }

  int calculateDayOfYear(string day, const vector<int> &prefixSum) {
    int month = stoi(day.substr(0, 2)); // 获取日期字符串中的月份
    int date = stoi(day.substr(3));     // 获取日期字符串中的日期
    return prefixSum[month - 1] + date; // 返回这一年的第几天
  }
};