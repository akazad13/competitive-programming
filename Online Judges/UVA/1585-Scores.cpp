#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    //freopen("D:\\Programing Code\\ONLINE\\doc\\1585.txt","r",stdin);
    char result[80];

    int t,i,j,score;

    while(cin>>t)
    {
        while(t--)
        {
            cin>>result;
            score=0;
            j=1;
            //cout<<result<<endl;
            for(i=0;result[i]!='\0';i++)
            {
                if(result[i]=='O')
                   {
                       score+=j++;
                       // j++;
                   }
                else
                    j=1;
            }
            cout<<score<<endl;
        }

    }
    return 0;
}
