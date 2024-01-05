#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
剑指 Offer II 039. 直方图最大矩形面积

给定非负整数数组 heights ，数组中的数字用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 

示例 1:



输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10
示例 2：



输入： heights = [2,4]
输出： 4

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/0ynMMM
*/

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {

        stack<int> index_stack;
        int max = 0;
        index_stack.push(-1);

        for (int i = 0; i < heights.size(); i++)
        {
            while (index_stack.top() != -1 && heights[index_stack.top()] >= heights[i])
            {
                int height = heights[index_stack.top()];
                index_stack.pop();

                int left = index_stack.top();
                int right = i;
                int size = (right - left - 1) * height;
                max = size > max ? size : max;
            }

            index_stack.push(i);
        }

        while (index_stack.top() != -1)
        {
            int height = heights[index_stack.top()];
            index_stack.pop();
            int wigth = heights.size() - index_stack.top() - 1;
            int size = height * wigth;
            max = size > max ? size : max;
        }

        return max;
    }
};


int main() {


    Solution solution;
    vector<int> param = {2,1,5,6,2,3};
    int res = solution.largestRectangleArea(param);
    cout << res << endl;

}