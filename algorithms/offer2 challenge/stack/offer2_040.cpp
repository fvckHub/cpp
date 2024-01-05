#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
剑指 Offer II 040. 矩阵中最大的矩形

给定一个由 0 和 1 组成的矩阵 matrix ，找出只包含 1 的最大矩形，并返回其面积。

注意：此题 matrix 输入格式为一维 01 字符串数组。

 

示例 1：



输入：matrix = ["10100","10111","11111","10010"]
输出：6
解释：最大矩形如上图所示。
示例 2：

输入：matrix = []
输出：0
示例 3：

输入：matrix = ["0"]
输出：0
示例 4：

输入：matrix = ["1"]
输出：1
示例 5：

输入：matrix = ["00"]
输出：0
 

提示：

rows == matrix.length
cols == matrix[0].length
0 <= row, cols <= 200
matrix[i][j] 为 '0' 或 '1'
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/PLYXKQ
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

class Solution
{
public:
    int maximalRectangle(vector<string> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return 0;
        }
        

        int max = 0;
        vector<int> heights(matrix[0].length());
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
            }

            stack<int> index_stack;
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
        }
        return max;
    }
};