#include <iostream>
#include <vector>
#include <string>
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
    return deleteWord(child, word.substr(1));
}

void storeSuggestion(TrieNode *curr, vector<string> &temp, string &prefix)
{
    // base case
    if (curr->isTerminal)
    {
        temp.push_back(prefix);
    }

    // A to Z tak choices
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        int index = ch - 'a';

        // yha par jane ki koshish
        TrieNode *next = curr->children[index];

        if (next != NULL)
        {
            // if child exits
            prefix.push_back(ch);
            // recursive call
            storeSuggestion(next, temp, prefix);

            // backtrack
            prefix.pop_back();
        }
    }
}
vector<vector<string>> getSuggestion(TrieNode *root, string input)
{
    // var , DS
    TrieNode *prev = root;
    vector<vector<string>> output;
    string prefix = "";
    for (int i = 0; i < input.length(); i++)
    {
        char lastChar = input[i];
        int index = lastChar - 'a';
        TrieNode *curr = prev->children[index];

        // the given word in not found
        if (curr == NULL)
        {
            break;
        }
        else
        {
            // ith word is found in the trie
            // make all the child from the curr node
            vector<string> temp; //! -> stores all the suggestions
            prefix.push_back(lastChar);
            storeSuggestion(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }
    }
    return output;
}
int main()
{

    vector<string> v;
    v.push_back("love");
    v.push_back("lover");
    v.push_back("loving");
    v.push_back("last");
    v.push_back("lost ");
    v.push_back("lane");
    v.push_back("lord");
    int size = v.size();
    string input = "lovi";

    TrieNode *root = new TrieNode('-');

    for (int i = 0; i < size; i++)
    {
        insertWord(root, v[i]);
    }

    vector<vector<string>> ans = getSuggestion(root, input);

    cout << "Printing the Answer ->>>>> " << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ,";
        }
        cout << endl;
    }

    return 0;
}