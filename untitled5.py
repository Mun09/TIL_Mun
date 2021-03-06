list_input=[input() for _ in range(2)]
n1=len(list_input[0])
n2=len(list_input[1])
list_result=[]
list_result_later=[]
k=0

for i in range(n1):
    for t in range(n2):
        if list_input[0][i]==list_input[1][t]:
            for j in range(len(list_result)-1,-1,-1):
                if list_result[j][-1]<t:
                    list_result_later+=[list_result[j]+[t]]
                    k+=1
                    break
            if k==0:
                list_result_later+=[[t]]
            k=0
            
    list_result+=list_result_later
    list_result_later=[]
    list_result=sorted(list_result,key=len)

if list_result==[]:
    print(0)
else: 
   print(len(list_result[-1]))