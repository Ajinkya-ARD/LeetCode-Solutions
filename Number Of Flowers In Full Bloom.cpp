class Solution {
public:
    std::vector<int> fullBloomFlowers(std::vector<std::vector<int>>& flowers,
                                      std::vector<int>& persons) {
        std::vector<int> ans;
        std::vector<int> starts;
        std::vector<int> ends;

        for (const std::vector<int>& flower : flowers) {
            starts.push_back(flower[0]);
            ends.push_back(flower[1]);
        }

        std::sort(starts.begin(), starts.end());
        std::sort(ends.begin(), ends.end());

        for (const int p : persons) {
            const int started = std::upper_bound(starts.begin(), starts.end(), p) - starts.begin();
            const int ended = std::lower_bound(ends.begin(), ends.end(), p) - ends.begin();
            ans.push_back(started - ended);
        }

        return ans;
    }
};