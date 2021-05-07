#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

const int MAX = 1000000+5;
int arr[MAX]={0,};

void solve(){
    int n;
    cin >> n;

    string a;
    cin >> a;

    arr[0]=0;
    if(a[0]=='*'){arr[0]++;}
    for(int i=1; i<n; i++){
        arr[i]=0;
        if(a[i]=='*') 
        {arr[i]=arr[i-1]+1;}
        else{arr[i]=arr[i-1];}
    }

    int allnum=arr[n-1];
    int result=allnum/2+allnum%2;
    ll ans=0;
    int index, front = result-1;
    for(int i=0; i<n; i++){
        if(arr[i] == result){index=i; break;}
    }
    for(int i=0; i<n; i++){
        if(a[i]=='*'){
            ans+=(abs(index-i)-abs(front));
            front--;
        }
    }

    cout << ans << endl;

}
int main(){
    
    int t;
    cin >> t;

    while(t--){
        solve();
    }
    
}