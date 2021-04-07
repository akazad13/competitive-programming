#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int month,depreciasion_no;
    double down,loan;

    while(cin>>month>>down>>loan>>depreciasion_no,month>=0)
    {
        double Depri[110];
        int month_no,temp=0;
        double dep;
        while(depreciasion_no--)
        {
            cin>>month_no;
            for(int i=temp+1;i<month_no;i++)
                Depri[i]=dep;
            cin>>dep;

            Depri[month_no]=dep;
            temp=month_no;

        }
       // cout<<month_no<<" "<<dep<<endl;

        for(int i=month_no+1;i<102;i++)
            Depri[i]=dep;

     /*   for(int i=0;i<102;i++)
            cout<<Depri[i]<<endl;
            */

        double loan_diff = loan/month;
        double car_val  = (down+loan)*(1.0-Depri[0]);

       // cout<<loan_diff<< " "<<car_val<<endl;

        int month_res = 0;

        while(car_val<loan)
        {
            month_res++;
            loan-=loan_diff;
            car_val = car_val*(1.0-Depri[month_res]);
        }

        if(month_res==1)
            printf("1 month\n");
        else
            printf("%d months\n",month_res);


    }

    return 0;
}
