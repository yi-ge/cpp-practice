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
    vector<int> datesOfMonths = {31, 28, 31, 30, 31, 30,
                                 31, 31, 30, 31, 30, 31};
    vector<int> prefixSum(1, 0);
    for (int date : datesOfMonths) {
      prefixSum.emplace_back(prefixSum.back() + date);
    }

    int arriveAliceDay = calculateDayOfYear(arriveAlice, prefixSum);
    int leaveAliceDay = calculateDayOfYear(leaveAlice, prefixSum);
    int arriveBobDay = calculateDayOfYear(arriveBob, prefixSum);
    int leaveBobDay = calculateDayOfYear(leaveBob, prefixSum);
    return max(0, min(leaveAliceDay, leaveBobDay) -
                      max(arriveAliceDay, arriveBobDay) + 1);
  }

  int calculateDayOfYear(string day, const vector<int> &prefixSum) {
    int month = stoi(day.substr(0, 2));
    int date = stoi(day.substr(3)); // LCOV_EXCL_LINE
    return prefixSum[month - 1] + date;
  } // LCOV_EXCL_LINE
};