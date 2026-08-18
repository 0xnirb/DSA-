class Solution {
public:

    vector<string> ans;

    void solve(string &s, int index, int parts, string current) {

        // We have created 4 parts
        if (parts == 4) {
            if (index == s.size()) {
                current.pop_back();   // remove last '.'
                ans.push_back(current);
            }
            return;
        }

        // Try taking 1, 2, or 3 digits
        for (int len = 1; len <= 3; len++) {

            // Not enough characters
            if (index + len > s.size())
                break;

            string part = s.substr(index, len);

            // Leading zero
            if (part.size() > 1 && part[0] == '0')
                continue;

            // Convert string to number
            int value = stoi(part);

            // Must be <= 255
            if (value > 255)
                continue;

            // Choose
            solve(s, index + len, parts + 1,
                  current + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {

        solve(s, 0, 0, "");

        return ans;
    }
};