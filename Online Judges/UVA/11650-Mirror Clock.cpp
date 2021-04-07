#include<iostream>
#include<cstdio>

using namespace std;

int main()

{
   // freopen("D:\\11650.txt","r",stdin);
    int t,h,m;
    while(cin>>t)
    {
        while(t--)
        {
            scanf("%d:%d",&h,&m);
            if(m>0&&h<11)
            {
                m=60-m;
                h=11-h;
            }
            else if(m>0&&h==11)
            {
                h=12;
                m=60-m;
            }
            else if(m>0&&h==12)
            {
                m=60-m;
                h=11;
            }
            else if(m==0&&h==12)
            {
                //m=0;
                //h=12;
            }
            else
            {
                h=12-h;
            }
            if(h<10&&m<10)
                printf("0%d:0%d\n",h,m);
            else if(h<10&&m>=10)
                printf("0%d:%d\n",h,m);
            else if(h>=10&&m<10)
                printf("%d:0%d\n",h,m);
            else
                printf("%d:%d\n",h,m);
        }
    }
    return 0;
}
