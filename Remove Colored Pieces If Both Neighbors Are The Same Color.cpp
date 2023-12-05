class Solution {
public:
  bool winnerOfGame(string colors) {
    int nums[2] = {};
    char color = colors.front();
    int count = 0;
    for(auto c : colors) {
      if(c == color) {
        count += 1;
      } else {
        nums[color - 'A'] += max(0, count - 2);
        color = c;
        count = 1;
      }
    }
    nums[color - 'A'] += max(0, count - 2);
    return nums[0] > nums[1];
  }
};