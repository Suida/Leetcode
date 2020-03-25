/*
 * #208 --- Trie
 * Difficulty: Medium
 * -----------------------------------------------------------------------------
 * Implement a @Tire with 3 methods:
 *      void insert(string word);
 *      bool search(string word);
 *      bool startsWith(string const& prefix);
 * -----------------------------------------------------------------------------
 * Leetcode Rank:
 *      Speed:   39.56%     
 *      Mem:     79.35%
 *      (The codes with better rank in leetcode are totally the same, the 
 *      difference may be from testing error.)
 * -----------------------------------------------------------------------------
 * Insert: O(n)
 * Search: O(m)
 * 2020-03-25
 */
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Trie {
public:
    // On g++ (7.5.0) & ubuntu (18.04), `next = new Trie*[26]` is ok,
    // but in leetcode's environment, there is an UB error.
    // So `memset` is chosen on leetcode: 
    // ```
    //      // Definition of `next`
    //      Trie* next[26];
    //      // Initialization of `next` in constructor
    //      memset(next, 0, sizeof(next))
    // ```
    Trie() { next = new Trie*[26]; } 
    ~Trie() {
        for (int i=0; i<26; ++i) {
            if (!next[i]) continue;
            delete next[i];
        }
    }
    void insert(string const& w) {
        Trie* t = this;
        for (auto const c: w) {
            int i = c - 'a';
            if (!t->next[i]) t->next[i] = new Trie();
            t = t->next[i];
        }
        t->isEnd = true;
    }

    bool search(string const& w) {
        Trie* t = this;
        for (auto const c: w)
            if (!(t = t->next[c-'a'])) return false;
        return t->isEnd;
    }

    bool startsWith(string const& prefix) {
        Trie* t = this;
        for (auto const c: prefix)
            if (!(t = t->next[c-'a'])) return false;
        return true;
    }

private:
    bool isEnd = false;
    Trie** next;
};
