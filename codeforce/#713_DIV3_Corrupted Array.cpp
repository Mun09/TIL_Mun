#include <iostream>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        n+=2;
        int arr[300000], sum=0;
        for(int i=0; i<n; i++){cin >> arr[i]; sum+=arr[i];}

        sort(arr, arr+n);
        int i=-10,j=-11,t;
        if((float)(sum-arr[n-1])/(float)arr[n-2] == 2){i=n-1; j= n-2; t=-20;}
        else{t=n-2;}
        while(t>-1){
            if((float)(sum-arr[t])/(float)arr[n-1] == 2){i=t; t=-2;  j=n-1; break;}
            t--;
        }

        if(t==-1){cout << -1 << '\n';}
        else{
            for(int k=0; k<n; k++){
                if(k!=i && k!=j){cout << arr[k] << ' ';}
            }
            cout << '\n';
        }
    }
}