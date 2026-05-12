/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getMax(TreeNode * root){
        if(root == NULL){
            return -1;
        }
        while(root->right != NULL){
            root = root->right;
        }
        return root->val;
    }
    int getMin(TreeNode * root){
        if(root == NULL){
            return -1;
        }
        while(root -> left != NULL){
            root = root->left;
        }

        return root-> val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }

        if(root->val == key){
            //4case

            //delete node with 

            //1) 0 child
            if(root->left == NULL && root->right == NULL){
                TreeNode*temp = root;
                delete temp;
                return NULL;
            }
            //2) 1 child -> left

            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root;
                TreeNode* child = root->left;
                temp->left = NULL;
                delete temp;
                return child;
            }
            //3) 1 child -> right
                if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root;
                TreeNode* child = root->right;
                temp->right = NULL;
                delete temp;
                return child;
            }
            //4) 2 child
            if(root -> left != NULL && root->right != NULL){
                int replaceValue = getMin(root->right);
                root->val = replaceValue;

                root->right = deleteNode(root->right,replaceValue);
                return root;
            }
        }
        else{
            //not match
            if(key > root->val){
                //deletion right side me hoga
                root->right = deleteNode(root->right,key);
            }
            else{
                //deletion left side me hoga
                root->left = deleteNode(root->left,key);
            }
        }
        return root;
    }
};