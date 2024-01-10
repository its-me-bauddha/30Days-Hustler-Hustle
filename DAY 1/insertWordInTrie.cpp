#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char d)
    {
        this->data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insertWord(TrieNode *root, string word)
{
    cout << "Inserting -> " << word << endl;
    // base case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    // pick out the index
    char ch = word[0];
    int index = ch - 'a';

    TrieNode *child;

    // node (char) is already present

    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // node (char) is not present
        // create the (char) node
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recursive call for the remaining string

    insertWord(child, word.substr(1));
}
int main()
{
    TrieNode *root = new TrieNode('-');
    // root->insertWord("coding");

    insertWord(root, "coding");
    return 0;
}