
using namespace std;
int id = 0;
int appointment_num = 1;
#include "Menu.h"
#include "Singleton.h"
void Menu() {
    Singleton *s = s->getSharedInstance();
    bool want_to_continue = true;
    do {
        cout << "Vaccination Application" << endl;
        cout << "=======================" << endl;
        cout << "Press: " << endl
             << "C - Register yourself for Vaccination " << endl
             << "M - Message to cancel appointment " <<endl
             << "O - Manager "
             << "T - Create Center " << endl
             << "R - Read from Existing Files " << endl
             << "E - Exit " << endl;
        char word = {};
        cout << "Enter here: ";
        cin >> word;
        if (word == 'r' || word == 'R'){
            s->ReadFromFile();
        }
        if (word == 't' || word == 'T') {
            s->CreateCenter();
        }
        if(word == 'o' || word == 'O'){
            char otherWord{};
            do {
                cout << "Do you want to send message? " << endl
                     << "Y - to message " << endl
                     << "E - Exit " << endl;
                cin >> otherWord;
                if(otherWord == 'y' || otherWord == 'Y'){
                    s->ManagerMessage();
                }
                else{
                    break;
                }
            }while(otherWord == 'e');
            while(true){
                char otherWord{};
                cout << "Do you want to Delete a message? " << endl
                     << "Y - to message " << endl
                     << "E - Exit " << endl;
                cin >> otherWord;
                if(otherWord == 'y' || otherWord == 'Y'){
                    s->ManagerMessageDel();
                }
                else{
                    break;
                }
            }
        }
        if (word == 'c' || word == 'C') {
            s->CreteEntry();
            char otherWord{};
            do {
                cout << "Do you want to send message? " << endl
                << "Y - to message " << endl
                << "E - Exit " << endl;
                cin >> otherWord;
                if(otherWord == 'y' || otherWord == 'Y'){
                    s->CitizenMessage();
                }
                else{
                    break;
                }
            }while(otherWord == 'e');
            while(true){
                char otherWord{};
                cout << "Do you want to Delete a message? " << endl
                        << "Y - to message " << endl
                        << "E - Exit " << endl;
                cin >> otherWord;
                if(otherWord == 'y' || otherWord == 'Y'){
                    s->DeleteCitizenMessage();
                }
                else{
                    break;
                }
            }
        }
        if (word == 'm' || word == 'M') {
            cout << "Enter your Appointment Number: ";
            int p{};
            cin >> p;
            s->Delete(p);
        }
        if (word == 'e' || word == 'E') {
            break;
        }
    } while (want_to_continue = true);
    return;
}
int main() {
    Menu();
    return 0;
}