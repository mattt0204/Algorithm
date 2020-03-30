#include <iostream>
#include <bits/stdc++.h>

int main()
{
    int n = 756580036;

    for (int i = 1; i * i < n; i++)
    {
        if (i * i == n)
        {
            return 1;
        }
    }
    return 0;
}
// 루트 n의 시간복잡도