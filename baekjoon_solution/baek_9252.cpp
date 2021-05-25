#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int main(){
    string a,b; cin >> a >> b;
    int an=a.length(), bn=b.length();
    vector<vector<int>> dp(an+10, vector<int>(bn+10,0));
    vector<vector<string>> dp_string(an+10, vector<string>(bn+10,""));
    for(int i=1; i<=an; i++){
        for(int j=1; j<=bn; j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=max(dp[i-1][j-1]+1, dp[i][j-1]);
                dp_string[i][j]=dp[i-1][j-1]+1>dp[i][j-1]?dp_string[i-1][j-1]+a[i-1]:dp_string[i][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                dp_string[i][j]=dp[i-1][j]>dp[i][j-1]?dp_string[i-1][j]:dp_string[i][j-1];
            }
        }
    }
    cout << dp[an][bn] << endl;
    if(dp_string[an][bn].length()){
    cout << dp_string[an][bn] << endl;
    }
    return 0;
}