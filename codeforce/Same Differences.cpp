#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

void solve(){
    int n;
    cin >> n;

    ll ans=0;
    vector<ll> v(n+5);
    vector<ll> v2(2*n+5);
    for(int i=1; i<=n; i++){
        cin >> v[i];
        v[i]-=i;
        if(v[i]<0){
            v2[-v[i]+n]++;
        }
        else{
        v2[v[i]]++;
        }
    }

    for(int i=0; i<=2*n+3; i++){
        if(v2[i]>1){ans+=v2[i]*(v2[i]-1)/2;}
    }

    cout << ans << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){solve();}
}