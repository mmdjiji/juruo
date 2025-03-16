// 思路：先排序，然后固定一个数，双指针找另外两个数，注意去重
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0)
        break;
      int l = i + 1, r = n - 1;
      while (l < r) {
        if (nums[i] + nums[l] + nums[r] == 0) {
          ans.push_back({nums[i], nums[l], nums[r]});
          ++l;
          --r;
          while (l < r && nums[l] == nums[l - 1])
            ++l;
          while (l < r && nums[r] == nums[r + 1])
            --r;
        } else if (nums[l] + nums[r] < -nums[i])
          ++l;
        else
          --r;
      }
      while (i + 1 < n && nums[i + 1] == nums[i])
        ++i;
    }
    return ans;
  }
};