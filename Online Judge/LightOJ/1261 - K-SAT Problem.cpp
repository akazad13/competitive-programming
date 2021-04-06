#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int arr[33];
vector<int> vec[50];
vector<char> sign[50];

int main()
{
    int test,n,m,k, num, qq;
    char ch;

    scanf("%d",&test);

    for(int Case = 1; Case<=test; Case++)
    {
        for(int i=0;i<50;i++)
        {
            vec[i].clear();
            sign[i].clear();
        }
        for(int i=0;i<33;i++) arr[i]=0;

        scanf("%d %d %d",&n,&m,&k);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                scanf(" %c",&ch);
                scanf("%d",&num);
                vec[i].push_back(num);
                sign[i].push_back(ch);
            }
        }
        scanf("%d",&qq);

        for(int i=0;i<qq;i++)
        {
            scanf("%d",&num);
            arr[num]=1;
        }


        int res=1;

        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int j=0;j<k;j++)
            {
                if(sign[i][j]=='+')
                {
                    temp = temp|arr[vec[i][j]];
                }
                else
                {
                    temp = temp|(arr[vec[i][j]]^1);
                }
            }

            res = res & temp;
        }

        if(res==1)
            printf("Case %d: Yes\n",Case);

        else
             printf("Case %d: No\n",Case);

    }

    return 0;
}
