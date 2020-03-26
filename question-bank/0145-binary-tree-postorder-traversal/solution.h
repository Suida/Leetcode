/*
 * #145 --- Post-order Traversal of Binary Tree
 * Difficulty: High
 * -----------------------------------------------------------------------------
 * Given a binary tree, return the result after post-order traversal.
 * ----------------------------------
 * Example:
 * Input: 
 *      7
 *     / \
 *    /   \
 *   5     6
 *  / \   / \
 * 1   2 3   4
 * Output: [ 1, 2, 5, 3, 4, 6, 7 ]
 * Explanation: 
 * Recursive solution is obvious, try iterate version.
 * -----------------------------------------------------------------------------
 * Leetcode Rank:
 *      Speed:  100.00%     (0 ms)
 *      Mem:    100.00%     (8.4 MB)
 * -----------------------------------------------------------------------------
 * O(n)         2020-03-26
 */

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> stk {};
        if (root) stk.push_back(root);
        while (!stk.empty()) {
            TreeNode* node = stk.back();
            while (node->right || node->left) {
                if (node->right) stk.push_back(node->right);
                if (node->left)  stk.push_back(node->left);
                node = stk.back();
            }
            res.push_back(node->val);
            stk.pop_back();
            while (!stk.empty() &&
                   (stk.back()->left==node || stk.back()->right==node) )
            {
                res.push_back((node=stk.back())->val);
                stk.pop_back();
            }
        }
        return res;
    }
};
