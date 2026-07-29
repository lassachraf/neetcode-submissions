
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        if (nums.size() < 3)
            return result;

        sort(nums.begin(), nums.end());
        set<vector<int>> uniqueTriplets;

        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        uniqueTriplets.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        result.assign(uniqueTriplets.begin(), uniqueTriplets.end());

        return result;
    }
};