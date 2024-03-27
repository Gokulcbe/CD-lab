#include<stdio.h> 
#include<string.h> 
struct stack 
{ 
    char s[20]; 
    int top; 
}; 
struct stack st; 
int isempty() 
{   return (st.top==1); 
} 
void push(char p) 
{ 
    st.s[st.top++]=p; 
} 
char pop() 
{ 
    if(isempty()) 
        printf("stack empty"); 
    else 
        return st.s[st.top--]; 
} 
void disp() 
{   int i; 
    for(i=0;i<st.top;i++) 
        printf("%c",st.s[i]); 
} 
int reduce(int *j,char rp[10][10],int n) 
{   int i,t,k; 
    char u[10]; 
    t=st.top-1; 
    for (i=0;i<=st.top;i++) 
    {   u[i]=st.s[t]; 
        u[i+1]='\0'; 
        for(k=0;k<n;k++) 
        { 
            if(strcmp(rp[k],u)==0) 
	        { 
	            st.top=st.top-i-1; 
	            return k; 
            } 
        } 
        t--; 
    } 
    return 99; 
} 
int shift(char ip[],int *j) 
{   push(ip[*j]); 
    (*j)++; 
    disp(); 
    return 1; 
} 
void main() 
{   int n,i,j=0,k,h; 
    char lp[10]; 
    char ip[10]; 
    char rp[10][10]; 
    st.top=0; 
    printf("\nEnter the number of productions:"); 
    scanf("%d",&n); 
    for(i=0;i<n;i++) 
    {	printf("\nEnter the left side of the production %d:",i+1); 
	    scanf(" %c",&lp[i]); 
	    printf("\nEnter the right side of the production %d:",i+1); 
	    scanf("%s",rp[i]); 
    } 
    printf("\nEnter the input:"); 
    scanf("%s",ip); 
    printf("================================================================="); 
    printf("\nSTACK                 INPUT                       OUTPUT         "); 
    printf("\n=================================================================\n"); 
    strcat(ip,"$"); 
    push('$'); 
    printf("$                    %s          \n",ip); 
    while(!(st.s[st.top-1]==lp[0]&&st.s[st.top-2]=='$'&&(j==(strlen(ip)-1))&&st.top==2)) 
    { 
        if((h=reduce(&j,rp,n))!=99) 
        {   push(lp[h]);disp();printf("\t\t\t"); 
            for(k=j;k<strlen(ip);k++) 
                printf("%c",ip[k]); 
            printf("\t\t\tReduce %c->%s\n",lp[h],rp[h]); 
        } 
        else if(shift(ip,&j)) 
        {     printf("\t\t\t"); 
	          for(k=j;k<strlen(ip);k++) 
                    printf("%c",ip[k]); 
              printf("\t\t\tshift %c\n",ip[j-1]); 
        } 
    } 
    disp(); 
    printf("\t\t\t"); 
    for(k=j;k<strlen(ip);k++) 
        printf("%c",ip[k]); 
    printf("\t\t\taccept\n"); 
}

