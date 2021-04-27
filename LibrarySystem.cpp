//
// Created by dumanoglu on 1.12.2020.
//

#include "LibrarySystem.h"
#include "Movie.h"
#include "CircularSinglyLinkedList.h"
#include "CircularDoublyLinkedList.h"
#include "User.h"
#include <fstream>

//this class executes library functions

LibrarySystem::LibrarySystem() = default;

LibrarySystem::~LibrarySystem() = default;

Movie movieFindInCheckOut(int movieId);

Movie movieFindInNotCheckOut(int movieId);

User userControl(int userId
);
extern ofstream  outputFile;

CircularSinglyLinkedList notCheckedMovieList=CircularSinglyLinkedList();

CircularDoublyLinkedList userLinkedList=CircularDoublyLinkedList();
using  namespace std;

void LibrarySystem::addMovie(const int movieId, const string movieTitle, const int year) {
    //this methods adds movies initially in not checked movie list
    if(movieFindInNotCheckOut(movieId).getMovieId()==0&&movieFindInCheckOut(movieId).getMovieId()==0){
        //if movie has not been added already
        Movie movie=Movie(movieId,movieTitle,year,"Not checked out\n");
        notCheckedMovieList.insertNewNode(movie);
        string output="Movie "+to_string(movie.getMovieId())+" has been added\n";
        outputFile<<output;

    }
    else if(movieFindInCheckOut(movieId).getMovieId()!=0){
        //if movie exist in any user lists
        string output="Movie "+to_string(movieId)+" already exists\n";
        outputFile<<output;

    }
    else{
        //if movie exist in not checked out linked list
        string output="Movie "+to_string(movieId)+" already exists\n";
        outputFile<<output;
    }


}

void LibrarySystem::addUser(const int userId, const string userName) {
    //this method adds new users in user list
    if(userControl(userId).getUserId()==0){
        User user=User(userName,userId);
        userLinkedList.insertNewNode(user);
        string output="User "+to_string(userId)+" has been added\n";
        outputFile<<output;
    }
    else{
        //if a user aldready exist
        string output="User "+to_string(userId)+" already exists\n";
        outputFile<<output;
    }

}

void LibrarySystem::showAllMovie() {
    //this method shows all recorded movies either checked or not
    outputFile<<"Movie id - Movie name - Year - Status\n";
    DoublyNode* userTemp=userLinkedList.head;
    SinglyNode* movieTemp=notCheckedMovieList.head;
    if(movieTemp!= nullptr){//writes not checked out movies
        do{
            string output=to_string(movieTemp->data.getMovieId())+" "+movieTemp->data.getMovieTitle()
                          +" "+to_string(movieTemp->data.getMovieYear())+" Not checked out\n";
            outputFile<<output;
            movieTemp=movieTemp->next;
        }
        while(movieTemp!=notCheckedMovieList.head);
    }
    if(userTemp!=nullptr){//writes checked out movies by users
        if(userTemp->data.getCheckOutLinkedList().head!= nullptr){
            do{
                SinglyNode* temp3=userTemp->data.getCheckOutLinkedList().head;
                if(temp3!= nullptr){
                    do{
                        string output=to_string(temp3->data.getMovieId())+" "+temp3->data.getMovieTitle()
                                      +" "+to_string(temp3->data.getMovieYear())+" "+temp3->data.getStatus()+"\n";
                        outputFile<<output;
                        temp3=temp3->next;}
                    while(temp3!=userTemp->data.getCheckOutLinkedList().head);
                }

                userTemp=userTemp->next;
            }while(userTemp!=userLinkedList.head);
        }
    }

}

void LibrarySystem::checkOutMovie(const int movieId, const int userId) {
    //this methods adds check out movies to checker user and deletes from not checked linked list
    DoublyNode* temp2=userLinkedList.head;
    if(temp2!=nullptr){
        do{
            if(movieFindInNotCheckOut(movieId).getMovieId()!=0){//it controls movie exist or not in not checked out linked list
                if(temp2->data.getUserId()==userId&&userControl(userId).getUserId()!=0){
                    CircularSinglyLinkedList linkedList=temp2->data.getCheckOutLinkedList();
                    Movie newMovie=movieFindInNotCheckOut(movieId);
                    string status="Checked out by User "+to_string(userId);
                    newMovie.setStatus(status);//change status to checked
                    linkedList.insertNewNode(newMovie);//insert movie in users lists
                    temp2->data.setCheckOutLinkedList(linkedList);
                    string output="Movie "+to_string(movieId)+" has been checked out by User "+to_string(userId)+"\n";
                    outputFile<<output;
                    break;}
                else if(userControl(userId).getUserId()==0){//it controls users exist or not
                    string output="User "+to_string(userId)+" does not exist for checkout\n";
                    outputFile<<output;
                    break;
                }}
            else if(movieFindInNotCheckOut(movieId).getMovieId()==0){//it controls movie exist or not
                string output="Movie "+to_string(movieId)+" does not exist for checkout\n";
                outputFile<<output;
                break;
            }
            temp2=temp2->next;
        }
        while(temp2!=userLinkedList.head);

        if(userControl(userId).getUserId()!=0&&movieFindInNotCheckOut(movieId).getMovieId()!=0){
            notCheckedMovieList.deleteNode(movieId);
        }
    }


}

void LibrarySystem::showMovie(const int movieId) {
    //it shows particular movie
    if(movieFindInCheckOut(movieId).getMovieId()!=0){//if movie is checked out
        Movie particularMovie=movieFindInCheckOut(movieId);
        string output=to_string(particularMovie.getMovieId())+" "+particularMovie.getMovieTitle()+" "+to_string(particularMovie.getMovieYear())+" "+particularMovie.getStatus()+"\n";
        outputFile<<output;
    }
    else if(movieFindInNotCheckOut(movieId).getMovieId()!=0){//if movie is not checked out
        Movie particularMovie=movieFindInNotCheckOut(movieId);
        string output=to_string(particularMovie.getMovieId())+" "+particularMovie.getMovieTitle()+" "+to_string(particularMovie.getMovieYear())+" "+particularMovie.getStatus()+"\n";
        outputFile<<output;
    }
    else{
        //movie does not exist
        outputFile<<"Movie with the id "+to_string(movieId)+" does not exist\n";

    }



}

void LibrarySystem::showUser(const int userId) {
    //it shows particular  user and her/hims checked movies
    if(userControl(userId).getUserId()!=0){
        User particularUser=userControl(userId);
        outputFile<<"User id: "+to_string(particularUser.getUserId())+" "+"User name: "+particularUser.getUserName()+"\n";
        outputFile<<"User "+to_string(particularUser.getUserId())+" checked out the following Movies:\n";
        SinglyNode* temp7=particularUser.getCheckOutLinkedList().head;
        if(temp7!=nullptr){
            outputFile<<"Movie id - Movie name - Year\n";
            do{//it writes him/hers checked movies
                outputFile<<to_string(temp7->data.getMovieId())+" "+temp7->data.getMovieTitle()+" "+to_string(temp7->data.getMovieYear())+"\n";
                temp7=temp7->next;
            }
            while(temp7!=particularUser.getCheckOutLinkedList().head);
        }

    }

}

void LibrarySystem::deleteMovie(const int movieId) {
    //deletes movies
    if(movieFindInCheckOut(movieId).getMovieId()!=0){//if movie is checked it deletes movies from users checked lists
        DoublyNode* temp2=userLinkedList.head;
        if(temp2!=nullptr){
            do{
                SinglyNode* temp3=temp2->data.getCheckOutLinkedList().head;
                if(temp2->data.getCheckOutLinkedList().head!= nullptr){
                    do{
                        if(temp3->data.getMovieId()==movieId){
                            CircularSinglyLinkedList userList=temp2->data.getCheckOutLinkedList();
                            userList.deleteNode(movieId);
                            temp2->data.setCheckOutLinkedList(userList);
                            break;
                        }
                        temp3=temp3->next;
                    }while(temp3!=temp2->data.getCheckOutLinkedList().head);
                }
                temp2=temp2->next;
            }
            while(temp2!=userLinkedList.head);

        }
        outputFile<<"Movie "+to_string(movieId)+" has been checked out\n";
        outputFile<<"Movie "+to_string(movieId)+" has been deleted\n";
    }
    else if(movieFindInNotCheckOut(movieId).getMovieId()!=0){//if movie is not checked deletes from users lists
        notCheckedMovieList.deleteNode(movieId);
        outputFile<<"Movie "+to_string(movieId)+" has not been checked out\n";
        outputFile<<"Movie "+to_string(movieId)+" has been deleted\n";
    }
    else{//if movie does not exist it gives warning
        outputFile<<"Movie "+to_string(movieId)+" does not exist\n";
    }

}

void LibrarySystem::deleteUser(const int userId) {
    //this method deletes users with its movies if user exists
    if(userControl(userId).getUserId()!=0){//if user exist
        userLinkedList.deleteNode(userId);
        outputFile<<"User"+to_string(userId)+" has been deleted\n";
    }
    else{//if user not exist
        outputFile<<"User "+to_string(userId)+" does not exist\n";
    }

}

void LibrarySystem::returnMovie(const int movieId) {
    //this function return movie which is in the users list to not checked out movies list
    if(movieFindInCheckOut(movieId).getMovieId()!=0){//if movie exist in any users checked list
        DoublyNode* temp2=userLinkedList.head;
        if(temp2!=nullptr){
            do{
                SinglyNode* temp3=temp2->data.getCheckOutLinkedList().head;
                if(temp2->data.getCheckOutLinkedList().head!= nullptr){
                    do{
                        if(temp3->data.getMovieId()==movieId){
                            CircularSinglyLinkedList userList=temp2->data.getCheckOutLinkedList();
                            Movie returned=movieFindInCheckOut(movieId);
                            returned.setStatus("Not checked out");//if it finds it changes its status to not checked
                            notCheckedMovieList.insertNewNode(returned);
                            userList.deleteNode(movieId);
                            temp2->data.setCheckOutLinkedList(userList);
                            break;
                        }
                        temp3=temp3->next;
                    }while(temp3!=temp2->data.getCheckOutLinkedList().head);
                }
                temp2=temp2->next;
            }
            while(temp2!=userLinkedList.head);

        }
        outputFile<<"Movie "+to_string(movieId)+" has been returned\n";
    }
    else if(movieFindInNotCheckOut(movieId).getMovieId()!=0){//if movie is not checked out
        outputFile<<"Movie "+to_string(movieId)+" has not been checked out\n";
    }
    else{//if movie is not exist in library
        outputFile<<"Movie "+to_string(movieId)+" not exist in the library\n";
    }

}

Movie movieFindInNotCheckOut(int movieId){
    //this method checks a movie exist and not checked by any user and if movie exist in not checked out lists it returns this movie
    SinglyNode* temp1=notCheckedMovieList.head;
    if(temp1!= nullptr) {
        do{
            if(temp1->data.getMovieId()==movieId){
                return temp1->data;

            }
            temp1=temp1->next;
        }
        while(temp1!=notCheckedMovieList.head);
    }
    return Movie();
}
Movie movieFindInCheckOut(int movieId){
    //this method checks if a movie is checked out by any users and if checked returns this movie
    DoublyNode* temp2=userLinkedList.head;
    if(temp2!=nullptr){
        do{
            SinglyNode* temp3=temp2->data.getCheckOutLinkedList().head;
            if(temp2->data.getCheckOutLinkedList().head!= nullptr){
                do{
                    if(temp3->data.getMovieId()==movieId){
                        return temp3->data;
                    }
                    temp3=temp3->next;
                }while(temp3!=temp2->data.getCheckOutLinkedList().head);
            }
            temp2=temp2->next;
        }
        while(temp2!=userLinkedList.head);

    }
    return Movie();
}

User userControl(int userId){
    //this method controls if a user exist or not in users linked list and isf it exist it returns user
    DoublyNode* temp4=userLinkedList.head;
    if(temp4!= nullptr){
        do{
            if(temp4->data.getUserId()==userId){
                return temp4->data;
            }
            temp4=temp4->next;
        }
        while(temp4!=userLinkedList.head);
    }
    return User();
}
