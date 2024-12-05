class Trie {
public:
    Trie* children[26];
    bool endofword;
    Trie() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        endofword = false;
    }

    void insert(string word) {
        Trie* curr = this;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i]-'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new Trie();
            }
            if (i == word.length() - 1) {
                curr->children[idx]->endofword = true;
            }
            curr = curr->children[idx];
        }
    }

    bool search(string word) {
        Trie* curr = this;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i]-'a';
            if (curr->children[idx] == NULL) {
                return false;
            }
            if (i == word.length() - 1  &&
                curr->children[idx]->endofword == true) {
                return true;
            }
            curr=curr->children[idx];
        }
        return false;
    }

    bool startsWith(string prefix) {
        Trie* curr = this;
        for (int i = 0; i < prefix.length(); i++) {
            int idx = prefix[i] - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }
};
  static Trie* root = new Trie();
