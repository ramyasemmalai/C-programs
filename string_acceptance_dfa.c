#include<stdio.h>
#include<string.h>
void main()
{
    printf("DFA FOR REGULAR EXPRESSION : (a+b)*+(ac)*\n");
    int n=5;
    int m=3;
    char ter[m];
    strcpy(ter,"abc");
    int dfa[5][3]={
        {1,2,-1},
        {2,2,3},
        {2,2,-1},
        {4,-1,-1},
        {-1,-1,3}};
    printf("Enter the string to parsing = ");
    char str[100];
    int ind=-1;
    int st=0;
    int count;
    scanf("%s",str);
    int len=strlen(str);
    while(ind!=len+1)
    {
        if(ind+1==len && (st==1||st==2||st==3))
        {
            printf("String accepted\n");
            break;
        }
        else{
            ind++;
        }
        for(int i=0;i<m;i++)
        {
            if(ter[i]==str[ind])
            {
                count=i;
            }
        }
        st=dfa[st][count];
        if(st==-1)
        {
            printf("Not accept\n");
            break;
        }
    }
}
