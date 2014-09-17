//
//  AirlineReservationSystem.cpp
//  Homework Three
//
//  Created by dunkuCoder on 23/07/14.
//  Copyright (c) 2014 Çağdaş Öztekin. All rights reserved.
//

#include <iostream>
#include "AirlineReservationSystem.h"

using std::cout;
using std::endl;

AirlineReservationSystem::AirlineReservationSystem()
{
    fHead = NULL;
}

AirlineReservationSystem::~AirlineReservationSystem()
{
    delete fHead;
}

void AirlineReservationSystem::addFlight(const int flightId, const string fromCity, const string toCity)
{
    int closestId = -1;
    bool alreadyExists = false;
    Flight* currentFlight = getFlightHead();
    while(currentFlight != NULL && !alreadyExists)
    {
        if(currentFlight->getFlightId() == flightId)
        {
            alreadyExists = true;
        }
        else if(currentFlight->getFlightId() < flightId)
        {
            closestId = currentFlight->getFlightId();
        }
        
        currentFlight = currentFlight->getNextFlight();
    }
    
    if(alreadyExists)
    {
        cout<<"Flight already exists!"<<endl;
    }
    
    else
    {
        Flight* newFlight = new Flight(flightId, fromCity, toCity);
        if(closestId == -1)
        {
            if(fHead == NULL)
            {
                fHead = newFlight;
            }
            else
            {
                newFlight->setNextFlight(fHead);
                fHead = newFlight;
            }
        }
        else
        {
            currentFlight = fHead;
            
            while(currentFlight->getFlightId() != closestId)
            {
                if(currentFlight->getNextFlight() != NULL)
                {
                    currentFlight = currentFlight->getNextFlight();
                }
                
            }
            if(currentFlight->getFlightId() == closestId)
            {
                newFlight->setNextFlight(currentFlight->getNextFlight());
                currentFlight->setNextFlight(newFlight);
            }
            
        }
    }
}

void AirlineReservationSystem::showAllFlights() const
{
    Flight* current = fHead;
    while(current != NULL)
    {
        cout<<"Flight "<<current->getFlightId()<<": from "<<current->getFlightFrom()<<" to "<<current->getFlightTo()<<":"<<endl;
        Flight::Passenger* currentP = current->getHeadPassenger();
        
        while(currentP != NULL)
        {
            cout<<currentP->firstName<<" "<<currentP->lastName<<endl;
            currentP = currentP->pNext;
        }
        
        cout<<endl;
        
        current = current->getNextFlight();
    }
}

Flight* AirlineReservationSystem::getFlightHead()
{
    return fHead;
}

void AirlineReservationSystem::removeFlight(const int flightId)
{
    Flight* current = fHead;
    Flight* previous = NULL;
    bool deleted = false;
    
    while(current != NULL && !deleted)
    {
        if(current->getFlightId() == flightId)
        {
            Flight* next = current->getNextFlight();
            
            if(previous == NULL)
            {
                fHead = next;
            }
            else
            {
                previous->setNextFlight(next);
            }
            
            current->setNextFlight(NULL);
            deleted = true;
            delete current;
        }
        
        if(!deleted)
        {
            previous = current;
            current = current->getNextFlight();
        }
    }
    
    if(!deleted)
    {
        cout<<"flight with that id not found"<<endl;
    }
}

void AirlineReservationSystem::addPassenger(const int flightId, const string firstName, const string lastName)
{
    bool exists = false;
    Flight* current = fHead;
    
    while(current != NULL && !exists)
    {
        if(current->getFlightId() == flightId)
        {
            exists = true;
        }
        
        if(!exists)
        {
            current = current->getNextFlight();
        }
    }
    
    if(!exists)
    {
        cout<<"flight with given id does not exist"<<endl;
    }
    else
    {
        current->addPassenger(firstName, lastName);
    }
}

void AirlineReservationSystem::showPassenger(const string firstName, const string lastName) const
{
    Flight* currentF = fHead;
    Flight::Passenger* currentP;
    cout<<"Flights for "<<firstName<<" "<<lastName<<endl;
    while(currentF != NULL)
    {
        currentP = currentF->getHeadPassenger();
        while(currentP != NULL)
        {
            if(currentP->firstName.compare(firstName) == 0 && currentP->lastName.compare(lastName) == 0)
            {
                cout<<"Flight "<<currentF->getFlightId()<<": from "<<currentF->getFlightFrom()<<" to "<<currentF->getFlightTo()<<endl;
            }
            
            currentP = currentP->pNext;
        }
        
        currentF = currentF->getNextFlight();
    }
}

void AirlineReservationSystem::showFlight(const int flightId) const
{
    Flight* current = fHead;
    bool isFound = false;
    
    while(current != NULL && !isFound)
    {
        if(current->getFlightId() == flightId)
        {
            isFound = true;
        }
        
        if(!isFound)
        {
            current = current->getNextFlight();
        }
    }
    
    
    if(isFound)
    {
        cout<<"Flight "<<current->getFlightId()<<": from "<<current->getFlightFrom()<<" to "<<current->getFlightTo()<<":"<<endl;
        Flight::Passenger* currentP = current->getHeadPassenger();
        while(currentP != NULL)
        {
            cout<<currentP->firstName<<" "<<currentP->lastName<<endl;
            currentP = currentP->pNext;
        }
    }
    else
    {
        cout<<"flight with given id not found"<<endl;
    }
}

void AirlineReservationSystem::removePassenger(const int flightId, const string firstName, const string lastName)
{
    Flight* current = fHead;
    bool isFound = false;
    
    while(current != NULL && !isFound)
    {
        if(current->getFlightId() == flightId)
        {
            isFound = true;
        }
        
        if(!isFound)
        {
            current = current->getNextFlight();
        }
    }
    
    if(isFound)
    {
        Flight::Passenger* wickedP = current->getHeadPassenger();
        Flight::Passenger* previousP = NULL;
        bool deleted = false;
        
        while(wickedP != NULL && !deleted)
        {
            if(wickedP->firstName.compare(firstName) == 0 && wickedP ->lastName.compare(lastName) == 0)
            {
                Flight::Passenger* nextP = wickedP->getNext();
                
                if(previousP == NULL)
                {
                    current->setHeadPassenger(nextP);
                }
                else
                {
                    previousP->setNext(nextP);
                }
                
                wickedP->setNext(NULL);
                deleted = true;
                delete wickedP;
            }
            
            if(!deleted)
            {
                previousP = wickedP;
                wickedP = wickedP->getNext();
            }
        }
        
        if(!deleted)
        {
            cout<<"no such passenger exists"<<endl;
        }
    }
    
}
