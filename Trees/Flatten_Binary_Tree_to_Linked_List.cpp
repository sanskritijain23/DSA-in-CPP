/*
Problem: Flatten Binary Tree to Linked List
Platform: LeetCode (#114)
Topic: Trees, Binary Tree, Morris Traversal

Approach:
- Traverse the tree using the current node.
- If the current node has a left subtree:
  - Find the rightmost node of the left subtree.
  - Connect the original right subtree to this rightmost node.
  - Move the left subtree to the right.
  - Set the left child to nullptr.
- Move to the right child and repeat until the tree is flattened.

Time Complexity: O(n)
Space Complexity: O(1)
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
    void flatten(TreeNode* root) {
        TreeNode* curr=root;
        while(curr){
            if(curr->left){
                TreeNode* pre=curr->left;
                while(pre->right){
                    pre=pre->right;
                }
                pre->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};