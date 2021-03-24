#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;


int main(){

    stack<int> st_answer;
    vector<int> v;

    int N,j=0;
    scanf("%d",&N);
    int arr[N];

    for(int i=0; i<N; i++){
        scanf("%d",&arr[i]);
    }

    for(int i=1; i<=N; i++){

        st_answer.push(i);
        v.push_back('+');

        
        while( !st_answer.empty() && st_answer.top()==arr[j]){
            v.push_back('-');
            st_answer.pop();
            j++;
        }
        
    }

    if(st_answer.empty()){
        for(char i: v){
            printf("%c\n", i);
        }
    }
    else{
    
        printf("NO");
    }

}
// 배열은 크기를 입력 받은 다음에 정의하자.