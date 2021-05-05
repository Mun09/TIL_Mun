#include <iostream>
#include <string>
using namespace std;
#define endl '\n';

int main(){
    int T;
    cin >> T;

    int cj, jc;
    string work;
    for(int i=0; i<T; i++){

        cin >> cj >> jc;
        cin.ignore();
        getline(cin, work);

        //////input finish///////
        int sum=0;
        int j=1;
        char recent=work[0];
        while(j<work.size()){

            
            while(work[j]!='?'){
                if(work[j]!=recent){
                    if(recent=='J'){sum+=jc;}
                    else if(recent=='C'){sum+=cj;}
                }
                recent=work[j];
                j++;
                if(j>=work.size()){break;}
            }

            while(work[j]=='?'){j++;}
            if(j>=work.size()){break;}

            if(work[j]!='?'){
                if(work[j]!=recent && recent!='?'){
                    if(recent=='J'){sum+=jc;}
                    else if(recent=='C'){sum+=cj;}
                }
                recent=work[j];
                j++;
            }

            while(work[j]=='?'){j++;}
            

        }
           
            
            cout << "Case #" << i+1 << ": " << sum << endl;
        
        }

        

    }

    
