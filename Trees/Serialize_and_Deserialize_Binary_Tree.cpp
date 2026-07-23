/*
Problem: Serialize and Deserialize Binary Tree
Platform: LeetCode (#297)
Topic: Trees, Binary Tree, BFS, Queue, Design

Approach:
- Use Level Order Traversal (BFS) to serialize the tree.
- Store each node's value separated by commas.
- Represent null nodes using '#'.
- During deserialization, split the serialized string.
- Reconstruct the tree level by level using a queue.
- Attach left and right children according to the serialized order.

Time Complexity: O(n)
Space Complexity: O(n)
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "";

        string s;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* cur = q.front();
            q.pop();

            if (cur == nullptr) {
                s += "#,";
            } else {
                s += to_string(cur->val) + ",";
                q.push(cur->left);
                q.push(cur->right);
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;

        stringstream ss(data);

        string str;
        getline(ss, str, ',');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if (!getline(ss, str, ','))
                break;

            if (str == "#")
                node->left = nullptr;
            else {
                TreeNode* left = new TreeNode(stoi(str));
                node->left = left;
                q.push(left);
            }

            if (!getline(ss, str, ','))
                break;

            if (str == "#")
                node->right = nullptr;
            else {
                TreeNode* right = new TreeNode(stoi(str));
                node->right = right;
                q.push(right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));