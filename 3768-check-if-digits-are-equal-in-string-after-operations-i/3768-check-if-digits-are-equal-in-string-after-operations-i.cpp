class Solution {
public:
    bool hasSameDigits(string s) {
         while (s.length() > 2) {
        string new_s;
        for (int i = 0; i < s.length() - 1; ++i) {
            int sum = (s[i] - '0') + (s[i+1] - '0');
            new_s += to_string(sum % 10);
        }
        s = new_s;
    }
    return s[0] == s[1];
    }
};