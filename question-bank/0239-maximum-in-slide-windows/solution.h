/*
 * #239 --- Maximum in Sliding Window
 * Difficulty: High
 * -----------------------------------------------------------------------------
 *  Given an array @nums and int @k, imagine there is a window which can contain
 *  @k numbers sliding along the array 1 number each time. Every time the window
 *  has slidden, collect the maximum number inside the window into a
 *  `vector<int>` and return the vector.
 * ----------------------------------
 * Example:
 * Input: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
 * Output: [3,3,5,5,6,7] 
 * Explanation: 
 *
 *   Position of Sliding Window   Maximum
 *   --------------------------    -----
 *   [1  3  -1] -3  5  3  6  7       3
 *    1 [3  -1  -3] 5  3  6  7       3
 *    1  3 [-1  -3  5] 3  6  7       5
 *    1  3  -1 [-3  5  3] 6  7       5
 *    1  3  -1  -3 [5  3  6] 7       6
 *    1  3  -1  -3  5 [3  6  7]      7
 * -----------------------------------------------------------------------------
 * Leetcode Rank:
 *      Speed:   88.16%
 *      Mem:    100.00%
 * -----------------------------------------------------------------------------
 * O(n)         2020-03-25
 */
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> win;
        int n = nums.size();
        
        for (int i=0; i<n; ++i) {
            while (!win.empty() && win.back()<nums[i]) win.pop_back();
            win.push_back(nums[i]);
            if (k-1<=i) {
                res.push_back(win.front());
                if (nums[i-k+1] == win.front()) win.pop_front();
            }
        }
        return res;
    }
};
