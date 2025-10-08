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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int n = 0;
        ListNode* lenPtr = head;
        while (lenPtr) {
            n++;
            lenPtr = lenPtr->next;
        }

        k = k % n;
        if (k == 0) return head;
        int count = 0;
        

        for(int i=1;i<=k;i++){
            ListNode* prev = NULL;
            ListNode* temp = head;
            if(count == k){
                break;
            }
            while(temp->next != NULL){
                prev = temp;
                temp = temp->next;
                
            }
            prev -> next = NULL;
            temp -> next = head;
            head = temp;

            count++;
        }

        return head;
    }
};