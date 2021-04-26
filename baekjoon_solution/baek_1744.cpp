#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

int main(){

    istream::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N,minus=0,plus=0;
    cin >> N;
    vector<int> v(N);
    for(auto &i:v){
        cin >> i;
        if(i<0)
            minus++;
        else if(i>0)
            plus++;
    }
    int zero = N - minus - plus;

    sort(v.begin(), v.end());

    int sum=0,i,j;

    for(i=0; i<=minus-2; i+=2){
        sum += v[i]*v[i+1];
    }
    for(j=N-1; j>=N-plus+1; j-=2){
        sum += max(v[j]*v[j-1], v[j]+v[j-1]);
    }

    if(minus%2){
        if(!zero)
            sum += v[minus-1];
    }
    if(plus%2){
        sum+=v[N-plus];
    }

    cout << sum;
}