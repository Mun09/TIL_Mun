#include <iostream>
using namespace std;
#define Max 1000000

int main(){
    int N, weight;
    cin >> N >> weight;
    
    int arr[N+1][2];

    for(int i=1; i<=N; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    int dp[N+10][Max];

    for(int i=1; i<=N; i++){
        for(int j=1; j<=weight; j++){
            if(j>=arr[i][0]){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-arr[i][0]]+arr[i][1]);
            }
            else{
                dp[i][j]=dp[i-1][j];
                }
            }
        }

    cout << dp[N][weight];
    }
