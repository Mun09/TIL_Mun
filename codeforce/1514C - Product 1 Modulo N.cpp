#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n';
using namespace std;
int arr[100005];
int main(){

    int n;
    cin >> n;
    
    ll except = 1;

    for(int i=1 ;i<=n-1; i++){
        if(__gcd(n, i)==1){
            arr[i]=1;
            except = (except*i)%n;
        }
    }

    if(except!=1){arr[except]=0;}

    cout << count(arr+1, arr+n, 1) << endl;
    for(int j=1; j<=n-1; j++){
        if(arr[j]){
            cout << j << ' ';
        }
    }
}