class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxLength = 0;
        unordered_set<char> substring;
        while (r < s.size()) {
            // char already in substring
            if (substring.count(s[r]) > 0) {
                while (substring.count(s[r]) > 0) {
                    substring.erase(s[l]);
                    l++;
                }
                substring.insert(s[r]);
            }
            // char not in substring
            else {
                substring.insert(s[r]);
            }
            maxLength = max(maxLength, r - l + 1);
            r++;
        }
        return maxLength;
    }
};
