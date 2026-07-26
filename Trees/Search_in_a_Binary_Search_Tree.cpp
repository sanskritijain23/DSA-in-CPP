/*
Problem: Search in a Binary Search Tree
Platform: LeetCode (#700)
Topic: Binary Search Tree (BST), Trees

Approach:
- Traverse the BST iteratively starting from the root.
- If the current node's value matches the target, return the node.
- If the target is smaller, move to the left subtree.
- Otherwise, move to the right subtree.
- Continue until the node is found or the traversal reaches nullptr.

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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=nullptr && root->val!=val){
            root=val<root->val?root->left:root->right;
        }
        return root;
    }
};