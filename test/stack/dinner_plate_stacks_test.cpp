#include <stack/dinner_plate_stacks.cpp>

TEST(餐盘栈, DinnerPlates) {
  // 示例：
  // 输入：
  // ["DinnerPlates","push","push","push","push","push","popAtStack","push","push","popAtStack","popAtStack","pop","pop","pop","pop","pop"]
  // [[2],[1],[2],[3],[4],[5],[0],[20],[21],[0],[2],[],[],[],[],[]]
  // 输出：
  // [null,null,null,null,null,null,2,null,null,20,21,5,4,3,1,-1]

  // 解释：
  // DinnerPlates D = DinnerPlates(2);  // 初始化，栈最大容量 capacity = 2
  // D.push(1);
  // D.push(2);
  // D.push(3);
  // D.push(4);
  // D.push(5);         // 栈的现状为：    2  4
  //                                     1  3  5
  //                                     ﹈ ﹈ ﹈
  // D.popAtStack(0);   // 返回 2。栈的现状为：      4
  //                                           1  3  5
  //                                           ﹈ ﹈ ﹈
  // D.push(20);        // 栈的现状为：  20  4
  //                                    1  3  5
  //                                    ﹈ ﹈ ﹈
  // D.push(21);        // 栈的现状为：  20  4 21
  //                                    1  3  5
  //                                    ﹈ ﹈ ﹈
  // D.popAtStack(0);   // 返回 20。栈的现状为：       4 21
  //                                             1  3  5
  //                                             ﹈ ﹈ ﹈
  // D.popAtStack(2);   // 返回 21。栈的现状为：       4
  //                                             1  3  5
  //                                             ﹈ ﹈ ﹈
  // D.pop()            // 返回 5。栈的现状为：        4
  //                                             1  3
  //                                             ﹈ ﹈
  // D.pop()            // 返回 4。栈的现状为：    1  3
  //                                            ﹈ ﹈
  // D.pop()            // 返回 3。栈的现状为：    1
  //                                            ﹈
  // D.pop()            // 返回 1。现在没有栈。
  // D.pop()            // 返回 -1。仍然没有栈。

  DinnerPlates D(2);
  D.push(1);
  D.push(2);
  D.push(3);
  D.push(4);
  D.push(5);
  EXPECT_EQ(D.popAtStack(0), 2);
  D.push(20);
  D.push(21);
  EXPECT_EQ(D.popAtStack(0), 20);
  EXPECT_EQ(D.popAtStack(2), 21);
  EXPECT_EQ(D.pop(), 5);
  EXPECT_EQ(D.pop(), 4);
  EXPECT_EQ(D.pop(), 3);
  EXPECT_EQ(D.pop(), 1);
  EXPECT_EQ(D.pop(), -1);
}
