// 餐盘栈
// https://leetcode.cn/problems/dinner-plate-stacks
// INLINE  ../../images/stack/dinner_plate_stacks.jpeg
#include <headers.hpp>
// #include <queue>
// #include <vector>

class DinnerPlates {
public:
  DinnerPlates(int capacity) { this->capacity = capacity; }

  // 将元素压入栈中
  void push(int val) {
    if (poppedPos.empty()) { // 如果没有弹出的位置
      int pos = stk.size();
      stk.emplace_back(val);     // 将元素压入栈中
      if (pos % capacity == 0) { // 如果栈已经达到容量上限
        top.emplace_back(0);     // 新开一个栈
      } else {
        top.back()++; // 将元素压入当前栈
      }
    } else {
      int pos = *poppedPos.begin();
      poppedPos.erase(pos);
      stk[pos] = val;
      int index = pos / capacity;
      top[index]++;
    }
  }

  // 从最右边的栈中弹出一个元素
  int pop() {
    // 将右边的弹出位置全部弹出
    while (!stk.empty() && poppedPos.count(stk.size() - 1)) {
      stk.pop_back();
      int pos = *poppedPos.rbegin();
      poppedPos.erase(pos);
      if (pos % capacity == 0) {
        top.pop_back(); // LCOV_EXCL_LINE
      }                 // LCOV_EXCL_LINE
    }
    if (stk.empty()) {
      return -1;
    } else {
      int pos = stk.size() - 1;
      int val = stk.back();
      stk.pop_back();
      if (pos % capacity == 0) {
        top.pop_back();
      } else {
        top.back() = top.size() - 2;
      }
      return val;
    }
  }

  // 从指定的栈中弹出一个元素
  int popAtStack(int index) {
    if (index >= top.size()) {
      return -1; // LCOV_EXCL_LINE
    }
    int stackTop = top[index];
    if (stackTop < 0) {
      return -1; // LCOV_EXCL_LINE
    }
    top[index]--;
    int pos = index * capacity + stackTop;
    poppedPos.emplace(pos);
    return stk[pos];
  }

private:
  int capacity;
  vector<int> stk;    // 栈
  vector<int> top;    // 每个栈的栈顶元素的下标
  set<int> poppedPos; // 弹出的位置
};

// class DinnerPlates {
// public:
//   DinnerPlates(int capacity) : capacity(capacity) {}

//   void push(int val) {
//     if (poppedPos.empty()) {
//       stk.emplace_back(val);
//       if (stk.size() % capacity == 1) {
//         top.emplace_back(stk.size() - 1);
//       }
//     } else {
//       int pos = poppedPos.top();
//       poppedPos.pop();
//       stk[pos] = val;
//       int index = pos / capacity;
//       if (top[index] == -1 || top[index] < pos) {
//         top[index] = pos;
//       }
//     }
//   }

//   int pop() {
//     while (!stk.empty() && top.back() == -1) {
//       top.pop_back();
//     }

//     if (stk.empty())
//       return -1;

//     int pos = top.back();
//     int val = stk[pos];
//     poppedPos.push(pos);
//     top.back()--;

//     if (top.back() % capacity == capacity - 1) {
//       top.pop_back();
//     }

//     return val;
//   }

//   int popAtStack(int index) {
//     if (index >= top.size() || top[index] == -1) {
//       return -1;
//     }

//     int pos = top[index];
//     int val = stk[pos];
//     poppedPos.push(pos);
//     top[index]--;

//     return val;
//   }

// private:
//   int capacity;
//   std::vector<int> stk;
//   std::vector<int> top;
//   std::priority_queue<int, std::vector<int>, std::greater<int>> poppedPos;
// };

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */