#include <bits/stdc++.h>
using namespace std;

void swap (int* a, int* b){
    int* temp = b;
    b = a;
    a = temp;

}

int main (){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[3];

    cin >> arr[0] >> arr[1] >> arr[2];
    for (int i = 0 ; i<2 ; i++)
        for ( int j = 0 ; j<2;j++)
            {
                if(arr[j] >arr[j+1]) swap(arr[j],arr[j+1]);
            }

    cout << arr[0] << ' ' << arr[1] << ' ' << arr[2];
    return 0;
}