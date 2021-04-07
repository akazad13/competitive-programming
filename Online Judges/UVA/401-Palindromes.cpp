#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    char real[200];

    while(cin>>real)
    {
        char rev[200], mir[200];
        int p=0,m=0,s=0,i,j=0;
        int l=strlen(real);
        for(i=l-1;i>=0;i--)
        {
            rev[j++]=real[i];
        }
        rev[j]='\0';
        j=0;
        for(i=0;i<l;i++)
        {
            if(real[i]=='E')
                mir[j++]='3';
            else if(real[i]=='3')
                mir[j++]='E';
            else if(real[i]=='J')
                mir[j++]='L';
            else if(real[i]=='L')
                mir[j++]='J';
            else if(real[i]=='S')
                mir[j++]='2';
            else if(real[i]=='2')
                mir[j++]='S';
            else if(real[i]=='Z')
                mir[j++]='5';
            else if(real[i]=='5')
                mir[j++]='Z';
            else if(real[i]=='A'||real[i]=='H'||real[i]=='I'||real[i]=='M'||real[i]=='O'||real[i]=='T'||real[i]=='U'||real[i]=='V'||real[i]=='W'||real[i]=='X'||real[i]=='Y'||real[i]=='1'||real[i]=='8')
                mir[j++]=real[i];
            else
                {
                    s=1;
                    break;
                }

        }

        mir[j]='\0';


        if(strcmp(real,rev)==0)
            p=1;
        if(s==0)
        {
            if(strcmp(rev,mir)==0)
               m=1;
        }

        if(p==1&&m==1)
        {
            cout<<real<<" -- is a mirrored palindrome.\n"<<endl;
        }
        else if(p==1 && m==0)
        {
            cout<<real<<" -- is a regular palindrome.\n"<<endl;
        }
        else if(p==0 && m==1)
        {
            cout<<real<<" -- is a mirrored string.\n"<<endl;
        }
        else if(p==0 && m==0)
        {
            cout<<real<<" -- is not a palindrome.\n"<<endl;
        }

    }

    return 0;
}
