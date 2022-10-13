#include <bits/stdc++.h>
using namespace std;
 
// Function to return
// gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int main()
{
    int a = 10, b = 15;
      // Function call
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b)
         << endl;
    return 0;
}
