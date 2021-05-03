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

    ll sum=0;

    for(int i=1; i<=n; i++){cin >> arr[i];}

    for(int i=n; i>=1; i--){
        if(arr[i] <= arr[i-1]){
            int term = arr[i-1]-arr[i]+1;
            arr[i-1]-=term;
            sum+=term;
        }
    }

    cout << sum;
}
