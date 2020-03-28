#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int arr[7];
    int sum = 0;
    for (int i = 0; i < 7; i++)
    {
        cin >> arr[i];

        if (arr[i] % 2 != 0)
        {
            sum += arr[i];
        }
    }
    int smallest, first=1;
    for (int i = 0; i < 7; i++)
    {
        
        if (arr[i] % 2 != 0 && first)
        {
            smallest = arr[i];
            first = 0;
        }
            
        if (smallest > arr[i] && arr[i] % 2 != 0 && !first)
            smallest = arr[i];
    }
    if (sum) cout << sum << '\n' << smallest;
    else cout << -1;
    return 0;
}