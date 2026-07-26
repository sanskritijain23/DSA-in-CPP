/*
Problem: Kth Smallest Element in a BST
Platform: LeetCode (#230)
Topic: Binary Search Tree, Trees, Inorder Traversal

Approach:
- Perform inorder traversal of BST.
- Since inorder traversal gives values in sorted ascending order,
  the kth visited node is the kth smallest element.
- Use a counter while traversing.
- Also perform reverse inorder traversal to find kth largest element.

Time Complexity: O(n)
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
    int small=-1,large=-1;
    void inorder(TreeNode* root, int & k){
        if(!root)    return ;
        inorder(root->left,k);
        k--;
        if(k==0){
            small=root->val;
            return;
        }
        inorder(root->right,k);
    }
    void revinorder(TreeNode* root, int& k){
        if(!root)   return ;
        revinorder(root->right,k);
        k--;
        if(k==0){
            large=root->val;
            return;
        }
        revinorder(root->left,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int k1=k,k2=k;
        inorder(root,k1);
        revinorder(root,k2);
        return small;
    }
};