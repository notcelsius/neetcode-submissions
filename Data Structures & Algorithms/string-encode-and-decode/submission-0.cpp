class Solution {
public:

    string encode(vector<string>& strs) {
        string code = "";
        for (string& s: strs) {
            code += to_string(s.size());
            code += "#";
            code += s;
        }
        return code;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;
            int length = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, length));
            i = j + 1 + length;   // jump exactly past this string
        }
        return res;
    }
};
