/*
Problem: Binary Search Tree Iterator
Platform: LeetCode (#173)
Topic: Binary Search Tree (BST), Stack, Inorder Traversal

Approach:
- Simulate inorder traversal using a stack.
- Initially push all left nodes from the root.
- next():
    - Pop the top node.
    - Push all left nodes from its right subtree.
    - Return the popped node's value.
- hasNext():
    - Return whether the stack is empty.

Time Complexity:
- Constructor: O(h)
- next(): Amortized O(1)
- hasNext(): O(1)

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
class BSTIterator {
private: stack<TreeNode*> mystack;
	public:
		BSTIterator(TreeNode* root){
			pushAll(root);
		}
		
		bool hasNext(){
			return !mystack.empty();
		}
		
		int next(){
            TreeNode* tmpnode=mystack.top();
            mystack.pop();
            pushAll(tmpnode->right);
            return tmpnode->val;
		}
    private:
        void pushAll(TreeNode* node){
            for(;node!=nullptr;mystack.push(node),node=node->left);
        }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */