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
    bool hasCycle(ListNode* head) {
        if(head==NULL || head->next ==NULL) return false;

        ListNode* p1 = head;
        ListNode* p2= head;

        while(p1!=NULL && p2!=NULL && p2->next !=NULL){
            p1= p1->next;
            p2= p2->next->next;

            if(p1==p2) return true;
        }

        return false;
    }
};
