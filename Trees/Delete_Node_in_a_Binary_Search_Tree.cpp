/*
Problem: Delete Node in a Binary Search Tree
Platform: LeetCode (#450)
Topic: Binary Search Tree (BST), Trees

Approach:
- Search for the node containing the key using BST property.
- If the node is found, handle deletion using three cases:
    1. Node has no left child → return right child.
    2. Node has no right child → return left child.
    3. Node has both children:
       - Attach the right subtree to the rightmost node of the left subtree.
       - Return the left subtree as the replacement.

- Use iterative traversal to find the node and delete it.

Time Complexity: O(h)
Space Complexity: O(h)

where h is the height of the BST.
*/



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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return nullptr;
        }
        if(root->val==key){
            return helper(root);
        }
        TreeNode* dummy=root;
        while(root!=nullptr){
            if(root->val>key){
                if(root->left!=nullptr && root->left->val==key){
                    root->left=helper(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right!=nullptr && root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return dummy;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left==nullptr){
            return root->right;
        }
        else if(root->right==nullptr){
            return root->left;
        }
        TreeNode* rightchild=root->right;
        TreeNode* lastright=findlastright(root->left);
        lastright->right=rightchild;
        return root->left;
    }
    TreeNode* findlastright(TreeNode* root){
        if(root->right==nullptr){
            return root;
        }
        return findlastright(root->right);
    }
};