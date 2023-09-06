#include<stdio.h>
#include<string.h>
typedef struct node{
     int n;
     char ip[20];
 }pro;
 pro ar[100];
 int num[20];
 int p=0;
 int x;
 void add(int i,char ch,int r)
 {
     int j;
     int len=strlen(ar[i].ip);
     for(int p=0;p<len;p++)
     {
           if(ar[i].ip[p]=='|')
           {
                 j=p;
                 break;
           }
           j=len;
     }

     int b=3;
     ar[r].ip[0]=ch;
      ar[r].ip[1]='-';
      ar[r].ip[2]='>';

     for(int a=4;a<j;a++)
     {
           ar[r].ip[b]=ar[i].ip[a];
           b++;
     }
     ar[r].ip[b]=ch;
     b++;
      ar[r].ip[b]='|';
      b++;
      ar[r].ip[b]='#';
     char ch1=ar[i].ip[0];
     char arr[20];
     strcpy(arr,ar[i].ip);
     strcpy(ar[i].ip," ");
     ar[i].ip[0]=ch1;
      ar[i].ip[1]='-';
      ar[i].ip[2]='>';
      int q=3;
     if(ar[i].ip[j]=='|')
     {
           for(int a=j+1;a<len;a++)
           {
                 ar[i].ip[q]=arr[a];
                 q++;
           }
           ar[i].ip[q]=ch;
           q++;
           ar[i].ip[q]='\0';
     }
     else{
           ar[i].ip[3]=ch;
           ar[i].ip[4]='\0';
     }
 }
void main()
{
    printf("Enter the number of non-terminals = ");
    scanf("%d",&x);
    printf("Enter the productions : \n");
    for(int i=0;i<x;i++)
    {
        ar[i].n=i;
        scanf("%s",ar[i].ip);
    }
    for(int i=0;i<x;i++)
    {
        if(ar[i].ip[0]==ar[i].ip[3])
        {
            num[p]=ar[i].n;
            p++;
        }
    }
    printf("Productions which have left recursion :\n");
    for(int i=0;i<p;i++)
    {
        printf("%s\n",ar[num[i]].ip);
    }
    int c=65;
    for(int i=0;i<p;i++)
    {
        int j=num[i];
        add(j,c,x);
        ar[x].n=x;
        c++;
        x++;
    }
    printf("AFTER REMOVING LEFT RECURSION :\n");
    for(int i=0;i<x;i++)
    {
        printf("%d  ",ar[i].n);
        printf("%s\n",ar[i].ip);
    }
}
