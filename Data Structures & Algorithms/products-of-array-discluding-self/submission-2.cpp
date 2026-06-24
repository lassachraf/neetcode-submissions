class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j)
                    continue ;
                product *= nums[j];
            }
            result.push_back(product);
            product = 1;
        }

        return result;
    }
};
