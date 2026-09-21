class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }
        unordered_map<char, int> count_t;
        
        int formed = 0;
        unordered_map<char, int> window;
        int start = 0;
        int length = s.size() + 1;
        for (char c: t) {
            count_t[c]++;
        }
        int required = count_t.size();
        int l = 0;
        int r = 0;
        while (r < s.size()) {
            window[s[r]]++;
            if (count_t.contains(s[r]) && window[s[r]] == count_t[s[r]]) {
                formed++;
            }
            while (formed == required) {
                if (r - l + 1 < length) {
                    start = l;
                    length = r - l + 1;
                }
                window[s[l]]--;
                if (count_t.contains(s[l]) && window[s[l]] < count_t[s[l]]) {
                    formed--;
                }
                l++;
            }
            r++;  
        }
        if (length > s.size()) {
            return "";
        }
        return s.substr(start, length);
        
    }
};
