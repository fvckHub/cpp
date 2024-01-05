#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <unordered_map>
using namespace std;

/*
给定一个字符串数组 strs ，将 变位词 组合在一起。 可以按任意顺序返回结果列表。

注意：若两个字符串中每个字符出现的次数都相同，则称它们互为变位词。

 

示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:

输入: strs = [""]
输出: [[""]]
示例 3:

输入: strs = ["a"]
输出: [["a"]]

*/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        for (const string& str : strs)
        {
            string key = str;
            // sort 
            sort(key.begin(), key.end());
            anagramMap[key].push_back(str);
        }
        vector<vector<string>> res;
        for (auto& [k, v] : anagramMap)
        {
            res.push_back(v);
        }
        return res;
        
    }
};

int main() {

    string a = "afdsaf";
    char c = a[1];
    if(c == '\0') {
        cout << "true" << endl;
    };

}


