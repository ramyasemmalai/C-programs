#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct node{
     char a[20];
     int n;
}pro;
typedef struct node1{
      int n1;
      char ch;
      char ar[20];
}f;
typedef struct node2{
      int n2;
      char ch1;
}terminal;
char input[30];
int top=-1;
char stack[30];
terminal ter[20];
int t=0;
f parsetable[20][20];
f first[20];
f follow[20];
int x,y;
int r,s;
int m;
pro inp[20];
void First(int p,int n)
{
    if(isupper(inp[p].a[n]))
    {
        for(int i=0;i<m;i++)
        {
             if(inp[i].a[0]==inp[p].a[n])
             {
                 First(i,3);
             }
        }
    }
    else{
        first[r].ar[s]=inp[p].a[n];
        ++s;
    }
    for(int j=n;j<strlen(inp[p].a);j++)
    {
            if(inp[p].a[j]=='|')
            {
                  First(p,j+1);
            }
    }
}
void Follow(int n)
{
      for(int i=0;i<m;i++)
      {
            int len=strlen(inp[i].a);
            for(int j=3;j<len;j++)
            {
                  if(inp[n].a[0]==inp[i].a[j])
                  {
                        if(inp[i].a[j+1]=='|'||inp[i].a[j+1]=='\0')
                        {
                              for(int d=0;d<x;d++)
                              {
                                    if(inp[i].a[0]==follow[d].ch)
                                    {
                                          int h=0;
                                          while(follow[d].ar[h]!='\0')
                                          {
                                                int s=0;
                                                while(s!=strlen(follow[x].ar))
                                                {
                                                      if(follow[x].ar[s]!=follow[d].ar[h])
                                                      {
                                                            follow[x].ar[y]=follow[d].ar[h];
                                                            h++;
                                                            y++;
                                                      }
                                                      s++;
                                                }
                                          }
                                    }
                              }
                        }
                        else if(isupper(inp[i].a[j+1]))
                        {
                              for(int d=0;d<m;d++)
                              {
                                    if(inp[i].a[j+1]==first[d].ch)
                                    {
                                          int h=0;
                                          while(first[d].ar[h]!='\0')
                                          {
                                                if(first[d].ar[h]=='#')
                                                {
                                                      int g=0;
                                                      while(follow[i].ar[g]!='\0')
                                                      {
                                                            int s=0;
                                                            while(s!=strlen(follow[x].ar))
                                                            {
                                                                  if(follow[x].ar[s]!=follow[i].ar[g])
                                                                  {
                                                                      follow[x].ar[y]=follow[i].ar[g];
                                                                      g++;
                                                                      y++;
                                                                  }
                                                                  s++;
                                                            }
                                                      }

                                                }
                                                else{
                                                      int s=0;
                                                      while(s!=strlen(follow[x].ar))
                                                      {
                                                            if(follow[x].ar[s]!=first[d].ar[h])
                                                            {
                                                                follow[x].ar[y]=first[d].ar[h];
                                                                y++;
                                                            }
                                                            s++;
                                                      }
                                                }
                                                h++;
                                          }
                                    }
                              }
                        }
                        else{
                              int s=0;
                              while(s!=strlen(follow[x].ar))
                              {
                                    if(follow[x].ar[s]!=inp[i].a[j+1])
                                    {
                                          follow[x].ar[y]=inp[i].a[j+1];
                                          y++;
                                    }
                                    s++;
                              }
                        }
                  }
            }
      }
      if(x==0)
      {
            follow[x].ar[y]='$';
      }
}
void parsing(char ch,char st,int n,char str[])
{
      char string[20];
      for(int i=0;i<m;i++)
      {
            if(inp[i].a[0]==ch)
            {
                  for(int j=0;j<t;j++)
                  {
                        if(ter[j].ch1==st)
                        {
                              strcpy(string,parsetable[i][j].ar);
                              break;
                        }
                  }
                  break;
            }
      }
      int length=strlen(string);
      top--;
      if(length>0)
      {
      for(int i=length-1;i>=0;i--)
      {
            top++;
            stack[top]=string[i];

      }
      }
      if(stack[top]=='#')
      {
            stack[top]='\0';
            top--;
      }
}
void parsing_table()
{
      for(int i=0;i<m;i++)
    {
          int len=strlen(first[i].ar);
          for(int s=0;s<len;s++)
          {
                int p=strlen(inp[i].a);
                int count=0;
                for(int j=0;j<p;j++)
                {
                      if(inp[i].a[j]=='|')
                      {
                            count=j;
                      }
                        if(inp[i].a[j]=='#')
                        {
                              int p1=strlen(follow[i].ar);
                             for(int r=0;r<p1;r++)
                             {

                                    for(int k=0;k<t;k++)
                                    {
                                          if(follow[i].ar[r]==ter[k].ch1)
                                          {
                                                strcpy(parsetable[i][k].ar,"#");
                                          }
                                    }
                              }
                        }
                }
                if(count==0)
                {
                        for(int j=0;j<t;j++)
                        {
                              if(first[i].ar[s]==ter[j].ch1)
                              {
                                    strncpy(parsetable[i][j].ar,inp[i].a+3,p-3);
                              }
                        }
                }
                else{
                        for(int j=0;j<t;j++)
                        {
                              if(first[i].ar[s]==ter[j].ch1)
                              {
                                    if(inp[i].a[count+1]==ter[j].ch1)
                                    {
                                          strncpy(parsetable[i][j].ar,inp[i].a+count+1,p-3);
                                    }
                                    if(inp[i].a[3]==ter[j].ch1)
                                    {
                                          strncpy(parsetable[i][j].ar,inp[i].a+3,count-3);
                                    }
                              }
                        }
                }
            }
      }
      printf("\n ");
}
void main()
{
    printf("Enter the number of production rules = ");
    scanf("%d",&m);
    printf("Enter the production rules one by one :\n");
    for(int i=0;i<m;i++)
    {

        inp[i].n=i;
        scanf("%s",inp[i].a);
    }
    for(int i=0;i<m;i++)
    {
          int len=strlen(inp[i].a);
          for(int j=3;j<len;j++)
          {
                if(!isupper(inp[i].a[j])&&inp[i].a[j]!='|'&&inp[i].a[j]!='#')
                {
                      ter[t].n2=t;
                      ter[t].ch1=inp[i].a[j];
                      t++;
                }
          }
    }
    ter[t].n2=t;
    ter[t].ch1='$';
    t++;
    printf("\nTERMINALS :\n");
    for(int i=0;i<t;i++)
    {
          printf("%d --> %c\n",ter[i].n2,ter[i].ch1);
    }
    for(int i=0;i<m;i++)
    {
          r=i,s=0;
          first[i].n1=i;
          first[i].ch=inp[i].a[0];
          First(i,3);
    }
    printf("\nFIRST POSITION :\n");
    for(int i=0;i<m;i++)
    {
          printf("%c --> %s\n",first[i].ch,first[i].ar);
    }
    for(int i=0;i<m;i++)
    {
          x=i,y=0;
          follow[i].n1=i;
          follow[i].ch=inp[i].a[0];
          strcpy(follow[x].ar," ");
    }
    for(int i=0;i<m;i++)
    {
          x=i,y=0;
          follow[i].n1=i;
          follow[i].ch=inp[i].a[0];
          Follow(x);
    }
    printf("\nFOLLOW POSITION :\n");
    for(int i=0;i<m;i++)
    {
          printf("%c --> %s\n",follow[i].ch,follow[i].ar);
    }
    parsetable[m][t];
    parsing_table();
      printf("PARSING TABLE :\n   ");
      for(int i=0;i<t;i++)
      {
            printf("\t%c",ter[i].ch1);
      }
      printf("\n____________________________________________________\n");
      for(int i=0;i<m;i++)
      {
            printf("%c |\t",inp[i].a[0]);
            for(int j=0;j<t;j++)
            {
                  printf("%s\t",parsetable[i][j].ar);
            }
            printf("\n____________________________________________________\n");
      }
      char string[20],str[20];
      printf("\nEnter the input string to parsing = ");
      scanf("%s",input);
      top=0;
      stack[top]='$';
      top++;
      stack[top]=inp[0].a[0];
      int i=0;
      char ch=input[i];
      int len1=strlen(input);
      input[len1]='$';
      int length=strlen(input);
      printf("\n\tSTACK\t\tINPUT BUFFER\t\n\n");
      while(stack[top]!='$')
      {
            strncpy(str,input+i,length-i+1);
            int le=strlen(str);
            str[le-1]='$';
            str[le]='\0';
            printf("\t%s\t\t\t%s\n",stack,str);
            parsing(stack[top],ch,i,str);
            printf("\t%s\t\t\t%s\n",stack,str);
            if(stack[top]!=input[i])
            {
                  parsing(stack[top],ch,i,str);
                  printf("\t%s\t\t\t%s\n",stack,str);
                  if(stack[top]!=input[i])
                  {
                        parsing(stack[top],ch,i,str);
                        printf("\t%s\t\t\t%s\n",stack,str);
                        if(stack[top]!=input[i])
                        {
                              parsing(stack[top],ch,i,str);
                              printf("\t%s\t\t\t%s\n",stack,str);
                              if(stack[top]!=input[i])
                              {
                                   parsing(stack[top],ch,i,str);
                                   printf("\t%s\t\t\t%s\n",stack,str);
                              }
                        }
                  }
            }
            if(stack[top]==input[i] && stack[top]!='$')
            {
                  stack[top]='\0';
                  top--;
                  i++;
                  ch=input[i];
            }
      }
      if(stack[top]=='$'&&input[i]=='$')
      {
            printf("\nGiven string will be accepted by given Grammar!!\n");
      }
      else{
            printf("\nGiven string not accepted by given Grammar!!\n");
      }
}
