#pragma once
#include "person.cpp"
#include "disease.cpp"
#include "doctor.cpp"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class patient {
    private:
        int patientId;
        Disease disease;
        doctor d;
        Person person;
        string appointDate;
        char patientFile[20]= "patientData.dat";
         char patientTempFile[20]= "patientData2.dat";


        public:
            void getPatientInformation()
            {

                cout<<"enter the data for person "<<endl;
                person.getPersonData();
                cout<<"disease details :"<<endl;
                disease.getdesiaseDetail();

                cout<<"appoint date:";
                cin>>appointDate;

            }

            void addPatient()
            {
                cout<<"patient Id  :";
                 cin>>patientId;

                 getPatientInformation();
                 ofstream patientDatabase(patientFile, ios::binary | ios::out | ios::app);
                 patientDatabase.write((char*)this,sizeof(patient));


            }

            void showPatientData(){
                cout<<"---- patient data ------"<<endl;
                cout<<"patient Id :"<<patientId<<endl;

                person.showPersonData();
                disease.showdiseaseList();
                cout<<"appointment date :"<<appointDate<<endl;
            }

            void showPatientDataFormFile(){
                ifstream readdatafromdatabase(patientFile, ios::binary | ios::in);

                while(!readdatafromdatabase.eof()){
                    if(readdatafromdatabase.read((char*)this,sizeof(patient)))
                    showPatientData();
                }
            }

            void dischargePatient(){
                int n,flag=0;

               cout<<"pentent the Id of the patient you want to delete:"<<endl;
               cin>>n;

               ifstream ifpatient;
               ifpatient.open(patientFile,ios::in | ios::binary);

               ofstream ofpatient;
               ofpatient.open(patientTempFile, ios::out | ios::binary);

               while(!ifpatient.eof()){
                ifpatient.read((char*)this, sizeof(patient));
                if(ifpatient){
                    if(n==patientId){
                        flag=1;
                    }
                    else{
                        ofpatient.write((char*)this, sizeof(patient));
                    }
                }
               }
               ifpatient.close();
               ofpatient.close();
               remove(patientFile);
               rename(patientTempFile,patientFile);

               if( flag == 1){
                 cout<<"\n record sucessfully deleted \n";
               }
               else{
                cout<<"\n record not found \n";
               }
            }
            void editPatient(){
                int n,pos,flag =0;
                 cout<<"enter the Id of patient you want to edit"<<endl;
                 cin>>n;

                 fstream fpatient;
                 fpatient.open(patientFile,ios:: binary | ios::in | ios::out);

                 while(!fpatient.eof()){
                    pos = fpatient.tellg();
                    fpatient.read((char*)this, sizeof(patient));
                    if(fpatient){
                        if(n == patientId){
                            flag = 1;

                            getPatientInformation();

                            fpatient.seekp(pos);
                        }

                        fpatient.write((char*)this, sizeof(patient));

                        showPatientData();
                        break;

                    }
                 }

            }

            void doPatientRelatedWork(){
                char flag;
                int choice;

                do{

                    cout<<"\n enter option 1 to add patient \n"<<endl;
                    cout<<"\n enter option 2 to show all data \n"<<endl;
                    cout<<"\n enter option 3 to discharge patient \n"<<endl;
                    cout<<"\n enter option 4 to edit patient data \n"<<endl;
                    cout<<"\n enter option 5 to exit program \n"<<endl;

                    cin>>choice;

                    if(choice == 1){
                        do{
                            addPatient();
                            cout<<"add another patient? 1 for yes \n";
                            cin>>flag;

                        }while(flag == 1);
                    }
                    else if(choice == 2){
                        showPatientDataFormFile();
                    }
                    else if(choice == 3){
                        dischargePatient();
                    }
                     else if(choice == 4){
                        editPatient();
                    }
                }while (choice == 1 | choice == 2 | choice == 3 | choice == 4);
            }
};
/*
int main()
{
    patient p1;
    p1.doPatientRelatedWork();

    return 0;
}*/
