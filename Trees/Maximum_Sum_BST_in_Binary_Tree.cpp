/*
Problem: Maximum Sum BST in Binary Tree
Platform: LeetCode (#1373)
Topic: Binary Tree, Binary Search Tree, Postorder Traversal, Tree DP

Approach:
- Use postorder traversal so that information from the left and right
  subtrees is available before processing the current node.
- For every subtree, return:
    1. Minimum value in the subtree.
    2. Maximum value in the subtree.
    3. Sum of all nodes in the subtree.
- A subtree rooted at the current node is a BST if:
      left.maxNode < root->val < right.minNode
- If it is a valid BST:
    - Calculate its total sum.
    - Update the maximum BST sum.
    - Return updated min, max and sum.
- If it is not a BST, return invalid boundary values so that
  its parent cannot consider it as a valid BST.

Time Complexity: O(n)
Space Complexity: O(h)

where h is the height of the tree.
*/


class NodeValue {
public:
    int minNode;
    int maxNode;
    int sum;

    NodeValue(int minNode, int maxNode, int sum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

class Solution {
private:
    int maxSum = 0;

    NodeValue helper(TreeNode* root) {
        if (root == nullptr) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        NodeValue left = helper(root->left);
        NodeValue right = helper(root->right);

        if (left.maxNode < root->val && root->val < right.minNode) {
            int currentSum = left.sum + right.sum + root->val;

            maxSum = max(maxSum, currentSum);

            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currentSum
            );
        }

        return NodeValue(INT_MIN, INT_MAX, 0);
    }

public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};