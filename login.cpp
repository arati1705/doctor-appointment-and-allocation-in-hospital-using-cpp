#include<iostream>
#include<fstream>
#include<string.h>
#include "patient.cpp"
using namespace std;

class sample{

    public:
    patient p;
    void login()
{
	int count;
	string userID,password,id,pass;


	cout<<"\n\t\t\t please enter the username and password:"<<endl;
	cout<<"\n\t\t\t USERNAME:";
	cin>>userID;
	cout<<"\n\t\t\t PASSWORD:";
	cin>>password;

	ifstream input("records.txt");

	while(input>>id>>pass)
	{
		if(id==userID&& pass==password)
		{
			count=1;

		}
	}
	input.close();

	if(count==1)
	{
		cout<<userID<<"\n your login is sucessfully \n thanks for logging in \n";
		p.doPatientRelatedWork();


	}
	else{
		cout<<"\n LOGIN ERROR\n please ckeck your username and password\n";

	}
}

void registration()
{
	string ruserID,rpassword,rid,rpass;


	cout<<"\n\t\t\t USERNAME:";
	cin>>ruserID;
	cout<<"\n\t\t\t PASSWORD:";
	cin>>rpassword;

	ofstream f1("records.txt",ios::app);
	f1<<ruserID<<' '<<rpassword<<endl;


	cout<<"\n\t\t\t registration is sucessfully \n";


}

void signup()
{
    int c;
    do{


	cout<<"\t\t\t ------------------------------------------\n\n\n";
	cout<<"\t\t\t ---------- welcome to login page --------\n\n\n";
	cout<<"\t\t\t ----------------- MENU ------------------\n\n\n";
	cout<<"\t| 1 LOGIN                             |"<<endl;
	cout<<"\t| 2 REGISTRATION                      |"<<endl;
	cout<<"\t| 3 EXIT                              |"<<endl;
	cout<<"\n enter your choice:";
        cin>>c;

                    if(c == 1){
                       login();
                    }
                    else if(c == 2){
                        registration();
                    }
                    else if(c == 3){
                        exit(0);
                    }
                }while (c == 1 | c == 2 | c == 3);
            }
};
/*
int main()
{
	sample s1;

	s1.signup();
}*/


