#include <iostream>
using namespace std;
long long basic[2][2];
long long Ans[2][2];
long long tmp[2][2];

void multiply(long long X[2][2], long long Y[2][2]){

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            tmp[i][j]=0;
            for(int k=0; k<2; k++){
            tmp[i][j]+=X[i][k]*Y[k][j];
            }
            tmp[i][j]%=1000000007;
        }
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            X[i][j]=tmp[i][j];
        }
    }
}
int main(){
    long long n;
    cin >> n;

    for(int i=0; i<2; i++){
        Ans[i][i]=1;
    }
    long long basic[2][2]={{1,1},{1,0}};

    while(n>0){
        if(n%2==1){
            multiply(Ans, basic);
        }
        multiply(basic, basic);
        n/=2;
    }

    cout << Ans[1][0];
}