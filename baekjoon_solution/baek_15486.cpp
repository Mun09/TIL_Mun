#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int dp[1500010];
int main(){
    int n,ans=0; cin >> n;
    vector<pair<int,int>> v(n+10);
    for(int i=1; i<n+1; i++){cin >> v[i].first >> v[i].second;}
    for(int i=1; i<=n; i++){
        int idex=i+v[i].first;
        dp[i]=max(dp[i-1],dp[i]);
        if(idex<=n+1){
            dp[idex]=max(dp[idex],dp[i]+v[i].second);
        }
        ans=max(ans, dp[i]);
    }
    ans=max(ans,dp[n+1]);
    
    cout << ans << endl;
    return 0;
}