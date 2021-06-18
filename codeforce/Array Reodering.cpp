#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v)
        cin >> i;
    int ans=0;
    sort(v.begin(), v.end(), [](int x, int y){return x%2 < y%2;});
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ans += __gcd(v[i], v[j]*2) > 1;
        }
    }
    cout << ans << endl;
}
int main(){
    int n;
    cin >> n;
    while(n--)
        solve();
    return 0;
}