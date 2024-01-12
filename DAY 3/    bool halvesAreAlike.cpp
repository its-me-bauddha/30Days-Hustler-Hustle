class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        int n = s.size();
        int mid = n / 2;

        int firstHalf = 0;
        int secondHalf = 0;

        for (int i = 0; i < mid; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                firstHalf++;
            }
        }
        for (int i = mid; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                secondHalf++;
            }
        }

        if (secondHalf == firstHalf)
            return true;
        else
            return false;
    }
};