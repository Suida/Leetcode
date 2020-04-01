#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
public:
    bool starts_with(string s, string p) {
        for (int i=0; i<p.size(); ++i) {
            if (i == s.size()) return false;
            if (s[i] != p[i]) return false;
        }
        return true;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int m = s.size(), n = wordDict.size();
        int** dp = new int*[m+1] {};
        for (int i=0; i<m+1; ++i) dp[i] = new int[n] {};
        dp[0][0] = 1;
        string w, sfx;
        // 看起来是 O(n*m*m), 实际上是 O(n*m)
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (dp[i][j] == 0) continue;
                for (int k=0; k<n; ++k) {
                    w = wordDict[k];
                    sfx = s.substr(i);
                    if (starts_with(sfx, w)) {
                        dp[i+w.size()][k] = 1;
                    }
                }
                j = n;
            }
        }
        return dfs(dp, m, n, wordDict);
    }

    vector<string> dfs(int** dp, int i, int n, vector<string> const& words) {
        if (i == 0) return {""};
        vector<string> res;
        for (int j=0; j<n; ++j) {
            if (dp[i][j] == 0) continue;
            for (auto s: dfs(dp, i-words[j].size(), n, words)) {
                s = (s == "")? words[j]: s + " " + words[j];
                res.push_back(s);
            }
        }
        return res;
    }
};

int main() {
    string s, w;
    cin >> s;
    vector<string> d;
    char c = getchar();
    while ((c = getchar()) != '\n') {
        if (c == ' ') d.push_back(w), w = "";
        else w.push_back(c);
    }
    d.push_back(w);
    cout << "String: " << s << endl << "Words:" << endl;
    for (auto w: d) cout << "--" << w << endl;
    for (auto str: Solution().wordBreak(s, d))
        cout << str << endl;
    return 0;
}
