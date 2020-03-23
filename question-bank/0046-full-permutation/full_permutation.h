/*
 * #46 --- Full Permutation
 * Difficulty: Medium
 * -----------------------------------------------------------------------------
 * Given a non-repeating integer sequence, calculate all the 
 * possible arrangements and return them in a 2-dimensional sequence
 * ----------------------------------
 * Examples:
 * Input: [1, 2, 3]
 * Output: 
 * [
 *     [ 1 2 3  ]
 *     [ 1 3 2  ]
 *     [ 2 1 3  ]
 *     [ 2 3 1  ]
 *     [ 3 1 2  ]
 *     [ 3 2 1  ]
 * ]
 * -----------------------------------------------------------------------------
 * Leetcode Rank:
 *      Speed:   90.19%
 *      Mem:     28.62%
 * O(n!)   2020-03-23
 */
#include <set>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> hot;
    set<int> used;
    public:
        void backtrace(vector<int> const& nums) {
            if (hot.size() == nums.size())
                res.push_back(vector<int>(hot));
            else
                for (int i=0; i<nums.size(); ++i) {
                    if (used.find(i) == used.end()) {
                        hot.push_back(nums[i]);
                        used.insert(i);
                        backtrace(nums);
                        hot.pop_back();
                        used.erase(i);
                    }
                }
        }

        vector<vector<int>> permute(vector<int>& nums) {
            backtrace(nums);
            return res;
        }
};
