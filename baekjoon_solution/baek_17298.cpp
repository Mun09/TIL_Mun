#include <stdio.h>
#include <stack>
using namespace std;

int main(){
    
    int N;
    scanf("%d",&N);
    int arr[N];

    for(int i=0; i<N; i++){
        scanf("%d",&arr[i]);
    }

    stack<int> st;
    st.push(arr[0]);

    int answer[N]={0,};
    int j;

    for(int i=0; i<=N-2; i++){

        j=i;
        while(!st.empty() && st.top()<arr[i+1] ){
            
            st.pop();
            while(answer[j]){j--;}
            answer[j]=arr[i+1];
            
        }
        st.push(arr[i+1]);

        
    }

    for(int i=0; i<N; i++){
        if(!answer[i]){
            printf("-1 ");
        }
        else{
            printf("%d ",answer[i]);
        }
    }
    
}