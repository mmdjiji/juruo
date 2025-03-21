class Solution {
public:
  void quicksort(vector<int> &s, int l, int r) {
    if (l < r) {
      int i = l, j = r, x = s[rand() % (r - l + 1) + l]; // 随机化选择基准值
      while (i <= j) {
        while (s[i] < x)
          i++;
        while (s[j] > x)
          j--;
        if (i <= j) {
          swap(s[i], s[j]); // 交换元素
          i++;
          j--;
        }
      }
      quicksort(s, l, j); // 递归排序左半部分
      quicksort(s, i, r); // 递归排序右半部分
    }
  }
  vector<int> sortArray(vector<int> &nums) {
    quicksort(nums, 0, nums.size() - 1);
    return nums;
  }
};