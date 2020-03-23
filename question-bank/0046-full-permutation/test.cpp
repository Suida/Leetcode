#include <vector>
#include <iostream>
#include "full_permutation.h"
using namespace std;

void printResult(vector<vector<int>> v);

int main() {
    auto v = vector<int>({1});
    printResult(Solution().permute(v));
    v = vector<int>({1, 2, 3});
    printResult(Solution().permute(v));
    v = vector<int>({1, 2, 3, 4});
    printResult(Solution().permute(v));
}

void printResult(vector<vector<int>> vv) {
    cout << "[" << endl;
    for (auto v: vv) {
        cout << "\t[ ";
        for (auto e: v)
            cout << e << " ";
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

