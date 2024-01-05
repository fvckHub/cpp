#include <string>
#include <iostream>
using namespace std;

/*
剑指 Offer II 018. 有效的回文

给定一个字符串 s ，验证 s 是否是 回文串 ，只考虑字母和数字字符，可以忽略字母的大小写。

本题中，将空字符串定义为有效的 回文串 。

 

示例 1:

输入: s = "A man, a plan, a canal: Panama"
输出: true
解释："amanaplanacanalpanama" 是回文串
示例 2:

输入: s = "race a car"
输出: false
解释："raceacar" 不是回文串
 

提示：

1 <= s.length <= 2 * 105
字符串 s 由 ASCII 字符组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/XltzEq
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

class Solution
{
public:
    bool isPalindrome(string s)
    {

        int p1 = 0;
        int p2 = s.length() - 1;

        bool isPalindrome = true;

        while (p1 < p2)
        {
            int p1_char = (int)s[p1];
            p1_char = (p1_char >= 97 && p1_char <= 122) ? p1_char - 32 : p1_char;
            int p2_char = (int)s[p2];
            p2_char = (p2_char >= 97 && p2_char <= 122) ? p2_char - 32 : p2_char;
            if (p1_char >= 48 && p1_char <= 57 ||
                p1_char >= 65 && p1_char <= 90)
            {
                if (p2_char >= 48 && p2_char <= 57 ||
                    p2_char >= 65 && p2_char <= 90)
                {
                    if (p1_char != p2_char)
                    {
                        return false;
                    }
                    else
                    {
                        p1++;
                        p2--;
                    }
                }
                else
                {
                    p2--;
                }
            }
            else
            {
                p1++;
                if (!(p2_char >= 48 && p2_char <= 57 ||
                    p2_char >= 65 && p2_char <= 90))
                {
                    p2--;
                }
            }
        }
        return isPalindrome;
    }
};

int main()
{

    Solution solution;
    bool result = solution.isPalindrome("A man, a plan, a canal: Panama");
    cout << "result : " << result << endl;
}