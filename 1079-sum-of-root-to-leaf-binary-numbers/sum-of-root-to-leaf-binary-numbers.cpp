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
    void dfs(TreeNode* node, int current, int &sum) {
        if(node == nullptr)
            return;

        current = current * 2 + node->val;

        if(node->left == nullptr && node->right == nullptr) {
            sum += current;
            return;
        }

        dfs(node->left, current, sum);
        dfs(node->right, current, sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
};
