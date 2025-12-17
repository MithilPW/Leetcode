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
       stack <int> st;

       vector <int> node;
       ListNode* temp = head;
       while(temp != NULL){
            node.push_back(temp->val);
            temp = temp -> next;
       }
        vector <int>ans(node.size());

        for(int i = 0;i<node.size();i++){
            while(!st.empty() && node[i] > node[st.top()]){
                int kids = st.top();
                st.pop();
                ans[kids] = node[i];
            }
            st.push(i);
        }
        return ans;        
    }
};