#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

vector<int> v(1010);
int main(){
    int n;
    int ans=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    vector<int> dp(1010,1);
    for(int i=0; i<n; i++){
        int dp_max=0;
        for(int j=0; j<i; j++){
            if(v[i]<v[j])
                dp_max=max(dp[j],dp_max);
        }
        dp[i]=dp_max+1;
        ans=max(dp[i],ans);
    }
    cout << ans << endl;
    return 0;
}