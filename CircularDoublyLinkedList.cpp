
#include "CircularDoublyLinkedList.h"

void CircularDoublyLinkedList::insertNewNode(User user) {
    //this methods inserts new node in linked list
    auto *newDoublyNode =new DoublyNode();
    newDoublyNode->data=std::move(user);
    //if linked list is empty
    if(head==nullptr){
        head=tail=newDoublyNode;
        head->next=head;
        head->prev=head;
    }
    else{
        tail->next=newDoublyNode;
        newDoublyNode->prev=tail;
        newDoublyNode->next=head;
        head->prev=newDoublyNode;
        tail=newDoublyNode;
    }
    tail->next=head;

}

void CircularDoublyLinkedList::deleteNode(int userId) {
        // If linked list is empty
        if (head == nullptr)
            return;

        // If the list contains one node
        if(head->data.getUserId()==userId && head->next==head)
        {
            free(head);
            head= nullptr;
            return;
        }

        DoublyNode* last=head,*deleteNode;

        // If head will be deleted
        if(head->data.getUserId()==userId)
        {

            while(last->next!=head)
                last=last->next;


            last->next=head->next;
            free(head);
            head=last->next;
        }
        // If node to be deleted was found
        while(last->next!=head&&last->next->data.getUserId()!=userId)
        {
            last=last->next;
            tail=last;
        }


        if(last->next->data.getUserId()==userId)
        {
            deleteNode=last->next;
            last->next=deleteNode->next;
            free(deleteNode);
        }

}
