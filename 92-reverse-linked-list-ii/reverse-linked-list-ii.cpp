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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL){
            return NULL;
        }

        ListNode* temp = head;
        vector <int> arr;
        while(temp != NULL){
            arr.push_back(temp -> val);
            temp = temp -> next;
        }

        int bright = right-1;
        for(int i = left-1;i<bright;i++){
            swap(arr[i],arr[bright]);
            bright--;
        }
        temp = head;
        int i = 0;
        while(temp != NULL){
            temp -> val = arr[i];
            i++;
            temp = temp -> next;
        }
        return head;
    }
};