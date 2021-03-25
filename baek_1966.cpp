#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    int N;
    cin >> N;

    for(int i=0; i<N; i++){

        int N, location;
        cin >> N >> location;
        int arr[N];
        queue<int> qu, qu_1;

        for(int j=0; j<N; j++){
            cin >> arr[j];
            qu.push(arr[j]);
            }
        for(int j=0; j<N; j++){
            if(j==location){
                qu_1.push(1);
            }
            else{
                qu_1.push(0);
            }
        }

        sort(arr,arr+N);

        int j=N-1;
        while(1){

            if(arr[j]==qu.front()){
                if(qu_1.front()){

                    cout << N-j << endl;
                    break;

                }
                else{
                    j--;
                    qu.pop();
                    qu_1.pop();
                }
            }
            else{
                qu.push(qu.front());
                qu.pop();
                qu_1.push(qu_1.front());
                qu_1.pop();
                
            }
        }

    }
}
