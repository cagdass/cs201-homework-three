#include <string>

//using namespace std;

using std::string;

//struct Passenger {
//    string firstName;
//    string lastName;
//    Passenger* pNext;
//};

class Flight {
public:
    struct Passenger {
        string firstName;
        string lastName;
        Passenger* pNext;
        void setNext(Passenger* next);
        Passenger* getNext();
    };
    Flight( const int flightId, const string fromCity, const string toCity );
    ~Flight();
    Flight* getNextFlight();
    void setNextFlight(Flight* next);
    int getFlightId();
    string getFlightFrom();
    string getFlightTo();
    Passenger* getHeadPassenger();
    void setHeadPassenger(Passenger* head);
    void addPassenger(const string firstName, const string lastName);
    void removePassenger(Passenger* wickedPassenger);
private:
    int flightId;
    string fromCity;
    string toCity;
    Passenger* pHead;
    Flight* fNext;
};
