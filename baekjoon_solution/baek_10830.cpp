#include <iostream>
using namespace std;
long long A[5][5];
long long Ans[5][5];
long long tmp[5][5];

int n, b;
void multiply(long long X[5][5], long long Y[5][5]){
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tmp[i][j]=0;
            for(int k=0; k<n; k++){
                tmp[i][j]+=(X[i][k]*Y[k][j]);
            }
            tmp[i][j]%=1000;
        }
    }

     for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            X[i][j]=tmp[i][j];
        }
    }
}

void print(long long X[5][5]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << X[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    cin >> n >> b;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> A[i][j];
            
        }
        Ans[i][i]=1;
    }

    while(b>0){
        if(b%2==1){
            multiply(Ans, A);
        }
        multiply(A,A);
        b/=2;
    }

    print(Ans);
}