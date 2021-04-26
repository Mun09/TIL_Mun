#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {

  
    ll y, x;
    cin >> x >> y;
    
    ll ans = (floor)(100.0 * y / x);
    ll left = 1, right = x;
    ll mid, result=-1;

    while(left <= right){

        mid = (left+right)/2.0;
        if(ans < (floor)(100.0*(y+mid)/(x+mid))){
            right = mid -1;
            result = mid;
        }
        else{
            left = mid +1;
        }
    }
    cout << result;
}
