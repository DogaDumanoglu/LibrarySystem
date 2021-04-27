//
// Created by dumanoglu on 1.12.2020.
//

#include "Movie.h"
//getters setters and constructors
int Movie::getMovieId() const {
    return movieId;
}

void Movie::setMovieId(int id) {
    Movie::movieId = id;
}

const string &Movie::getMovieTitle() const {
    return movieTitle;
}

void Movie::setMovieTitle(const string &title) {
    Movie::movieTitle = title;
}

int Movie::getMovieYear() const {
    return movieYear;
}

void Movie::setMovieYear(int year) {
    Movie::movieYear = year;
}

Movie::Movie(int movieId, const string &movieTitle, int movieYear,const string& status) {
    setMovieId(movieId);
    setMovieTitle(movieTitle);
    setMovieYear(movieYear);
    setStatus("Not checked out");

}

const string &Movie::getStatus() const {
    return status;
}

void Movie::setStatus(const string &stat) {
    Movie::status = stat;
}

Movie::~Movie() = default;

Movie::Movie() = default;
