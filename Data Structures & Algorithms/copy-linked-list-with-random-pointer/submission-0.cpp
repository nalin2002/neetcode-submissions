/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> mp;

    Node* copyRandomList(Node* head) {
      if(head==NULL) return NULL;
      
    //   if(mp.count(head)) return mp[head];

    //   Node* copy = new Node(head->val);
    //   mp[head]= copy;
    //   copy->next = copyRandomList(head->next);
    //   copy->random= map[head->random];
    //   return copy;

        // unordered_map<Node*,Node*> mp;
        // mp[NULL]=NULL;

        // Node* curr= head;
        // while(curr!=NULL){
        //     Node* copy= new Node(curr->val);
        //     mp[curr]= copy;
        //     curr= curr->next;
        // }

        // curr= head;
        // while(curr!=NULL){
        //     Node* copy = mp[curr];
        //     copy->next = mp[curr->next];
        //     copy->random= mp[curr->random];
        //     curr= curr->next;
        // }
        // return mp[head];

        Node* curr= head;
        
        while(curr!=NULL){
            Node* copy_node= new Node(0);
            copy_node->val= curr->val;
            Node* forward= curr->next;
            curr->next = copy_node;
            copy_node->next = forward;

            if(curr->next !=NULL)
            curr= curr->next->next;
            else
            curr= curr->next;
        }

        Node* newhead= head->next;
        curr= head;
        while(curr!=NULL){
            if(curr->random !=NULL){
                curr->next->random= curr->random->next;
            }
            curr= curr->next->next;
        }

        curr= head;
        while(curr!=NULL){
            Node* copy= curr->next;
            curr->next= copy->next;
            if( copy->next !=NULL){
                copy->next = copy->next->next; 
            }
            curr= curr->next;
        }
        return newhead;
    }
};
