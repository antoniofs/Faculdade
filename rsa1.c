/*
Enrique Madureira
Rebeca Rodrigues
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long int p,q,n,t,expo,e[100],d[100],temp[100],j,m[100],en[100],i;
char msg[100];
int primo(long int);
void ce();
long int cd(long int);
void cripto();
void descripto();
void main()
{
    printf("\nPrimeiro Primo\n");
    scanf("%d",&p);
    int *pont = &p;
    teste(pont);
    expo=primo(p);
    if(expo==0)
    {
        printf("\nEntrada invalida\n");

        exit(1);
    }
    printf("\nSegundo Primo\n");
    scanf("%d",&q);
    if (p==q)
    {
        printf ("Chaves iguais");
    }
    else;
    if (q == 7)
    {
        q+=6;
    }
    expo=primo(q);
    if(expo==0||p==q)
    {
        printf("\nEntrada Invalida\n");
        getch();
        exit(1);
    }
    printf("\nDigite a mensagem\n");
    fflush(stdin);
    gets(msg);
    for (i=0; msg[i]!=NULL; i++)
        m[i]=msg[i]-65;
    n=p*q;
    t=(p-1)*(q-1);
    ce();
    printf("\nValores Possiveis\nE       D");
    for (i=0; i<j-1; i++)
        printf("\n%ld\t%ld",e[i],d[i]);
    cripto();
    descripto();
    getch();
}
int primo(long int pr)
{
    int i;
    j=sqrt(pr);
    for (i=2; i<=j; i++)
    {
        if(pr%i==0)
            return 0;
    }
    return 1;
}
void ce()
{
    int k;
    k=0;
    for (i=2; i<t; i++)
    {
        if(t%i==0)
            continue;
        expo=primo(i);
        if(expo==1&&i!=p&&i!=q)
        {
            e[k]=i;
            expo=cd(e[k]);
            if(expo>0)
            {
                d[k]=expo;
                k++;
            }
            if(k==99)
                break;
        }
    }
}
long int cd(long int x)
{
    long int k=1;
    while(1)
    {
        k=k+t;
        if(k%x==0)
            return(k/x);
    }
}
void cripto()
{
    long int pt,ct,chave=e[0],k,tam;
    i=0;
    tam=strlen(msg);
    while(i!=tam)
    {
        pt=m[i];
        pt=pt-96;
        k=1;
        for (j=0; j<chave; j++)
        {
            k=k*pt;
            k=k%n;
        }
        temp[i]=k;
        ct=k+96;
        en[i]=ct;
        i++;
    }
    en[i]=-1;
    printf("\nA mensagem criptografada e'\n");
    for (i=0; en[i]!=-1; i++)
        printf("%c",en[i]);
}
void descripto()
{
    long int pt,ct,chave=d[0],k;
    i=0;
    while(en[i]!=-1)
    {
        ct=temp[i];
        k=1;
        for (j=0; j<chave; j++)
        {
            k=k*ct;
            k=k%n;
        }
        pt=k+96;
        m[i]=pt;
        i++;
    }
    m[i]=-1;
    printf("\nMensagem descriptografada\n");
    for (i=0; m[i]!=-1; i++)
        if (m[i]+65 == '{')
        {
            printf (" ");
        }
        else
            printf("%c",m[i]+65);
}

void teste(int *pX)
{
    if (p == 2)
    {
        pX+=29;
    }
    if (pX == 3)
    {
        pX+=20;
    }
    if (pX == 5)
    {
        pX+=8;
    }
}
