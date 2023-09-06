#include<stdio.h>
#include<string.h>
#include<stdbool.h>
typedef struct node{
      char n1[10];
}nfa;
typedef struct node1{
      char n2[10];
}dfa;
typedef struct node3{
      int n;
      char a[10];
}st;
int p=1;
st nfa_st[100];
nfa ip[100][100];
dfa ipt[100][100];
st dfa_st[100];
void compare(int col,int c)
{
      int count=0;
      for(int x=0;x<p;x++)
      {
      for(int i=0;i<col;i++)
      {
            bool b=strcmp(dfa_st[x].a,ipt[x][i].n2);
            if(b==true)
            {
                  for(int s=0;s<p;s++)
                  {
                        if(strcmp(dfa_st[s].a,ipt[x][i].n2)==false)
                        {
                              break;
                        }
                        else
                        {
                              dfa_st[p].n=p;
                              strcpy(dfa_st[p].a,ipt[x][i].n2);
                        }
                  }
            }
      }
      }
}
void main()
{
      printf("Enter the number of states in NFA = ");
      int row,col;
      scanf("%d",&row);
      nfa_st[row];
      printf("Enter the number of input symbols = ");
      scanf("%d",&col);
      ip[row][col];
      printf("Enter the state representation :\n");
      for(int i=0;i<row;i++)
      {
            nfa_st[i].n=i;
            printf("State %d -> ",i);
            scanf("%s",nfa_st[i].a);
      }
      for(int i=0;i<row;i++)
      {
            printf("For state %s : \n",nfa_st[i].a);
            for(int j=0;j<col;j++)
            {
                  printf("For input %d -> ",j);
                  scanf("%s",ip[i][j].n1);
            }
      }
      printf("\nNFA TRANSITION TABLE :\n\nstates       0\t1\n");
      for(int i=0;i<row;i++)
      {
            printf("%s",nfa_st[i].a);
            for(int j=0;j<col;j++)
            {
                  printf("\t%s",ip[i][j].n1);
            }
            printf("\n");
      }
      printf("\n");
      dfa_st[0].n=nfa_st[0].n;
      strcpy(dfa_st[0].a,nfa_st[0].a);
      for(int i=0;i<col;i++)
      {
            strcpy(ipt[0][i].n2,ip[0][i].n1);
      }
      compare(col,p);
      p++;
      for(int x=1;x<5;x++)
      {
      int len=strlen(dfa_st[x].a);
      for(int k=0;k<col;k++)
      {
            int r=0;
            for(int s=0;s<len;s++)
            {
                  for(int i=0;i<row;i++)
                  {
                        if(dfa_st[x].a[s]==nfa_st[i].a[0])
                        {
                              int j=nfa_st[i].n;
                              int len1=strlen(ip[j][k].n1);
                              for(int q=0;q<len1;q++)
                              {
                                    if(ip[j][k].n1[q]!='-')
                                    {
                                    ipt[x][k].n2[r]=ip[j][k].n1[q];
                                    r++;
                                    }
                              }

                        }
                  }

            }
      }
      compare(col,p);
      p++;
      }
      int x=0;
      for(int i=0;i<p;i++)
      {
            for(int j=i;j<p;j++)
            {
                  if(strcmp(dfa_st[i].a,dfa_st[j].a)==true)
                  {
                        strcpy(dfa_st[j].a,"\0");
                        x=j;
                  }
            }
      }
      for(int i=0;i<p-1;i++)
      {
            for(int j=0;j<col;j++)
            {
                  int count=0;
                  for(int k=0;k<p;k++)
                  {
                        if(strcmp(dfa_st[k].a,ipt[i][j].n2)==false)
                        {
                              count++;
                              break;
                        }
                  }
                  if(count==0)
                  {
                        strcpy(dfa_st[x].a,ipt[i][j].n2);
                        break;
                  }

            }
      }
      int len=strlen(dfa_st[x].a);
      for(int k=0;k<col;k++)
      {
            int r=0;
            for(int s=0;s<len;s++)
            {
                  for(int i=0;i<row;i++)
                  {
                        if(dfa_st[x].a[s]==nfa_st[i].a[0])
                        {
                              int j=nfa_st[i].n;
                              int len1=strlen(ip[j][k].n1);
                              for(int q=0;q<len1;q++)
                              {
                                    if(ip[j][k].n1[q]!='-')
                                    {
                                    ipt[x][k].n2[r]=ip[j][k].n1[q];
                                    r++;
                                    }
                              }

                        }
                  }

            }
      }
      printf("Total number of States in DFA = %d\n",p-1);
      printf("DFA STATES\n");
      for(int i=0;i<p-1;i++)
      {
            printf("   %d  %s \n",dfa_st[i].n,dfa_st[i].a);
      }
      printf("\n");
      printf("   DFA TRANSITION TABLE : \n");
      printf(" \n");
      printf("   states       0       \t1  \n");
      for(int i=0;i<p-1;i++)
      {
            printf("   ");
            printf("%s",dfa_st[i].a);
            for(int j=0;j<2;j++)
            {
                  printf("\t\t%s",ipt[i][j].n2);
            }
            printf("\n");
      }
      printf("\n");
      printf("   Enter the no.of final states in NFA = ");
      int q;
      scanf("%d",&q);
      printf("   Enter the final states in NFA = ");
      char q1[q];
      scanf("%s",q1);
      printf("   Final States in DFA : \n");
      for(int i=0;i<strlen(q1);i++)
      {
            for(int j=0;j<p-1;j++)
            {
                  int d=strlen(dfa_st[j].a);
                  for(int k=0;k<d;k++)
                  {
                        if(q1[i]==dfa_st[j].a[k])
                        {
                              printf("   \t%d -->%s\n",j,dfa_st[j].a);
                              break;
                        }
                  }
            }
      }
}
