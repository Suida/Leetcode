/*
 * #25 --- Reverse Nodes in Groups Divided as k Nodes per Each
 * Difficulty: High
 * -----------------------------------------------------------------------------
 * Given a forward list, divide them to groups where the adjucent @k nodes are
 * in one group, and reverse the order in each group and return the new list. If
 * the total of node is not integral multiple of @k, please remain the order of
 * the last residual nodes.
 * ----------------------------------
 * Examples:
 * Input: @List: 1->2->3->4->5; 
 * Output: 
 * if @k = 2:                       if @k = 3:
 *    @ret = 2->1->4->3->5;            @ret = 3->2->1->4->5
 * -----------------------------------------------------------------------------
 * Leetcode Rank:
 *      Speed:   91.08%
 *      Mem:    100.00%
 * -----------------------------------------------------------------------------
 * O(n)         2020-03-24
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int const k) {
            ListNode* A[k], *p = head, *frnt = nullptr, *newh = head;
            int i = 0;

            while (p) {
                A[i++%k] = p;

                if ((i % k) == 0) {
                    if (i == k) newh = p;
                    if (frnt) frnt->next = p;
                    frnt = A[0];

                    p = p->next;
                    int j = k - 1;
                    while (0 < j) {
                        A[j--]->next = A[j-1];
                    }
                    A[j]->next = p;
                }
                else
                    p = p->next;
            }
            return newh;
        }
        
};
