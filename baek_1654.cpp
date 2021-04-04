#include <stdio.h>
#include <algorithm>
#include <cmath>
#define endl '\n';
typedef long long ll;


int main(){

    int n, length;
    scanf("%d %d", &n, &length);
    long long tmp;
    long long sum=0;

    int arr_remain[100000];
    int arr_share[100000];

    for(int i=0; i<n; i++){
        scanf("%d", &arr_remain[i]);
        sum+=arr_remain[i];
    }

    tmp=sum/length;
    sum=0;
    for(int i=0; i<n; i++){
        arr_share[i]=arr_remain[i]/tmp;
        arr_remain[i]%=tmp;
        sum+=arr_share[i];
    }

    long long ans=tmp;
    int arr_last[100000];
    
        while(length > 2*sum){
            for(int i=0; i<n; i++){
                arr_last[i]= round((ll)(ans-arr_remain[i])/(arr_share[i]+1));
            }
            sum+=n;
            ans-= *std::max_element(arr_last, arr_last+n);
        }
        
        int last=length-sum;
        if(last){

        for(int i=0; i<n; i++){
                arr_last[i]= ceil((float)(ans-arr_remain[i])/(float)(arr_share[i]+1));
        }
        std::sort(arr_last, arr_last+n);
        ans-=arr_last[last-1];
        }
    printf("%d", ans);
}