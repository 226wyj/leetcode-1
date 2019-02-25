struct Node {
    unordered_map<char, Node*> next;
    bool flag;
};
class Trie {
    private: Node* root;
    public:
             /** Initialize your data structure here. */
             Trie() {
                root = new Node();
             }

             /** Inserts a word into the trie. */
             void insert(string word) {
                Node* p = root;
                for (char c : word) {
                    // does not have any children yet, create one
                    if ((p -> next).count(c) == 0) {
                        (p -> next).insert(make_pair(c, new Node()));
                    }
                    p = (p -> next)[c];
                }
                p -> flag = true;
             }

             /** Returns if the word is in the trie. */
             bool search(string word) {
                Node* p = root;
                for (char c : word) {
                    if ((p -> next).count(c) == 0)
                        return false;
                    p = (p -> next)[c];
                }
                return p -> flag;
             }

             /** Returns if there is any word in the trie that starts with the given prefix. */
             bool startsWith(string prefix) {
                Node* p = root;
                for (char c : prefix) {
                    if ((p -> next).count(c) == 0) return false;
                    p = (p -> next)[c];
                }
                return true;

             }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
