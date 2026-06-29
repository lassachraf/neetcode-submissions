class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;

        for (int i = 0; i < numbers.size(); i++) {
            auto index = find(numbers.begin() + i + 1, numbers.end(), target - numbers[i]);

            if (index != numbers.end()) {
                res.push_back(i + 1);
                res.push_back(index - numbers.begin() + 1);
                break;
            }
        }

        return res;
    }
};