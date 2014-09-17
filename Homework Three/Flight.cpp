//
//  Flight.cpp
//  Homework Three
//
//  Created by dunkuCoder on 23/07/14.
//  Copyright (c) 2014 Çağdaş Öztekin. All rights reserved.
//

#include "Flight.h"
#include <iostream>

using std::cout;
using std::endl;

Flight::Passenger* Flight::Passenger::getNext()
{
    return pNext;
}

void Flight::Passenger::setNext(Passenger* pNext)
{
    this->pNext = pNext;
}

Flight::Flight( const int flightId, const string fromCity, const string toCity )
{
    this->flightId = flightId;
    this->fromCity = fromCity;
    this->toCity = toCity;
}

Flight::~Flight()
{
    if(pHead != NULL)
    {
        Passenger* sawyer = pHead;
        while(sawyer != NULL)
        {
            Passenger* oc = sawyer;
            sawyer = sawyer->pNext;
            delete oc;
        }
    }
    
    if(fNext != NULL)
    {
        delete fNext;
    }
}

Flight* Flight::getNextFlight()
{
    return fNext;
}

void Flight::setNextFlight(Flight* nextFlight)
{
    fNext = nextFlight;
}

int Flight::getFlightId()
{
    return flightId;
}

string Flight::getFlightFrom()
{
    return fromCity;
}

string Flight::getFlightTo()
{
    return toCity;
}

Flight::Passenger* Flight::getHeadPassenger()
{
    return pHead;
}

void Flight::setHeadPassenger(Flight::Passenger* head)
{
    pHead = head;
}

void Flight::addPassenger(const string firstName, const string lastName)
{
    if(pHead == NULL)
    {
        pHead = new Passenger;
        pHead->firstName = firstName;
        pHead->lastName = lastName;
    }
    else
    {
        bool alreadyExists = false;
        Passenger* current = pHead;
        
        while(current->pNext != NULL)
        {
            if(firstName.compare(current->firstName) == 0 && lastName.compare(current->lastName) == 0)
            {
                alreadyExists = true;
            }
            
            current = current->pNext;
        }
        
        if(alreadyExists)
        {
            cout<<"passenger already exists"<<endl;
        }
        else
        {
            current->pNext = new Passenger;
            current->pNext->firstName = firstName;
            current->pNext->lastName = lastName;
        }
    }
}