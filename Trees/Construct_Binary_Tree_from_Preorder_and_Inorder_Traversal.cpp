/*
Problem: Construct Binary Tree from Preorder and Inorder Traversal
Platform: LeetCode (#105)
Topic: Trees, Binary Tree, Recursion, Divide and Conquer

Approach:
- Store the index of each node in the inorder traversal using a map.
- The first element in the preorder traversal is the root.
- Find the root's position in the inorder traversal.
- The elements on the left form the left subtree, and the elements on the right form the right subtree.
- Recursively construct the left and right subtrees using the calculated ranges.
- Return the root of the constructed binary tree.

Time Complexity: O(n)
Space Complexity: O(n)
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;

        }
        TreeNode* root=buildTree1(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);
        return root;
    }
    TreeNode* buildTree1(vector<int> &preorder,int prestart, int preend,vector<int>& inorder,int instart,int inend,map<int,int> &inmap){
        if(prestart>preend || instart>inend)   return NULL;
        TreeNode* root=new TreeNode(preorder[prestart]);
        int inroot=inmap[root->val];
        int numsleft=inroot-instart;
        root->left=buildTree1(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,inmap);
        root->right=buildTree1(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,inmap);
        return root;
    }
};