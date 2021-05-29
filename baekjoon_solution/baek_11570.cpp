#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
const ll MAX=3*1e9;
int arr[2010];
ll dp[2010][2010];
int main(){
    int n; cin >> n;
    for(int i=1; i<=n; i++){cin >> arr[i];}

    for(int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
            dp[i][j]=MAX;
            if(i==j+1) {
                dp[i][j]=dp[j][0];
                for(int k=1; k<j; k++) 
                    dp[i][j]=min(dp[i][j],dp[j][k]+abs(arr[i]-arr[k]));
            }
            if(i>j+1){dp[i][j]=min(dp[i][j],dp[i-1][j]+abs(arr[i]-arr[i-1]));}
            if(j>1){dp[i][j]=min(dp[i][j],dp[i][j-1]+abs(arr[j]-arr[j-1]));}
        }
    }
    ll ans=MAX;
    for(int i=0; i<n; i++){
        ans=min(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}