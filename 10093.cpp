#include <bits/stdc++.h>

using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    unsigned long long a, b;
    cin >> a >> b;
    if (a < b)
    {
        cout << b - a - 1 << '\n';
        for (unsigned long long i = a + 1; i < b; i++)
            cout << i << ' ';
    }
    else if ( b < a)
    {
        cout << a - b - 1 << '\n';
        for (unsigned long long i = b + 1; i < a; i++)
            cout << i << ' ';
    }
    else cout << 0 << '\n';


    return 0;
}