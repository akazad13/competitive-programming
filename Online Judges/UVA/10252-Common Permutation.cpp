#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()

{
    char first[1002];
    char second[1002];

    while(gets(first))
    {
        char ans[1002];
        gets(second);
        int l1,l2;

        l1=strlen(first);
        l2=strlen(second);
        sort(first,first+l1);
        sort(second,second+l2);
        int k=0;
        int i,j,m=0;
        for(i=0;i<l1;i++)
        {
            for(j=m;j<l2;j++)
            {
                if(first[i]==second[j])
                {
                    //cout<<first[i]<<endl;
                    ans[k++]=first[i];
                    i++;
                    m=j+1;

                }

            }
        }
        ans[k]='\0';
       // sort(ans,ans+strlen(ans));
       puts(ans);
    }
    return 0;
}
