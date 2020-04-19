#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        long s_size = s.size(), t_size = t.size();
        vector<vector<long>> dp(t_size+1, vector<long>(s_size+1, 0));
        for (int i=0; i<s_size+1; ++i) dp[0][i] = 1;
        for (int i=1; i<t_size+1; ++i) {
            for (int j=1; j<s_size+1; ++j) {
                if (s[j-1] == t[i-1]) dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                else dp[i][j] = dp[i][j-1];
            }
        }
        return dp[t_size][s_size];
    }
};
