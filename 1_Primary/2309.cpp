#include <bits/stdc++.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

using namespace std;
void quickSort(int arr[], int left, int right)
{
    int i, j;
    int s, t;

    if (left < right)
    {
        s = arr[left];
        i = left;
        j = right + 1;
        while (1)
        {
            while ((i < right) && (arr[++i] < s))
                ;
            while ((j > left) && (arr[--j] > s))
                ;

            if (i >= j)
                break;
            SWAP(arr[i], arr[j], t);
        }
        SWAP(arr[left], arr[j], t);
        quickSort(arr, left, j - 1);
        quickSort(arr, j + 1, right);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int arr[9];
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    quickSort(arr, 0, 8);
    int test = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (sum - arr[i] - arr[j] == 100)
            {
                for (int k = 0; k < 9; k++)
                {
                    if (k == i || k == j)
                        continue;
                    else
                        cout << arr[k] << '\n';
                        
                }
                test = 1;
                break;
            }
        }
        if(test) break;
    }
    return 0;
}