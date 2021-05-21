#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
const int inf =int(1e9);
int main(){
    int n;
    cin >> n;
    vector<int> a(n), pos;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]){pos.push_back(i);}
    }
    int k=pos.size();
    vector<vector<int>> dp(n+1,vector<int>(k+1,inf));
    dp[0][0]=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=k; j++){
            if(dp[i][j]==inf) continue;
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            if(j<k &&!a[i]){
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+abs(pos[j]-i));
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}
