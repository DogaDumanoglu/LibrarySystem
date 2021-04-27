//
// Created by dumanoglu on 1.12.2020.
//

#ifndef UNTITLED8_USER_H
#define UNTITLED8_USER_H
#include <iostream>
#include "CircularSinglyLinkedList.h"

using namespace std;
class User {
private:
    string userName;
    int userId=0;
    CircularSinglyLinkedList checkOutLinkedList;
public:
    const string &getUserName() const;

    void setUserName(const string &userName);

    int getUserId() const;

    void setUserId(int userId);

    const CircularSinglyLinkedList &getCheckOutLinkedList() const;

    void setCheckOutLinkedList(const CircularSinglyLinkedList &checkOutLinkedList);

    User(const string& username,int userId);
    User();
};


#endif //UNTITLED8_USER_H
