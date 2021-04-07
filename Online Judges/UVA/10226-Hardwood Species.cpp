#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
   // freopen("10226.txt","r",stdin);

    int test;

    cin>>test;
    char ch=getchar();
        ch=getchar();

    for(int i=0;i<test;i++)
    {


        char str[50];
        map<string, int>myMap;
        map<string, int> :: iterator it;

        int count=0;

        while(gets(str))
        {
            //cout<<23<<endl;
            if(strlen(str)==0)
                break;
            myMap[str]++;
            count++;
        }


        if(i>0)
            cout<<"\n";

        for(it=myMap.begin();it!=myMap.end();it++)
        {
            cout<<it->first<<" ";
            printf("%0.4f\n",((((double)it->second)*100.0)/((double)count)));
        }

      //  myMap.clear();
    }

    return 0;
}
