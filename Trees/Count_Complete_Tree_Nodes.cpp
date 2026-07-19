/*
Problem: Count Complete Tree Nodes
Platform: LeetCode (#222)
Topic: Trees, Binary Tree, Complete Binary Tree

Approach:
- Compute the height of the leftmost path and the rightmost path.
- If both heights are equal, the subtree is a perfect binary tree.
- The number of nodes in a perfect binary tree is (2^height - 1).
- Otherwise, recursively count nodes in the left and right subtrees.
- Return the total count.

Time Complexity: O((log n)^2)
Space Complexity: O(log n)
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
    int countNodes(TreeNode* root) {
        if(root==NULL)    return 0;
        int lh=heightleft(root);
        int rh=heightright(root);
        if(lh==rh)    return(1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int heightleft(TreeNode* node){
        int hght=0;
        while(node){
            hght++;
            node=node->left;
        }
        return hght;
    }
    int heightright(TreeNode* node){
        int hght=0;
        while(node){
            hght++;
            node=node->right;
        }
        return hght;
    }
};