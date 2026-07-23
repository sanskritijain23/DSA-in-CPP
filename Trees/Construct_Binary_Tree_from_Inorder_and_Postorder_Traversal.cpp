/*
Problem: Construct Binary Tree from Inorder and Postorder Traversal
Platform: LeetCode (#106)
Topic: Trees, Binary Tree, Recursion, Divide and Conquer

Approach:
- Store the index of each node in the inorder traversal using a map.
- The last element in the postorder traversal is the root.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())
            return nullptr;
        map<int,int> hm;
        for(int i=0;i<inorder.size();++i)
            hm[inorder[i]]=i;
        return buildtreepostin(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,hm);
    }
    TreeNode* buildtreepostin(vector<int>& inorder,int is, int ie, vector<int>& postorder,int ps,int pe, map<int,int>& hm){
        if(ps>pe || is>ie)    return nullptr;
        TreeNode* root=new TreeNode(postorder[pe]);
        int inroot=hm[postorder[pe]];
        int numsleft=inroot-is;
        root->left=buildtreepostin(inorder, is, inroot-1, postorder, ps, ps+numsleft-1,hm);
        root->right=buildtreepostin(inorder, inroot+1, ie, postorder, ps+numsleft, pe-1,hm);
        return root;
    }
};