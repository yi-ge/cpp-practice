#include <gtest/gtest.h>
#include <headers.hpp>
#include <utils.hpp>

TEST(Utils, split)
{
  vector<string_view> res = Utils::split("a,b,cc,d", ',');
  EXPECT_STREQ(string(res[0]).c_str(), "a");
  EXPECT_STREQ(string(res[1]).c_str(), "b");
  EXPECT_STREQ(string(res[2]).c_str(), "cc");
  EXPECT_STREQ(string(res[3]).c_str(), "d");
}

TEST(Utils, join)
{
  vector<string_view> ans = Utils::split("a,b,cc,d", ',');
  EXPECT_STREQ(Utils::join(ans, ',').c_str(), "a,b,cc,d");
}
