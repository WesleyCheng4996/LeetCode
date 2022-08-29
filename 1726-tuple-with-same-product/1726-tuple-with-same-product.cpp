int foo(std::vector<int> &nums) {
  std::vector<int> m;
  m.reserve(nums.size() * (nums.size() - 1) / 2 + 1);
  int rv = 0;

  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      auto n = nums[i] * nums[j];
      m.push_back(n);
    }
  }
  std::sort(m.begin(), m.end());
  m.push_back(-1);
  int prev = m[0];
  int count = 0;

  for (auto scan : m) {
    if (prev != scan) {
      rv += (count - 1) * count;
      count = 0;
    }
    prev = scan;
    count++;
  }
  return rv << 2;
}



class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        return foo(nums);
    }
};