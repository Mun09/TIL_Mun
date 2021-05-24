#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

void solve(){
    int siz; cin >> siz;
    vector<int> v(siz);
    for(auto &i:v)
        cin >> i;
    vector<vector<int>> dp1(siz+1,vector<int>(siz+1,0)), dp2(siz+1,vector<int>(siz+1,0));
    for(int i=0; i<siz; i++){
        dp1[i][i]=v[i];
    }
    for(int i=siz-1; i>=0; i--){
        for(int j=i+1; j<siz; j++){
            int dp_min=int(1e9+10);
            for(int k=1; k<=j-i; k++)
                dp_min=min(dp1[i][j-k]+dp1[j+1-k][j],dp_min);
            dp1[i][j]=dp_min;    
        }
    }
    for(int i=siz-1; i>=0; i--){
        for(int j=i+1; j<siz; j++){
            int dp_min=int(1e9+10);
            for(int k=1; k<=j-i; k++)
                dp_min=min(dp1[i][j-k]+dp1[j+1-k][j]+dp2[i][j-k]+dp2[j+1-k][j],dp_min);
            
            dp2[i][j]+=dp_min;            
        }
    }
    cout << dp2[0][siz-1] << endl;
}
int main(){
    int n; cin >> n;
    while(n--){solve();}
}