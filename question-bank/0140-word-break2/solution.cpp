#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

struct Trie {
    bool isEnd;
    Trie** next;
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int m = s.size();
        Trie* root = &buildTrie(wordDict), *cur;
        vector<vector<string>> dp;
        for (int i=0; i<m+1; ++i) {
            dp.push_back(vector<string> {});
        }
        dp[0].push_back("");
        for (int i=0; i<m; ++i) {
            if (dp[i].empty()) continue;
            cur = root;
            for (int j=i; j<m+1; ++j) {
                if (cur->isEnd) {
                    dp[j].push_back(s.substr(i, j-i));
                }
                if (cur->next[s[j]-'a'] && j != m) {
                    cur = cur->next[s[j]-'a'];
                    continue;
                }
                break;
            }
        }
        return dfs(dp, m);
    }

    vector<string> dfs(vector<vector<string>> const& dp, int i) {
        vector<string> res;
        int j;
        for (auto& w: dp[i]) {
            j = i - w.size();
            if (j == 0) {
                res.push_back(w);
                continue;
            }
            for (auto sfx: dfs(dp, j)) {
                res.push_back(sfx + " " + w);
            }
        }
        return res;
    }

    Trie& buildTrie(vector<string> const& words) {
        Trie* root = new Trie, *cur;
        root->isEnd = false;
        root->next = new Trie*[26] { nullptr };
        for (auto& w: words) {
            cur = root;
            for (auto c: w) {
                if (cur->next[c-'a'] == nullptr) {
                    cur->next[c-'a'] = new Trie;
                    cur->next[c-'a']->isEnd = false;
                    cur->next[c-'a']->next = new Trie*[26] { nullptr };
                }
                cur = cur->next[c-'a'];
            }
            cur->isEnd = true;
        }
        return *root;
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
