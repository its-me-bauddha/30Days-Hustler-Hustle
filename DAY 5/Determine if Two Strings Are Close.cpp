class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        vector<int> arr1(26);
        vector<int> arr2(26);
        if (word1.size() != word2.size())
            return false;
        for (int i = 0; i < word1.size(); i++)
        {
            int index1 = word1[i] - 'a';
            int index2 = word2[i] - 'a';
            arr1[index1]++;
            arr2[index2]++;
        }
        // presence of char in word1 & word2
        for (int i = 0; i < 26; i++)
        {
            if (arr1[i] != 0 && arr2[i] != 0)
                continue;
            if (arr1[i] == 0 && arr2[i] == 0)
                continue;

            return false;
        }

        // check freq
        sort(begin(arr1), end(arr1));
        sort(begin(arr2), end(arr2));
        return arr1 == arr2;
    }
};