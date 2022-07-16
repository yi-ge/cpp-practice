// 数据流中的移动平均值
// https://leetcode.cn/problems/moving-average-from-data-stream/
// INLINE  ../images/array/moving_average_from_data_stream.jpeg
#include <headers.hpp>

class MovingAverage
{
public:
  MovingAverage(int size)
  {
    this->sum = 0;
    this->size = size;
  }

  double next(int val)
  {
    if (arr.size() == size)
    {
      vector<int>::iterator iter = arr.begin();
      sum -= *iter;
      arr.erase(iter);
    }

    sum += val;
    arr.push_back(val);
    return floor((double)sum / arr.size() * 100000 + 0.5) / 100000;
  }

private:
  int size;
  int sum;
  vector<int> arr; // 推荐使用queue<int>
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */