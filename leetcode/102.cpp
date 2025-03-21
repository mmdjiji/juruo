/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    vector<vector<int>> ans;
    if (root == nullptr)
      return ans;
    while (!q.empty()) {
      vector<int> lv;
      int qsz = q.size();
      for (int i = 0; i < qsz; ++i) {
        TreeNode *cur = q.front();
        q.pop();
        lv.push_back(cur->val);
        if (cur->left != nullptr)
          q.push(cur->left);
        if (cur->right != nullptr)
          q.push(cur->right);
      }
      ans.push_back(lv);
    }
    return ans;
  }
};