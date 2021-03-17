#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    long long length[N], cost[N];

    for (int i = 0; i < N - 1; i++){
		cin >> length[i];
    }
	
	for (int i = 0; i < N; i++){
		cin >> cost[i];
    }

    long long price = cost[0];
    long sum=0;

    for(int i=0; i<N-1; i++){

        if(cost[i]<price){
            price=cost[i];
        }

        sum+=price*length[i];
    }
    cout << sum;
        
}

// 백준 풀 때 long long 과 같은 자료형을 조심하자!!