#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        string arr;
        
        int n;
        cin >> n;

        string string_arr[n][30];
        

        for(int j=0; j<n; j++){
        cin >> arr >> arr;
        *string_arr[j]=arr;

        }
        
        int number[n];
        fill_n(number,n,1);
        vector<int> king_number;
        int tt;
        for(int j=0; j<n; j++){
            
            if(number[j]==1){
                tt=0;
                for(int k=j; k<n; k++){
                    if(*string_arr[j]==*string_arr[k]){
                    number[k]=0;
                    tt++;
                    }
                }
                king_number.push_back(tt);
            }
        }
        int sum=1;

        for(int j=0; j<king_number.size(); j++){

            sum*=(king_number[j]+1);

        }

        cout << sum-1 << endl;
       
    }
    
}

