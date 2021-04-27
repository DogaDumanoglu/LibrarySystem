//
// Created by dumanoglu on 1.12.2020.
//

#ifndef UNTITLED8_CIRCULARSINGLYLINKEDLIST_H
#define UNTITLED8_CIRCULARSINGLYLINKEDLIST_H

#include "Movie.h"
//This class hold movies in a circular linked list
class SinglyNode{
public:
    Movie data;
    SinglyNode* next=nullptr;
    SinglyNode();
};

class CircularSinglyLinkedList {
public:
    CircularSinglyLinkedList();
    void insertNewNode(Movie movie);
    void deleteNode(int movieId);
    SinglyNode* head=nullptr;
    SinglyNode* tail=head;

};


#endif //UNTITLED8_CIRCULARSINGLYLINKEDLIST_H
