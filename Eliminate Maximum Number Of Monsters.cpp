class Solution {
 public:
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    const int n = dist.size();
    vector<int> arrivalTime(n);

    // Calculate arrival times
    for (int i = 0; i < n; ++i)
      arrivalTime[i] = (dist[i] - 1) / speed[i];

    // Sort arrival times
    sort(begin(arrivalTime), end(arrivalTime));

    // Check if the weapon can be used before a monster arrives
    for (int i = 0; i < n; ++i)
      if (i > arrivalTime[i])
        return i;

    // All monsters can be eliminated
    return n;
  }
};