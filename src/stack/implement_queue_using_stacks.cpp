// 用栈实现队列
// https://leetcode.cn/problems/implement-queue-using-stacks/
// INLINE  ../../images/stack/implement_queue_using_stacks.jpeg
#include <headers.hpp>

class MyQueue {
private:
  stack<int> inStack, outStack; // 用两个栈来实现队列

  void
  inToOut() { // 翻转inStack栈，将元素按照队列的先进先出的顺序压入outStack栈
    while (!inStack.empty()) {
      outStack.push(inStack.top());
      inStack.pop();
    }
  }

public:
  MyQueue() {} // 构造函数

  void push(int x) { inStack.push(x); } // 将元素x压入inStack栈

  int pop() { // 弹出队列中的第一个元素
    if (outStack
            .empty()) { // 如果outStack栈为空，则需要先将inStack翻转到outStack中
      inToOut();
    }
    int n = outStack.top(); // 取出outStack栈顶元素
    outStack.pop();         // 弹出outStack栈顶元素
    return n;               // 返回栈顶元素
  }

  int peek() { // 返回队列中的第一个元素
    if (outStack
            .empty()) { // 如果outStack栈为空，则需要先将inStack翻转到outStack中
      inToOut();
    }
    return outStack.top(); // 返回outStack栈顶元素
  }

  bool empty() {
    return inStack.empty() && outStack.empty();
  } // 判断队列是否为空
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */