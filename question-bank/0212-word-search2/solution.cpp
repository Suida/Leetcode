/*
 * #212 --- Word Search II
 * Difficulty: High
 * -----------------------------------------------------------------------------
 * Given a 2-dimensional character array and a word array, find all the words
 * which appear in both the arrays.
 *
 * In character array, the words have to be composed with adjacent characters
 * with the exact order. 'Adjacent' means both horizontally neighboring and
 * vertically neighboring.
 * ----------------------------------
 * Example:
 * Input: 
 *      words = ["oath","pea","eat","rain"],
 *      board = 
 *          [
 *              ['o','a','a','n'],
 *              ['e','t','a','e'],
 *              ['i','h','k','r'],
 *              ['i','f','l','v']
 *          ]
 * Output: ["eat","oath"]
 * Explanation: 
 * Assume all characters are lowercase.
 * -----------------------------------------------------------------------------
 * Leetcode Rank:
 *      Speed:   23.11%
 *      Mem:     38.75%
 * -----------------------------------------------------------------------------
 * O(n!)         2020-03-26
 */
#include <iostream>
#include <vector>
#include <string>
#include "../0208-implement-trie/solution.h"
using namespace std;

class Solution {
private:
    bool** seen;
    vector<vector<char>> _board;
    string word;
    vector<string> res;
    Trie t;
    int xl;
    int yl;
public:
    void backtrace(int x, int y) {
        if (!(0<=x && x<xl && 0<=y && y<yl)) return;
        if (seen[x][y]) return;
        word.push_back(_board[x][y]);
        if (t.search(word)) {
            bool found = false;
            for (auto s: res)
                if (s==word) found = true;
            if (!found) res.push_back(word);
        }
        if (t.startsWith(word)) {
            seen[x][y] = true;
            backtrace(x-1, y);
            backtrace(x, y-1);
            backtrace(x+1, y);
            backtrace(x, y+1);
            seen[x][y] = false;
        }
        word.pop_back();
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty()) return res;
        this->_board = board;
        for (auto s: words)
            t.insert(s);
        xl = board.size();
        yl = board[0].size();
        seen = new bool*[xl];
        for (int x=0; x<xl; ++x) {
            seen[x] = new bool[yl];
            for (int y=0; y<yl; ++y)
                seen[x][y] = false;
        }
        for (int x=0; x<xl; ++x)
            for (int y=0; y<yl; ++y) backtrace(x, y);
        return res;
    }
};

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

