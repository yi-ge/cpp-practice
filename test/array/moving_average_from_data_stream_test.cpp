#include <array/moving_average_from_data_stream.cpp>

TEST(数据流中的移动平均值, MovingAverage)
{
  // 示例：
  // 输入：
  // ["MovingAverage", "next", "next", "next", "next"]
  // [[3], [1], [10], [3], [5]]
  // 输出：
  // [null, 1.0, 5.5, 4.66667, 6.0]

  MovingAverage movingAverage(3);
  EXPECT_DOUBLE_EQ(movingAverage.next(1), 1.0);     // 返回 1.0 = 1 / 1
  EXPECT_DOUBLE_EQ(movingAverage.next(10), 5.5);    // 返回 5.5 = (1 + 10) / 2
  EXPECT_DOUBLE_EQ(movingAverage.next(3), 4.66667); // 返回 4.66667 = (1 + 10 + 3) / 3
  EXPECT_DOUBLE_EQ(movingAverage.next(5), 6.0);     // 返回 6.0 = (10 + 3 + 5) / 3
}
