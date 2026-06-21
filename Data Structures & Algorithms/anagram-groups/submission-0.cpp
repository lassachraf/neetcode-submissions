class Solution {
public:
    bool    areAnagram(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;

        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());

        return s1 == s2;
    } 
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> grp;
        vector<string> tmp = strs;
        vector<vector<string>> ret;
        vector<int> pushed(tmp.size(), 0);

        for (int i = 0; i < tmp.size(); i++) {
            if (pushed[i] == 1)
                continue;
            pushed[i] = 1;
            grp.push_back(tmp[i]);
            for (int j = i + 1; j < tmp.size(); j++) {
                if (pushed[j] != 1 && areAnagram(tmp[i], tmp[j])) {
                    pushed[j] = 1;
                    grp.push_back(tmp[j]);
                }
            }
            ret.push_back(grp);
            grp.clear();
        }

        return ret;
    }
};
