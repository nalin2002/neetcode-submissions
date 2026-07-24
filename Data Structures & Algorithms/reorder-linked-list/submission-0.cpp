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

    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next ==NULL) return head;

        ListNode* prev=NULL;
        ListNode* curr= head;
        while(curr!=NULL){
            ListNode* forward= curr->next;
            curr->next= prev;
            prev= curr;
            curr= forward;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return ;
        if( head->next->next == NULL) return ;

        ListNode* slow= head;
        ListNode* fast= head;

        while( fast->next !=NULL && fast->next->next !=NULL){
            slow= slow->next;
            fast= fast->next->next;
        }
        ListNode* list2= slow->next;
        slow->next= NULL;
        list2= reverse(list2);

        ListNode dummy(0);
        ListNode* tail= &dummy;


        ListNode* p1= head;
        ListNode* p2= list2;

        
        while(p1!=NULL && p2!=NULL ){
            ListNode* f1= p1->next;
            ListNode* f2= p2->next;
            tail= p1;
            p1->next= p2;
            p2->next = f1;
            p1= f1;
            p2=f2;
            tail= tail->next;
        }

    }
};
