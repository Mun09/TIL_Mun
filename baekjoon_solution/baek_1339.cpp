#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
#define endl '\n'; 

int main(){
    
    int n;
    cin >> n;
    ll arr[27] = {0,};

    while(n--){
        string a;
        cin >> a;

        for(int i=a.length()-1; i>=0; i--){
            arr[(int)a[i] - 65] += pow(10,a.length()-i-1);
        }
    }

    sort(arr, arr+27);
    int j=9;
    ll sum=0;
    for(int k = 26; arr[k]!=0; k--){
        sum+=arr[k]*j;
        j--;
    }

    cout << sum;

}