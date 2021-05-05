#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main() {

    iostream::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int left = 0, right = k;
    int mid;
    int num, ans;

    while(left <= right){
        mid = (left + right)/2;
        num=0;
        int i, j;

        for(i = 1; i <= n; i++)
            num += min(mid/i, n);

        if(num < k){left = mid + 1;}
        else{
            right = mid-1;
            ans = mid;
        }
        }
    
    cout << ans;
}
