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
    //    stack <int> st;
       vector <int> ans;
       vector <int> node;
       ListNode* temp = head;
       while(temp != NULL){
            node.push_back(temp->val);
            temp = temp -> next;
       }

        int n = node.size();

        for (int i = 0; i < n; i++) {
            int nextGreater = 0;

            for (int j = i + 1; j < n; j++) {
                if (node[j] > node[i]) {
                    nextGreater = node[j];
                    break;      
                }
            }
            ans.push_back(nextGreater);
        }

        return ans;
    }
};