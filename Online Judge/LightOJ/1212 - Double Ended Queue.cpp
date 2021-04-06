#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        printf("Case %d:\n",i);
        int Size, command;

        cin>>Size>>command;

        deque<int> myDeq;
        char str[20];
        int num;

        for(int j=0;j<command;j++)
        {
            scanf(" %s",str);

            if(strcmp(str,"pushLeft")==0)
            {
                cin>>num;
                if(myDeq.size()>=Size)
                {
                    cout<<"The queue is full\n";
                }
                else
                {
                    cout<<"Pushed in left: "<<num<<"\n";
                    myDeq.push_front(num);
                }
            }
            else if(strcmp(str,"pushRight")==0)
            {
                cin>>num;
                if(myDeq.size()>=Size)
                {
                    cout<<"The queue is full\n";
                }
                else
                {
                    cout<<"Pushed in right: "<<num<<"\n";
                    myDeq.push_back(num);
                }
            }

            else if(strcmp(str,"popLeft")==0)
            {
                if(myDeq.size()<=0)
                {
                    cout<<"The queue is empty\n";
                }
                else
                {
                    cout<<"Popped from left: "<<myDeq.front()<<"\n";
                    myDeq.pop_front();
                }
            }
            else if(strcmp(str,"popRight")==0)
            {
                if(myDeq.size()<=0)
                {
                    cout<<"The queue is empty\n";
                }
                else
                {
                    cout<<"Popped from right: "<<myDeq.back()<<"\n";
                    myDeq.pop_back();
                }
            }
        }
    }
    return 0;
}
