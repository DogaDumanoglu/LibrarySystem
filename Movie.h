//
// Created by dumanoglu on 1.12.2020.
//
//add möovie vs hatalı düzelt check ouyt bıdı bıdı
#ifndef UNTITLED8_MOVIE_H
#define UNTITLED8_MOVIE_H
#include <iostream>

using namespace std;
class Movie {
private:
    int movieId=0;
    string movieTitle;
    int movieYear=0;
    string status="Not checked out";
public:
    int getMovieId() const;

    void setMovieId(int movieId);

    const string &getMovieTitle() const;

    void setMovieTitle(const string &movieTitle);

    int getMovieYear() const;

    void setMovieYear(int movieYear);

    const string &getStatus() const;

    void setStatus(const string &status);

public:
    Movie(int movieId,const string& movieTitle,int movieYear,const string& status);
    Movie();
    ~Movie();
};


#endif //UNTITLED8_MOVIE_H
