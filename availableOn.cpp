#pragma once
#include<iostream>
#include<string>
#include<time.h>
using namespace std;

class Available
{
    private:

        char DayOfWeek[15][7],shift1[25],shift2[25];
        int i,NoD;

        public:
            void whenAvailable()
            {
                cout<<"enter no. of available days 1-7  :"<<endl;
                cin>>NoD;
               while ((NoD>=1)&&(NoD>7))
               {
                cout<<"Error, the number you entered is out of range."<<endl;
                cout<<"enter the number between 1-7 "<<endl;

                cin>>NoD;
               }

               cout<<"enter"<<NoD<<"days of week of Dr. Available?:"<<endl;

               for (i=0; i < NoD; i++)
               {
                cin>>DayOfWeek[i];
               }
               cout<<"enter Dr. first shift:"<<endl;
               cin>>shift1;

               cout<<"enter Dr. second shift:"<<endl;
               cin>>shift2;
            }

            void displayAvailable()
            {
               time_t rawtime;
               struct tm * timeinfo;
               time(&rawtime);
               timeinfo = localtime(&rawtime);
               cout<<"local time:"<<endl;
               cout<<asctime(timeinfo);
               cout<<"Dr. is available for"<<NoD<<"days in week"<<endl;
               cout<<"available days are:"<<endl;

               for(i=0;i<NoD;i++){
                  cout<<DayOfWeek[i]<<endl;
               }
                 cout<<"Dr. shift are"<<endl;
                 cout<<shift1<<endl;
                 cout<<shift2<<endl;
            }
};
/*
int main()
{
    Available a1;
    a1.whenAvailable();
    a1.displayAvailable();

    return 0;
}
*/
