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
 *      Speed:   82.83%
 *      Mem:     69.38%
 * -----------------------------------------------------------------------------
 * O(n!)         2020-03-26
 */
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution {
private:
    struct Trie {
        string word;
        Trie* next[26];
        Trie(): word("") { memset(next, 0, sizeof(next)); }
    };
    vector<vector<char>> _board;
    vector<string> res;
    int xl;
    int yl;
public:
    void backtrace(int x, int y, Trie* t) {
        char c = _board[x][y];
        if (c=='#' || t->next[c-'a']==nullptr) return;
        Trie* next = t->next[c-'a'];
        if (next->word != "") {
            res.push_back(next->word);
            next->word = "";
        }
        _board[x][y] = '#';
        if (0<x) backtrace(x-1, y, next);
        if (0<y) backtrace(x, y-1, next);
        if (x<xl-1) backtrace(x+1, y, next);
        if (y<yl-1) backtrace(x, y+1, next);
        _board[x][y] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty()) return res;
        this->_board = board;
        Trie* t = buildTrie(words);
        xl = board.size();
        yl = board[0].size();
        for (int x=0; x<xl; ++x)
            for (int y=0; y<yl; ++y) backtrace(x, y, t);
        return res;
    }
    
    Trie* buildTrie(vector<string>& words) {
        Trie* res = new Trie;
        for (string s: words) {
            Trie* t = res;
            for (char c: s) {
                if (!t->next[c-'a']) t->next[c-'a'] = new Trie;
                t = t->next[c-'a'];
            }
            t->word = s;
        }
        return res;
    }
};

