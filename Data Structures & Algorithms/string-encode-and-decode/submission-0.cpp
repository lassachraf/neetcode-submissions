class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for (int i = 0; i < strs.size(); i++) {
            encoded += to_string(strs[i].size()) + "#" + strs[i]; 
        }
        cout << "Encoded: " << encoded << endl;
        return encoded; 
    }

    // vector<string> decode(string s) {
    //     int length = -1;
    //     string sub = "";
    //     int findHashTag = -1;
    //     vector<string> decoded;

    //     int i = 0;
    //     while (i < s.length()) {
    //         findHashTag = s.find("#");
    //         length = stoi(s.substr(i, findHashTag));
    //         sub = s.substr(findHashTag + 1, length);
    //         i = findHashTag + length;
    //         decoded.push_back(sub);
    //     }

    //     return decoded;
    // }

    vector<string> decode(string s) {
    int i = 0;
    vector<string> decoded;

    while (i < s.length()) {
        int j = i;
        
        while (s[j] != '#')
            j++;

        int length = stoi(s.substr(i, j - i));
        string sub = s.substr(j + 1, length);
        decoded.push_back(sub);
        i = j + 1 + length;
    }

    return decoded;
}
};
