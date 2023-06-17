// 构建回文串检测
// https://leetcode.cn/problems/can-make-palindrome-from-substring
// INLINE  ../../images/math/can_make_palindrome_from_substring.jpeg

#include <headers.hpp>

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<vector<int>> prefix(s.size() + 1, vector<int>(26, 0));
        for (int i = 0; i < s.size(); ++i) {
            prefix[i + 1] = prefix[i];
            prefix[i + 1][s[i] - 'a']++;
        }
        for (auto& query : queries) {
            int left = query[0], right = query[1], k = query[2];
            int odd = 0;
            for (int i = 0; i < 26; ++i) {
                odd += (prefix[right + 1][i] - prefix[left][i]) % 2;
            }
            ans.push_back(odd / 2 <= k);
        }
        return ans;
    }
};