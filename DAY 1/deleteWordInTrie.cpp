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
    // cout << "Inserting -> " << word << endl;
    //  base case
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

bool searchWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    // present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // not present
        return false;
    }

    // recursive call
    return searchWord(child, word.substr(1));
}
TrieNode *deleteWord(TrieNode *root, string word)
{ // base case
    if (word.size() == 0)
    {
        root->isTerminal = false;
        return root;
    }

    int index = word[0] - 'a';
    TrieNode *child;
    // word is  present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    { // not present
        return root;
    }

    // recursive call
    return  deleteWord(child, word.substr(1));
}
int main()
{

    // creation
    TrieNode *root = new TrieNode('-');
    // root->insertWord("coding");

    // insertion of words
    insertWord(root, "coding");
    insertWord(root, "code");
    insertWord(root, "codehelp");
    insertWord(root, "coder");
    insertWord(root, "baba");
    insertWord(root, "baby");
    insertWord(root, "babu");

    // search word function call
    string word = "coding";
    cout << "Before Deletion  => "
         << " ";
    cout << word << " is ->  ";
    if (searchWord(root, word))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }

    //! delete a word
    TrieNode *deletedNode = deleteWord(root, "coding");
    cout << "deleted word is -> " << deletedNode->data << endl;
    // searching the word after deletion

    // search word function call
    cout << "After Deletion => "
         << " ";

    cout << word << " is ->  ";
    if (searchWord(root, "coding"))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }

    return 0;
}