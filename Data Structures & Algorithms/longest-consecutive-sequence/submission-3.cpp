class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

        int count = 1;
        int longestSeq = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == 1)
                count++;
            else {
                if (count > longestSeq)
                    longestSeq = count;
                count = 1;
            }
        }
        if (count > longestSeq)
            longestSeq = count;
        return longestSeq;
    }
};
