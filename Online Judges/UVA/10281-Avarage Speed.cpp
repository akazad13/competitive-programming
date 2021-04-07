#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("10281.txt","r",stdin);
    int h,m,s,speed;
    double dis=0;
    int preH,preM,preS;
    preH=preM=preS=0;

    int k=0;

    while(scanf("%d:%d:%d",&h,&m,&s)==3)
    {
        int preTime,curTime;
        char ch=getchar();
        if(ch==' ')
        {

            if(k>0)

             {
                 preTime = preH*3600+preM*60+preS;

           // cout<<"Pre"<<preTime<<endl;
                curTime  = h*3600+m*60+s;
            //cout<<"cur"<<(speed*(curTime-preTime))<<endl;
           // cout<<curTime-preTime<<endl;

                dis+=(double)(speed*(curTime-preTime))/3600.0;
             }
             cin>>speed;

            preH=h;
            preM = m;
            preS = s;

            k++;

        }
        else
        {
            preTime = preH*3600+preM*60+preS;

          //  cout<<"Pre"<<preTime<<endl;
            curTime  = h*3600+m*60+s;
           // cout<<"cur"<<curTime<<endl;
           // cout<<curTime-preTime<<endl;

            dis+=(double)(speed*(curTime-preTime))/3600.0;

           // cout<<()<<"\n";

           if(h>9)
            printf("%d:",h);
           else
            printf("0%d:",h);
           if(m>9)
            printf("%d:",m);
        else
            printf("0%d:",m);
        if(s>9)
            printf("%d",s);
        else
            printf("0%d",s);

        printf(" %.2f km\n",dis);

        preH=h;
        preM = m;
        preS = s;

        }

        //cout<<curTime<< "  "<<preTime<<endl;

       // cout<<(curTime-preTime)<<endl;

        //cout<<dis<<endl;

    }

}
