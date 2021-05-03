#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <memory.h>
using namespace std;
#define endl '\n';
typedef long long ll;

int arr[105]={0,};
int main(){

    istream::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    string a;
    cin >> a;

    int i=0;
    int result=n;

    while(i<n){
        if(a[i]=='L'){
            result--;
            i+=2;
        }
        else{i++;}
    }

    if(result==a.size()){
        cout << result;
    }
    else{
    cout << result+1;
    }
    return 0;
}
