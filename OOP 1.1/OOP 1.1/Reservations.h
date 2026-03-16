#pragma once
#include "User.h"
#include "Book.h"

class ReservationRequest
{
public:
    User* user;
    Book* book;
    bool approved = false;

    ReservationRequest(User* user, Book* book);
};