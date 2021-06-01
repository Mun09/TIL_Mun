#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;
const ll MAX=1000000;

typedef struct Matrix_2x2
{
    unsigned long long f[2][2];
}Matrix2x2;

Matrix2x2 multiply(Matrix2x2 A, Matrix2x2 B)
{
    Matrix_2x2 C;
    C.f[0][0]=A.f[0][0]*B.f[0][0]+A.f[0][1]*B.f[1][0];
    C.f[0][1]=A.f[0][0]*B.f[0][1]+A.f[0][1]*B.f[1][1];
    C.f[1][0]=A.f[1][0]*B.f[0][0]+A.f[1][1]*B.f[1][0];
    C.f[1][1]=A.f[1][0]*B.f[0][1]+A.f[1][1]*B.f[1][1];
    C.f[0][0]%=MAX;
    C.f[1][0]%=MAX;
    C.f[0][1]%=MAX;
    C.f[1][1]%=MAX;

    return C;
}

Matrix2x2 Matrix_Power(Matrix2x2 A, unsigned long long n){
    if(n>1){
        A=Matrix_Power(A,n/2);
        A=multiply(A,A);

        if(n & 1){
            Matrix2x2 F1= {1,1,1,0};
            A=multiply(A,F1);
        }
    }
    return A;
}

int main(){
    unsigned long long n;
    cin >> n;
    Matrix2x2 F1={1,1,1,0};
    F1=Matrix_Power(F1,n);
    cout << F1.f[0][1]%MAX << endl;
    return 0;
}