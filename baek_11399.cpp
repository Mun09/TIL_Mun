#include <iostream>
#include <algorithm>
using namespace std;

int N;
int main(){
 cin >> N;
 int arr[N];
 for(int i=0; i<N; i++){
     cin >> arr[i];
 }

 sort(arr, arr+N);

int sum=0;
 for(int i=0; i<N; i++){
     sum+=arr[i]*(N-i);
 }

cout << sum;

}