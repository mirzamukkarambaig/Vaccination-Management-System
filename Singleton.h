//
// Created by Mirza on 7/18/2021.
//

#ifndef DSA_PROJECT_SINGLETON_H
#define DSA_PROJECT_SINGLETON_H

#include "Organization.h"
class Singleton {
private:
    static Singleton *instance;
    Organization astra_zeneca;
    Singleton() {}
public:
    static Singleton* getSharedInstance(){
        if(!instance){
            instance = new Singleton();
        }
        return instance;
    }
    void CreateCenter(){
        bool what = astra_zeneca.AddCenter();
        if(what == false){
            cerr << "Add Vaccince" << endl;
            astra_zeneca.AddVaccine(5000);
            astra_zeneca.AddCenter();
        }
    }
    void CreteEntry(){
        bool what = astra_zeneca.AddCitizen();
        if(what == false){
            astra_zeneca.AddCenter();
            astra_zeneca.AddCitizen();
        }
    }
    void Display(){
        astra_zeneca.DisplayCitizenList();
    }
    void ReadFromFile(){
        astra_zeneca.ReadManagerDetails();
        astra_zeneca.ReadCitizenDetails();
    }
    void DirectDisplay(){
        astra_zeneca.DisplayCitizenList();
    }
    void CancelAppointment(){
        astra_zeneca.DeleteAppoinment();
    }
    void Delete(int p){
        astra_zeneca.Delete(p);
    }
    void DeleteCitizenMessage(){
        astra_zeneca.DeleteCitizenMessage();
    }
    void CitizenMessage(){
        astra_zeneca.CitizenMessage();
    }
    void ManagerMessage(){
        astra_zeneca.ManagerMessage();
    }
    void ManagerMessageDel(){
        astra_zeneca.DelteManagerMessage();
    }
}; Singleton *Singleton::instance = nullptr;


#endif //DSA_PROJECT_SINGLETON_H
