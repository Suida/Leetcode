#include <cassert>
#include "solution.h"
using namespace std;

int main() {
    Trie t;
    t.insert("string");
    t.insert("strxng");
    assert(t.search("string"));
    assert(!t.search("str"));
    assert(t.startsWith("str"));
    assert(!t.search("ssr"));

    assert(t.search("strxng"));
    assert(!t.search("strx"));

    Trie tt;
    tt.insert("apple");
    assert(tt.search("apple"));
    assert(!tt.search("app"));
    assert(tt.startsWith("app"));
    tt.insert("app");
    assert(tt.search("app"));
}
