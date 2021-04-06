#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros
#define read(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define lld long long int


bool isLeap(int n)
{
    if(n%400==0)
        return 1;
    if(n%100==0)
        return 0;
    else if(n%4==0)
        return 1;
    else
        return 0;
}

int cal(int n)
{
    return (n/4)-(n/100)+(n/400);
}


int main()
{
    int test,day1,year1,day2,year2,count;
    char m1[20],m2[20];
    read(test);

    for(int Case = 1; Case<=test ; Case++)
    {
        scanf("%s %d, %d",m1,&day1,&year1);
        scanf("%s %d, %d",m2,&day2,&year2);
        count=0;

        if(strcmp(m1,"January")==0 || strcmp(m1,"February")==0)
        {
            if(strcmp(m1,"January")==0)
            {
                if(isLeap(year1))
                {
                    count++;
                }
            }
            else if(strcmp(m1,"February")==0 && day1<=29)
            {
                if(isLeap(year1))
                {
                    count++;
                }
            }
        }

        if(strcmp(m2,"January")!=0)
        {
            if(strcmp(m2,"February")==0)
            {
                if(day2==29)
                    count++;
            }
            else
            {
                if(isLeap(year2))
                {
                    count++;
                }
            }
        }
        year2--;

        int ret1  = cal(year2);
        int ret2  = cal(year1);

        int diff  = ret1-ret2;

        printf("Case %d: %d\n",Case,diff+count);
    }

    return 0;

}


