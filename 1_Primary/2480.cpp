#include <bits/stdc++.h>
#define ARRAYSIZE(A) sizeof(A)/sizeof((A)[0])

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];

    if ( arr[0] == arr[1] && arr[1] == arr[2]) cout << 10000+arr[0]*1000;

    else if ( arr[0] == arr[1] && arr[0] != arr[2]) cout << 1000+arr[0]*100;

    
    else if ( arr[0] == arr[2] && arr[0] != arr[1]) cout << 1000+arr[0]*100;


    else if ( arr[2] == arr[1] && arr[0] != arr[2]) cout << 1000+arr[1]*100;

    else 
   {
       int largest = arr[0];
       for (int i=1 ; i<3; i++)
       {
           if( largest < arr[i]){
               largest = arr[i];
           }
       }
       cout << largest * 100;
}
    return 0;
}