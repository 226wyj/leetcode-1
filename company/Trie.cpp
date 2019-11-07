/*
 * Trie.cpp
 * Copyright (C) 2019 Haoyang <peter@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <algorithm>
#include <iostream>
#include <vector>
#define w(word, i) (word[i] - 'a')
using namespace std;
struct TrieNode {
    TrieNode* next[26];
    bool is_word;
    TrieNode(bool b = false)
        : is_word(b)
    {
        memset(next, 0, sizeof(next));
    }
};

class Trie {
public:
    Trie() { root = new TrieNode(); }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); ++i) {
            if (p->next[w(word, i)] == NULL)
                p->next[w(word, i)] = new TrieNode();
            p = p->next[w(word, i)];
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode* p = find(word);
        return p != NULL && p->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) { return find(prefix) != NULL; }

private:
    TrieNode* root;
    TrieNode* find(string key)
    {
        TrieNode* p = root;
        for (int i = 0; i < key.size() && p != NULL; ++i) {
            p = p->next[key[i] - 'a'];
        }
        return p;
    }
};

int main(int argc, char* argv[])
{
    string word = "test";
    Trie* obj = new Trie();
    obj->insert(word);
    /* bool param_3 = obj->search(word); */
    /* bool param_3 = obj->startsWith(prefix); */
    return 0;
}
