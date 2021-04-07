#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{



    int test,n,i,k;

    int sum1,sum2,temp;




    while((scanf("%d",&test))==1)
    {
        for(k=1;k<=test;k++)
        {
            int  arr[500];

            sum1=0;
            sum2=0;

            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                scanf("%d",&arr[i]);

            }

            for(i=0;i<n;i++)
            {
                if(arr[i]>29)
                {
                    sum1+=1;

                    temp=arr[i]-29;

                    sum1+= ceil(temp/30.0);
                }

                else
                {
                    sum1+=1;
                }


               if(arr[i]>59)
                {
                    sum2+=1;

                    temp=arr[i]-59;

                    sum2+= ceil(temp/60.0);
                }

                else
                {
                    sum2+=1;
                }


            }

            sum1*=10;
            sum2*=15;


        if(sum1>sum2)
            printf("Case %d: Juice %d\n",k,sum2);
        else if(sum1<sum2)
            printf("Case %d: Mile %d\n",k,sum1);
        else
            printf("Case %d: Mile Juice %d\n",k,sum1);
        }





    }

    return 0;
}





