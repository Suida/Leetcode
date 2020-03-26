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
