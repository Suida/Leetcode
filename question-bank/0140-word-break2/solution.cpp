#include <vector>
#include <string>
#include <set>
#include <utility>
#include <iostream>
#include <cstdio>
using namespace std;

struct Trie {
    bool isEnd;
    Trie** next;
};

class Solution {
public:
    Trie& buildTrie(vector<string> const& wordDict) {
        Trie* root = new Trie, *tmp;
        root->isEnd = true;
        root->next = new Trie*[26] {};
        for (auto& w: wordDict) {
            tmp = root;
            for (auto c: w) {
                if (tmp->next[c-'a'] == nullptr) {
                    tmp->next[c-'a'] = new Trie;
                    tmp->next[c-'a']->isEnd = false;
                    tmp->next[c-'a']->next = new Trie*[26] {};
                }
                tmp = tmp->next[c-'a'];
            }
            tmp->isEnd = true;
        }
        return *root;
    }

    bool hasWord(string w, Trie& r) {
        Trie* tmp = &r;
        for (auto c: w) {
            if (tmp->next[c-'a'] == nullptr) return false;
            tmp = tmp->next[c-'a'];
        }
        return tmp->isEnd;
    }

    bool startsWith(string w, Trie& r) {
        Trie* tmp = &r;
        for (auto c: w) {
            if (tmp->next[c-'a'] == nullptr) return false;
            tmp = tmp->next[c-'a'];
        }
        return true;
    }
   
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string lst; int slen;
        pair<string, int> tu; 
        auto dp = new vector<decltype(tu)>[s.size()+1] {};
        dp[0].push_back({"", 0});
        Trie& words = buildTrie(wordDict);
        for (int i=1; i<s.size()+1; ++i) {
            /* dp[i] = vector<pair<string, int>>(); */
            for (int j=0; j<dp[i-1].size(); ++j) {
                tu = dp[i-1][j];
                slen = tu.first.size();
                lst = tu.first.substr(tu.second, slen-tu.second)+s[i-1];
                if (hasWord(lst, words)) {
                    dp[i].push_back({tu.first+s[i-1]+' ', slen+2});
                }
                if (startsWith(lst, words)) {
                    dp[i].push_back({tu.first+s[i-1], tu.second});
                }
            }
        }
        vector<string> res;
        for (auto tuu: dp[s.size()]) {
            slen = tuu.first.size();
            if (tuu.second == slen) {
                res.push_back(tuu.first.substr(0, tuu.first.size()-1));
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
