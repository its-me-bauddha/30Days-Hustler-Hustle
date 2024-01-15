#include <iostream>
#include <vector>
using namespace std;

int topDownSolve(int n, int *dp)
{
    // base case
    if (n == 1 || n == 0)
        return n;

    // STEP 3 :  Check ans if already exists
    if (dp[n] != -1)
        return dp[n];

    // STEP 2 : replace ans with dp[n]
    dp[n] = topDownSolve(n - 1, dp) + topDownSolve(n - 2, dp);
    return dp[n];
}
int fib(int n)
{

    // 2. top down approach (memoization)
    // STEP 1 : Create  DP array
    int dp[100] = {-1};
    int ans = topDownSolve(n, dp);
    return ans;
    // T.C = O(n)
    // S.C = O(n) + O(n)  -> dp array of size n and
    // O(n) ->  topdown takes extra space for call stack (recursive calls)
}
int main()
{

    int num;
    cout << "Enter the number" << endl;
    cin >> num;

    int ans = fib(num);
    cout << "The " << num << "th fibonacci number is : " << ans << endl;

    return 0;
}