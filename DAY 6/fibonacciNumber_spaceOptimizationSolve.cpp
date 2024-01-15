#include <iostream>
#include <vector>
using namespace std;

int spaceOptimizationSolve(int n)
{
    // STEP 1 : make two variables
    int prev1 = 0;
    int prev2 = 1;

    if (n == 0)
        return prev1;
    if (n == 1)
        return prev2;

    // STEP 2:
    int curr;
    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        // shifting
        prev1 = prev2;
        prev2 = curr;
    }

    return curr;
}
int fib(int n)
{

    // 4. space optimization
    int ans = spaceOptimizationSolve(n);
    return ans;
    // T.C = O(n)
    // S.C = O(1)
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