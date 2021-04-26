#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
using namespace std;
int arr1[60][60], arr2[60][60];
bool check[60][60];

void change(int i, int j){

    for(int k = 0; k<3; k++){
        for(int t = 0; t<3; t++){
            check[i+k][j+t] = !check[i+k][j+t];
        }
    }
}
int main(){
    int N, M;
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        string a;
        cin >> a;
        for(int j=1; j<=M; j++){
            arr1[i][j] = a[j-1] - '0';
        }
    }
    
    for(int i=1; i<=N; i++){
        string a;
        cin >> a;
        for(int j=1; j<=M; j++){
            arr2[i][j] = a[j-1] - '0';
            check[i][j] = (arr1[i][j]==arr2[i][j]?false:true);
        }
    }

    int check_value=0;

    if(N>=3 && M>=3){
        int cnt = 0;
    for(int i=1; i<=N-2; i++){
        for(int j=1; j<=M-2; j++){
            if(check[i][j]){
                change(i,j);
                cnt++;
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(check[i][j]){
            check_value++;
            break;
        }
        }
        
    }
    int ans = check_value ? -1:cnt;
    cout << ans;
    }

    else{
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                if(check[i][j]){
                check_value++;
                break;
            }
        }
    }
    int ans = check_value?-1:0; 
    cout << ans;
    }

}