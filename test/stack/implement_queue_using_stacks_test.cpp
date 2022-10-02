#include <stack/implement_queue_using_stacks.cpp>

TEST(用栈实现队列, MyQueue) {
  // 示例 1：
  // 输入：
  // ["MyQueue", "push", "push", "peek", "pop", "empty"]
  // [[], [1], [2], [], [], []]
  // 输出：
  // [null, null, null, 1, 1, false]

  // 解释：
  // MyQueue myQueue = new MyQueue();
  // myQueue.push(1); // queue is: [1]
  // myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
  // myQueue.peek(); // return 1
  // myQueue.pop(); // return 1, queue is [2]
  // myQueue.empty(); // return false

  MyQueue myqueue;
  myqueue.push(1);
  myqueue.push(2);
  EXPECT_EQ(myqueue.peek(), 1);
  myqueue.pop();
  EXPECT_FALSE(myqueue.empty());
  myqueue.pop();
  myqueue.push(3);
  myqueue.pop();
  EXPECT_TRUE(myqueue.empty());
}
