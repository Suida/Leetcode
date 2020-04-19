#include <iostream>
#include <vector>
#include <map>
#define INT_MAX 0x7fffffff
using namespace std;

class Solution {
public:
    long long int conv(int x) { return (long long int)INT_MAX - x; }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int l, r, h;
        map<long long int, int> dp;
        dp[conv(-1)] = 0;
        decltype(dp.end()) f1, f2, cur;
        for (auto const& item: buildings) {
            l = item[0]; r = item[1]; h = item[2];
            f1 = dp.lower_bound(conv(l));
            f2 = dp.lower_bound(conv(r));
            if (f2->second<h){
                dp[conv(r)] = f2->second;
                f2 = dp.find(conv(r));
            }
            if (f1->second<h) {
                dp[conv(l)] = h;
                f1 = dp.find(conv(l));
            }
            cur = f1;
            while (f1!=f2 && --cur!=f2) {
                // `f1->second >= h`
                if (cur->second <= f1->second) {
                    if (f1->second == h) {
                        cur = dp.erase(cur);
                    }
                    else {
                        cur->second = h;
                    }
                }
                f1 = cur;
            }
        }
        dp.erase(conv(-1));
        vector<vector<int>> res;
        for (auto it=dp.rbegin(); it!=dp.rend(); it++) {
            res.push_back({(int) conv(it->first), it->second});
        }
        return res;
    }
};

void test(vector<vector<int>>& c) {
    Solution s {};
    auto res = s.getSkyline(c);
    for (auto p: res) cout << "{" << p[0] << ", " << p[1] << "} ";
    cout << endl;
    return;
}

int main() {
    vector<vector<int>> case1 = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    test(case1);
    vector<vector<int>> case2 = {{0,2,3},{2,5,3}};
    test(case2);
    vector<vector<int>> case3 = {{0,3,3},{1,5,3},{2,4,3},{3,7,3}};
    test(case3);
    vector<vector<int>> case4 = {{3,7,8},{3,8,7},{3,9,6},{3,10,5},{3,11,4},{3,12,3},{3,13,2},{3,14,1}};
    test(case4);
    return 0;
}
