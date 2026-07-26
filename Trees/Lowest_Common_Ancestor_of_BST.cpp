/*
Problem: Lowest Common Ancestor of a Binary Search Tree
Platform: LeetCode (#235)
Topic: Binary Search Tree, Trees, Recursion

Approach:
- Use BST property to navigate the tree.
- If both nodes are greater than current node, move to right subtree.
- If both nodes are smaller than current node, move to left subtree.
- Otherwise, current node is the split point and becomes the LCA.

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)    return nullptr;
            int curr=root->val;
            if(curr<p->val && curr<q->val){
                return lowestCommonAncestor(root->right,p,q);
            }
            if(curr>p->val && curr>q->val){
                return lowestCommonAncestor(root->left,p,q);
            }
            return root;
    }
};