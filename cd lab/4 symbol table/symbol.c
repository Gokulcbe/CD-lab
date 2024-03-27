#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct symtab
{
int lineno;
char var[25],dt[25],val[10];
}sa[20];
void main()
{
int i=0,j,k,max,f=0,xx,h,m,n,l,r,ty=1,m1,line=0;
char s[25],typ[25],temp[25],gar[]="garbage",t[25],got[10],e[10];
float m2;
FILE *fn,*ft,*fp;
//sa[1].line=1;
fn=fopen("input.txt","r");
printf("\n\nSYMBOL TABLE MANAGEMENT\n\n");
printf("Variable\tDatatype\tLine.no.\t\tValue\n");
while(!(feof(fn)))
{
fscanf(fn,"%s",s);
if((strcmp(s,"int")==0)||(strcmp(s,"float")==0))
{
strcpy(typ,s); line++;
while(s,";"!=0)
{
i++;

max=i; sa[i].lineno=line;
fscanf(fn,"%s",s);

strcpy(sa[i].var,s);
strcpy(sa[i].dt,typ);

fscanf(fn,"%s",s);
if(strcmp(s,"=")==0)
{
fscanf(fn,"%s",s);
strcpy(sa[i].val,s);

fscanf(fn,"%s",s);
}
else
strcpy(sa[i].val,gar);
if(strcmp(s,",")==0)
continue;
else break;
}
}
else if(strcmp(s,"char")==0)
{
strcpy(typ,s); line++;
while(strcmp(s,";")!=0)
{
i++;
max=i; sa[i].lineno=line;
fscanf(fn,"%s",s);
strcpy(sa[i].var,s);
strcpy(sa[i].dt,typ);
fscanf(fn,"%s",s);

if(strcmp(s,"=")==0)
{
fscanf(fn,"%s",s);
fscanf(fn,"%s",s);
strcpy(sa[i].val,s);
fscanf(fn,"%s",s);
fscanf(fn,"%s",s);
}
}//while

fscanf(fn,"%s",s);
if(strcmp(s,",")==0)
continue;
}//else if

}//while
for(i=1;i<=max;i++)
printf("\n%s\t\t%s\t\t%d\t\t%s\n",sa[i].var,sa[i].dt,sa[i].lineno,sa[i].val);
fclose(fn);
}
