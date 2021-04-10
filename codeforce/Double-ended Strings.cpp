#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
int main()
{
  //iostream::sync_with_stdio(false);
   //cin.tie(NULL); cout.tie(NULL);
   int T;
   cin >> T;

   for(int i=0; i< T; i++){
       string a,b;
       cin >> a;
       cin >> b;

       int arr[100][100]={0,};
       int max_one=0;
        int a_length=a.length();
        int b_length=b.length();
       for(int i=1; i<=a_length; i++){
           for(int j=1; j<=b_length; j++){
               if(a[i-1]==b[j-1]){
                   arr[i][j] = arr[i-1][j-1]+1;
                   max_one=max(max_one, arr[i][j]);
               }
               
           }
       }
       int ans = a.length()+b.length()-2*max_one;
       cout << ans << endl;
   }

}

