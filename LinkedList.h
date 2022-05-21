//
// Created by Mirza on 7/17/2021.
//

#ifndef DSA_PROJECT_LINKEDLIST_H
#define DSA_PROJECT_LINKEDLIST_H
/*string citizen_name, citizen_CNIC;
        string citizen_contact;
        int age;
        Dose dosage1, dosage2;*/
#include "Citizen.h"
#include "Manager.h"
template <class Type>
class LinkedList {
    Type *head, *tail;
    int total;
public:
    LinkedList(){
        head = tail = nullptr;
        total = 0;
    }
    void append (){
        Type *temp = new Type;
        if(head == nullptr && tail == nullptr){
            head = tail = temp;
            total++;
            cout << "Nodes: " << total << endl;
        }else{
            tail->setNext(temp);
            tail = temp;
            total++;
            cout << "Nodes: " << total << endl;
        }
    }
    void Display(){
        for(auto* temp = head; temp != nullptr; temp = temp->getNext()){
            temp->GetDetails();
        }
    }
    Type* getLast(){
        return tail;
    }
    Type* getFirst(){
        return head;
    }
    void removeFirst(){
        head = head->getNext();
    }

    [[maybe_unused]] void removeLast(){
        for(auto temp = head; temp != nullptr; temp = temp.getNext()){
            if(temp.getNext() == tail){
                tail = temp;
                tail->setNext(nullptr);
            }
        }
    }

    [[maybe_unused]] bool removeAtPoisiton(Type* found, int back){
        Type* backNode = getNode(back);
        if(found){
            backNode->setNext(found->getNext());
            delete found;
            return true;
        }
        else{
            removeFirst();
            return true;
        }
        return false;
    }
    Type* getNode(int number){
        Type* node = head;
        if(number > total){
            return NULL;
        }else {
            for(int i{1}; i<number; i++) {
                node = node->getNext();
            }
        }
        return node;
    }
};


#endif //DSA_PROJECT_LINKEDLIST_H
// append, prepend
// get first, get last
//  remove first, remove last
//Manager center_manager;
//    int center_vaccine;
//    string availiable_slot;
//    string center_regNo;