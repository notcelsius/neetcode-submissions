class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> count1(26,0);
        vector<int> count2(26,0);
        for (char c: s1) {
            count1[c - 'a']++;
        }
        int l = 0;
        int r = 0;
        while (r < s1.size()) {
            count2[s2[r] - 'a']++;
            r++;
        }
        if (count1 == count2) {
            return true;
        }
        r = s1.size();
        while (r < s2.size()) {
            count2[s2[r] - 'a']++;
            count2[s2[l] - 'a']--;
            l++;
            r++;
            if (count1 == count2) {
                return true;
            }
        }
        return false;
        
        
    }
};
