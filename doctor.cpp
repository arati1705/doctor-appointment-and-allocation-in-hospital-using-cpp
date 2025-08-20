#pragma once
#include "person.cpp"
#include "disease.cpp"
#include "availableOn.cpp"
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

class doctor {
    private:
        int doctorid;
        Disease disease;
        Person person;
        Available available;

        char doctorFile[20]= "doctorData.dat";
         char doctorTempFile[20]= "doctorData2.dat";


        public:
            void getdoctordata()
            {
                cout<<"*******enter the data for doctor******"<<endl;
                person.getPersonData();
                cout<<"enter doctor id :";
                cin>>doctorid;



                disease.getdesiaseDetail();
                available.whenAvailable();

            }

            void showDoctorData()
            {

                cout<<"details of doctor are :"<<endl;
                 person.showPersonData();

                  cout<<"doctor id is :"<<doctorid<<endl;

                  disease.showdiseaseList();
                  available.displayAvailable();
                  cout<<endl;


            }

            void addDoctorData(){
               getdoctordata();
                ofstream doctorDatabase(doctorFile, ios::binary | ios::out | ios::app);
                doctorDatabase.write((char*)this, sizeof(doctor));
            }

            void showDoctorDataFormFile(){
                ifstream readdatafromdatabase(doctorFile, ios::binary | ios::in);

                while(!readdatafromdatabase.eof()){
                    if(readdatafromdatabase.read((char*)this,sizeof(doctor)))
                    person.showPersonData();
                }
            }

            void deleteDoctor(){
                int n,flag=0;

               cout<<"enter the doctorId of the doctor you want to delete:"<<endl;
               cin>>n;

               ifstream ifdoctor;
               ifdoctor.open(doctorFile,ios::in | ios::binary);

               ofstream ofdoctor;
               ofdoctor.open(doctorTempFile, ios::out | ios::binary);

               while(!ifdoctor.eof()){
                ifdoctor.read((char*)this, sizeof(doctor));
                if(ifdoctor){
                    if(n==doctorid){
                        flag=1;
                    }
                    else{
                        ofdoctor.write((char*)this, sizeof(doctor));
                    }
                }
               }
               ifdoctor.close();
               ofdoctor.close();
               remove(doctorFile);
               rename(doctorTempFile,doctorFile);

               if( flag == 1){
                 cout<<"\n record sucessfully deleted \n";
               }
               else{
                cout<<"\n record not found \n";
               }
            }
            void editDoctor(){
                int n,pos,flag =0;
                 cout<<"enter the Id of doctor you want to edit"<<endl;
                 cin>>n;

                 fstream fdoctor;
                 fdoctor.open(doctorFile,ios:: binary | ios::in | ios::out);

                 while(!fdoctor.eof()){
                    pos = fdoctor.tellg();
                    fdoctor.read((char*)this, sizeof(doctor));
                    if(fdoctor){
                        if(n == doctorid){
                            flag = 1;

                            getdoctordata();
                            fdoctor.seekp(pos);
                        fdoctor.write((char*)this, sizeof(doctor));
                        showDoctorData();
                        break;
                        }
                    }
                 }
                 fdoctor.close();

                 if(flag == 1)
                 cout<<"\n record sucessfully modified \n";

                 else
                   cout<<"\n record not found\n";
            }

            void doDoctorRelatedWork(){
                char flag;
                int choice;

                do{
                    cout<<"\n enter option 1 to add doctor \n"<<endl;
                    cout<<"\n enter option 2 to show all data \n"<<endl;
                    cout<<"\n enter option 3 to delete \n"<<endl;
                    cout<<"\n enter option 4 to edit doctor data \n"<<endl;
                    cout<<"\n enter option 5 to exit program \n"<<endl;

                    cin>>choice;

                    if(choice == 1){
                        do{
                            addDoctorData();
                            cout<<"add another doctor? 1 for yes \n";
                            cin>>flag;

                        }while(flag == 1);
                    }
                    else if(choice == 2){
                        showDoctorDataFormFile();
                    }
                    else if(choice == 3){
                        deleteDoctor();
                    }
                     else if(choice == 4){
                        editDoctor();
                    }
                }while (choice == 1 | choice == 2 | choice == 3 | choice == 4);
            }
};
/*
int main()
{
    doctor d;
    d.doDoctorRelatedWork();

    return 0;
}*/

