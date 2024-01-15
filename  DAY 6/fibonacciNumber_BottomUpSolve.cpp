#include <iostream>
#include <vector>
using namespace std;

int bottomUpSolve(int n)
{

    // STEP 1 : create DP array
    int dp[100];

    // STEP 2 : Observe base case in above solution
    dp[0] = 0;
    dp[1] = 1;

    // STEP 3 :
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
int fib(int n)
{

    // 3. bottom up approach
    // T.C = O(n)
    // S.C = O(n) Better than top down approach
    // because it topdown takes extra space for call stack (recursive calls)
    int ans = bottomUpSolve(n);
    return ans;
}
int main()
{

    int num;
    cout << "Enter the number" << endl;
    cin >> num;

    int ans = fib(num);
    cout << "The " << num << "th fibonacci number is : " << ans << endl;
}