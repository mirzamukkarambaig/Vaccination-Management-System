//
// Created by Mirza on 7/19/2021.
//

#ifndef DSA_PROJECT_CENTER_H
#define DSA_PROJECT_CENTER_H
#include "Manager.h"
#include "LinkedList.h"
#include <string>
extern int id;
class Center {
    Manager center_manager;
    LinkedList<Citizen> citizen_list;
    unsigned int center_id;
    unsigned int center_vaccine;
    Center* next;
public:
    Center(){
        center_manager.EnterDetails();
        next = nullptr;
        center_vaccine = 200;
        center_id = id;
        id++;
    };
    void AppendCitien(){
        if(center_vaccine > 0) {
            citizen_list.append();
            center_vaccine--;
        }else{
            cerr << center_manager.SendMessage() << endl;
        }
    }

    [[maybe_unused]] void DisplayCitizenList(){
        citizen_list.Display();
    }
    void setNext (Center* cp){
        next = cp;
    }
    Center* getNext (){
        return next;
    }

    [[maybe_unused]] void RemoveCitizen(){
        citizen_list.removeFirst();
    }
    void GetDetails(){
        center_manager.GetDetails();
        cout << "Center ID: " << center_id << endl;
        cout << "Center Vaccine Count: " << center_vaccine << endl;
        citizen_list.Display();
    }
    void ManagerDetails(){
        center_manager.ReadFromFile();
    }
    void CitizenDetails(){
        citizen_list.getLast()->ReadFromFile();
    }
    unsigned int VaccineCount(){
        return center_vaccine;
    }
    void Delete(int p){
        Citizen* temp = citizen_list.getNode(p);
        citizen_list.removeAtPoisiton(temp, p-1);
    }
    Manager GetManager(){
        return center_manager;
    }
    void CitizenMessage(){
        citizen_list.getLast()->CitizenMessage();
    }
    void DeleteCitizenMessage(){
        citizen_list.getLast()->DeleteMessage();
    }
    void ManagerMessage(){
        center_manager.Message();
    }
    void DeleteManagerMessage(){
        center_manager.DeleteMessage();
    }
};


#endif //DSA_PROJECT_CENTER_H
