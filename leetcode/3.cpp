// 思路：滑动窗口
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    if (s.length() == 0)
      return 0;
    int head = 0, tail = 0;
    int ans = 0;
    ++map[s[0]];
    while (tail < s.length() - 1) {

      ++tail;
      ++map[s[tail]];
      while (map[s[tail]] > 1) {
        --map[s[head]];
        ++head;
      }

      if (tail - head > ans)
        ans = tail - head;
    }
    return ans + 1;
  }
};