#include <iostream>
#include <vector>
using namespace std;

/*
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的某个变位词。

换句话说，第一个字符串的排列之一是第二个字符串的 子串 。



示例 1：

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
示例 2：

输入: s1= "ab" s2 = "eidboaoo"
输出: False


提示：

1 <= s1.length, s2.length <= 104
s1 和 s2 仅包含小写字母

*/
class Solution
{

public:
    bool checkInclusion(string s1, string s2)
    {
        if (s2.length() < s1.length())
        {
            return false;
        }

        vector<int> counts(26);

        for (int i = 0; i < s1.length(); i++)
        {
            counts[s1[i] - 'a']++;
            counts[s2[i] - 'a']--;
        }
        if (areAllZero(counts))
        {
            return true;
        }

        for (int i = s1.length(); i < s2.length(); i++)
        {
            counts[s2[i] - 'a']--;
            counts[s2[i - s1.length()]  - 'a']++;
            if (areAllZero(counts))
            {
                return true;
            }
        }

        return false;
    }

private:
    bool areAllZero(vector<int> counts)
    {

        for (int i = 0; i < counts.size(); i++)
        {
            if (counts[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{

    Solution Solution;
    bool result = Solution.checkInclusion("ab", "eidbaooo");
    cout << "result =" << result << endl;
    return 1;
}