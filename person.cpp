#pragma once
#include<iostream>
#include<string>
using namespace std;

class Person
{
    private:
        int age;
        char name[40],address[40],email[40],phoneNo[40];

        public:
            void getPersonData()
            {
                cout<<"enter age :";
                cin>>age;
                cout<<"enter phone number";
                cin>>phoneNo;
                 cout<<"enter name";
                cin>>name;
                 cout<<"enter address ";
                cin>>address;
                 cout<<"enter email address ";
                cin>>email;


            }

            void showPersonData()
            {
               cout<<" age :"<<age<<endl;
                cout<<" phone number :"<<phoneNo<<endl;
                 cout<<" name :"<<name<<endl;
                  cout<<" address :"<<address<<endl;
                   cout<<" email address :"<<email<<endl;


            }
};

/*int main(){
    Person p1;
    p1.getPersonData();
    p1.showPersonData();

    return 0;
}*/
