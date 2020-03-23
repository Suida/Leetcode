/*
 * #44 --- 通配符匹配
 * 难度: 困难
 * -----------------------------------------------------------------------------
 * 给定一个字符串(s)和一个字符模式(p), 实现一个支持'？'和'*'的通配符匹配。
 * 两个字符串完全匹配才算匹配成功。
 *      '?' 可以匹配任何单个字符。
 *      '*' 可以匹配任意字符串（包括空字符串）。
 *  说明:
 *      s可能为空，且只包含从a-z的小写字母。
 *      p可能为空，且只包含从a-z的小写字母，以及字符?和*。
 *      贪婪匹配。
 * ----------------------------------
 * 示例 1:
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * ----------------------------------
 * 示例 2:
 * 输入:
 * s = "aa"
 * p = "*"
 * 输出: true
 * 解释: '*' 可以匹配任意字符串。
 * -----------------------------------------------------------------------------
 * 复杂度O(n)   2020-03-23
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            int n = s.size();
            int m = p.size();

            bool** dp = new bool*[n+1];
            for (int i = 0; i < n+1; ++i)
                dp[i] = new bool[m+1];

            for (int i = 0; i <= n; ++i)
                for (int j = 0; j <= m; ++j)
                    dp[i][j] = false;
            
            dp[0][0] = true;
            for (int j = 1; j <= m; ++j)
                dp[0][j] = dp[0][j-1] && p[j-1] == '*';

            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j) {
                    if (s[i-1] == p[j-1] || p[j-1] == '?')
                        dp[i][j] = dp[i-1][j-1];
                    else if (p[j-1] == '*')
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    else
                        dp[i][j] = false;
                }

            return dp[n][m];
        }
};

int main() {
    Solution s;
    cout << s.isMatch("aaaa", "*") << endl;
    cout << s.isMatch("a", "a*") << endl;
    cout << s.isMatch("a", "aa*") << endl;
    cout << s.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba",
            "a*******b") << endl;
    cout << s.isMatch("aaaa", "a*aaa") << endl;
    cout << s.isMatch("aaa", "a*?a") << endl;
    cout << s.isMatch("aaaa", "*a") << endl;
}

