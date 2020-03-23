/*
 * #45 --- 跳跃游戏II
 * 难度: 中等
 * -----------------------------------------------------------------------------
 * 给定一个非负整数数组，你最初位于数组的第一个位置。
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 * ----------------------------------
 * 示例:
 * 输入: [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 *     从下标为 0 跳到下标为 1 的位置，跳1步，然后跳3步到达数组的最后一个位置。
 * -----------------------------------------------------------------------------
 * Leetcode Rank:
 *      Speed:   95.09%
 *      Mem:    100.00%
 * 复杂度O(n)   2020-03-23
 */
#include <vector>
using namespace std;

class Solution {
    public:
        void backtrace(vector<int> const& b, vector<int> const& a,
                vector<vector<int>>& v)
        {
            if (b.empty()) {
                v.push_back(a);
                return;
            }
            for (int i=0; i<b.size(); ++i) {
                vector<int> aa(a);
                vector<int> bb(b);
                aa.push_back(b[i]);
                bb.erase(bb.begin()+i);
                backtrace(bb, aa, v);
            }
            return;
        }

        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> v;
            backtrace(nums, vector<int>(), v);
            return v;
        }
};
