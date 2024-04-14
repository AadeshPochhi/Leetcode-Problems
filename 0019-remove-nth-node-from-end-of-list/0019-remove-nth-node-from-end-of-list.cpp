/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* current = head;
    ListNode* prev = NULL;
    int length = 0;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    current = head;
    if (length == n) {
        head = head->next;
        delete current;
        return head;
    }
    for (int i = 0; i < length - n; i++) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    delete current;
    
    return head;
}

};