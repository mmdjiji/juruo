// 思路：双端队列，01状态机，每层是一个状态
// 实现状态：每次用!q.empty()判断队列非空后，一口气把队列全部遍历，这样结束的时候状态转换
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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (!root)
      return ans;
    deque<TreeNode *> q;
    q.push_back(root);
    bool flag = true;
    while (!q.empty()) {
      int n = q.size();
      vector<int> the;
      for (int i = 0; i < n; ++i) {
        TreeNode *cur;
        if (flag) { // lr
          cur = q.back();
          q.pop_back();
          if (cur->left)
            q.push_front(cur->left);
          if (cur->right)
            q.push_front(cur->right);
        } else { // rl
          cur = q.front();
          q.pop_front();
          if (cur->right)
            q.push_back(cur->right);
          if (cur->left)
            q.push_back(cur->left);
        }
        the.push_back(cur->val);
      }
      ans.push_back(the);
      flag = !flag;
    }
    return ans;
  }
};