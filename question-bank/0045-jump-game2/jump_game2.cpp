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
#include <iostream>
using namespace std;

class Solution {
    public:
        int jump(vector<int> const& nums) {
            int l = nums.size();
            if (l < 3) return l-1;
            int i = 0, n = 0, t = 0, ct = 0;
            while (i < l) {
                int j;
                for (j=t; j<=i+nums[i]; j++) {
                    if (j == l-1) return ++ct;
                    if (nums[n]+n <= nums[j]+j)
                        n = j;
                }
                t = j;
                i = n;
                ++ct;
            }
        }
};

int main() {
    Solution s;
    cout << s.jump({ 2, 1, 2, 8, 1, 1 }) << endl;
    cout << s.jump({ 2, 1, 3, 8, 1, 1 }) << endl;
}
