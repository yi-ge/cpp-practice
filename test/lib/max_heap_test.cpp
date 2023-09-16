#include <gtest/gtest.h>
#include <headers.hpp>
#include <max_heap.hpp>

#include <iostream>

using namespace std;

TEST(最大堆, maxHeap) {
  MaxHeap<int> maxHeap = MaxHeap<int>(100);
  cout << maxHeap.size() << endl;

  srand(time(NULL));
  for (int i = 0; i < 15; i++) {
    maxHeap.insert(rand() % 100);
  }
  cout << maxHeap.size() << endl;

  maxHeap.testPrint();

  EXPECT_EQ(maxHeap.size(), 15);
}
