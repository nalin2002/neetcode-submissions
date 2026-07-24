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
    int length(ListNode* head){
        if(head==NULL) return 0;
        int count=0;
        while(head!=NULL){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;

        int len= length(head);
        int pos= len-n;
        if(pos==0) return head->next;

        if(pos<0) return head;

        pos--;
        ListNode* temp = head;

        while(pos--){
            temp= temp->next;
        }
        ListNode* node= temp->next->next;
        temp->next = node;

        return head;
    }
};
