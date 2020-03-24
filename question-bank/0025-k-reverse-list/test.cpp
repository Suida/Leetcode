#include <iostream>
#include "group_reverse.h"
using namespace std;

void printList(ListNode* head) {
    cout << "[ ";
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "]" << endl;
}

int main() {
    ListNode head(0);
    ListNode* ptr = &head;
    for (int i=1; i<10; ++i){
        ListNode* n = new ListNode(i);
        ptr->next = n;
        ptr = ptr->next;
    }
    printList(&head);
    auto h = Solution().reverseKGroup(&head, 3);
    printList(h);

    auto tmp = h;
    for (int i=0; i<8; ++i)
        tmp = tmp->next;
    printList(tmp);
    printList(Solution().reverseKGroup(tmp, 3));
}

