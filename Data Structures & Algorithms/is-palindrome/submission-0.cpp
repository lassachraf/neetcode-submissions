class Solution {
public:
    bool isPalindrome(string s) {
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        string org = s;
        reverse(s.begin(), s.end());

        for (int i = 0, j = 0; i < org.length() && j < s.length(); i++, j++) {
            if (isalnum(org[i]) && isalnum(s[j])) {
                if (org[i] != s[j])
                    return false;
            }
            else if (isalnum(org[i]))
                i--;
            else
                j--;
        }

        return true;
    }
};
