// 数据流中的移动平均值
// https://leetcode.cn/problems/moving-average-from-data-stream/
// INLINE  ../../images/array/moving_average_from_data_stream.jpeg
#include <headers.hpp>

class MovingAverage
{
public:
  MovingAverage(int size)
  {
    this->sum = 0; // 初始化当前总和为0
    this->size = size; // 初始化队列最大长度
  }

  double next(int val)
  {
    if (arr.size() == size) // 如果队列长度已经达到最大值
    {
      vector<int>::iterator iter = arr.begin(); // 取出队列头部元素的迭代器
      sum -= *iter; // 从当前总和中减去头部元素的值
      arr.erase(iter); // 从队列中删除头部元素
    }

    sum += val; // 将新的元素值加入到当前总和中
    arr.push_back(val); // 将新元素加入到队列尾部
    return floor((double)sum / arr.size() * 100000 + 0.5) / 100000; // 计算队列中元素的平均值并返回，保留小数点后5位
  }

private:
  int size; // 队列最大长度
  int sum; // 队列中元素的总和
  vector<int> arr; // 存储队列元素的数组，推荐使用queue<int>
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */