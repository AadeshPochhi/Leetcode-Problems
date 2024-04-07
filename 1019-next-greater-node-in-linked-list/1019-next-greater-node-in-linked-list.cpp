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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>v;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        int n=v.size();
        stack<int>sk;
        vector<int>ans(n,0);
        int i=0;
        while(i<n){
            while(!sk.empty() && v[i]>v[sk.top()]){
                int idx=sk.top(); 
                sk.pop();
                ans[idx]=v[i];
            }
            sk.push(i);
            i++;
        }
        return ans;
    }
};  