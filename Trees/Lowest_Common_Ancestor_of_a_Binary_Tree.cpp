/*
Problem: Lowest Common Ancestor of a Binary Tree
Platform: LeetCode (#236)
Topic: Trees, Binary Tree

Approach:
- Traverse the tree recursively.
- If the current node is NULL, p, or q, return it.
- Recursively search in both left and right subtrees.
- If both recursive calls return non-null, the current node is the LCA.
- Otherwise, return the non-null subtree result.

Time Complexity: O(n)
Space Complexity: O(h)
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
        if(root==nullptr || root==p || root==q){
            return root;
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left==nullptr){
            return right;
        }
        else if(right==nullptr){
            return left;
        }
        else{
            return root;
        }
    }
};