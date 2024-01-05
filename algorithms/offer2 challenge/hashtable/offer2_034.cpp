#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
剑指 Offer II 034. 外星语言是否排序
某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。

给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。

 

示例 1：

输入：words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
输出：true
解释：在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。
示例 2：

输入：words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
输出：false
解释：在该语言的字母表中，'d' 位于 'l' 之后，那么 words[0] > words[1]，因此单词序列不是按字典序排列的。
示例 3：

输入：words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
输出：false
解释：当前三个字符 "app" 匹配时，第二个字符串相对短一些，然后根据词典编纂规则 "apple" > "app"，因为 'l' > '∅'，其中 '∅' 是空白字符，定义为比任何其他字符都小（更多信息）。
 

提示：

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
在 words[i] 和 order 中的所有字符都是英文小写字母。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/lwyVBB
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        // order > index_map
        unordered_map<char, int> index_map;
        for (int i = 0; i < order.size(); i++)
        {
            index_map[order[i]] = i;
        }

        for (int i = 1; i < words.size(); i++)
        {
            bool flag = false;
            for (int j = 0; j < words[i - 1].length() && j < words[i].length() && !flag; j++)
            {
                if (index_map[words[i - 1][j]] > index_map[words[i][j]])
                {
                    return false;
                }
                else if (index_map[words[i - 1][j]] < index_map[words[i][j]])
                {
                    flag = true;
                }
            }
            cout << "words[0].length =" << words[i - 1].length() << endl;
            cout << "words[1].length =" << words[i].length() << endl;
            if (!flag && words[i - 1].length() > words[i].length())
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{

    Solution solution;
    vector<string> words = {"apple", "app"};
    bool res = solution.isAlienSorted(words, "abcdefghijklmnopqrstuvwxyz");

    cout << "res = " << res << endl;
}