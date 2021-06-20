#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
const int N=3e5+2;
int arr[N];
int want(int x){return max(0, arr[x]-arr[x-1]);}
void solve(){
    int n, q;
    cin >> n >> q;
    long long ans=0;
    for(int i=0; i<n; i++){cin >> arr[i+1]; ans+=want(i+1);}
    arr[n+1]=0;
    cout << ans << endl;
    while(q--){
        int x,y; cin >> x >> y;
        ans-=want(x)+want(x+1)+(x<y)*want(y+1)+(x+1<y)*want(y);
        swap(arr[x],arr[y]);
        ans+=want(x)+want(x+1)+(x<y)*want(y+1)+(x+1<y)*want(y);
        cout << ans << endl;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}