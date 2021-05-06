#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
typedef long long ll;

const int MAX = 1000000000+1;
int arr[15],n;
int max_result=-MAX, min_result=MAX;
void solve(int plus, int minus, int divide, int multiply, int cnt, int sum){

    if(cnt==n){
        max_result = max(max_result, sum);
        min_result = min(min_result, sum);
    }

    if(plus>0){solve(plus-1,minus,divide,multiply,cnt+1,sum+arr[cnt]);}
    if(minus>0){solve(plus,minus-1,divide,multiply,cnt+1,sum-arr[cnt]);}
    if(divide>0){solve(plus,minus,divide-1,multiply,cnt+1,sum/arr[cnt]);}
    if(multiply>0){solve(plus,minus,divide,multiply-1,cnt+1,sum*arr[cnt]);}
}
int main(){
    int plus, minus, divide, multiply;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cin >> plus >> minus >> multiply >> divide;

    solve(plus, minus, divide, multiply, 1, arr[0]);

    cout << max_result << endl;
    cout << min_result;
    
}