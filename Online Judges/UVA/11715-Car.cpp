#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main()
{
    int choice,i=1;

    double u,v,t,s,a;

    while(cin>>choice)
    {
        if(choice==0)
            break;
        else
        {
            switch(choice)
            {
            case 1:
                {
                    cin>>u>>v>>t;

                    a=(v-u)/t;
                    s=u*t+(a*t*t)/2;

                    printf("Case %d: %.3lf %.3lf\n",i,s,a);
                }
                break;
            case 2:
                {
                    cin>>u>>v>>a;

                    s=((v*v)-(u*u))/(2*a);
                    t=(v-u)/a;

                    printf("Case %d: %.3lf %.3lf\n",i,s,t);
                }
                break;
            case 3:
                {
                    cin>>u>>a>>s;

                    v=sqrt((u*u)+2*a*s);
                    t=(v-u)/a;

                    printf("Case %d: %.3lf %.3lf\n",i,v,t);
                }
                break;
            case 4:
                {
                    cin>>v>>a>>s;
                    u=sqrt((v*v)-2*a*s);
                    t=(v-u)/a;

                    printf("Case %d: %.3lf %.3lf\n",i,u,t);
                }
                break;

            }

        }
        i++;
    }
    return 0;
}
