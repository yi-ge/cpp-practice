#if USE_MODULES
import <iostream>;
#else
#include <iostream>
#endif

#include <gtest/gtest.h>

TEST(Modules, std) {
  // std::cout << "Hello C++20." << std::endl;
  int a = 0;
  a++;
  EXPECT_EQ(a, 1);
}