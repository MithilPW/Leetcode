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

    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return NULL;
        }

        while (head != NULL && head->val == val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        }
        if(head == NULL){
            return NULL;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* NextNode = curr -> next;
        while(curr != NULL){
            if(curr->val == val){
                prev -> next = NextNode;
                delete curr;
                curr = NextNode;
                NextNode = (curr != NULL ? curr->next : NULL);
            }
            else{
                prev = curr;
                curr = NextNode;
                NextNode = (curr != NULL ? curr->next : NULL);
            }
        }

        return head;
    }
};