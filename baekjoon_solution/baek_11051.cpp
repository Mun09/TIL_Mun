#include <iostream>
using namespace std;

int main(){
    int  a,b;
    cin >> a >> b;
    
    int arr[a+1][b+1];
    arr[1][0]=1, arr[1][1]=1;

    for (int i=2; i< a+1; i++){
        for (int j=0; j<min(i+1, b+1); j++){
            if(j==0 || j==i){
                arr[i][j]=1;
            }
            else{
                arr[i][j]=(arr[i-1][j-1]+arr[i-1][j])%10007;
            }
        }
    }

    cout << arr[a][b];

}