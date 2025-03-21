class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int ans = nums[0];
    int thismax = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] + thismax < 0) {
        thismax = 0;
        if (nums[i] > ans)
          ans = nums[i];
        continue;
      }
      thismax += nums[i];
      if (thismax > ans)
        ans = thismax;
    }
    return ans;
  }
};