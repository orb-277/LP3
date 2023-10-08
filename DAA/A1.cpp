#include <bits/stdc++.h>
using namespace std;
 
int fib(int n)
{
    int a = 0, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int fibrec(int n)
{
    if (n <= 1)
        return n;
    return fibrec(n - 1) + fibrec(n - 2);
}
 
// Driver code
int main()
{
    int n = 9;
 
    cout << fib(n) << endl;
    cout << fibrec(n) << endl; 
    return 0;
}