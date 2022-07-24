#if USE_MODULES
import <iostream>;
#else
#include <iostream>
#endif

#include <gtest/gtest.h>

TEST(Modules, std)
{
  std::cout << "Hello C++20." << std::endl;
}