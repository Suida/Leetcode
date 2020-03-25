#include <iostream>
#include "solution.h"
using namespace std;

void printResult(vector<int> v) {
    for (auto i: v)
        cout << i << " ";
    cout << endl;
    return;
}

int main() {
    vector<int> v = {1, 2, 3, -1, -1, 4, 5, 6, 7, 8};
    printResult(Solution().maxSlidingWindow(v, 3));
    return 0;
}
