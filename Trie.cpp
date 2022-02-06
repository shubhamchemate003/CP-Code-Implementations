#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
    struct node {
        node* next[26];
        int countOfWordsEndingHere;
        int countOfPrefixes;
        node() {
            countOfWordsEndingHere = 0;
            countOfPrefixes = 0;
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
    };
    node* root;

public:
    Trie() {
        root = new node();
    }

    void insert(string word) {
        node* it = root;
        int i = 0;
        while (i < word.size()) {
            if (it->next[word[i] - 'a'] == NULL)
                it->next[word[i] - 'a'] = new node();
            it->countOfPrefixes++;
            it = it->next[word[i] - 'a'];
            i++;
        }
        it->countOfPrefixes++;
        it->countOfWordsEndingHere++;
    }

    void deleteLinks(string word) {
        node* it = root;
        int i = 0;
        while (i < word.size()) {
            node* next = it->next[word[i] - 'a'];
            if (next->countOfPrefixes == 0)
                it->next[word[i] - 'a'] = NULL;

            if (it->countOfPrefixes == 0 and it != NULL)
                delete it;

            it = next;
            i++;
        }

        if (it->countOfPrefixes == 0)
            delete it;
    }

    void deleteWord(string word) {
        if (countWordsEqualTo(word) == 0)
            return;

        node* it = root;
        int i = 0;
        while (i < word.size()) {
            if (it->next[word[i] - 'a'] == NULL)
                return;
            it->countOfPrefixes--;
            it = it->next[word[i] - 'a'];
            i++;
        }

        it->countOfPrefixes--;
        it->countOfWordsEndingHere--;

        deleteLinks(word);
    }

    int countWordsEqualTo(string word) {
        node* it = root;
        int i = 0;
        while (i < word.size()) {
            if (it->next[word[i] - 'a'] == NULL)
                return false;
            it = it->next[word[i] - 'a'];
            i++;
        }
        return it->countOfWordsEndingHere;
    }

    int countWordsStartingWith(string prefix) {
        node* it = root;
        int i = 0;
        while (i < prefix.size()) {
            if (it->next[prefix[i] - 'a'] == NULL)
                return 0;
            it = it->next[prefix[i] - 'a'];
            i++;
        }
        return it->countOfPrefixes;
    }

    int countTotalWords() {
        return root->countOfPrefixes;
    }
};

int main() {
    freopen("../input1.txt", "r", stdin);
    freopen("../output1.txt", "w", stdout);

    Trie* t = new Trie();

    vector<string> words = {"app", "apple", "apple", "banana", "app"};

    for (string word : words)
        t->insert(word);

    cout << t->countWordsStartingWith("app") << '\n';
    t->deleteWord("app");
    t->deleteWord("apple");
    t->deleteWord("apple");
    t->deleteWord("app");
    cout << t->countWordsStartingWith("app") << '\n';

    cout << t->countTotalWords() << '\n';

    return 0;
}