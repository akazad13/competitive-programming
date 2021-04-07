#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
    char s1[100];
    char s2[100];

    int l1,l2,l,carry,i,j,count,k;

    while((scanf("%s %s",&s1,&s2))==2)
    {
       l1=strlen(s1);
       l2=strlen(s2);
       if(l1==1&&l2==1 && s1[0]=='0'&&s2[0]=='0')
            break;
        carry=0;
        count=0;
        k=0;

        for(i=l1-1,j=l2-1;i>=0&&j>=0;i--,j--)
        {
            if(((s1[i]-'0')+(s2[j]-'0')+carry)>=10)
            {
                count++;
                carry=1;

                
            }
            else
                carry=0;
        }


        if(l2>l1)
        {

            for(k=j;k>=0;k--)
            {
                 if(((s2[k]-'0')+carry)>=10)
                {
                        count++;
                        carry=1;
                }
                else
                    break;
            }

        }
       else if(l1>l2)
        {
            for(k=i;k>=0;k--)
            {   if(((s1[k]-'0')+carry)>=10)
                {
                        count++;
                        carry=1;
                }
                else
                    break;
            }

        }

        if(count==1)
             printf("%d carry operation.\n",count);

        else if(count==0)
            printf("No carry operation.\n");
        else if(count>=2)
            printf("%d carry operations.\n",count);


    }

    return 0;
}




