class Solution
{
public:
    int minSteps(string s, string t)
    {

        int mp1[26] = {0};
        int mp2[26] = {0};

        for (int i = 0; i < s.size(); i++)
        {
            int ch = s[i];
            int index = ch - 'a';
            mp1[index]++;
        }

        for (int i = 0; i < t.size(); i++)
        {
            int ch = t[i];
            int index = ch - 'a';
            mp2[index]++;
        }

        int minCount = 0;
        for (int i = 0; i < 26; i++)
        {

            if (mp1[i] < mp2[i])
            {

                minCount += mp2[i] - mp1[i];
            }
        }

        return minCount;
    }
};