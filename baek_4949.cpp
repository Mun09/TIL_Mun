#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    string arr;

    while(getline(cin,arr)){
        vector<int> v1;
        int p=0;

        if(arr[0]=='.' && arr.size()==1){
            break;
        }

        else{
            for(int i=0; i<arr.size(); i++){
                
                
                if(arr[i]=='('){
                    v1.push_back(1);
                } 
                else if(arr[i]=='['){
                    v1.push_back(2);
                }

                if(arr[i]==']' || arr[i]==')'){
                    if(v1.empty()==0){
                if(arr[i]==')' && v1.back()==1 ){
                    v1.pop_back();
                }
                else if(arr[i]==']' && v1.back()==2){
                    v1.pop_back();
                }
                else{
                    p++;
                    break;
                }
                    }
                else{
                    p++;
                    break;
                }
            }

        
        }
        if(p==0 && v1.empty()==1){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
            }


        
    }
}
}