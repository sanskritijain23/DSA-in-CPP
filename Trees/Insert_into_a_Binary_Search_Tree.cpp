/*
Problem: Insert into a Binary Search Tree
Platform: LeetCode (#701)
Topic: Binary Search Tree (BST), Trees

Approach:
- If the tree is empty, create and return a new node.
- Traverse the BST iteratively from the root.
- If the value is greater than or equal to the current node, move to the right subtree.
- Otherwise, move to the left subtree.
- When a null child is found, insert the new node there.
- Return the original root.

Time Complexity: O(h)
Space Complexity: O(1)

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         if(root==nullptr)  return new TreeNode(val);
        TreeNode *cur=root;
        while(true){
            if(cur->val<=val){
                if(cur->right!=nullptr)   cur=cur->right;
                else{
                    cur->right=new TreeNode(val);
                    break;
                }
            }
            else{
                if(cur->left!=nullptr)    cur=cur->left;
                else{
                    cur->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};