#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <limits>
#define INF numeric_limits<float>::infinity()
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        map<vector<float>, int> lines;
        map<vector<float>, int>::iterator it;
        float k, b;
        for (int i=0; i<points.size(); ++i)
            for (int j=i+1; j<points.size(); ++j) {
                if (points[i] == points[j]) continue;
                k = ((float) points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
                k = (abs(k) == INF)? abs(k): k;
                b = (k == INF)
                    ? points[i][0]
                    : points[i][1] - k * points[i][0];
                if ((it=lines.find({k,b})) == lines.end()) lines.insert({{k, b}, 0});
            }
        for (auto p: points) {
            for (auto l=lines.begin(); l!=lines.end(); ++l) {
                if (l->first[0] == INF && l->first[1] == p[0]) l->second += 1, cout << l->second << endl;
                else if (abs(l->first[0] * p[0] + l->first[1] - p[1]) < 1e-4) l->second++;
            }
        }
        auto el = max_element(lines.begin(), lines.end(), [](
                    pair<vector<float>, int> a,
                    pair<vector<float>, int> b)
                { return a.second < b.second; });
        if (el == lines.end()) return points.size();
        return el->second;
    }
};

int main() {
    vector<vector<int>> v {{4,0},{4,-1},{4,5}};
    cout << Solution().maxPoints(v) << endl;
    /* vector<vector<int>> v {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}}; */
    /* cout << Solution().maxPoints(v) << endl; */
}
