#include "patient.cpp"
#include "login.cpp"
#include "doctorsignup.cpp"
int main()
{

    sample s;
    doctorlogin dl;
    int choice;

    do{
        cout<<"\n\n enter option 1 for patient"<<endl;
        cout<<"enter option 2 for doctor"<<endl;
        cin>>choice;

        switch(choice){
            case 1: cout<<"\n -------- patient ---------"<<endl;
            s.signup();
                break;
            case 2:
                cout<<"\n------------doctor ------------"<<endl;
                dl.docsignup();
                break;
            default:
                break;
        }
    }while(choice == 1 | choice == 2 );

    return 0;
}
