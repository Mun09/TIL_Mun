#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n';

int main(){
    int T;
    cin >> T;

    for (int i=0; i<T; i++){

        int N, C;
        cin >> N >> C;

        int arr[N];
        for(int j=1; j<=N; j++){arr[j-1]=j;}

        int real_cost=C-N+1;
        if(real_cost<0 || C > (N-1)*(N+2)/2){
        
            cout << "Case #" << i+1 << ": " << "IMPOSSIBLE" << endl;
        }
        else{

            int cannum[N-1];
            int many=0;
            for(int j=1; j<=N-1; j++){
                if(real_cost>=j){
                    cannum[j-1]=j;
                    real_cost-=j;
                    many++;
                }
                else{
                    
                    cannum[j-1]=real_cost;
                    real_cost=0;
                    many++;
                    break;
                    
                    
                }
            }

            
            ///////횟수설정///
            int time=0;
            

            for(int j=N-1; j>=0 && time<many; j--){
                reverse(arr+j-1, arr+j+cannum[time]);
                time++;  
            }

            cout << "Case #" << i+1 << ": ";
            for(int j=0; j<N-1; j++){
                cout << arr[j] << ' ';
            }
            cout << arr[N-1] << endl;


        }


    }
}

