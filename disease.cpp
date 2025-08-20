#pragma once
#include<iostream>
#include<string>
using namespace std;

class Disease
{
    private:

        char diseasename[25],virusname[25];

        public:
            void getdesiaseDetail()
            {
                cout<<"enter the name of disease :";
                cin>>diseasename;
                cout<<"enter the name of virus :";
                cin>>virusname;

            }

            void showdiseaseList()
            {
               cout<<endl;
                cout<<"Disease :"<<diseasename<<endl;
                 cout<<" virus name :"<<virusname<<endl;

            }
};

/*int main()
{
    Disease d1;
    d1.getdesiaseDetail();
    d1.showdiseaseList();

    return 0;
}*/
