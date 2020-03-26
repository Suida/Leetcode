#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    vector<string> words = {"oath","pea","eat","rain"};
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    for (auto s: Solution().findWords(board, words))
        cout << s << endl;
}

