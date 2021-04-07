#include<iostream>
#include<bits/stdc++.h>

using namespace std;

char Fact[100000];
char str1[100000];
char str[100];

int  res[1010][10]={0};

void addString(char *pro)
{
    int len1=strlen(str1);
    int len2=strlen(pro);
    int l_low,l_high;

   // cout<<len1<<" "<<len2<<endl;

    if(len1<=len2)
    {
        l_low=len1;
        l_high=len2;

    }
    else
    {
        l_low=len2;
        l_high=len1;
    }



    int temp=0;

    for(int i=1;i<=l_low;i++)
    {
        temp=((str1[len1-i]-'0')+(pro[len2-i])-'0')+temp;
      //  cout<<temp<<endl;
        str1[(l_high+1)-i]=(temp%10)+'0';
       // cout<<sum[i]<<endl;
        temp=temp/10;

    }

   // cout<<sum[2]<<endl;

    if(l_low==len1)
    {
        //cout<<"in if: "<<sum<<endl;
        int k;
        for(k=len2-len1-1;k>=0;k--)
        {
            temp=pro[k]-'0'+temp;
            str1[k+1]=(temp%10)+'0';
            temp=temp/10;
        }

        if(temp>0)
        {
            str1[k+1]=temp+'0';
        }
        else
            str1[k+1]='0';

        str1[len2+1]='\0';
    }



    else if(l_low==len2)
    {
       // cout<<"in else: "<<sum<<endl;
        int k;
        for(k=len1-len2-1;k>=0;k--)
        {
            temp=str1[k]-'0'+temp;
            str1[k+1]=(temp%10)+'0';
            temp=temp/10;
        }

        if(temp>0)
        {
            str1[k+1]=temp+'0';
        }
        else
            str1[k+1]='0';
        str1[len1+1]='\0';
    }
    return ;
    //cout<<sum<<endl;
}


void Product(char *str,int no)
{
    str1[0]='0';
    str1[1]='\0';
    int len1 = strlen(Fact);
    int len2 = strlen(str);
    int k=0;

        for(int i=len2-1;i>=0;i--)
        {
            char pro[100000];
            int temp=0;
            int n= str[i]-'0';
            for(int j=len1-1;j>=0;j--)
            {
                temp = (Fact[j]-'0')*n+temp;
                pro[j+1]= temp%10+'0';
                temp/=10;
            }
           // cout<<pro<<endl;

            pro[0]=temp+'0';
            for(int a=0;a<k;a++)
            {
                pro[len1+1+a]='0';
            }
            pro[len1+1+k]='\0';

            //cout<<no<<" :"<<pro<<endl;

            addString(pro);

            k++;

        }
        strcpy(Fact,str1);
       // cout<<Fact<<endl;

       int len=strlen(Fact);

      // int flag=0;
      // cout<<no<<endl;

        for(int i=0;i<len;i++)
        {
            res[no][0]+=Fact[i]-'0';
        }
        return ;
}


int main()
{
    //freopen("10106.txt","w",stdout);

    Fact[0]='1';
    Fact[1]='\0';

    for(int i=0;Fact[i]!='\0';i++)
    {
        res[1][Fact[i]-'0']++;
    }

    for(int i=2;i<=1000;i++)
    {
        int flag=0;
        int num=i;
        while(num!=0)
        {
            for(int m=flag;m>0;m--)
            {
                str[m]=str[m-1];

            }
            str[0]=(num%10)+'0';
            num/=10;
            flag++;
        }
        str[flag+1]='\0';

        Product(str,i);
    }

    int n;

    while(cin>>n)
    {
        if(n==0||n==1)
        {
            printf("1\n");
        }
        else
        {
            cout<<res[n][0]<<"\n";
        }
    }


    return 0;
}

