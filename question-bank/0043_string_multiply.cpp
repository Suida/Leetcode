/*
 * #43 --- 字符串相乘
 * 难度: 中等
 * -----------------------------------------------------------------------------
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2
 * 的乘积，它们的乘积也表示为字符串形式。
 * ----------------------------------
 * 示例 1:
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * ----------------------------------
 * 示例2:
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * -----------------------------------------------------------------------------
 * 复杂度O(n*m)   2020-03-22
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        string add(string const& b, string const& a, int i=0);
        string multi(string const& b, char a);
        string multiply(string num1, string num2) {
            reverse(num1.begin(), num1.end());
            reverse(num2.begin(), num2.end());
            vector<string> stk;
            for (char c: num2)
                stk.push_back(multi(num1, c));
            string res;
            for (int i = 0; i < stk.size(); ++i)
                res = add(res, stk[i], i);
            if (all_of(res.begin(), res.end(), [](char c) {return c=='0';}))
                return "0";
            reverse(res.begin(), res.end());
            return res;
        };
};

string Solution::add(string const& b, string const& a, int i) {
    string res(b, 0, i); int m, n = 0;
    for (int j = 0; j < a.size(); ++j, ++i) {
        char c = (i < b.size())? b[i]: '0';
        m = (c - 48) + (a[j] - 48) + n;
        res.push_back((char) (m % 10 + 48));
        n = m / 10;
    }
    if (0 < n)
        res.push_back((char) (n + 48));
    return res;
}

string Solution::multi(string const& b, char a) {
    string res; int m, n = 0;
    for (auto c: b) {
        m = (int) ((c - 48) * (a - 48) + n);
        res.push_back((char) (m % 10 + 48));
        n = m / 10;
    }
    if (0 < n)
        res.push_back((char) (n + 48));
    return res;
}

int main() {
    Solution s;
    cout << s.add("13579", "02468", 0) << endl;
    cout << s.add("1", "02468", 2) << endl;
    cout << s.multi("1009", '5') << endl;
    cout << s.multiply("1009", "1234") << endl;
    cout << s.multiply("00", "0") << endl;
    return 0;
}

