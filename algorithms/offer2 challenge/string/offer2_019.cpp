#include <iostream>
#include <string>
using namespace std;

/*
剑指 Offer II 019. 最多删除一个字符得到回文

给定一个非空字符串 s，请判断如果 最多 从字符串中删除一个字符能否得到一个回文字符串。

 

示例 1:

输入: s = "aba"
输出: true
示例 2:

输入: s = "abca"
输出: true
解释: 可以删除 "c" 字符 或者 "b" 字符
示例 3:

输入: s = "abc"
输出: false
 

提示:

1 <= s.length <= 105
s 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/RQku0D
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

class Solution {
public:
    bool validPalindrome(string s) {
        
        int p1 = 0, p2 = s.length() - 1, p1_tag = 0, p2_tag = 0;

        int chance = 0;

        bool isPalindrome = true;

        while (p1 < p2)
        {
            if (s[p1] != s[p2])
            {
                if (chance < 1)
                {
                    if (s[p1] == s[p2 - 1])
                    {
                        p2--;
                        p1_tag = p1 + 1;
                        p2_tag = p2 + 1;
                        chance ++;
                    } else if (s[p1 + 1] == s[p2])
                    {
                        p1 ++;
                        p1_tag = p1 - 1;
                        p2_tag = p2 - 1;
                        chance ++;
                    } else {
                        chance +=2;
                    }
                    
                    
                } else if (chance == 1)
                {
                    p1 = p1_tag;
                    p2 = p2_tag;
                    chance ++;
                } else {
                    return false;
                }
                
            } else {
                p1++;
                p2--;
            }
            
        }
        return isPalindrome;
    }
};

int main() {

    Solution solution;
    bool result = solution.validPalindrome("aba");
    cout <<"result :" << result << endl;
}