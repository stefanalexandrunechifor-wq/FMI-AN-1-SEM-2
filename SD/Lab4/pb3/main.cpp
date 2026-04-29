
// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    void inorder(TreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        if (prev != nullptr && prev->val > node->val) {
            if (first == nullptr) {
                first = prev;
            }
            second = node;
        }
        prev = node;
        inorder(node->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        if (first != nullptr && second != nullptr) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};