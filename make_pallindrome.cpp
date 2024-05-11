
class Solution {
public:
    void create_z(string &str, int n, vector<int> &Z) {
        int l = 0, r = 0;
        for (int i = 1; i < n; ++i) {
            if (i > r) {
                l = r = i;
                while (r < n && str[r] == str[r - l]) ++r;
                Z[i] = r - l;
                --r;
            } else {
                int k = i - l;
                if (Z[k] < r - i + 1) Z[i] = Z[k];
                else {
                    l = i;
                    while (r < n && str[r] == str[r - l]) ++r;
                    Z[i] = r - l;
                    --r;
                }
            }
        }
    }
    
    string shortestPalindrome(string text) {
        string pattern = text;
        reverse(pattern.begin(), pattern.end());
        string str = text + "#" + pattern;

        vector<int> Z(str.size());
        create_z(str, str.size(), Z);

        int maxlen = 0;
        for (int i = text.size() + 1; i < str.size(); ++i) {
            if (Z[i] >= text.size() - (i - text.size() - 1)) {
                maxlen = Z[i];
                break;  // you need the first full match
            }
        }

        string prefix = pattern.substr(0, text.size() - maxlen);
        return prefix + text;
    }
};
