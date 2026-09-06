class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char,int> numOfChars;
        for (char c: s) {
            numOfChars[c]++;
        }
        for (char c: t) {
            numOfChars[c]--;
            if (numOfChars[c] < 0) {
                return false;
            }
        }
        return true;
    }
};
