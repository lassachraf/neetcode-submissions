class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> seen;

        for (int num : nums)
            seen[num]++;

        vector<pair<int, int>> vec(seen.begin(), seen.end());

        sort(vec.begin(), vec.end(),
             [](const auto& a, const auto& b) {
                 return a.second > b.second;
             });

        vector<int> ret;
        for (auto it = vec.begin(); it != vec.end() && k > 0; ++it, --k) {
            ret.push_back(it->first);
        }

        return ret;
    }
};