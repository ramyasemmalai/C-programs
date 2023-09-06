#include<stdio.h>
#include<string.h>
int i=0;
char input[100];
void B()
{
    if(input[i]=='a')
    {
    	printf("B->aB \n");
        i++;
        B();
    }
    else if(input[i]=='b')
    {
    	printf("B->bB \n");
        i++;
        B();
    }
    else if(input[i]=='#')
    {
    	printf("B-> epsilon \n");
    	printf("Given string is Accepted\n");
	}
	else if(input[i]=='\0')
    {
    	printf("B -> epsilon \n");
    	printf("Given string is Accepted\n");
	}
    else{
    	printf("B->Ea \n");
        E();
        if(input[i]=='a')
        {
            printf("Given string is Accepted");
        }
        else{
            printf("Given string is Not accepted");
        }
    }
}
void E()
{

    if(input[i]=='a')
    {
        i++;
        if(input[i]=='b')
        {
        	printf("E->abB \n");
            i++;
            B();
        }
        else{
    	    printf("E->Ba \n");
            B();
            if(input[i]=='a')
            {
                printf("Given string is Accepted");
            }
        }
    }
    else{
    	printf("Given string is Not Accepted\n");
	}
}
void S()
{
	printf("S->E\n");
    E();
}
void main()
{
	printf("PRODUCTION RULES : \n");
	printf("S -> E\n");
	printf("E -> abB | Ba \n");
	printf("B -> aB | Ea | bB | #(epsilon) \n");
    int n;
    input[n];
    printf("Enter the string = ");
    scanf("%s",&input);
    n=strlen(input);
    printf("USED PRODUCTION RULES : \n");
    S();
}
