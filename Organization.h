//
// Created by Mirza on 7/10/2021.
//

#ifndef DSA_PROJECT_Organization_H
#define DSA_PROJECT_Organization_H
#include <string>
#include <utility>
#include "Center.h"
#include "LinkedList.h"
using namespace std;
class Organization {
private:
    string org_name, org_contact;
    int org_vaccine;
    LinkedList<Center> center_list;
    unsigned int id;
public:
      explicit Organization(string name = {"Oxford"}, string contact={"37350329"}, int t_vaccine=5000)
    {
        org_name = std::move(name);
        org_contact = std::move(contact);
        org_vaccine = t_vaccine;
        id = 0;
    }

    [[maybe_unused]] void SetOrgDetails(){
        cout << "Enter Organisation Name: ";
        getline(cin >> ws, org_name);

        cout << "Enter Organisation Contact: ";
        getline(cin >> ws, org_contact);

    }

    [[maybe_unused]] void ChangeOrganizationName(char* name ){
        org_name = name;
        id = 0;
    }

    [[maybe_unused]] void ChangeContact(char* contact){
        org_contact = contact;
    }

    [[maybe_unused]] void AddVaccine (int vac){
        org_vaccine += vac;
    }

    [[maybe_unused]] string GetOrgName() {
        return org_name;
    }

    [[maybe_unused]] string GetContact(){
        return org_contact;
    }

    [[maybe_unused]] [[nodiscard]] int GetVaccineCount() const{
        return org_vaccine;
    }

    [[maybe_unused]] void DecVaccineCount (){
        org_vaccine--;
    }

    [[maybe_unused]] void Display(){
        cout << "Organization name: " << org_name << " "
        << "Organization Contact: " << org_contact << " "
        << "Organization Vaccine Count: " << org_vaccine << endl;
    }
    bool AddCenter(){
        if(org_vaccine < 200){
            cerr << "Not enough vaccines to create another center! " << endl;
            return false;
        }else {
            center_list.append();
            //center_list.getLast()->setID(id);
            org_vaccine -= 200;
            return true;
        }
    }
    bool AddCitizen(){
          if(center_list.getLast()->VaccineCount() == 0){
              cout << center_list.getLast()->GetManager().SendMessage();
              return false;
          }else {
              center_list.getLast()->AppendCitien();
              return true;
          }
    }
    void DisplayCitizenList(){
        center_list.Display();
    }
    void ReadManagerDetails() {
        center_list.getLast()->ManagerDetails();
    }
    void ReadCitizenDetails() {
        center_list.getLast()->CitizenDetails();
    }
    void DeleteAppoinment() {
        center_list.getLast()->RemoveCitizen();
    }
    void Delete(int p){
          center_list.getLast()->Delete(p);
      }
    void CitizenMessage(){
          center_list.getLast()->CitizenMessage();
    }
    void DeleteCitizenMessage(){
          center_list.getLast()->DeleteCitizenMessage();
    }
    void ManagerMessage(){
          center_list.getLast()->ManagerMessage();
    }
    void DelteManagerMessage(){
        center_list.getLast()->DeleteManagerMessage();
    }
};


#endif //DSA_PROJECT_Organization_H
