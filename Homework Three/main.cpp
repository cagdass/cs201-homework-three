//
//  driver.cpp
//  Homework Three
//
//  Created by dunkuCoder on 23/07/14.
//  Copyright (c) 2014 Çağdaş Öztekin. All rights reserved.
//

#include <iostream>
#include "AirlineReservationSystem.h"

using namespace std;

int main(int argc, const char * argv[])
{
    
    // insert code here...
    //    std::cout << "Hello, World!\n";
    AirlineReservationSystem ars;
    // ars.addFlight(200, "Ankara", "Izmir");
    // ars.showAllFlights();
    // ars.showAllFlights();
    // ars.removeFlight(200);
    // ars.showAllFlights();
    ars.addPassenger(200, "arya", "stark");
    ars.addFlight(100, "Asd", "lemore");
    ars.addFlight(150, "braavos", "dreadfort");
    ars.addFlight(50, "a", "b");
    ars.addFlight(102, "kings landing", "casterly rock");
    // //
    ars.showAllFlights();
    ars.removeFlight(100);
    ars.showAllFlights();
    ars.removeFlight(200);
    ars.addPassenger(102, "arya", "stark");
    ars.addPassenger(150, "arya", "stark");
    ars.addPassenger(150, "tyrion", "lannister");
    ars.addPassenger(150, "arya", "stark");
    ars.addPassenger(150, "jon", "snow");
    ars.showPassenger("arya", "stark");
    ars.showFlight(150);
    ars.addPassenger(150, "tyrion", "lannister");
    ars.addPassenger(150, "jon", "snow");
    ars.showAllFlights();
    // ars.showFlight(150);
    ars.addPassenger(150, "tyrion", "lannister");
    // ars.showFlight(150);
    ars.showAllFlights();
    // ars.removePassenger(150, "arya", "stark");
    // ars.showFlight(150);
    ars.removePassenger(150, "jon", "snow");
    // ars.showFlight(150);
    ars.removePassenger(150, "tyrion", "lannister");
    ars.removePassenger(102, "arya", "stark");
    // ars.showFlight(150);
    // ars.addPassenger(150, "tyrion", "lannister");
    // ars.showFlight(150);
    ars.addPassenger(150, "tyrion", "lannister");
    ars.showFlight(150);
    
    ars.showAllFlights();
    
    ars.addFlight(815, "sidney", "los angeles");
    ars.addPassenger(815, "jack", "shephard");
    
    ars.showAllFlights();
    ars.showPassenger("jack", "shephard");
    ars.showPassenger("arya", "stark");
    ars.addPassenger(52, "arya", "stark");
    ars.showPassenger("arya", "stark");
    ars.removeFlight(52);
    
    ars.addPassenger(100, "asd", "bcd");
    
    ars.showFlight(815);
    ars.showPassenger("asd", "bcd");
    
    ars.showAllFlights();
    
    
    
    return 0;
}

