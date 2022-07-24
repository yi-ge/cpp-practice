module;

export module headers;
#if USE_MODULES
// #pragma once
// C++ stl libraries
import <iostream>;
import <string>;
import <vector>;
// import <algorithm>;
import <map>;
import <set>;
import <unordered_set>;
import <unordered_map>;
// import <stack>;
// import <queue>;

// C libraries
import <cmath>;
// import <cctype>;
// import <climits>;
// import <cstring>;

#else
// C++ stl libraries
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>

// C libraries
#include <cmath>
// #include <cctype>
// #include <climits>
// #include <cstring>

// #include <gtest/gtest.h>

#endif