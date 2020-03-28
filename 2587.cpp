#include <bits/stdc++.h>
#define SWAP(x,y,t) ((t) = (x), (x) = (y) , (y) = (t))

using namespace std;
void quickSort(int arr[],int left,int right)
{
    int i,j;
    int s,t;

    if(left<right){
        s= arr[left];
        i = left;
        j = right + 1;
        while(1)
        {
            while((i<right) && (arr[++i] < s));
            while((j>left) && (arr[--j] > s));
            
            if (i >= j) break;
            SWAP(arr[i],arr[j],t);

        }
        SWAP(arr[left],arr[j],t);
        quickSort(arr,left,j-1);
        quickSort(arr,j+1,right);   

    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[5];
    int sum=0;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    quickSort(arr ,0 , 4);

    cout << sum/5 << '\n' << arr[2];

    return 0;
}