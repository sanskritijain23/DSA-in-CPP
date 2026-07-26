/*
Problem: Construct Binary Search Tree from Preorder Traversal
Platform: LeetCode (#1008)
Topic: Binary Search Tree, Trees, Recursion

Approach:
- Traverse preorder array using a shared index.
- Use an upper bound to decide whether the current value belongs to the subtree.
- Create the current node.
- Recursively build:
    1. Left subtree with bound = current node value.
    2. Right subtree with the previous bound.

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
    }
    TreeNode* build(vector<int>& a, int& i,int bound){
        if(i==a.size() || a[i]>bound)    return nullptr;
        TreeNode* root=new TreeNode(a[i++]);
        root->left=build(a,i,root->val);
        root->right=build(a,i,bound);
        return root;
    }
};