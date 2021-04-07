#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int num;

    while(cin>>num,num)
    {
        int flag=0;
        printf("Discarded cards:");
        deque<int>myDeq;
        for(int i=1;i<=num;i++)
        {
            myDeq.push_back(i);
        }

        while(myDeq.size()!=1)
        {
            if(flag==0)
            {
                cout<<" "<<myDeq.front();
                flag=1;
            }
            else
            {
                cout<<", "<<myDeq.front();
            }

            myDeq.pop_front();
            int temp=myDeq.front();
            myDeq.pop_front();
            myDeq.push_back(temp);
        }

        cout<<"\nRemaining card: "<<myDeq.front()<<"\n";
        myDeq.clear();
    }


    return 0;
}
