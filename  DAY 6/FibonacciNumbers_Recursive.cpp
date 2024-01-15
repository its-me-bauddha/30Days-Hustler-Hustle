#include <iostream>
using namespace std;

int Fib_Recursive(int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return n;
    }

    // recursive call
    return Fib_Recursive(n - 1) + Fib_Recursive(n - 2);

    // T.C = O(2^n) -> exponential time complexity
    // S.C = O(n)
}
int main()
{

    int num;
    cout << "Enter the number" << endl;
    cin >> num;

    int ans = Fib_Recursive(num);
    cout << "The " << num << "th fibonacci number is : " << ans << endl;
}