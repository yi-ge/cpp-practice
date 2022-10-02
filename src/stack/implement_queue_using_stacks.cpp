// 用栈实现队列
// https://leetcode.cn/problems/implement-queue-using-stacks/
// INLINE  ../../images/stack/implement_queue_using_stacks.jpeg
#include <headers.hpp>

class MyQueue {
private:
  stack<int> inStack, outStack;

  void inToOut() {
    while (!inStack.empty()) {
      outStack.push(inStack.top());
      inStack.pop();
    }
  }

public:
  MyQueue() {}

  void push(int x) { inStack.push(x); }

  int pop() {
    if (outStack.empty()) {
      inToOut();
    }
    int n = outStack.top();
    outStack.pop();
    return n;
  }

  int peek() {
    if (outStack.empty()) {
      inToOut();
    }
    return outStack.top();
  }

  bool empty() { return inStack.empty() && outStack.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */