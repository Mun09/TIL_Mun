#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define endl '\n';
typedef long long ll;

int main(){

    int n, m, result=0;
    cin >> n >> m;

    while(m>0 && m!=n){
        if(m%10==1){
            m/=10;
        }
        else if(m%2==0){
            m/=2;
        }
        else{break;}
        result++;
    }

    if(m==n){cout << result+1;}
    else{cout << -1;}
    
}  