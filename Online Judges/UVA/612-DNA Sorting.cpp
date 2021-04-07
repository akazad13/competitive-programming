#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct DNA{
    char ch[55];
    int count;
};

int main()
{
    freopen("E:\\1.txt","r",stdin);
    freopen("E:\\3.txt","w",stdout);
    int i,j,d,n,m,k,l;

    cin>>d;
    while(d--)
    {
        cin>>n>>m;
        int o=getchar();
        struct DNA a[m],temp1;
        for(i=0;i<m;i++)
        {
            gets(a[i].ch);
        }
        for(i=0;i<m;i++)
        {
            a[i].count=0;
             l=strlen(a[i].ch);
            for(j=0;j<l;j++)
            {
                for(k=j;k<l;k++)
                {
                    if(a[i].ch[j]>a[i].ch[k])
                    {
                        a[i].count++;
                    }
                }
            }
        }
        for(i=0;i<m-1;i++)
        {
            for(j=0;j<m-1;j++)
            if(a[j].count>a[j+1].count)
            {
                temp1=a[j];
                a[j]=a[j+1];
                a[j+1]=temp1;
            }
        }

        for(i=0;i<m;i++)
            cout<<a[i].ch<<endl;
        if(d>0)
            cout<<'\n';

    }

    return 0;
}
