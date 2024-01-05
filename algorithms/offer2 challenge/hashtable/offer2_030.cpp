#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
剑指 Offer II 030. 插入、删除和随机访问都是 O(1) 的容器

设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构：

insert(val)：当元素 val 不存在时返回 true ，并向集合中插入该项，否则返回 false 。
remove(val)：当元素 val 存在时返回 true ，并从集合中移除该项，否则返回 false 。
getRandom：随机返回现有集合中的一项。每个元素应该有 相同的概率 被返回。
 

示例 :

输入: inputs = ["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
输出: [null, true, false, true, 2, true, false, 2]
解释:
RandomizedSet randomSet = new RandomizedSet();  // 初始化一个空的集合
randomSet.insert(1); // 向集合中插入 1 ， 返回 true 表示 1 被成功地插入

randomSet.remove(2); // 返回 false，表示集合中不存在 2

randomSet.insert(2); // 向集合中插入 2 返回 true ，集合现在包含 [1,2]

randomSet.getRandom(); // getRandom 应随机返回 1 或 2

randomSet.remove(1); // 从集合中移除 1 返回 true 。集合现在包含 [2]

randomSet.insert(2); // 2 已在集合中，所以返回 false

randomSet.getRandom(); // 由于 2 是集合中唯一的数字，getRandom 总是返回 2
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/FortPu
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/
class RandomizedSet
{
public:
    unordered_map<int, int> numToLocation;
    vector<int> nums;
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (numToLocation.find(val) != numToLocation.end())
        {
            return false;
        }
        numToLocation[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (numToLocation.find(val) == numToLocation.end())
        {
            return false;
        }

        int location  = numToLocation[val];
        numToLocation[nums.back()] = location;
        numToLocation.erase(val);
        nums[location] = nums.back();
        nums.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        int a = rand();
        cout << "random = " << a << endl;
        int idx = a % nums.size();
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{

    RandomizedSet *randomizedSet = new RandomizedSet();
    bool res1 = randomizedSet->insert(1);
    bool res2 = randomizedSet->remove(2);
    bool res3 = randomizedSet->insert(2);
    int res4 = randomizedSet->getRandom();
    bool res5 = randomizedSet->remove(1);
    bool res6 = randomizedSet->insert(2);
    int res7 = randomizedSet->getRandom();

    cout << res1 << endl;
    cout << res2 << endl;
    cout << res3 << endl;
    cout << res4 << endl;
    cout << res5 << endl;
    cout << res6 << endl;
    cout << res7 << endl;
}