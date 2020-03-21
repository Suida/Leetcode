/*
 * #42 --- 接雨水
 * 难度: 困难
 * -----------------------------------------------------------------------------
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图
 * 即, 以给定数组的索引为横坐标, 元素值为纵坐标做一柱状图, 示例如下:
 * `vector<int> height = { 1, 2, 0, 4, 3, 2, 5 }`
 *      |                             5
 *      |                 4         +---+
 *      |               +---+ 3     |   |
 *      |         2     |   |---+ 2 |   |
 *      |     1 +---+   |   |   |---|   |
 *      |   +---|   |   |   |   |   |   |
 *      |   |   |   | 0 |   |   |   |   |
 *      +-------------------------------------
 *            0   1   2   3   4   5   6
 * 想象有流水倒入柱间, 请写出算法计算柱间最多驻留多少水 (上例中最多驻留5单位水,
 * 索引2处驻留2单位, 4处1单位, 5处2单位)
 * -----------------------------------------------------------------------------
 * 复杂度O(n)   2020-03-21
 */
#include <vector>
using namespace std;

class Solution {
    public:
        int trap(vector<int>& height) {
            if (height.size() < 3) return 0;
            int ret = 0, h = 0;
            auto p = height.begin();
            for (auto it = p + 1; it < height.end(); ++it){
                if (*p <= *it) {
                    h = (*p <= *it)? *p: *it;
                    for (++p; p < it; ++p)
                        ret += h - *p;
                }
            }
            auto rp = height.rbegin();
            for (auto it = rp + 1; it < height.rend(); ++it){
                if (*rp < *it) {
                    h = (*rp <= *it)? *rp: *it;
                    for (++rp; rp < it; ++rp)
                        ret += h - *rp;
                }
            }
            return ret;
        }
};

