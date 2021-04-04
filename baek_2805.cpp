#include <stdio.h>
#include <algorithm>
bool compare(int a, int b){return a>b;}
int main(){

    
    int n;
    long long height_max;
    scanf("%d %lld", &n, &height_max);
    long long arr[n+10];

    for(int i=0; i<n; i++){
        scanf("%lld", &arr[i]);
    }

    std::sort(arr, arr+n, compare);

    arr[n]=0;
    long long tree=0;
    long long recent=arr[0];
    long long sum=0;

    for(int i=0; i<n+1; i++){
        if(arr[i]==recent){tree++;}
        else{
            recent=arr[i];
            sum += tree*(arr[i-1]-arr[i]);
            if(sum >= height_max){break;}
            tree++;
        }
    }
    long long count=0;
    while(sum - height_max >= tree){sum-=tree; count++;}

    printf("%lld", count+arr[tree] );
    
}