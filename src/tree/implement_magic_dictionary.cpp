// 实现一个魔法字典
// https://leetcode.cn/problems/implement-magic-dictionary
// INLINE  ../../images/tree/implement_magic_dictionary.jpeg
// 解题思路
// 字典树DFS
#include <headers.hpp>

struct Trie // 字典树
{
  bool is_finished = false;
  Trie *child[26];
  Trie()
  {
    fill(begin(child), end(child), nullptr);
  }
};

class MagicDictionary
{
private:
  Trie *root;
  unordered_set<int> wordLengthSet;

public:
  MagicDictionary()
  {
    root = new Trie();
  }

  void buildDict(vector<string> dictionary)
  {
    for (string &word : dictionary)
    {
      wordLengthSet.emplace(word.length()); // 记录一下所有字典元素的长度

      Trie *current = root;
      for (char ch : word)
      {
        int index = ch - 'a'; // 获取对应字母在字母表的位置，从0开始
        if (current->child[index] == nullptr)
        { // 默认填充了26个元素都为nullptr
          current->child[index] = new Trie();
        }
        current = current->child[index];
      }
      current->is_finished = true; // 最关键的一步，遍历完该单词标识结束，意味着该单词在字典树中存在
    }
  };

  bool search(string searchWord)
  {
    if (wordLengthSet.find(searchWord.length()) == wordLengthSet.end())
    {
      return false; // 如果长度没有和字典元素相同的，直接false
    }
    /**
     * @brief 字典树DFS
     * @param Trie* node 当前节点
     * @param pos searchWord 的第pos个字符
     * @param modified 是否已替换过字符
     */
    function<bool(Trie *, int, bool)> dfs = [&](Trie *node, int pos, bool modified)
    {
      if (pos == searchWord.size()) // 终止条件1 查找到最后一个字符
      {
        return node->is_finished && modified; // 如果在字典树搜索到对应的单词并且成功替换过一个字符
      }

      int index = searchWord[pos] - 'a'; // 获取对应字母在字母表的位置
      if (node->child[index])
      {
        if (dfs(node->child[index], pos + 1, modified)) // ? 不能直接return结果，任意一个true的结果都代表搜索到
        {
          return true;
        }
      }

      if (!modified) // ? 如果没有符合的结果，且没有修改过字符，继续执行下面的代码替换某个字符再查找
      {
        for (int i = 0; i < 26; ++i) // 遍历26个英文字母替换不同于当前字母的字母
        {
          if (i != index && node->child[i]) // 判断不是当前字母的同时判断字典树是否存在字符
          {
            if (dfs(node->child[i], pos + 1, true)) // 第三个参数true即标识替换过字符
            {
              return true;
            }
          }
        }
      }

      return false;
    };

    return dfs(root, 0, false);
  };
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */