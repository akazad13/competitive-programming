#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctype.h>
using namespace std;

int main()
{

    int i,j,k;

    char st[200];

    while(gets(st))
    {
        char real[200], rev[200];
        j=0;
        k=0;
        if(strcmp(st,"DONE")==0)
            break;
        else
        {
            for(i=0;st[i]!='\0';i++)
            {
                if(st[i]>='A'&&st[i]<='Z')
                {
                    real[j++]=st[i]+'a'-'A';
                }
                else if(st[i]>='a'&&st[i]<='z')
                {
                    real[j++]=st[i];
                }
            }
            real[j]='\0';
            for(i=j-1;i>=0;i--)
            {
                rev[k++]=real[i];
            }

            rev[j]='\0';

            if(strcmp(real,rev)==0)
                cout<<"You won't be eaten!"<<endl;
            else
                cout<<"Uh oh.."<<endl;
        }

    }
    return 0;
}
