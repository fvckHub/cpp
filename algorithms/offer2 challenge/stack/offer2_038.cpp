#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
剑指 Offer II 038. 每日温度
请根据每日 气温 列表 temperatures ，重新生成一个列表，要求其对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。

 

示例 1:

输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]
示例 2:

输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]
示例 3:

输入: temperatures = [30,60,90]
输出: [1,1,0]
 

提示：

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/iIQa4I
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> index_sta;
        vector<int> res(temperatures.size());
        for (size_t i = 0; i < temperatures.size(); i++)
        {
            int t = temperatures[i];
            while (!index_sta.empty() && temperatures[index_sta.top()] < t)
                {
                    res[index_sta.top()] = i - index_sta.top();
                    index_sta.pop();
                }
            index_sta.push(i);
        }
        
        return res;
    }
};

int main() {

    Solution solution;
    vector<int> param = {73,74,75,71,69,72,76,73};
    vector<int> res = solution.dailyTemperatures(param);

    for (int &r : res)
    {
        cout << r << endl;

    }
    

}