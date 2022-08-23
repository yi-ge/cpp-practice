// 归并排序

#include <headers.hpp>

class Solution
{
public:
  vector<int> mergeSort(vector<int> &nums)
  {
    if (nums.size() <= 1)
      return nums;
    int halfIndex = floor(nums.size() / 2);
    vector<int> left;
    left.assign(nums.begin(), nums.begin() + halfIndex);

    vector<int> right;
    right.assign(nums.begin() + halfIndex, nums.end());

    vector<int> leftSort = mergeSort(left);
    vector<int> rightSort = mergeSort(right);
    return marge(leftSort, rightSort);
  }

private:
  vector<int> marge(vector<int> &left, vector<int> &right)
  {
    vector<int> res;
    while (left.size() > 0 && right.size() > 0)
    {
      if (left[0] < right[0])
      {
        res.push_back(left[0]);
        vector<int>::iterator k = left.begin();
        left.erase(k);
      }
      else
      {
        res.push_back(right[0]);
        vector<int>::iterator j = right.begin();
        right.erase(j);
      }
    }
    res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
    return res;
  }
};