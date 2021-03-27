#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;
#define endl '\n';
deque<int> split(string str, char delimiter);

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int T, num;
    string command;
    string numbers;

    cin >> T;
    cin.ignore();
    for(int i=0; i<T; i++){
        
        getline(cin, command);
        cin >> num;
        cin.ignore();
        getline(cin, numbers);
        
        
        deque<int> numbers_real = split(numbers, ',');
        
        ///////////// input ///////////////

        queue<int> qu;
        for(int j=0; j<command.size(); j++){
            qu.push(command[j]);
        }
        //////////qu oper/////////////

        int isitfirst=1;
        
        
        while(!qu.empty()){
            if(qu.front()!='R' && numbers_real.empty()){
                cout << "error" << endl ;
                isitfirst=2;
                break;
            }
            if(isitfirst){
                if(qu.front()=='R'){
                    isitfirst=0;
                }
                else{
                    numbers_real.pop_front();
                }
            }
            else{
                if(qu.front()=='R'){
                    isitfirst=1;
                }
                else{
                    numbers_real.pop_back();
                }
            }
            
            qu.pop();
        }
        

        /////////oper end///////

        num=numbers_real.size();
        
        

        if(isitfirst!=2){
        if(!num){cout << "[]" << endl;}
        else{
        cout << '[';
        if(isitfirst){
        for(int j=0; j<num-1; j++){
            cout << numbers_real.front() << ',';
            numbers_real.pop_front();
        }
        cout << numbers_real.front() << ']' << endl;
        }

        else{
            for(int j=0; j<num-1; j++){
            cout << numbers_real.back() << ',';
            numbers_real.pop_back();
        }
        cout << numbers_real.back() << ']' << endl;
        }}}
    }

}

deque<int> split(string input, char delimiter){
    string input_real;
    input_real.assign(input, 1, input.size()-2);

    deque<int> answer;
    stringstream ss(input_real);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(stoi(temp));
    }
 
    
    return answer;

}
