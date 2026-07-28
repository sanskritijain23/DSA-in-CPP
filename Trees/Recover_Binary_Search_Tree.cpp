/*
Problem: Recover Binary Search Tree
Platform: LeetCode (#99)
Topic: Binary Search Tree, Inorder Traversal, Recursion

Approach:
- Perform inorder traversal of the BST.
- In a valid BST, inorder traversal is strictly increasing.
- Detect positions where the current node value is smaller than
  the previous node value.
- For the first violation:
    - Store previous node as first.
    - Store current node as middle.
- For the second violation:
    - Store current node as last.
- If two violations occur, swap first and last.
- Otherwise, swap first and middle.

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
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
public:
    void recoverTree(TreeNode* root) {
       first=middle=last=nullptr;
       prev=new TreeNode(INT_MIN);
       inorder(root);
       if(first && last)    swap(first->val,last->val);
       else if(first && middle)    swap(first->val,middle->val);
    }
    void inorder(TreeNode* root){
        if(root==nullptr)    return;
        inorder(root->left);
        if(prev!=nullptr && (root->val<prev->val)){
            if(first==nullptr){
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
};