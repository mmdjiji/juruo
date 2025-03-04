// 思路：桶排
// 如果快排需要做剪枝优化
// 题解给的是双路快速排序 https://zhuanlan.zhihu.com/p/688702689
// 如果使用单路快排好像还是会超时

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    int bucket[20005] = {0}; // -10000 <= i <= 10000
    for (int i = 0; i < nums.size(); ++i) {
      ++bucket[nums[i] + 10000];
    }
    for (int i = 20001; i >= 0; --i) {
      if (bucket[i] > 0) {
        if (k > 0) {
          k -= bucket[i];
          if (k <= 0)
            return i - 10000;
        } else {
          return i - 10000;
        }
      }
    }
    return -1;
  }
};
