
//KARTIK GARG
#include <stdio.h>
#include <string.h>
#include <math.h>
#include<malloc.h>
#include<ctype.h>
int depth=0;
int ctr1[3000000],ctr2[3000000];
int place=1;
//PROGRAM FOR DOCUMENT DISTANCE USING TRIE DATA STRUCTURE.
//the use of trie data structure gives an efficient way of searching for a string.
//the string with O(n) size and a substring with O(m) size takes O(n) minimum time to be searched,and takes least amount of memory.
//this algorithm searches the substring in O(m) time which is independent of the source string.
//TIME= O(|m|)!
int done=0;
struct trie
{
    int val;
    struct trie *alpha[26];
}*root=NULL;
struct trie* newnode()
{
    int i;
   struct trie *n= malloc(sizeof(struct trie));
        n->val=0;
    for(i=0;i<26;i++)
            n->alpha[i]=NULL;
    return n;
}
void insertin1(char a[])
{

    int i=0,l=strlen(a);
    if(root==NULL)
    {
        root=newnode();
    }
struct trie* n=root;
    while(i<l)
        {

            while(n->alpha[a[i]-'a']!=NULL && i<l)
            {
             //   printf("%c*",a[i]);
                n=n->alpha[a[i]-'a'];
                i++;
                if(i==l)break;
            }
            if(i==l)break;
            //printf("%d",i);
            if(i!=l)
            {
            //printf("%c*",a[i]);
            n->alpha[a[i]-'a']=newnode();

            }

        }
        if(n->val==0)
        {n->val=place++;}
        ctr1[n->val]++;
}
void insertin2(char a[])
{

    int i=0,l=strlen(a);
    if(root==NULL)
    {
        root=newnode();
        root->val=1;
    }
struct trie* n=root;
    while(i<l)
        {

            while(n->alpha[a[i]-'a']!=NULL && i<l)
            {
             //   printf("%c*",a[i]);
                n=n->alpha[a[i]-'a'];
                i++;
                if(i==l)break;
            }
            if(i==l)
                break;
            //printf("%d",i);
            if(i!=l)
            {
            //printf("%c*",a[i]);
            n->alpha[a[i]-'a']=newnode();

            }

        }
        if(n->val==0)
        {n->val=place++;}
        ctr2[n->val]++;
}

int search(char a[])
{
    int i=0,l=strlen(a);
    struct trie* n=root;
    while(i<l)
        {

            while(n->alpha[a[i]-'a']!=NULL && i<l)
            {
                n=n->alpha[a[i]-'a'];
                i++;
            }
            //printf("%d",i);
            if(i==l)
            {
                if(n->val!=0)
                printf("FOUND!");
                else
                    printf("NOT FOUND!");
                return 1;
            }
            else
            {
                printf("NOT FOUND!");
                return 0;
            }
            }
    printf("NOT FOUND");
    return 0;
}
int main()
{
    int i=0;
    for(i=0;i<300000;i++)
        ctr1[i]=ctr2[i]=0;
    char ins[40];
    char c;
    FILE *f1,*f2;
    f1=fopen("FILE1.txt","r");
    c=fgetc(f1);
   // printf("The words in file 1 is:");
    while(c!=EOF)
    {
        i=0;
        while(!isalpha(c) && c!=EOF)c=fgetc(f1);
        if(c==EOF)break;
        while(isalpha(c))
        {
            c=tolower(c);
     //       printf("%c",c);
            ins[i++]=c;
            c=fgetc(f1);
        }
        ins[i]='\0';
        //printf("\n%s",ins);
        insertin1(ins);
        c=fgetc(f1);
    }
    fclose(f1);
    //printf("*");
    f2=fopen("FILE1.txt","r");
    c=fgetc(f2);
    //printf("\n\nThe words in file 2 is:");
    while(c!=EOF)
    {
        i=0;
        while(!isalpha(c) && c!=EOF)c=fgetc(f2);
        if(c==EOF)break;
        while(isalpha(c))
        {
            c=tolower(c);
            ins[i++]=c;
            c=fgetc(f2);
        }
        ins[i]='\0';
        //printf("\n%s",ins);
        insertin2(ins);
        //printf("*");
        if(c==EOF)break;
    }
    //printf("*");
    fclose(f2);
    float sum=0;
    float mod1=0,mod2=0;
    for(i=1;i<place;i++)
        {
            sum=sum+(ctr1[i]*ctr2[i]);
            mod1+=(pow(ctr1[i],2));
            mod2+=(pow(ctr2[i],2));
        }
        mod1=sqrt(mod1);
        mod2=sqrt(mod2);
        //printf("\n%f %f %f\n",sum,mod1,mod2);
        float sim=0;
        sim=sum/(mod1*mod2);
        printf("\n\nThe similarity between the two files is %0.2f",sim*100);
        printf("%%");
    printf("\nThe number of distinct words including both the files is:%d\n\n",place-1);
/*    printf("the word count of each file is:\n");
    printf("FILE1  FILE2");
    for(i=1;i<place;i++)
    printf("\n %d       %d",ctr1[i],ctr2[i]);
  */
    printf("\n\n");
    //SEARCH FOR WORDS IN THE LOADED TRIE.
    /*while(1)
    {
        scanf("%s",ins);
        if(strcmp(ins,"done")==0)
        {
            break;
        }
        else
            search(ins);
        printf("\n");
    }*/
    return 0;
}
