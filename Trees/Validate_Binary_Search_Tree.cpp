/*
Problem: Validate Binary Search Tree
Platform: LeetCode (#98)
Topic: Binary Search Tree, Trees, Recursion

Approach:
- Use recursion with a valid range for every node.
- Initially every value must lie between LLONG_MIN and LLONG_MAX.
- For the left subtree, update the upper bound to current node value.
- For the right subtree, update the lower bound to current node value.
- If any node violates its range, the tree is not a valid BST.

Time Complexity: O(n)
Space Complexity: O(h)

where h is the height of the tree.
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
    bool isValidBST(TreeNode* root) {
        return check(root,LLONG_MIN,LLONG_MAX);
    }
    bool check(TreeNode* root, long long low, long long high){
            if(root==nullptr){
                return true;
            }
            if(root->val<=low || root->val>=high){
                return false;
            }
            return check(root->left,low,root->val)&& check(root->right,root->val,high);
        }
};