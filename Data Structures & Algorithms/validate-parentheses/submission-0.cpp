class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        unordered_map<char,char> match;
        match[']'] = '[';
        match['}'] = '{';
        match[')'] = '(';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                open.push(s[i]);
            }
            else {
                if (open.empty()) {
                    return false;
                }
                if (match[s[i]] != open.top()) {
                    return false;
                }
                open.pop();
            }
        }
        if (!open.empty()) {
            return false;
        }
        return true;

    }
};
