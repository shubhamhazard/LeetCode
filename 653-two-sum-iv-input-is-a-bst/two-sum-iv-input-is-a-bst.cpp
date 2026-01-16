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
    void inorder(TreeNode* root, vector<int> &inorderVal)
    {
        if(root == NULL)
            return;
        inorder(root->left, inorderVal);
        inorderVal.push_back(root->val);
        inorder(root->right, inorderVal);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderVal;
        inorder(root,inorderVal);

        int s = 0;
        int l = inorderVal.size()-1;

        while(s<l)
        {
            int sum = inorderVal[s] + inorderVal[l];
            if(sum == k)
                return true;
            else if(sum > k)
                l--;
            else
                s++;
        }

        return false;
    }
};