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
 * 复杂度O(n)   2020-03-21
 */
#include <string>
using namespace std;

class Solution {
    public:
        string multiply(string num1, string num2) {
            int i = 0, j = 0;
            for (auto it = num1.begin(); it < num1.end(); ++it)
                i = i * 10 + (int) *it - 48;
            for (auto it = num2.begin(); it < num2.end(); ++it)
                j = j * 10 + (int) *it - 48;
            i *= j;
            if (i == 0) return "0";
            string stk;
            while (0 < i) {
                stk.push_back((char) (i % 10 + 48));
                i /= 10;
            }
            string ret = string(stk.rbegin(), stk.rend());
            return ret;
        }
};

