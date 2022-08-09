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

## 测试环境

### MAC

```bash
brew install cmake node yarn llvm

echo 'export PATH="/opt/homebrew/opt/llvm/bin:$PATH"' >> ~/.zshrc
echo 'export LDFLAGS="-L/opt/homebrew/opt/llvm/lib"' >> ~/.zshrc
echo 'export CPPFLAGS="-I/opt/homebrew/opt/llvm/include"' >> ~/.zshrc

```

### Linux

参考<https://apt.llvm.org/>安装LLVM 14(clang-14)。

以Ubuntu 20.04为例，安装LLVM 14：

```bash
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key 2>/dev/null | sudo apt-key add -
sudo add-apt-repository 'deb http://apt.llvm.org/focal/ llvm-toolchain-focal-14 main' -y
sudo apt-get update -q
sudo apt-get install -y clang-14 lld-14 libc++-14-dev libc++abi-14-dev clang-tools-14 lcov
sudo node bin/ci.cjs
sudo chmod +x /usr/bin/llvm-gcov.sh
sudo update-alternatives --config c++
wget https://github.com/Kitware/CMake/releases/download/v3.23.2/cmake-3.23.2-linux-x86_64.sh
sudo chmod +x cmake-3.23.2-linux-x86_64.sh
sudo ./cmake-3.23.2-linux-x86_64.sh --prefix=/usr
```

以Kali Rolling(Debian)为例，安装LLVM 14：

```bash
# 如果是2022版本，不需要加载源，默认可以安装LLVM 14
# wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key 2>/dev/null | sudo apt-key add -
# sudo apt-key export AF4F7421|sudo gpg --dearmour -o /etc/apt/trusted.gpg.d/llvm.gpg
# sudo bash -c "echo  'deb [arch=amd64 signed-by=/etc/apt/trusted.gpg.d/llvm.gpg] http://apt.llvm.org/unstable/ llvm-toolchain-14 main' >> /etc/apt/sources.list"
sudo apt-get update -y
sudo apt-get install -y clang-14 lld-14 libc++-14-dev libc++abi-14-dev clang-tools-14 lcov
sudo node bin/ci.cjs
sudo chmod +x /usr/bin/llvm-gcov.sh
sudo update-alternatives --config c++
```

根据<https://nodejs.org/en/download/package-manager/>安装Node.js环境。根据安装时的提示安装`yarn`。

安装完成后执行`yarn`安装依赖。

### Windows

安装最新版cmake: <https://cmake.org/download/>

安装 **Visual Studio 2022**，并在`Visual Studio Installer`勾选`使用C++的桌面开发`中的`适用于Windows的C++ Clang工具`（13.0.1+）。

在`VSCode`的Cmake插件选择`Clang 13.0.1+(GUN CLI) for MSVC 17.x.32630.192+ (Visual Studio Professional 2022 Release - amd64)`。或者手动执行的时候使用对应版本的`llvm clang`。

## 基础排序算法

*待补充。*

- [插入排序](src/sort/insertSort.cpp)
- [冒泡排序](src/sort/bubbleSort.cpp)
- [选择排序](src/sort/selectSort.cpp)
- [快速排序](src/sort/quickSort.cpp)
- [归并排序](src/sort/mergeSort.cpp)

## 基础数据结构

## 算法题

### 字符串

- [数组中的字符串匹配](src/string/string_matching_in_an_array.cpp)  [字符串, 字符串匹配]

  - LeetCode 1408. 数组中的字符串匹配 <https://leetcode.cn/problems/string-matching-in-an-array>

### 数组/队列/集合/映射

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

### 树

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

### 排序

### 其它
