#include <bits/stdc++.h>

using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int arr[9];
    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
    }

    int largest = arr[0];
    int index = 1;
    for (int i = 1; i < 9; i++)
    {
        if (largest < arr[i])
        {
            largest = arr[i];
            index = i+1;
        }
    }
    cout << largest << '\n' << index;

    return 0;
}