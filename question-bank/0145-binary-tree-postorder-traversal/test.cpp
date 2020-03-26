#include <cassert>
#include "solution.h"
using namespace std;

TreeNode* buildBinTree(vector<int> const& A) {
    int m = A.size();
    vector<TreeNode*>* stk = new vector<TreeNode*>;
    TreeNode* root = new TreeNode(A[0]);
    stk->push_back(root);
    for (int i=1; i<m;) {
        int n = stk->size();
        vector<TreeNode*>* tmp = new vector<TreeNode*>;
        int j=0;
        for (; i+j<m && j<n*2; ++j) {
            TreeNode* node = (A[i+j])? new TreeNode(A[i+j]): nullptr;
            if (j%2) (*stk)[j/2]->right = node;
            else (*stk)[j/2]->left = node;
            tmp->push_back(node);
        }
        i += j;
        delete stk;
        stk = tmp;
    }
    delete stk;
    return root;
}

int main() {
    vector<int> v = {0, 1, 2};
    auto root = buildBinTree(v);
    auto res = Solution().postorderTraversal(root);
    assert((res == vector<int> {1, 2, 0}));

    v = { 7, 5, 6, 1, 2, 3, 4 };
    root = buildBinTree(v);
    res = Solution().postorderTraversal(root);
    assert((res == vector<int> { 1, 2, 5, 3, 4, 6, 7 }));
}

