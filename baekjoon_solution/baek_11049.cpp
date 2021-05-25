#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int main(){
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    vector<vector<int>> dp(n+10, vector<int>(n+10,0));
    for(int i=0; i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    for(int i=n-1; i>=0; i--){
        for(int j=i+1; j<=n-1; j++){
            int dp_min=int(1e9+10);
            for(int k=1;k<=j-i;k++)
                dp_min=min(dp_min,dp[i][j-k]+dp[j-k+1][j]+v[i].first*v[j-k].second*v[j].second); 
            dp[i][j]=dp_min;
        }
        
    }
    cout << dp[0][n-1] << endl;
    return 0;

}