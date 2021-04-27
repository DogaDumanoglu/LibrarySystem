//
// Created by dumanoglu on 1.12.2020.
//

#include "User.h"

const string &User::getUserName() const {
    return userName;
}

void User::setUserName(const string &name) {
    User::userName = name;
}

int User::getUserId() const {
    return userId;
}

void User::setUserId(int id) {
    User::userId = id;
}

const CircularSinglyLinkedList &User::getCheckOutLinkedList() const {
    return checkOutLinkedList;
}

void User::setCheckOutLinkedList(const CircularSinglyLinkedList &list) {
    User::checkOutLinkedList = list;
}

User::User(const string &username, int userId) {
    setUserName(username);
    setUserId(userId);
    setCheckOutLinkedList(CircularSinglyLinkedList());

}

User::User() = default;
