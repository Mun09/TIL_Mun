#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int main() {

    int n;
    scanf("%d", &n);
    vector<int> v;
    v.push_back(-100);

    int num, cnt=0;
    for(int i=0; i<n; i++){
        scanf("%d", &num);

        if(num > v.back()){
            v.push_back(num);
            cnt++;
        }
        else{
            vector<int>::iterator low = lower_bound(v.begin(), v.end(), num);
            *low = num;
        }
    }

    printf("%d", cnt);
    return 0;

    
}
