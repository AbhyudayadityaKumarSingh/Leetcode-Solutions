class Solution {
public:
    set<char> allowed = {'a', 'b', 'c'};

    bool isHappy(string str) {
        for (int i = 0; i < str.size() - 1; i++) {
            if (str[i] == str[i + 1] || allowed.find(str[i]) == allowed.end()) return false;
        }
        return true;
    }

    void solve(int n, vector<string>& ans, string& temp) {
        if (temp.size() == n) {
            if (isHappy(temp)) {
                ans.push_back(temp);
            }
            return;
        }
        for (char ch : allowed) {
            if (temp.empty() || temp.back() != ch) {
                temp.push_back(ch);
                solve(n, ans, temp);
                temp.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> ans;
        string temp;
        solve(n, ans, temp);

        sort(ans.begin(), ans.end());
        if (ans.size() < k) return "";
        return ans[k - 1];
    }
};