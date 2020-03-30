#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
private:
    string S;
    set<string> D;
    vector<string> res;
public:
    void traceback(vector<int>& spc, string& lst, int i) {
        if (i == S.size()) return;
        lst += S[i++];
        traceback(spc, lst, i);
        if (D.find(lst) != D.end()) {
            spc.push_back(i-1);
            string old = lst; lst = "";
            if (i != S.size()) traceback(spc, lst, i);
            else res.push_back(buildRes(spc));
            lst = old;
            spc.pop_back();
        }
        lst.pop_back();
    }

    string buildRes(vector<int> const& spc) {
        int i = 0;
        string s = "";
        for (auto j=1; j<spc.size(); ++j) {
            s += string(S, i, spc[j]-i+1);
            s += ' ';
            i = spc[j]+1;
        }
        s = string(s, 0, s.size()-1);
        return s;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        S = s; D = set<string>(wordDict.begin(), wordDict.end());
        vector<int> spc {0}; string lst = "";
        traceback(spc, lst, 0);
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
