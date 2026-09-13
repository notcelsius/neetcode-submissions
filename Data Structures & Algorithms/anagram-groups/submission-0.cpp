class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (string& s : strs) {
            string key = stringKey(s);
            groups[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& [key,bucket] : groups) {
            result.push_back(bucket);
        }
        return result;
    }

    string stringKey(string& s) {
        vector<int> count(26,0);
        string key = "";
        for (char c:s) {
            count[c-'a']++;
        }
        for (int n: count) {
            key += "#";
            key += to_string(n);
        }
        return key;
    }
};
