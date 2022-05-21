//
// Created by Mirza on 7/11/2021.
//

#ifndef DSA_PROJECT_MANAGER_H
#define DSA_PROJECT_MANAGER_H
#include <iostream>
#include <fstream>
using namespace std;
class Manager {
private:
    string manager_name, manager_contact, manager_CNIC;
    string message;
    int age;
public:
    Manager(){

        age = 0;
    }

    void EnterDetails (){
        cout << "Manager Name: ";
        getline(cin >> ws, manager_name);

        cout << "CNIC: ";
        getline(cin >> ws, manager_CNIC);

        cout << "Contact Number: ";
        getline(cin >> ws, manager_contact);

        cout << "Age: ";
        cin >> age;
        fstream file;
        file.open("Manager.txt" , ios :: out | ios :: app);
        file << "Manager Name: " << manager_name << " Contact: " << manager_contact << " CNIC: " << manager_CNIC << " " << age << endl;
        file.close();
    }
    [[maybe_unused]] string getName(){
        return manager_name;
    }
    [[maybe_unused]] string getCNIC(){
        return manager_CNIC;
    }
    void GetDetails(){
        cout << "Manager: " << manager_name << " "
        << "CNIC:" <<manager_CNIC << " "
        << "Contact Number: " <<manager_contact << " "
        << "Age: " <<age << endl;

    }
    void ReadFromFile(){
        string myText;
        fstream file;
        file.open ("Manager.txt", ios :: in);
        while (getline (file, myText)){
            cout << myText;
        }
        file.close();
    }
    string SendMessage(){
        message = "Not Enough slots available, Make a new Center!";
        return message;
    }
    void Message(){
        cout << "What message you want to send: ";
        cin >> message;
        fstream file;
        file.open("Messages.txt" , ios :: out | ios :: app);
        file << manager_name << " : " << message;
        file.close();
    }
    void DeleteMessage(){
        string deleteline;
        string line;
        ifstream fin;
        fin.open("Manager_Messages.txt");
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
        rename("temp.txt","Manager_Messages.txt");

    }
};


#endif //DSA_PROJECT_MANAGER_H
