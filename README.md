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
brew install cmake node yarn

```

### Linux

以Ubuntu 20.04为例，安装LLVM 14：

```bash
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key 2>/dev/null | sudo apt-key add -
sudo add-apt-repository 'deb http://apt.llvm.org/focal/ llvm-toolchain-focal-14 main' -y
sudo apt-get update -q
sudo apt-get install -y clang-14 lld-14 libc++-14-dev libc++abi-14-dev clang-tools-14 lcov
sudo node bin/ci.cjs
sudo chmod +x /usr/bin/llvm-gcov.sh
sudo update-alternatives --config c++
```

根据<https://nodejs.org/en/download/package-manager/>安装Node.js环境。根据安装时的提示安装`yarn`。

安装完成后执行`yarn`安装依赖。

## 基础排序算法

- [插入排序](src/sort/insertSort.cpp)
- [冒泡排序](src/sort/bubbleSort.cpp)
- [选择排序](src/sort/selectSort.cpp)
- [快速排序](src/sort/quickSort.cpp)
- [归并排序](src/sort/mergeSort.cpp)

## 基础数据结构

## 算法题

### 字符串

### 数组/队列/集合/映射

- [摘樱桃](src/array/cherry_pickup.cpp)  [数组, 动态规划, 矩阵]

  - LeetCode 741. 摘樱桃 <https://leetcode.cn/problems/cherry-pickup>

- [最长的斐波那契子序列的长度](src/array/length_of_longest_fibonacci_subsequence.cpp)  [数组, 哈希表, 动态规划]

  - LeetCode 873. 最长的斐波那契子序列的长度 <https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence>

- [玩筹码](src/array/minimum_cost_to_move_chips_to_the_same_position.cpp)  [贪心, 数组, 数学]

  - LeetCode 1217. 玩筹码 <https://leetcode.cn/problems/minimum-cost-to-move-chips-to-the-same-position>

### 栈

### 树

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
