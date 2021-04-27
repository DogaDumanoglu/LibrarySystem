//
// Created by dumanoglu on 1.12.2020.
//

#ifndef UNTITLED8_LIBRARYSYSTEM_H
#define UNTITLED8_LIBRARYSYSTEM_H
#include <iostream>
using namespace std;
class LibrarySystem {
public:

    LibrarySystem();
    ~LibrarySystem();

    void addMovie(const int movieId,const string movieTitle,const int year);
    void deleteMovie(const int movieId);

    void addUser(const int userId,const string username);
    void deleteUser(const int userId);

    void checkOutMovie(const int movieId,const int userId);
    void returnMovie(const int movieId);

    void showAllMovie();

    void showMovie(const int movieId);
    void showUser(const int userId);


};


#endif //UNTITLED8_LIBRARYSYSTEM_H
