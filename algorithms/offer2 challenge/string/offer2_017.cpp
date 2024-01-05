#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
剑指 Offer II 017. 含有所有字符的最短字符串

给定两个字符串 s 和 t 。返回 s 中包含 t 的所有字符的最短子字符串。如果 s 中不存在符合条件的子字符串，则返回空字符串 "" 。

如果 s 中存在多个符合条件的子字符串，返回任意一个。

 

注意： 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。

 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最短子字符串 "BANC" 包含了字符串 t 的所有字符 'A'、'B'、'C'
示例 2：

输入：s = "a", t = "a"
输出："a"
示例 3：

输入：s = "a", t = "aa"
输出：""
解释：t 中两个字符 'a' 均应包含在 s 的子串中，因此没有符合条件的子字符串，返回空字符串。
 

提示：

1 <= s.length, t.length <= 105
s 和 t 由英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/M1oyTv


*/

class Solution
{
public:
    string minWindow(string s, string t)
    {

        int s_length = s.length();
        int t_length = t.length();

        map<char, int> t_map_counts;
        // map<char, int> count_map;
        
        for (int i = 0; i < t_length; i++)
        {
            t_map_counts[t[i]]++;
        }

        int min_length = INT_MAX;
        int count = t_map_counts.size();
    
        int start = 0, end = 0, minStart = 0, minEnd = 0;

        while (end < s_length || (count == 0 && end == s_length))
        {
            if (count > 0)
            {
                char endCh = s[end];
                if (t_map_counts.find(endCh) != t_map_counts.end())
                {
                    t_map_counts[endCh]--;
                    if (t_map_counts[endCh] == 0)
                    {
                        count--;
                    }
                }

                end++;
            }
            else
            {
                if (end - start < min_length)
                {
                    min_length = end - start;
                    minStart = start;
                    minEnd = end;
                }

                char startCh = s[start];
                if (t_map_counts.find(startCh) != t_map_counts.end())
                {
                    t_map_counts[startCh]++;
                    if (t_map_counts[startCh] == 1)
                    {
                        count++;
                    }
                }
                start++;
            }
        }

        return min_length < INT_MAX ? s.substr(minStart, min_length) : "";
    }

    string minWindow2(string s, string t) {
        
        int s_length = s.length();
        int t_length = t.length();

        int start = 0, end = 0;

        
        map<char, int> t_map;
        for (int i = 0; i < t_length; i++)
        {
            t_map[t[i]]++;
        }
        int count = t_map.size();

        while (end < s_length)
        {
            if (count > 0)
            {
                char s_char = s[end];

                
            }
            
        }
        



    }
};

int main() {


    Solution solution;
    string a = solution.minWindow("abc", "b");

    cout << "result :" << a << endl;

}