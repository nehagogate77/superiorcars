#include <iostream>
using namespace std;

int reservationCounter[1];
int a = sizeof(reservationCounter)/sizeof(reservationCounter[0]);
char reservationBooking;

void reservationBookingSystem() {
    cout << "Did you book your reservation (Y or N): ";
    cin >> reservationBooking;

    for (int i = 0; i < a; i++) {
        if (reservationBooking == 'Y') {
            cout << "Great! Your reservation number is " << reservationCounter[i] << ".\n\n";
            reservationBookingSystem();
        }
        reservationCounter[i]++;
        cout << reservationCounter[i] << endl << endl;
    }
}

void searchReservation() {
    int searchReservation;
    cout << "Please enter your reservation number: ";
    cin >> searchReservation;

    //https://www.techiedelight.com/find-index-element-array-cpp/
    int i = 0;
    while (i < a) {
        if (reservationCounter[i] == searchReservation) {
            break;
        }
        i++;
    }

    if (i < a) {
        cout << "There is 1 reservation with this number.\n\n";
    } else {
        cout << "Sorry, there is no reservation with this number.\n\n";
    }
}

int main() {
    reservationBookingSystem();
    
    if ((reservationBooking == 'N') || (reservationBooking != 'Y')) {
        char reservationsChoice;
        cout << "Would you like to search a reservation (Y or N)? ";
        cin >> reservationsChoice;
        if (reservationsChoice == 'Y') {
            searchReservation();
        } else {
            cout << "That's ok, feel free to book a vehicle anytime at Superior Cars!\n\n";
        }
    }
}