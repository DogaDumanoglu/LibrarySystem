
#ifndef UNTITLED8_CIRCULARDOUBLYLINKEDLIST_H
#define UNTITLED8_CIRCULARDOUBLYLINKEDLIST_H

#include "User.h"
//this class hold users in circular linked list
class DoublyNode{
public:
    User data;
    DoublyNode* next = nullptr;
    DoublyNode* prev= nullptr;

};
class CircularDoublyLinkedList {
public:
    CircularDoublyLinkedList() = default;
    void insertNewNode(User user);
    void deleteNode(int userId);

    DoublyNode* head=nullptr;
    DoublyNode *tail=head;


};


#endif //UNTITLED8_CIRCULARDOUBLYLINKEDLIST_H
