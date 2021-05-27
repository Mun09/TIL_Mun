#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

const int MAX=1000000000, a=(1<<10)-1;
int arr[105][15][a+10];
int main(){
    int n; cin >> n;
    for(int j=1; j<10; j++){
        int b=1<<j;
        arr[1][j][b]=1;
    }
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            int k=1<<j;
            if(j==0){
                for(int t=1; t<=a; t++){
                    arr[i][j][t | k]+=arr[i-1][j+1][t];
                    arr[i][j][t | k]%=MAX;
                }
            }
            else if(j==9){
                for(int t=1; t<=a; t++){
                    arr[i][j][t | k]+=arr[i-1][j-1][t];
                    arr[i][j][t | k]%=MAX;
                }
            }
            else{
                for(int t=1; t<=a; t++){
                    arr[i][j][t | k]+=arr[i-1][j+1][t];
                    arr[i][j][t | k]+=arr[i-1][j-1][t];
                    arr[i][j][t | k]%=MAX;
                }
            }
        }
    }
    int sum=0;
    for(int i=0; i<10; i++){
        sum+=arr[n][i][a];
        sum%=MAX;
    }
    cout << sum;
}