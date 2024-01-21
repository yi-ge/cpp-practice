# C++ 算法练习

[![license](https://img.shields.io/github/license/yi-ge/cpp-practice.svg?style=flat-square)](https://github.com/yi-ge/cpp-practice/blob/master/LICENSE)
[![GitHub Actions](https://img.shields.io/endpoint.svg?url=https%3A%2F%2Factions-badge.atrox.dev%2Fyi-ge%2Fcpp-practice%2Fbadge%3Fref%3Dmain&style=flat-square)](https://actions-badge.atrox.dev/yi-ge/cpp-practice/goto?ref=main)
[![Test Results](https://gist.github.com/yi-ge/cfafaf2ba23090ed9f8aa8fc875c9ce5/raw/badge.svg)](https://github.com/yi-ge/cpp-practice)
[![Coveralls github](https://img.shields.io/coveralls/github/yi-ge/cpp-practice?style=flat-square)](https://coveralls.io/github/yi-ge/cpp-practice)
[![GitHub last commit](https://img.shields.io/github/last-commit/yi-ge/cpp-practice.svg?style=flat-square)](https://github.com/yi-ge/cpp-practice)
[![Gitpod Ready-to-Code](https://img.shields.io/badge/Gitpod-Ready--to--Code-blue?logo=gitpod&style=flat-square)](https://gitpod.io/#https://github.com/yi-ge/cpp-practice)

C++ 基础算法、数据结构练习，包含 LeetCode 或其它算法练习记录。

此为个人练习仓库，代码中对重要思想进行了注释，会尽量补充解题思路。

每一道题都对应写有测试用例，但可能不够完整。如果您发现错误，欢迎给我留言，谢谢！

安装以下测试环境后，运行`yarn start`可以自动从LeetCode获取代码函数和用例说明。保存文件后将自动同步到浏览器。

特别说明：题目截图仅为了方便在代码编辑器中直接预览从而优化编码体验，题目以LeetCode官方页面为准，题目著作权及其他权利以LeetCode官方说明为准或属于LeetCode。请大家尊重版权，共同维护良好网络环境。

## 测试环境

如果你使用VSCode进行开发，那么可以安装[CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)、[clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd)和[C++ TestMate](https://marketplace.visualstudio.com/items?itemName=matepek.vscode-catch2-test-adapter)以获得更好的单元测试体验。

注意，由于此项目使用LLVM，因此推荐使用与之对应的[clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd)插件，所以您不应当再安装[C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)插件。

以下是各个平台安装依赖的说明。

### MAC

```bash
brew install cmake node zlib yarn llvm ninja

echo 'export PATH="/opt/homebrew/opt/llvm/bin:$PATH"' >> ~/.zshrc
echo 'export LDFLAGS="-L/opt/homebrew/opt/llvm/lib"' >> ~/.zshrc
echo 'export CPPFLAGS="-I/opt/homebrew/opt/llvm/include"' >> ~/.zshrc
```

安装完成后执行`yarn`安装依赖。

在`VSCode`的`Cmake Tools`插件选择`active kit`为`Clang`。

### Linux

参考<https://apt.llvm.org/>安装LLVM 16(clang-16)。

以Ubuntu Jammy (22.04) LTS为例，安装LLVM 16：

```bash
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key 2>/dev/null | sudo apt-key add -
sudo add-apt-repository 'deb http://apt.llvm.org/jammy/ llvm-toolchain-jammy-16 main' -y
sudo apt-get update -q
sudo apt-get install -y clang-16 llvm-16 lld-16 libc++-16-dev libc++abi-16-dev clang-tools-16 clang-16-doc wasi-libc llvm-16-doc binutils ninja-build
sudo update-alternatives --config c++
wget https://github.com/Kitware/CMake/releases/download/v3.23.2/cmake-3.23.2-linux-x86_64.sh
sudo chmod +x cmake-3.23.2-linux-x86_64.sh
sudo ./cmake-3.23.2-linux-x86_64.sh --prefix=/usr
```

以Kali Rolling(Debian)为例，安装LLVM 16：

```bash
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key 2>/dev/null | sudo apt-key add -
sudo apt-key export AF4F7421|sudo gpg --dearmour -o /etc/apt/trusted.gpg.d/llvm.gpg
sudo bash -c "echo  'deb [arch=amd64 signed-by=/etc/apt/trusted.gpg.d/llvm.gpg] http://apt.llvm.org/unstable/ llvm-toolchain-16 main' >> /etc/apt/sources.list"
sudo apt-get update -y
sudo apt-get install -y clang-16 llvm-16 lld-16 libc++-16-dev libc++abi-16-dev clang-tools-16 clang-16-doc wasi-libc llvm-16-doc binutils ninja-build
sudo update-alternatives --config c++
```

执行最后一行命令后，提示选择C++编译器，选择clang++。

如果是Kali 2022之前的版本，需要加载对应版本的源，参考[https://apt.llvm.org/](https://apt.llvm.org/)进行配置。

根据<https://nodejs.org/en/download/package-manager/>安装Node.js环境。根据安装时的提示安装`yarn`。

安装完成后执行`yarn`安装依赖。

在`VSCode`的`Cmake Tools`插件选择`active kit`为`Clang`。

### Windows

执行`winget install CMake`安装最新版`cmake`。

执行`winget install Node.js`安装最新版`node`。

执行`winget install Ninja-build.Ninja`安装最新版`ninja`。

安装`LLVM`，方法一：

执行`winget install --id LLVM.LLVM`安装最新版`LLVM`，并将`C:\Program Files\LLVM\bin`路径添加到系统`Path`。

安装`LLVM`，方法二：

安装 **Visual Studio 2022**，并在`Visual Studio Installer`勾选`使用C++的桌面开发`中的`适用于Windows的C++ Clang工具`（15.0.1+）。

安装`LLVM`后，在`VSCode`的`Cmake Tools`插件选择`active kit`版本为`Clang`，例如：`Clang 16.0.1 x86_64-pc-windows-msvc`或`Clang 15.0.1 (GNU CLI) for MSVC 17.5.33530.505`。或者手动执行的时候使用对应版本的`llvm clang`。

需要特别注意的是，在Windows平台，Microsoft Visual Studio的MSVC标准库和LLVM的Clang标准库之间可能会产生冲突，需要根据具体情况进行调整。

上述安装完成后执行`yarn`安装依赖。

**Windows下中文乱码？**

~~需要在 Windows 中设置`使用 Unicode UTF-8 提供全球语言支持`，请按照以下步骤操作：~~

~~1. 打开“控制面板”。~~
~~2. 单击“时钟和区域”，然后单击“区域”。~~
~~3. 在“区域”窗口中，转到“管理”选项卡。~~
~~4. 单击“更改系统区域设置…”。~~
~~5. 在新弹出的“区域设置”窗口中，勾选“Beta 版：使用 Unicode UTF-8 提供全球语言支持（可能会影响与某些老应用程序的兼容性）”复选框。~~
~~6. 点击“确定”保存更改。系统可能需要重启以使更改生效。~~

已解决此问题，无论是否启用`使用 Unicode UTF-8 提供全球语言支持`，均可展示正确的中文内容。请在`测试资源管理器`中`刷新测试`，查看`TestMate C++`下的测试集，将会展示正确的中文内容。

## 基础排序算法

- [插入排序](src/sort/insert_sort.cpp)
- [冒泡排序](src/sort/bubble_sort.cpp)
- [选择排序](src/sort/select_sort.cpp)
- [快速排序](src/sort/quick_sort.cpp)
- [归并排序](src/sort/merge_sort.cpp)
- [堆排序](src/sort/heap_sort.cpp)

| 排序算法 | 时间复杂度 (平均) | 时间复杂度 (最坏) | 时间复杂度 (最好) | 原地排序 | 空间复杂度 | 稳定性 |
|:--------:|:----------------:|:----------------:|:----------------:|:--------:|:----------:|:------:|
| 插入排序 | \(O(n^2)\)       | \(O(n^2)\)       | \(O(n)\)         | 是       | \(O(1)\)   | 是     |
| 冒泡排序 | \(O(n^2)\)       | \(O(n^2)\)       | \(O(n)\)         | 是       | \(O(1)\)   | 是     |
| 选择排序 | \(O(n^2)\)       | \(O(n^2)\)       | \(O(n^2)\)       | 是       | \(O(1)\)   | 否     |
| 快速排序 | \(O(n \log n)\)  | \(O(n^2)\)       | \(O(n \log n)\)  | 是       | \(O(\log n)\) | 否   |
| 归并排序 | \(O(n \log n)\)  | \(O(n \log n)\)  | \(O(n \log n)\)  | 否       | \(O(n)\)   | 是     |
| 堆排序   | \(O(n \log n)\)  | \(O(n \log n)\)  | \(O(n \log n)\)  | 是       | \(O(1)\)   | 否     |

## 基础数据结构

### C++标准库中的数据结构（部分）

C++标准库提供的数据结构实在是太多了，参考[C++标准库头文件](https://zh.cppreference.com/w/cpp/header)，仅列举常见的：

- [数组类容器 vector array等](https://zh.cppreference.com/w/cpp/header/vector)
- [集合 set unordered_set等](https://zh.cppreference.com/w/cpp/header/set)
- [键 - 值对 map unordered_map等](https://zh.cppreference.com/w/cpp/header/map)
- [列表 list](https://zh.cppreference.com/w/cpp/header/list)
- [队列 deque queue等](https://zh.cppreference.com/w/cpp/header/deque)
- [栈 stack](https://zh.cppreference.com/w/cpp/header/stack)

### 通过C++实现的数据结构及其常见操作

- [链表结点](include/list_node.hpp)
- [树结点](include/tree_node.hpp)

## 算法题

### 字符串

- [构造限制重复的字符串](src/string/construct_string_with_repeat_limit.cpp)  [贪心, 字符串, 计数, 堆（优先队列）]

  - LeetCode 2182. 构造限制重复的字符串 <https://leetcode.cn/problems/construct-string-with-repeat-limit>

- [统计重复个数](src/string/count_the_repetitions.cpp)  [字符串, 动态规划]

  - LeetCode 466. 统计重复个数 <https://leetcode.cn/problems/count-the-repetitions>

- [字典序最小回文串](src/string/lexicographically_smallest_palindrome.cpp)  [贪心, 双指针, 字符串]

  - LeetCode 2697. 字典序最小回文串 <https://leetcode.cn/problems/lexicographically-smallest-palindrome>

- [子串能表示从 1 到 N 数字的二进制串](src/string/binary_string_with_substrings_representing_1_to_n.cpp)  [字符串]

  - LeetCode 1016. 子串能表示从 1 到 N 数字的二进制串 <https://leetcode.cn/problems/binary-string-with-substrings-representing-1-to-n>

- [有效时间的数目](src/string/number_of_valid_clock_times.cpp)  [字符串, 枚举]

  - LeetCode 2437. 有效时间的数目 <https://leetcode.cn/problems/number-of-valid-clock-times>

- [数青蛙](src/string/minimum_number_of_frogs_croaking.cpp)  [字符串, 计数]

  - LeetCode 1419. 数青蛙 <https://leetcode.cn/problems/minimum-number-of-frogs-croaking>

- [按字典序排在最后的子串](src/string/last_substring_in_lexicographical_order.cpp)  [双指针, 字符串]

  - LeetCode 1163. 按字典序排在最后的子串 <https://leetcode.cn/problems/last-substring-in-lexicographical-order>

- [段式回文](src/string/longest_chunked_palindrome_decomposition.cpp)  [贪心, 双指针, 字符串, 动态规划, 哈希函数, 滚动哈希]

  - LeetCode 1147. 段式回文 <https://leetcode.cn/problems/longest-chunked-palindrome-decomposition>

- [隐藏个人信息](src/string/masking_personal_information.cpp)  [字符串]

  - LeetCode 831. 隐藏个人信息 <https://leetcode.cn/problems/masking-personal-information>

- [检查二进制字符串字段](src/string/check_if_binary_string_has_at_most_one_segment_of_ones.cpp)  [字符串]

  - LeetCode 1784. 检查二进制字符串字段 <https://leetcode.cn/problems/check-if-binary-string-has-at-most-one-segment-of-ones/>

- [在LR字符串中交换相邻字符](src/string/swap_adjacent_in_lr_string.cpp)  [双指针, 字符串]

  - LeetCode 777. 在LR字符串中交换相邻字符 <https://leetcode.cn/problems/swap-adjacent-in-lr-string>

- [重新排列单词间的空格](src/string/rearrange_spaces_between_words.cpp)  [字符串]

  - LeetCode 1592. 重新排列单词间的空格 <https://leetcode.cn/problems/rearrange-spaces-between-words>

- [数组中的字符串匹配](src/string/string_matching_in_an_array.cpp)  [字符串, 字符串匹配]

  - LeetCode 1408. 数组中的字符串匹配 <https://leetcode.cn/problems/string-matching-in-an-array>

### 数组/队列/集合/映射

- [分割数组的最大值](src/array/split_array_largest_sum.cpp)  [贪心, 数组, 二分查找, 动态规划, 前缀和]

  - LeetCode 410. 分割数组的最大值 <https://leetcode.cn/problems/split-array-largest-sum>

- [按分隔符拆分字符串](src/array/split_strings_by_separator.cpp)  [数组, 字符串]

  - LeetCode 2788. 按分隔符拆分字符串 <https://leetcode.cn/problems/split-strings-by-separator>

- [最大字符串配对数目](src/array/find_maximum_number_of_string_pairs.cpp)  [数组, 哈希表, 字符串, 模拟]

  - LeetCode 2744. 最大字符串配对数目 <https://leetcode.cn/problems/find-maximum-number-of-string-pairs>

- [统计出现过一次的公共字符串](src/array/count_common_words_with_one_occurrence.cpp)  [数组, 哈希表, 字符串, 计数]

  - LeetCode 2085. 统计出现过一次的公共字符串 <https://leetcode.cn/problems/count-common-words-with-one-occurrence>

- [回旋镖的数量](src/array/number_of_boomerangs.cpp)  [数组, 哈希表, 数学]

  - LeetCode 447. 回旋镖的数量 <https://leetcode.cn/problems/number-of-boomerangs>

- [经营摩天轮的最大利润](src/array/maximum_profit_of_operating_a_centennial_wheel.cpp)  [数组, 模拟]

  - LeetCode 1599. 经营摩天轮的最大利润 <https://leetcode.cn/problems/maximum-profit-of-operating-a-centennial-wheel>

- [使用最小花费爬楼梯](src/array/min_cost_climbing_stairs.cpp)  [数组, 动态规划]

  - LeetCode 746. 使用最小花费爬楼梯 <https://leetcode.cn/problems/min-cost-climbing-stairs>

- [用邮票贴满网格图](src/array/stamping_the_grid.cpp)  [贪心, 数组, 矩阵, 前缀和]

  - LeetCode 2132. 用邮票贴满网格图 <https://leetcode.cn/problems/stamping-the-grid>

- [可获得的最大点数](src/array/maximum_points_you_can_obtain_from_cards.cpp)  [数组, 前缀和, 滑动窗口]

  - LeetCode 1423. 可获得的最大点数 <https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards>

- [找出叠涂元素](src/array/first_completely_painted_row_or_column.cpp)  [数组, 哈希表, 矩阵]

  - LeetCode 2661. 找出叠涂元素 <https://leetcode.cn/problems/first-completely-painted-row-or-column>

- [打家劫舍](src/array/house_robber.cpp)  [数组, 动态规划]

  - LeetCode 198. 打家劫舍 <https://leetcode.cn/problems/house-robber>

- [二进制字符串前缀一致的次数](src/array/number_of_times_binary_string_is_prefix_aligned.cpp)  [数组]

  - LeetCode 1375. 二进制字符串前缀一致的次数 <https://leetcode.cn/problems/number-of-times-binary-string-is-prefix-aligned>

- [数组中不等三元组的数目](src/array/number_of_unequal_triplets_in_array.cpp)  [数组, 哈希表]

  - LeetCode 2475. 数组中不等三元组的数目 <https://leetcode.cn/problems/number-of-unequal-triplets-in-array>

- [相等行列对](src/array/equal_row_and_column_pairs.cpp)  [数组, 哈希表, 矩阵, 模拟]

  - LeetCode 2352. 相等行列对 <https://leetcode.cn/problems/equal-row-and-column-pairs>

- [对数组执行操作](src/array/apply_operations_to_an_array.cpp)  [数组, 模拟]

  - LeetCode 2460. 对数组执行操作 <https://leetcode.cn/problems/apply-operations-to-an-array>

- [统计范围内的元音字符串数](src/array/count_vowel_strings_in_ranges.cpp)  [数组, 字符串, 前缀和]

  - LeetCode 2559. 统计范围内的元音字符串数 <https://leetcode.cn/problems/count-vowel-strings-in-ranges>

- [可被三整除的偶数的平均值](src/array/average_value_of_even_numbers_that_are_divisible_by_three.cpp)  [数组, 数学]

  - LeetCode 2455. 可被三整除的偶数的平均值 <https://leetcode.cn/problems/average-value-of-even-numbers-that-are-divisible-by-three>

- [有序矩阵中的第 k 个最小数组和](src/array/find_the_kth_smallest_sum_of_a_matrix_with_sorted_rows.cpp)  [数组, 二分查找, 矩阵, 堆（优先队列）]

  - LeetCode 1439. 有序矩阵中的第 k 个最小数组和 <https://leetcode.cn/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows>

- [大样本统计](src/array/statistics_from_a_large_sample.cpp)  [数组, 数学, 概率与统计]

  - LeetCode 1093. 大样本统计 <https://leetcode.cn/problems/statistics-from-a-large-sample>

- [差值数组不同的字符串](src/array/odd_string_difference.cpp)  [数组, 哈希表, 字符串]

  - LeetCode 2451. 差值数组不同的字符串 <https://leetcode.cn/problems/odd-string-difference/>

- [蓄水](src/array/store_water.cpp)  [贪心, 数组, 堆（优先队列）]

  - LeetCode LCP 33. 蓄水 <https://leetcode.cn/problems/o8SXZn>

- [负二进制数相加](src/array/adding_two_negabinary_numbers.cpp)  [数组, 数学]

  - LeetCode 1073. 负二进制数相加 <https://leetcode.cn/problems/adding-two-negabinary-numbers>

- [判断两个事件是否存在冲突](src/array/determine_if_two_events_have_conflict.cpp)  [数组, 字符串]

  - LeetCode 2446. 判断两个事件是否存在冲突 <https://leetcode.cn/problems/determine-if-two-events-have-conflict>

- [工作计划的最低难度](src/array/minimum_difficulty_of_a_job_schedule.cpp)  [数组, 动态规划]

  - LeetCode 1335. 工作计划的最低难度 <https://leetcode.cn/problems/minimum-difficulty-of-a-job-schedule>

- [按列翻转得到最大值等行数](src/array/flip_columns_for_maximum_number_of_equal_rows.cpp)  [数组, 哈希表, 矩阵]

  - LeetCode 1072. 按列翻转得到最大值等行数 <https://leetcode.cn/problems/flip-columns-for-maximum-number-of-equal-rows>

- [翻转子数组得到最大的数组值](src/array/reverse_subarray_to_maximize_array_value.cpp)  [贪心, 数组, 数学]

  - LeetCode 1330. 翻转子数组得到最大的数组值 <https://leetcode.cn/problems/reverse-subarray-to-maximize-array-value>

- [总持续时间可被 60 整除的歌曲](src/array/pairs_of_songs_with_total_durations_divisible_by_60.cpp)  [数组, 哈希表, 计数]

  - LeetCode 1010. 总持续时间可被 60 整除的歌曲 <https://leetcode.cn/problems/pairs-of-songs-with-total-durations-divisible-by-60>

- [处理用时最长的那个任务的员工](src/array/the_employee_that_worked_on_the_longest_task.cpp)  [数组]

  - LeetCode 2432. 处理用时最长的那个任务的员工 <https://leetcode.cn/problems/the-employee-that-worked-on-the-longest-task>

- [摘水果](src/array/maximum_fruits_harvested_after_at_most_k_steps.cpp)  [数组, 二分查找, 前缀和, 滑动窗口]

  - LeetCode 2106. 摘水果 <https://leetcode.cn/problems/maximum-fruits-harvested-after-at-most-k-steps>

- [最长字符串链](src/array/longest_string_chain.cpp)  [数组, 哈希表, 双指针, 字符串, 动态规划]

  - LeetCode 1048. 最长字符串链 <https://leetcode.cn/problems/longest-string-chain>

- [两个非重叠子数组的最大和](src/array/maximum_sum_of_two_non_overlapping_subarrays.cpp)  [数组, 动态规划, 滑动窗口]

  - LeetCode 1031. 两个非重叠子数组的最大和 <https://leetcode.cn/problems/maximum-sum-of-two-non-overlapping-subarrays>

- [填充书架](src/array/filling_bookcase_shelves.cpp)  [数组, 动态规划]

  - LeetCode 1105. 填充书架 <https://leetcode.cn/problems/filling-bookcase-shelves>

- [最长等差数列](src/array/longest_arithmetic_subsequence.cpp)  [数组, 哈希表, 二分查找, 动态规划]

  - LeetCode 1027. 最长等差数列 <https://leetcode.cn/problems/longest-arithmetic-subsequence>
  
- [分隔数组以得到最大和](src/array/partition_array_for_maximum_sum.cpp)  [数组, 动态规划]

  - LeetCode 1043. 分隔数组以得到最大和 <https://leetcode.cn/problems/partition-array-for-maximum-sum>

- [子数组中占绝大多数的元素](src/array/online_majority_element_in_subarray.cpp)  [设计, 树状数组, 线段树, 数组, 二分查找]

  - LeetCode 1157. 子数组中占绝大多数的元素 <https://leetcode.cn/problems/online-majority-element-in-subarray>

- [出现最频繁的偶数元素](src/array/most_frequent_even_element.cpp)  [数组, 哈希表, 计数]

  - LeetCode 2404. 出现最频繁的偶数元素 <https://leetcode.cn/problems/most-frequent-even-element>

- [检查相同字母间的距离](src/array/check_distances_between_same_letters.cpp)  [数组, 哈希表, 字符串]

  - LeetCode 2399. 检查相同字母间的距离 <https://leetcode.cn/problems/check-distances-between-same-letters>

- [合并石头的最低成本](src/array/minimum_cost_to_merge_stones.cpp)  [数组, 动态规划]

  - LeetCode 1000. 合并石头的最低成本 <https://leetcode.cn/problems/minimum-cost-to-merge-stones>

- [交换一次的先前排列](src/array/previous_permutation_with_one_swap.cpp)  [贪心, 数组]

  - LeetCode 1053. 交换一次的先前排列 <https://leetcode.cn/problems/previous-permutation-with-one-swap>

- [多边形三角剖分的最低得分](src/array/minimum_score_triangulation_of_polygon.cpp)  [数组, 动态规划]

  - LeetCode 1039. 多边形三角剖分的最低得分 <https://leetcode.cn/problems/minimum-score-triangulation-of-polygon>

- [算术三元组的数目](src/array/number_of_arithmetic_triplets.cpp)  [数组, 哈希表, 双指针, 枚举]

  - LeetCode 2367. 算术三元组的数目 <https://leetcode.cn/problems/number-of-arithmetic-triplets>

- [和相等的子数组](src/array/find_subarrays_with_equal_sum.cpp)  [数组, 哈希表]

  - LeetCode 2395. 和相等的子数组 <https://leetcode.cn/problems/find-subarrays-with-equal-sum>

- [字符串中的第一个唯一字符](src/array/first_unique_character_in_a_string.cpp)  [队列, 哈希表, 字符串, 计数]

  - LeetCode 387. 字符串中的第一个唯一字符 <https://leetcode.cn/problems/first-unique-character-in-a-string/>

- [矩阵置零](src/array/set_matrix_zeroes.cpp)  [数组, 哈希表, 矩阵]

  - LeetCode 73. 矩阵置零 <https://leetcode.cn/problems/set-matrix-zeroes>

- [杨辉三角](src/array/pascals_triangle.cpp)  [数组, 动态规划]

  - LeetCode 118. 杨辉三角 <https://leetcode.cn/problems/pascals-triangle>

- [重塑矩阵](src/array/reshape_the_matrix.cpp)  [数组, 矩阵, 模拟]

  - LeetCode 566. 重塑矩阵 <https://leetcode.cn/problems/reshape-the-matrix/>

- [买卖股票的最佳时机](src/array/best_time_to_buy_and_sell_stock.cpp)  [数组, 动态规划]

  - LeetCode 121. 买卖股票的最佳时机 <https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/>

- [删除某些元素后的数组均值](src/array/mean_of_array_after_removing_some_elements.cpp)  [数组, 排序]

  - LeetCode 1619. 删除某些元素后的数组均值 <https://leetcode.cn/problems/mean-of-array-after-removing-some-elements/>

- [特殊数组的特征值](src/array/special_array_with_x_elements_greater_than_or_equal_x.cpp)  [数组, 二分查找, 排序]

  - LeetCode 1608. 特殊数组的特征值 <https://leetcode.cn/problems/special-array-with-x-elements-greater-than-or-equal-x>

- [优美的排列 II](src/array/beautiful_arrangement_ii.cpp)  [数组, 数学]

  - LeetCode 667. 优美的排列 II <https://leetcode.cn/problems/beautiful-arrangement-ii>

- [最长数对链](src/array/maximum_length_of_pair_chain.cpp)  [贪心, 数组, 动态规划, 排序]

  - LeetCode 646. 最长数对链 <https://leetcode.cn/problems/maximum-length-of-pair-chain>

- [通过翻转子数组使两个数组相等](src/array/make_two_arrays_equal_by_reversing_sub_arrays.cpp)  [数组, 哈希表, 排序]

  - LeetCode 1460. 通过翻转子数组使两个数组相等 <https://leetcode.cn/problems/make-two-arrays-equal-by-reversing-sub-arrays>

- [逐步求和得到正数的最小值](src/array/minimum_value_to_get_positive_step_by_step_sum.cpp)  [数组, 前缀和]

  - LeetCode 1413. 逐步求和得到正数的最小值 <https://leetcode.cn/problems/minimum-value-to-get-positive-step-by-step-sum>

- [数组序号转换](src/array/rank_transform_of_an_array.cpp)  [数组, 哈希表, 排序]

  - LeetCode 1331. 数组序号转换 <https://leetcode.cn/problems/rank-transform-of-an-array>

- [数据流中的移动平均值](src/array/moving_average_from_data_stream.cpp)  [设计, 队列, 数组, 数据流]

  - LeetCode 346. 数据流中的移动平均值 <https://leetcode.cn/problems/moving-average-from-data-stream/>
  - LeetCode 剑指 Offer II 041. 滑动窗口的平均值 <https://leetcode.cn/problems/qIsx9U/>

- [摘樱桃](src/array/cherry_pickup.cpp)  [数组, 动态规划, 矩阵]

  - LeetCode 741. 摘樱桃 <https://leetcode.cn/problems/cherry-pickup>

- [最长的斐波那契子序列的长度](src/array/length_of_longest_fibonacci_subsequence.cpp)  [数组, 哈希表, 动态规划]

  - LeetCode 873. 最长的斐波那契子序列的长度 <https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence>

- [玩筹码](src/array/minimum_cost_to_move_chips_to_the_same_position.cpp)  [贪心, 数组, 数学]

  - LeetCode 1217. 玩筹码 <https://leetcode.cn/problems/minimum-cost-to-move-chips-to-the-same-position>

### 栈

- [删除子串后的字符串最小长度](src/stack/minimum_string_length_after_removing_substrings.cpp)  [栈, 字符串, 模拟]

  - LeetCode 2696. 删除子串后的字符串最小长度 <https://leetcode.cn/problems/minimum-string-length-after-removing-substrings>

- [队列中可以看到的人数](src/stack/number_of_visible_people_in_a_queue.cpp)  [栈, 数组, 单调栈]

  - LeetCode 1944. 队列中可以看到的人数 <https://leetcode.cn/problems/number-of-visible-people-in-a-queue>

- [从链表中移除节点](src/stack/remove_nodes_from_linked_list.cpp)  [栈, 递归, 链表, 单调栈]

  - LeetCode 2487. 从链表中移除节点 <https://leetcode.cn/problems/remove-nodes-from-linked-list>

- [两数相加 II](src/stack/add_two_numbers_ii.cpp)  [栈, 链表, 数学]

  - LeetCode 445. 两数相加 II <https://leetcode.cn/problems/add-two-numbers-ii>

- [叶值的最小代价生成树](src/stack/minimum_cost_tree_from_leaf_values.cpp)  [栈, 贪心, 数组, 动态规划, 单调栈]

  - LeetCode 1130. 叶值的最小代价生成树 <https://leetcode.cn/problems/minimum-cost-tree-from-leaf-values>

- [检查替换后的词是否有效](src/stack/check_if_word_is_valid_after_substitutions.cpp)  [栈, 字符串]

  - LeetCode 1003. 检查替换后的词是否有效 <https://leetcode.cn/problems/check-if-word-is-valid-after-substitutions>

- [餐盘栈](src/stack/dinner_plate_stacks.cpp)  [栈, 设计, 哈希表, 堆（优先队列）]

  - LeetCode 1172. 餐盘栈 <https://leetcode.cn/problems/dinner-plate-stacks>

- [链表中的下一个更大节点](src/stack/next_greater_node_in_linked_list.cpp)  [栈, 数组, 链表, 单调栈]

  - LeetCode 1019. 链表中的下一个更大节点 <https://leetcode.cn/problems/next-greater-node-in-linked-list>

- [用栈实现队列](src/stack/implement_queue_using_stacks.cpp)  [栈, 设计, 队列]

  - LeetCode 232. 用栈实现队列 <https://leetcode.cn/problems/implement-queue-using-stacks/>

- [文件夹操作日志搜集器](src/stack/crawler_log_folder.cpp)  [栈, 数组, 字符串]

  - LeetCode 1598. 文件夹操作日志搜集器 <https://leetcode.cn/problems/crawler-log-folder>

- [最长有效括号](src/stack/longest_valid_parentheses.cpp)  [栈, 字符串, 动态规划]

  - LeetCode 32. 最长有效括号 <https://leetcode.cn/problems/longest-valid-parentheses/>

### 树

- [字符串中的额外字符](src/tree/extra_characters_in_a_string.cpp)  [字典树, 数组, 哈希表, 字符串, 动态规划]

  - LeetCode 2707. 字符串中的额外字符 <https://leetcode.cn/problems/extra-characters-in-a-string>

- [从二叉搜索树到更大和树](src/tree/binary_search_tree_to_greater_sum_tree.cpp)  [树, 深度优先搜索, 二叉搜索树, 二叉树]

  - LeetCode 1038. 从二叉搜索树到更大和树 <https://leetcode.cn/problems/binary-search-tree-to-greater-sum-tree>

- [树节点的第 K 个祖先](src/tree/kth_ancestor_of_a_tree_node.cpp)  [树, 深度优先搜索, 广度优先搜索, 设计, 二分查找, 动态规划]

  - LeetCode 1483. 树节点的第 K 个祖先 <https://leetcode.cn/problems/kth-ancestor-of-a-tree-node>

- [删点成林](src/tree/delete_nodes_and_return_forest.cpp)  [树, 深度优先搜索, 数组, 哈希表, 二叉树]

  - LeetCode 1110. 删点成林 <https://leetcode.cn/problems/delete-nodes-and-return-forest>

- [根到叶路径上的不足节点](src/tree/insufficient_nodes_in_root_to_leaf_paths.cpp)  [树, 深度优先搜索, 二叉树]

  - LeetCode 1080. 根到叶路径上的不足节点 <https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths>

- [二叉搜索子树的最大键值和](src/tree/maximum_sum_bst_in_binary_tree.cpp)  [树, 深度优先搜索, 二叉搜索树, 动态规划, 二叉树]

  - LeetCode 1373. 二叉搜索子树的最大键值和 <https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree>

- [通知所有员工所需的时间](src/tree/time_needed_to_inform_all_employees.cpp)  [树, 深度优先搜索, 广度优先搜索]

  - LeetCode 1376. 通知所有员工所需的时间 <https://leetcode.cn/problems/time-needed-to-inform-all-employees>

- [节点与其祖先之间的最大差值](src/tree/maximum_difference_between_node_and_ancestor.cpp)  [树, 深度优先搜索, 二叉树]

  - LeetCode 1026. 节点与其祖先之间的最大差值 <https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor>

- [驼峰式匹配](src/tree/camelcase_matching.cpp)  [字典树, 双指针, 字符串, 字符串匹配]

  - LeetCode 1023. 驼峰式匹配 <https://leetcode.cn/problems/camelcase-matching>

- [二叉搜索树的最近公共祖先](src/tree/lowest_common_ancestor_of_a_binary_search_tree.cpp)  [树, 深度优先搜索, 二叉搜索树, 二叉树]

  - LeetCode 235. 二叉搜索树的最近公共祖先 <https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/>

- [两数之和 IV](src/tree/two_sum_iv_input_is_a_bst.cpp)  [树, 深度优先搜索, 广度优先搜索, 二叉搜索树, 哈希表, 双指针, 二叉树]

  - LeetCode 653. 两数之和 IV <https://leetcode.cn/problems/two-sum-iv-input-is-a-bst/>

- [验证二叉搜索树](src/tree/validate_binary_search_tree.cpp)  [树, 深度优先搜索, 二叉搜索树, 二叉树]

  - LeetCode 98. 验证二叉搜索树 <https://leetcode.cn/problems/validate-binary-search-tree/>

- [二叉搜索树中的插入操作](src/tree/insert_into_a_binary_search_tree.cpp)  [树, 二叉搜索树, 二叉树]

  - LeetCode 701. 二叉搜索树中的插入操作 <https://leetcode.cn/problems/insert-into-a-binary-search-tree/>

- [二叉搜索树中的搜索](src/tree/search_in_a_binary_search_tree.cpp)  [树, 二叉搜索树, 二叉树]

  - LeetCode 700. 二叉搜索树中的搜索 <https://leetcode.cn/problems/search-in-a-binary-search-tree/>

- [路径总和](src/tree/path_sum.cpp)  [树, 深度优先搜索, 广度优先搜索, 二叉树]

  - LeetCode 112. 路径总和 <https://leetcode.cn/problems/path-sum/>

- [翻转二叉树](src/tree/invert_binary_tree.cpp)  [树, 深度优先搜索, 广度优先搜索, 二叉树]

  - LeetCode 226. 翻转二叉树 <https://leetcode.cn/problems/invert-binary-tree/>

- [二叉树的最大深度](src/tree/maximum_depth_of_binary_tree.cpp)  [树, 深度优先搜索, 广度优先搜索, 二叉树]

  - LeetCode 104. 二叉树的最大深度 <https://leetcode.cn/problems/maximum-depth-of-binary-tree/>

- [寻找重复的子树](src/tree/find_duplicate_subtrees.cpp)  [树, 深度优先搜索, 哈希表, 二叉树]

  - LeetCode 652. 寻找重复的子树 <https://leetcode.cn/problems/find-duplicate-subtrees>

- [二叉树最大宽度](src/tree/maximum_width_of_binary_tree.cpp)  [树, 深度优先搜索, 广度优先搜索, 二叉树]

  - LeetCode 662. 二叉树最大宽度 <https://leetcode.cn/problems/maximum-width-of-binary-tree>

- [最大层内元素和](src/tree/maximum_level_sum_of_a_binary_tree.cpp)  [树, 深度优先搜索, 广度优先搜索, 二叉树]

  - LeetCode 1161. 最大层内元素和 <https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree>

- [完全二叉树插入器](src/tree/complete_binary_tree_inserter.cpp)  [树, 广度优先搜索, 设计, 二叉树]

  - LeetCode 919. 完全二叉树插入器 <https://leetcode.cn/problems/complete-binary-tree-inserter>

- [实现一个魔法字典](src/tree/implement_magic_dictionary.cpp)  [设计, 字典树, 哈希表, 字符串]

  - LeetCode 676. 实现一个魔法字典 <https://leetcode.cn/problems/implement-magic-dictionary>

- [单词替换](src/tree/replace_words.cpp)  [字典树, 数组, 哈希表, 字符串]

  - LeetCode 648. 单词替换 <https://leetcode.cn/problems/replace-words>

### 链表

- [在链表中插入最大公约数](src/list/insert_greatest_common_divisors_in_linked_list.cpp)  [链表, 数学, 数论]

  - LeetCode 2807. 在链表中插入最大公约数 <https://leetcode.cn/problems/insert-greatest-common-divisors-in-linked-list>

- [从链表中删去总和值为零的连续节点](src/list/remove_zero_sum_consecutive_nodes_from_linked_list.cpp)  [哈希表, 链表]

  - LeetCode 1171. 从链表中删去总和值为零的连续节点 <https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list>

- [删除链表中的节点](src/list/delete_node_in_a_linked_list.cpp)  [链表]

  - LeetCode 237. 删除链表中的节点 <https://leetcode.cn/problems/delete-node-in-a-linked-list/>

- [删除排序链表中的重复元素](src/list/remove_duplicates_from_sorted_list.cpp)  [链表]

  - LeetCode 83. 删除排序链表中的重复元素 <https://leetcode.cn/problems/remove-duplicates-from-sorted-list/>

- [删除排序链表中的重复元素 II](src/list/remove_duplicates_from_sorted_list_ii.cpp)  [链表, 双指针]

  - LeetCode 82. 删除排序链表中的重复元素 II <https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/>

- [移除链表元素](src/list/remove_linked_list_elements.cpp)  [递归, 链表]

  - LeetCode 203. 移除链表元素 <https://leetcode.cn/problems/remove-linked-list-elements/>

- [两两交换链表中的节点](src/sort/swap_nodes_in_pairs.cpp)  [递归, 链表]

  - LeetCode 24. 两两交换链表中的节点 <https://leetcode.cn/problems/swap-nodes-in-pairs/>

### 图

- [重新规划路线](src/graphs/reorder_routes_to_make_all_paths_lead_to_the_city_zero.cpp)  [深度优先搜索, 广度优先搜索, 图]

  - LeetCode 1466. 重新规划路线 <https://leetcode.cn/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero>

- [最小化旅行的价格总和](src/graphs/minimize_the_total_price_of_the_trips.cpp)  [树, 深度优先搜索, 图, 数组, 动态规划]

  - LeetCode 2646. 最小化旅行的价格总和 <https://leetcode.cn/problems/minimize-the-total-price-of-the-trips>

- [到达首都的最少油耗](src/graphs/minimum_fuel_cost_to_report_to_the_capital.cpp)  [树, 深度优先搜索, 广度优先搜索, 图]

  - LeetCode 2477. 到达首都的最少油耗 <https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital>

- [T 秒后青蛙的位置](src/graphs/frog_position_after_t_seconds.cpp)  [树, 深度优先搜索, 广度优先搜索, 图]

  - LeetCode 1377. T 秒后青蛙的位置 <https://leetcode.cn/problems/frog-position-after-t-seconds/>

- [不邻接植花](src/graphs/flower_planting_with_no_adjacent.cpp)  [深度优先搜索, 广度优先搜索, 图]

  - LeetCode 1042. 不邻接植花 <https://leetcode.cn/problems/flower-planting-with-no-adjacent>

- [找到小镇的法官](src/graphs/find_the_town_judge.cpp)  [图, 数组, 哈希表]

  - LeetCode 997. 找到小镇的法官 <https://leetcode.cn/problems/find-the-town-judge>

### 排序

- [拿出最少数目的魔法豆](src/sort/removing_minimum_number_of_magic_beans.cpp)  [数组, 前缀和, 排序]

  - LeetCode 2171. 拿出最少数目的魔法豆 <https://leetcode.cn/problems/removing-minimum-number-of-magic-beans>

- [购买两块巧克力](src/sort/buy_two_chocolates.cpp)  [数组, 排序]

  - LeetCode 2706. 购买两块巧克力 <https://leetcode.cn/problems/buy-two-chocolates>

- [下一个更大元素 IV](src/sort/next_greater_element_iv.cpp)  [栈, 数组, 二分查找, 排序, 单调栈, 堆（优先队列）]

  - LeetCode 2454. 下一个更大元素 IV <https://leetcode.cn/problems/next-greater-element-iv>

- [出租车的最大盈利](src/sort/maximum_earnings_from_taxi.cpp)  [数组, 二分查找, 动态规划, 排序]

  - LeetCode 2008. 出租车的最大盈利 <https://leetcode.cn/problems/maximum-earnings-from-taxi>

- [拼车](src/sort/car_pooling.cpp)  [数组, 前缀和, 排序, 模拟, 堆（优先队列）]

  - LeetCode 1094. 拼车 <https://leetcode.cn/problems/car-pooling>

- [可被三整除的最大和](src/sort/greatest_sum_divisible_by_three.cpp)  [贪心, 数组, 动态规划, 排序]

  - LeetCode 1262. 可被三整除的最大和 <https://leetcode.cn/problems/greatest-sum-divisible-by-three>

- [比较字符串最小字母出现频次](src/sort/compare_strings_by_frequency_of_the_smallest_character.cpp)  [数组, 哈希表, 字符串, 二分查找, 排序]

  - LeetCode 1170. 比较字符串最小字母出现频次 <https://leetcode.cn/problems/compare-strings-by-frequency-of-the-smallest-character>

- [老鼠和奶酪](src/sort/mice_and_cheese.cpp)  [贪心, 数组, 排序, 堆（优先队列）]

  - LeetCode 2611. 老鼠和奶酪 <https://leetcode.cn/problems/mice-and-cheese>

- [不同的平均值数目](src/sort/number_of_distinct_averages.cpp)  [数组, 哈希表, 双指针, 排序]

  - LeetCode 2465. 不同的平均值数目 <https://leetcode.cn/problems/number-of-distinct-averages>

- [礼盒的最大甜蜜度](src/sort/maximum_tastiness_of_candy_basket.cpp)  [数组, 二分查找, 排序]

  - LeetCode 2517. 礼盒的最大甜蜜度 <https://leetcode.cn/problems/maximum-tastiness-of-candy-basket>

- [受标签影响的最大值](src/sort/largest_values_from_labels.cpp)  [贪心, 数组, 哈希表, 计数, 排序]

  - LeetCode 1090. 受标签影响的最大值 <https://leetcode.cn/problems/largest-values-from-labels>

- [距离相等的条形码](src/sort/distant_barcodes.cpp)  [贪心, 数组, 哈希表, 计数, 排序, 堆（优先队列）]

  - LeetCode 1054. 距离相等的条形码 <https://leetcode.cn/problems/distant-barcodes>

- [与对应负数同时存在的最大正整数](src/sort/largest_positive_integer_that_exists_with_its_negative.cpp)  [数组, 哈希表, 双指针, 排序]

  - LeetCode 2441. 与对应负数同时存在的最大正整数 <https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative>

- [按身高排序](src/sort/sort_the_people.cpp)  [数组, 哈希表, 字符串, 排序]

  - LeetCode 2418. 按身高排序 <https://leetcode.cn/problems/sort-the-people>

- [使数组严格递增](src/sort/make_array_strictly_increasing.cpp)  [数组, 二分查找, 动态规划, 排序]

  - LeetCode 1187. 使数组严格递增 <https://leetcode.cn/problems/make-array-strictly-increasing>

- [移动石子直到连续 II](src/sort/moving_stones_until_consecutive_ii.cpp)  [数组, 数学, 双指针, 排序]

  - LeetCode 1040. 移动石子直到连续 II <https://leetcode.cn/problems/moving-stones-until-consecutive-ii>

- [两点之间不包含任何点的最宽垂直区域](src/sort/widest_vertical_area_between_two_points_containing_no_points.cpp)  [数组, 排序]

  - LeetCode 1637. 两点之间不包含任何点的最宽垂直区域 <https://leetcode.cn/problems/widest-vertical-area-between-two-points-containing-no-points>

- [合并两个有序链表](src/sort/merge_two_sorted_lists.cpp)  [递归, 链表]

  - LeetCode 21. 合并两个有序链表 <https://leetcode.cn/problems/merge-two-sorted-lists/>

### 其它

- [构造有效字符串的最少插入数](src/other/minimum_additions_to_make_valid_string.cpp)  [Stack, Greedy, String, Dynamic Programming]

  - LeetCode 2645. 构造有效字符串的最少插入数 <https://leetcode.cn/problems/minimum-additions-to-make-valid-string>

- [最小体力消耗路径](src/search/path_with_minimum_effort.cpp)  [深度优先搜索, 广度优先搜索, 并查集, 数组, 二分查找, 矩阵, 堆（优先队列）]

  - LeetCode 1631. 最小体力消耗路径 <https://leetcode.cn/problems/path-with-minimum-effort>

- [爬楼梯](src/search/climbing_stairs.cpp)  [记忆化搜索, 数学, 动态规划]

  - LeetCode 70. 爬楼梯 <https://leetcode.cn/problems/climbing-stairs>

- [水域大小](src/search/pond_sizes_lcci.cpp)  [深度优先搜索, 广度优先搜索, 并查集, 数组, 矩阵]

  - LeetCode 面试题 16.19. 水域大小 <https://leetcode.cn/problems/pond-sizes-lcci>

- [黑白翻转棋](src/search/flip_chess.cpp)  [广度优先搜索, 数组, 矩阵]

  - LeetCode LCP 41. 黑白翻转棋 <https://leetcode.cn/problems/fHi6rV>

- [统计封闭岛屿的数目](src/search/number_of_closed_islands.cpp)  [深度优先搜索, 广度优先搜索, 并查集, 数组, 矩阵]

  - LeetCode 1254. 统计封闭岛屿的数目 <https://leetcode.cn/problems/number-of-closed-islands>

- [铺瓷砖](src/other/tiling_a_rectangle_with_the_fewest_squares.cpp)  [动态规划, 回溯]

  - LeetCode 1240. 铺瓷砖 <https://leetcode.cn/problems/tiling-a-rectangle-with-the-fewest-squares>

- [单字符重复子串的最大长度](src/map/swap_for_longest_repeated_character_substring.cpp)  [哈希表, 字符串, 滑动窗口]

  - LeetCode 1156. 单字符重复子串的最大长度 <https://leetcode.cn/problems/swap-for-longest-repeated-character-substring>

- [二进制矩阵中的最短路径](src/search/shortest_path_in_binary_matrix.cpp)  [广度优先搜索, 数组, 矩阵]

  - LeetCode 1091. 二进制矩阵中的最短路径 <https://leetcode.cn/problems/shortest-path-in-binary-matrix/>

- [活字印刷](src/map/letter_tile_possibilities.cpp)  [哈希表, 字符串, 回溯, 计数]

  - LeetCode 1079. 活字印刷 <https://leetcode.cn/problems/letter-tile-possibilities>

- [可被 K 整除的最小整数](src/map/smallest_integer_divisible_by_k.cpp)  [哈希表, 数学]

  - LeetCode 1015. 可被 K 整除的最小整数 <https://leetcode.cn/problems/smallest-integer-divisible-by-k>

- [推箱子](src/search/minimum_moves_to_move_a_box_to_their_target_location.cpp)  [广度优先搜索, 数组, 矩阵, 堆（优先队列）]

  - LeetCode 1263. 推箱子 <https://leetcode.cn/problems/minimum-moves-to-move-a-box-to-their-target-location>

- [强整数](src/map/powerful_integers.cpp)  [哈希表, 数学]

  - LeetCode 970. 强整数 <https://leetcode.cn/problems/powerful-integers>

- [删除字符使频率相同](src/map/remove_letter_to_equalize_frequency.cpp)  [哈希表, 字符串, 计数]

  - LeetCode 2423. 删除字符使频率相同 <https://leetcode.cn/problems/remove-letter-to-equalize-frequency>

- [第一个出现两次的字母](src/map/first_letter_to_appear_twice.cpp)  [哈希表, 字符串, 计数]

  - LeetCode 2351. 第一个出现两次的字母 <https://leetcode.cn/problems/first-letter-to-appear-twice>

- [赎金信](src/map/ransom_note.cpp)  [哈希表, 字符串, 计数]

  - LeetCode 383. 赎金信 <https://leetcode.cn/problems/ransom-note/>

- [最大人工岛](src/search/making_a_large_island.cpp)  [深度优先搜索, 广度优先搜索, 并查集, 数组, 矩阵]

  - LeetCode 827. 最大人工岛 <https://leetcode.cn/problems/making-a-large-island>

- [分数加减运算](src/math/fraction_addition_and_subtraction.cpp)  [数学, 字符串, 模拟]

  - LeetCode 592. 分数加减运算 <https://leetcode.cn/problems/fraction-addition-and-subtraction>

- [最大交换](src/math/maximum_swap.cpp)  [贪心, 数学]

  - LeetCode 670. 最大交换 <https://leetcode.cn/problems/maximum-swap/>

- [字符串相加](src/math/add_strings.cpp)  [数学, 字符串, 模拟]

  - LeetCode 415. 字符串相加 <https://leetcode.cn/problems/add-strings/>

- [旋转数字](src/math/rotated_digits.cpp)  [数学, 动态规划]

  - LeetCode 788. 旋转数字 <https://leetcode.cn/problems/rotated-digits>

- [统计字典序元音字符串的数目](src/math/count_sorted_vowel_strings.cpp)  [数学, 动态规划, 组合数学]

  - LeetCode 1641. 统计字典序元音字符串的数目 <https://leetcode.cn/problems/count-sorted-vowel-strings>

- [公因子的数目](src/math/number_of_common_factors.cpp)  [数学, 枚举, 数论]

  - LeetCode 2427. 公因子的数目 <https://leetcode.cn/problems/number-of-common-factors>

- [负二进制转换](src/math/convert_to_base_2.cpp)  [数学]

  - LeetCode 1017. 负二进制转换 <https://leetcode.cn/problems/convert-to-base-2>

- [最小的必要团队](src/math/smallest_sufficient_team.cpp)  [位运算, 数组, 动态规划, 状态压缩]

  - LeetCode 1125. 最小的必要团队 <https://leetcode.cn/problems/smallest-sufficient-team>

- [困于环中的机器人](src/math/robot_bounded_in_circle.cpp)  [数学, 字符串, 模拟]

  - LeetCode 1041. 困于环中的机器人 <https://leetcode.cn/problems/robot-bounded-in-circle>

- [统计共同度过的日子数](src/math/count_days_spent_together.cpp)  [数学, 字符串]

  - LeetCode 2409. 统计共同度过的日子数 <https://leetcode.cn/problems/count-days-spent-together>

- [最小偶倍数](src/math/smallest_even_multiple.cpp)  [数学, 数论]

  - LeetCode 2413. 最小偶倍数 <https://leetcode.cn/problems/smallest-even-multiple>

- [分割圆的最少切割次数](src/math/minimum_cuts_to_divide_a_circle.cpp)  [几何, 数学]

  - LeetCode 2481. 分割圆的最少切割次数 <https://leetcode.cn/problems/minimum-cuts-to-divide-a-circle>

- [构建回文串检测](src/math/can_make_palindrome_from_substring.cpp)  [位运算, 数组, 哈希表, 字符串, 前缀和]

  - LeetCode 1177. 构建回文串检测 <https://leetcode.cn/problems/can-make-palindrome-from-substring>

- [连通两组点的最小成本](src/math/minimum_cost_to_connect_two_groups_of_points.cpp)  [位运算, 数组, 动态规划, 状态压缩, 矩阵]

  - LeetCode 1595. 连通两组点的最小成本 <https://leetcode.cn/problems/minimum-cost-to-connect-two-groups-of-points>

- [最大化网格幸福感](src/math/maximize_grid_happiness.cpp)  [位运算, 记忆化搜索, 动态规划, 状态压缩]

  - LeetCode 1659. 最大化网格幸福感 <https://leetcode.cn/problems/maximize-grid-happiness>

- [圆和矩形是否有重叠](src/math/circle_and_rectangle_overlapping.cpp)  [几何, 数学]

  - LeetCode 1401. 圆和矩形是否有重叠 <https://leetcode.cn/problems/circle-and-rectangle-overlapping>

- [找出中枢整数](src/math/find_the_pivot_integer.cpp)  [数学, 前缀和]

  - LeetCode 2485. 找出中枢整数 <https://leetcode.cn/problems/find-the-pivot-integer>

- [下一个更大的数值平衡数](src/math/next_greater_numerically_balanced_number.cpp)  [数学, 回溯, 枚举]

  - LeetCode 2048. 下一个更大的数值平衡数 <https://leetcode.cn/problems/next-greater-numerically-balanced-number>

- [不浪费原料的汉堡制作方案](src/math/number_of_burgers_with_no_waste_of_ingredients.cpp)  [数学]

  - LeetCode 1276. 不浪费原料的汉堡制作方案 <https://leetcode.cn/problems/number-of-burgers-with-no-waste-of-ingredients>

- [参加考试的最大学生数](src/math/maximum_students_taking_exam.cpp)  [位运算, 数组, 动态规划, 状态压缩, 矩阵]

  - LeetCode 1349. 参加考试的最大学生数 <https://leetcode.cn/problems/maximum-students-taking-exam>

- [一周中的第几天](src/math/day_of_the_week.cpp)  [数学]

  - LeetCode 1185. 一周中的第几天 <https://leetcode.cn/problems/day-of-the-week>

- [被列覆盖的最多行数](src/math/maximum_rows_covered_by_columns.cpp)  [位运算, 数组, 回溯, 枚举, 矩阵]

  - LeetCode 2397. 被列覆盖的最多行数 <https://leetcode.cn/problems/maximum-rows-covered-by-columns>

- [统计整数数目](src/math/count_of_integers.cpp)  [数学, 字符串, 动态规划]

  - LeetCode 2719. 统计整数数目 <https://leetcode.cn/problems/count-of-integers>
