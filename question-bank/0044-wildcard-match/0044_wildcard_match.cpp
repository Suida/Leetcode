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
 *      非贪婪匹配。
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
            int i = 0, j = 0;
            while (i < s.size() && j < p.size()) {
                if (p[j] == '?' || s[i] == p[j]) {
                    ++i; ++j;
                } else if (p[j] == '*') {
                    if (j == p.size()-1) return true;
                    /* cout << (s[i] == p[j+1]) << endl; */
                    (p[j+1] == '?' || s[i] == p[j+1])? ++j: ++i;
                    /* if (s[i] != p[j+1]) */ 
                    /*     ++i; */
                    /* else */
                    /*     ++j; */
                } else {
                    return false;
                }
                /* cout << "i = " << i << "; j = " << j << endl; */
            }
            return i == s.size() && j == p.size();
        }
};

int main() {
    Solution s;
    cout << s.isMatch("aaaa", "*") << endl;
    cout << s.isMatch("aaaa", "a*aaa") << endl;
    cout << s.isMatch("aaa", "a*?a") << endl;
    cout << s.isMatch("aaaa", "*b") << endl;
}

