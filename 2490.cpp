#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int a, b, c, d;
    int arr[3] = {
        0,
    };
    for (int i = 0; i < 3; i++)
    {
        cin >> a >> b >> c >> d;
        arr[i] = a + b + c + d;
        if (arr[i] == 4)
            cout << 'E' << '\n';
        else if (arr[i] == 3)
            cout << 'A' << '\n';
        else if (arr[i] == 2)
            cout << 'B' << '\n';
        else if (arr[i] == 1)
            cout << 'C' << '\n';
        else
            cout << 'D' << '\n';
    }

    return 0;
}