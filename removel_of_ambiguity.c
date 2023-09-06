#include <stdio.h>
#include<string.h>
typedef struct node{
      int n;
      char a[20];
}pro;
int pr;
pro ar[100];
void add_pro(char ch,char ph,int i)
{
      ar[i-1].n=i-1;
      ar[i-1].a[0]=ph;
      ar[i-1].a[1]='-';
      ar[i-1].a[2]='>';
      ar[i-1].a[3]=ch;
}
void main()
{
      printf("Enter the no.of non terminals = ");
      int nt;
      scanf("%d",&nt);
      printf("Enter non terminal symbols = ");
      char ntl[pr];
      scanf("%s",ntl);
      printf("Enter the no.of production rules = ");
      scanf("%d",&pr);
      printf("Enter the productions like this nonterminal->rule :\n");
      for(int i=0;i<pr;i++)
      {
            ar[i].n=i;
            scanf("%s",ar[i].a);
      }
      pro num[10],temp[10];
      int t[10];
      char op[10];
      int p=0,q=0;
      int pos;
      for(int i=0;i<pr;i++)
      {
            for(int j=0;j<5;j++)
            {
                  if(ar[i].a[j]=='>')
                  {
                        if(ar[i].a[0]==ntl[0]&&ar[i].a[j+1]==ntl[0])
                        {
                              pos=j+1;
                              temp[p].n=ar[i].n;
                              temp[p].a[0]=ar[i].a[j+2];
                              p++;
                        }
                        else{
                              t[q]=i;
                              q++;
                        }
                  }
            }
      }
      int i=0;
      for(int j=0;j<p;j++)
            {
                  if(temp[j].a[0]=='+')
                  {
                        num[i].n=temp[j].n;
                        i++;
                        break;
                  }
            }
            for(int j=0;j<p;j++)
            {
                  if(temp[j].a[0]=='-')
                  {
                        num[i].n=temp[j].n;
                        i++;
                        break;
                  }
            }
            for(int j=0;j<p;j++)
            {
                  if(temp[j].a[0]=='*')
                  {
                        num[i].n=temp[j].n;
                        i++;
                        break;
                  }
            }
            for(int j=0;j<p;j++)
            {
                  if(temp[j].a[0]=='/')
                  {
                        num[i].n=temp[j].n;
                        i++;
                        break;
                  }
            }
      for(int r=0;r<p;r++)
      {
            int i=num[r].n;
            if(ar[i].a[pos+1]=='+')
            {
                  ar[i].a[pos+2]='P';
                  for(int s=0;s<p;s++)
                  {
                        if(ar[num[s+1].n].n==num[r+1].n)
                        {
                              ar[num[s+1].n].a[0]='P';
                              ar[num[s+1].n].a[pos]='P';
                        }
                  }
                  pr++;
                  for(int j=0;j<q;j++)
                  {
                        ar[t[j]].a[0]='P';
                  }
                  add_pro('P',ar[i].a[0],pr);
            }
            else if(ar[i].a[pos+1]=='-')
            {
                  ar[i].a[pos+2]='Q';
                  for(int s=0;s<p;s++)
                  {
                        if(ar[num[s+1].n].n==num[r+1].n)
                        {
                              ar[num[s+1].n].a[0]='Q';
                              ar[num[s+1].n].a[pos]='Q';
                        }
                  }
                  for(int j=0;j<q;j++)
                  {
                        ar[t[j]].a[0]='Q';
                  }
                  pr++;
                  add_pro('Q',ar[i].a[0],pr);
            }
            else if(ar[i].a[pos+1]=='*')
            {
                  ar[i].a[pos+2]='R';
                  for(int s=0;s<p;s++)
                  {
                        if(ar[num[s+1].n].n==num[s+1].n&&temp[num[s+1].n].a[0]=='/')
                        {
                              ar[num[s+1].n].a[0]='R';
                              ar[num[s+1].n].a[pos]='R';
                        }
                  }
                  for(int j=0;j<q;j++)
                  {
                        ar[t[j]].a[0]='R';
                  }
                  pr++;
                  add_pro('R',ar[i].a[0],pr);
            }
            else if(ar[i].a[pos+1]=='/')
            {
                  ar[i].a[pos+2]='S';
                  for(int s=0;s<p;s++)
                  {
                        if(ar[num[s+1].n].n==num[s].n)
                        {
                              ar[num[s+1].n].a[0]='S';
                              ar[num[s+1].n].a[pos]='S';
                        }
                  }
                  for(int j=0;j<q;j++)
                  {
                        ar[t[j]].a[0]='S';
                  }
                  pr++;
                  add_pro('S',ar[i].a[0],pr);
            }
      }
      printf("AFTER REMOVING AMBIGUITY : \n");
      for(int i=0;i<pr;i++)
      {
            printf("%d  %s\n",ar[i].n,ar[i].a);
      }
}
