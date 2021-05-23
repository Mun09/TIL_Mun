#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
int main(){
    int n; cin >> n;
    int A[1010]={};
    int Dp[1010]={};
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    int ans=0;
    for(int i=0; i<n; i++){
        int dp_max=0;
        for(int j=0; j<i; j++){
            if(A[j]<A[i]){
                dp_max=max(Dp[j],dp_max);
            }
        }
    Dp[i]=dp_max+A[i];
    ans=max(ans,Dp[i]);
    }

    cout << ans << endl;
    return 0;
}