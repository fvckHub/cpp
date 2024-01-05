#include <iostream>
#include <string>
using namespace std;

/*
剑指 Offer II 020. 回文子字符串的个数
给定一个字符串 s ，请计算这个字符串中有多少个回文子字符串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

 

示例 1：

输入：s = "abc"
输出：3
解释：三个回文子串: "a", "b", "c"
示例 2：

输入：s = "aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 

提示：

1 <= s.length <= 1000
s 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/a7VOhD
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

class Solution {
public:
    int countSubstrings(string s) {

        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 1; j <= s.length() - i; j++)
            {
                if (isParl(s.substr(i, j)))
                {
                    count++;
                }
            }
        }
        return count;
        
    }

    bool isParl(string s) {
        int p1 = 0, p2 = s.length() - 1;

        while (p1 < p2)
        {
            if (s[p1] != s[p2])
            {
                return false;
            }
            p1++;
            p2--;
        }
        return true;
    }
};

int main() {

    Solution solution;
    int count = solution.countSubstrings("abc");
    cout << "count: " << count << endl;
}