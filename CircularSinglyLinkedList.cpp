//
// Created by dumanoglu on 1.12.2020.
//

#include "CircularSinglyLinkedList.h"


CircularSinglyLinkedList::CircularSinglyLinkedList() = default;

void CircularSinglyLinkedList::insertNewNode(Movie movie) {
    auto* newSinglyNode=new SinglyNode();
    newSinglyNode->data=movie;
    if(head==nullptr){//if head is null
        head=tail=newSinglyNode;
    }
    else{
        tail->next=newSinglyNode;
        tail=tail->next;
    }
    tail->next=head;
}

void CircularSinglyLinkedList::deleteNode(int movieId) {
    // If linked list is empty
    if (head == nullptr)
        return;

    // If the list contains only a single node
    if(head->data.getMovieId()==movieId && head->next==head)
    {
        free(head);
        head= nullptr;
        return;
    }

    SinglyNode* last=head,*d;

    // If head will be deleted
    if(head->data.getMovieId()==movieId)
    {

        // Find the last node
        while(last->next!=head){
            last=last->next;
        }

        last->next=head->next;
        free(head);
        head=last->next;
    }


    while(last->next!=head&&last->next->data.getMovieId()!=movieId)
    {
        last=last->next;
        tail=last;
    }

    // If node to be deleted was found
    if(last->next->data.getMovieId()==movieId)
    {
        d=last->next;
        last->next=d->next;
        free(d);
    }
    }
SinglyNode::SinglyNode() = default;
