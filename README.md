# C++ 算法练习

[![license](https://img.shields.io/github/license/yi-ge/cpp-practice.svg?style=flat-square)](https://github.com/yi-ge/cpp-practice/blob/master/LICENSE)
[![GitHub Actions](https://img.shields.io/endpoint.svg?url=https%3A%2F%2Factions-badge.atrox.dev%2Fyi-ge%2Fcpp-practice%2Fbadge%3Fref%3Dmain&style=flat-square)](https://actions-badge.atrox.dev/yi-ge/cpp-practice/goto?ref=main)
[![Test Results](https://gist.github.com/yi-ge/cfafaf2ba23090ed9f8aa8fc875c9ce5/raw/badge.svg)](https://github.com/yi-ge/cpp-practice)
[![Coveralls github](https://img.shields.io/coveralls/github/yi-ge/cpp-practice?style=flat-square)](https://coveralls.io/github/yi-ge/cpp-practice?branch=main)
[![GitHub last commit](https://img.shields.io/github/last-commit/yi-ge/cpp-practice.svg?style=flat-square)](https://github.com/yi-ge/cpp-practice)
[![Gitpod Ready-to-Code](https://img.shields.io/badge/Gitpod-Ready--to--Code-blue?logo=gitpod&style=flat-square)](https://gitpod.io/#https://github.com/yi-ge/cpp-practice)

C++ 基础算法、数据结构练习，包含 LeetCode 或其它算法练习记录。

此为个人练习仓库，代码中对重要思想进行了注释，会尽量补充解题思路。

每一道题都对应写有测试用例，但可能不够完整。如果您发现错误，欢迎给我留言，谢谢！

安装以下测试环境后，运行`yarn start`可以自动从LeetCode获取代码函数和用例说明。保存文件后将自动同步到浏览器。

特别说明：题目截图仅为了方便在代码编辑器中直接预览从而优化编码体验，题目以LeetCode官方页面为准，题目著作权及其他权利以LeetCode官方说明为准或属于LeetCode。请大家尊重版权，共同维护良好网络环境。

## 测试环境

如果你使用VSCode进行开发，那么可以安装[C++ TestMate](https://marketplace.visualstudio.com/items?itemName=matepek.vscode-catch2-test-adapter)以获得更好的单元测试体验。

同时推荐安装：

- [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
- [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)

以下是各个平台安装依赖的说明。

### MAC

```bash
brew install cmake node yarn llvm ninja lcov

echo 'export PATH="/opt/homebrew/opt/llvm/bin:$PATH"' >> ~/.zshrc
echo 'export LDFLAGS="-L/opt/homebrew/opt/llvm/lib"' >> ~/.zshrc
echo 'export CPPFLAGS="-I/opt/homebrew/opt/llvm/include"' >> ~/.zshrc

```

安装完成后执行`yarn`安装依赖。

### Linux

参考<https://apt.llvm.org/>安装LLVM 15(clang-15)。

以Ubuntu 20.04为例，安装LLVM 15：

```bash
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key 2>/dev/null | sudo apt-key add -
sudo add-apt-repository 'deb http://apt.llvm.org/focal/ llvm-toolchain-focal-15 main' -y
sudo apt-get update -q
sudo apt-get install -y clang-15 llvm-15 lld-15 libc++-15-dev libc++abi-15-dev clang-tools-15 lcov binutils ninja-build
sudo update-alternatives --config c++
wget https://github.com/Kitware/CMake/releases/download/v3.23.2/cmake-3.23.2-linux-x86_64.sh
sudo chmod +x cmake-3.23.2-linux-x86_64.sh
sudo ./cmake-3.23.2-linux-x86_64.sh --prefix=/usr
```

以Kali Rolling(Debian)为例，安装LLVM 14：

```bash
# 如果是2022版本，不需要加载源，默认可以安装LLVM 15
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key 2>/dev/null | sudo apt-key add -
sudo apt-key export AF4F7421|sudo gpg --dearmour -o /etc/apt/trusted.gpg.d/llvm.gpg
sudo bash -c "echo  'deb [arch=amd64 signed-by=/etc/apt/trusted.gpg.d/llvm.gpg] http://apt.llvm.org/unstable/ llvm-toolchain-15 main' >> /etc/apt/sources.list"
sudo apt-get update -y
sudo apt-get install -y clang-15 llvm-15 lld-15 libc++-15-dev libc++abi-15-dev clang-tools-15 lcov binutils ninja-build
sudo update-alternatives --config c++
```

根据<https://nodejs.org/en/download/package-manager/>安装Node.js环境。根据安装时的提示安装`yarn`。

安装完成后执行`yarn`安装依赖。

如果使用VSCode进行开发，需要安装`clangd`以及对应的插件。

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

## 基础排序算法

- [插入排序](src/sort/insert_sort.cpp)
- [冒泡排序](src/sort/bubble_sort.cpp)
- [选择排序](src/sort/select_sort.cpp)
- [快速排序](src/sort/quick_sort.cpp)
- [归并排序](src/sort/merge_sort.cpp)

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

- [不邻接植花](src/graphs/flower_planting_with_no_adjacent.cpp)  [深度优先搜索, 广度优先搜索, 图]

  - LeetCode 1042. 不邻接植花 <https://leetcode.cn/problems/flower-planting-with-no-adjacent>

- [找到小镇的法官](src/graphs/find_the_town_judge.cpp)  [图, 数组, 哈希表]

  - LeetCode 997. 找到小镇的法官 <https://leetcode.cn/problems/find-the-town-judge>

### 排序

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
