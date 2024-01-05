#include <iostream>
#include <unordered_map>
using namespace std;

/*
剑指 Offer II 032. 有效的变位词

给定两个字符串 s 和 t ，编写一个函数来判断它们是不是一组变位词（字母异位词）。

注意：若 s 和 t 中每个字符出现的次数都相同且字符顺序不完全相同，则称 s 和 t 互为变位词（字母异位词）。


示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
示例 3:

输入: s = "a", t = "a"
输出: false
 

提示:

1 <= s.length, t.length <= 5 * 104
s and t 仅包含小写字母
 

*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_char_count_map;
        unordered_map<char, int> t_char_count_map;
        if (s.size() != t.size())
        {
            return false;
        }
        bool not_same = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != t[i])
            {
                not_same = true;
            }
            s_char_count_map[s[i]]++;
            t_char_count_map[t[i]]++;
        }

        for (const auto& [key, value] : s_char_count_map)
        {
            if (t_char_count_map[key] != value)
            {
                return false;
            }
            
        }
        
        return true && not_same;
        
        
        
    }
};

int main() {


    Solution solution;
    bool isAnagram = solution.isAnagram("anagram", "nagaram");
    cout << isAnagram << endl;      

}