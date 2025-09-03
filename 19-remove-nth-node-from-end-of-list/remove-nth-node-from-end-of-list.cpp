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

    int getLength(ListNode* head){

        ListNode *temp = head;
        int length = 0;
        while(temp != NULL){
            length++;
            temp = temp -> next;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return NULL;
        }

        ListNode *curr = head;
        ListNode *prev = NULL;


        int count = 1;
        int length = getLength(head);        
        if(n == length){
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            return head;
        }
        while(count != length - n+1){
            prev = curr;
            curr = curr -> next;
            count++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;

        return head;
    }
};