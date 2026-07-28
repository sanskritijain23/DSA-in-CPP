/*
Problem: Two Sum IV - Input is a BST
Platform: LeetCode (#653)
Topic: Binary Search Tree, Two Pointers, Stack, Iterator

Approach:
- Create two BST iterators:
    1. Forward iterator for ascending inorder traversal.
    2. Reverse iterator for descending inorder traversal.
- Initialize one pointer with the smallest value and the other
  with the largest value.
- Apply the two-pointer technique:
    - If their sum equals k, return true.
    - If the sum is smaller than k, move the forward iterator.
    - Otherwise, move the reverse iterator.
- Stop when the two pointers meet or cross.

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
class bstiterator{
    stack<TreeNode*> mystack;
    bool reverse=true;
public:
    bstiterator(TreeNode* root, bool isreverse){
        reverse=isreverse;
        pushall(root);
    }
    bool hasnext(){
        return !mystack.empty();
    }
    int next(){
        TreeNode* tmpnode=mystack.top();
        mystack.pop();
        if(!reverse) pushall(tmpnode->right);
        else pushall(tmpnode->left);
        return tmpnode->val;
    }
private:
    void pushall(TreeNode* node){
        for(;node!=nullptr;){
            mystack.push(node);
            if(reverse==true){
                node=node->right;
            }
            else{
                node=node->left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)    return false;
            bstiterator l(root,false);
            bstiterator r(root,true);
            int i=l.next();
            int j=r.next();
            while(i<j){
                if(i+j==k)    return true;
                else if(i+j<k)    i=l.next();
                else    j=r.next();
            }
            return false;
    }
};