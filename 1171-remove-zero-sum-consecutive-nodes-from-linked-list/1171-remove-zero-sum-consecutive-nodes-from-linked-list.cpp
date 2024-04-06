class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum = 0;
        std::unordered_map<int, ListNode*> sumNodeMp;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        sumNodeMp[0] = dummyHead;
        for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
            prefixSum += curr->val;
            if (sumNodeMp.find(prefixSum) != sumNodeMp.end()) {
                ListNode* prevAnchor = sumNodeMp[prefixSum];
                int sumToBeRmd = prefixSum;
                while (prevAnchor != curr) {
                    prevAnchor = prevAnchor->next;
                    sumToBeRmd += (prevAnchor != nullptr) ? prevAnchor->val : 0;
                    if (prevAnchor != curr)
                        sumNodeMp.erase(sumToBeRmd);
                }
                sumNodeMp[prefixSum]->next = curr->next;
            } else if (prefixSum != 0) {
                sumNodeMp[prefixSum] = curr;
            }
        }
        return dummyHead->next;
    }
};