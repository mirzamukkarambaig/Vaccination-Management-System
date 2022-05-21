//
// Created by Mirza on 7/11/2021.
//

#ifndef DSA_PROJECT_CITIZEN_H
#define DSA_PROJECT_CITIZEN_H
#include "Dose.h"
#include <iostream>
#include <fstream>
extern int appointment_num;
using namespace std;
class Citizen {
private:
    string citizen_name, citizen_CNIC, citizen_contact;
    int citizen_age;
    Dose dosage1;
    Citizen* next_citizen;
    bool vaccinated;
    int hours;
    static int minuets ;
    string apponintment_time;
    string message;
    int appointment_number;
public:
    Citizen(){
        next_citizen = nullptr;
        citizen_age = 0;
        this->EnterDetails();
        this->GetDoseDetails();
        vaccinated = true;
        hours = 0;
    }
    void EnterDetails (){
        cout << "Citizen Name: ";
        getline(cin >> ws, citizen_name) ;

        cout << "CNIC: ";
        getline(cin >> ws, citizen_CNIC) ;

        cout << "Contact Number: ";
        getline(cin >> ws, citizen_contact) ;

        cout << "Age: ";
        cin >> citizen_age;
        getTime();
        cin.ignore();
    }
    void setNext (Citizen* cp){
        next_citizen = cp;
    }
    Citizen* getNext (){
        return next_citizen;
    }

    [[maybe_unused]] string getName(){
        return citizen_name;
    }
    [[maybe_unused]] string getCNIC(){
        return citizen_CNIC;
    }
    void GetDoseDetails(){
        cout << " Details of Dose 1 " << endl;
        cout << "Enter Blood Pressure: ";
        string bp, pulse, temp;
        getline(cin >> ws,bp);

        cout << "Enter Pulse: ";
        getline(cin >> ws, pulse);

        cout << "Enter Temperature: ";
        getline(cin>>ws, temp);

        dosage1.setDetails(bp,pulse,temp);
        fstream file;
        file.open("Citizen.txt" , ios :: out | ios :: app);
        //file.write ((char *)this, sizeof (Citizen));
        file <<"Citizen Name: " << citizen_name << " Age: " << citizen_age << " Contact number: " << citizen_contact << " CNIC: " << citizen_CNIC
        <<" Appointment time: " << apponintment_time
        << " Blood Pressure(at vaccination time): " << dosage1.getBp()
        << " Pulse: " << dosage1.getPulse() << " Temperature: "
        << dosage1.getTemperature() << endl;
        file.close();
        /*std::time_t result = std::time(nullptr);
        vaccine_time = std::ctime(&result);
        vaccinated = true;*/
    }

    [[maybe_unused]] bool VaccinatedOrNot() const{
        return vaccinated;
    }

    [[maybe_unused]] string GetTime(){
        return apponintment_time;
    }
    void getTime() {
        string temp;
        if (minuets == 60) {
            hours++;
            minuets = 0;
            temp = to_string(hours);
        }
        else {
            temp = to_string(hours);
        }
        temp += ":";
        if ( minuets == 0) {
            string temp_min = "00";
            temp += temp_min;
        }
        else if(minuets == 60){
            minuets = 0;
            string temp_min = "00";
            temp += temp_min;
        }
        else {
            temp += to_string(minuets);
        }
        temp += ":";
        temp += "00";
        apponintment_time = temp;
        minuets += 15;
    }
    void GetDetails(){
        cout << "Citizen Name: " << citizen_name << " "
                << "Citizen ID: "<< citizen_CNIC << " "
                << "Citizen Contact: "<< citizen_contact << " "
                << "Citizen Age: "<< citizen_age << " "
                << "Citizen Appointment Time: "<< apponintment_time << " " << endl;
    }
    void ReadFromFile(){
        string myText;
        fstream file;
        file.open ("Citizen.txt", ios :: in);
        while (getline (file, myText)){
            cout << myText;
        }
        file.close();
    }
    void SetAppointMentNumber(){
        this->appointment_number = appointment_num;
    }
    void CitizenMessage(){
        cout << "What message you want to send: ";
        cin >> message;
        fstream file;
        file.open("Messages.txt" , ios :: out | ios :: app);
        file << citizen_name << " : " << message;
        file.close();
    }
    void DeleteMessage(){
        string deleteline;
        string line;
        ifstream fin;
        fin.open("Messages.txt");
        ofstream temp;
        temp.open("temp.txt");
        cout << "Which line do you want to remove? ";
        cin >> deleteline;
        while (getline(fin,line))
        {
            line.replace(line.find(deleteline),deleteline.length(),"");
            temp << line << endl;

        }
        temp.close();
        fin.close();
        remove("example.txt");
        rename("temp.txt","Messages.txt");

    }
}; int Citizen::minuets = 0;

#endif //DSA_PROJECT_CITIZEN_H
