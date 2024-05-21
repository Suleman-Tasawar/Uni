#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

// Declare the functions
void MetroStationsPrint(string station_names[], int size);
void TicketPriceMetro();
void BookMetroTicket();

int ticketPrice = 30;

int main() {
    int opt;
    bool isBookingOpen = true;
    string station_names[] = {
        "Saddar", "Liaquat Bagh", "Committee Chowk", "Waris Khan", "Chandni Chowk", 
        "Rehmanabad", "6th Road", "Shamsabad", "Faizabad", "IJP", "Potohar", 
        "Khayaban-e-Johar", "Faiz Ahmed Faiz", "Kashmir Highway", "Ibn-e-Sina", 
        "Kachehri", "PIMS", "Stock Exchange", "7th Avenue", "Shaheed-e-Millat", 
        "Parade Ground", "Pak Secretariat"
    };
    int station_count = sizeof(station_names) / sizeof(station_names[0]);

    cout << "Welcome to Metro Ticketing System" << endl;
    cout << "Press 1 for viewing Metro Stations\nPress 2 for viewing Metro Ticket price\nPress 3 to book a ticket\nPress 0 to quit" << endl;
    cout << "Enter choice: ";
    cin >> opt;
    cin.ignore();
    while (opt !=0)
    {
        cout << "Enter choice: ";
        cin >> opt; 
    switch (opt) {
    case 1:
        MetroStationsPrint(station_names, station_count);
        break;
    case 2:
        TicketPriceMetro();
        break;
    case 3:
        BookMetroTicket();
        break;
    default:
        break;
    }   
    }

    return 0;
}

void MetroStationsPrint(string station_names[], int size) {
    cout << "Metro Stations:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << station_names[i] << endl;
    }
}

void TicketPriceMetro() {
    cout << "The ticket price is "<<ticketPrice<<" Rs" << endl;
}

void BookMetroTicket() {
    ofstream myfile;
    myfile.open ("ticket.txt");
    string name,date,stationNameEntry,stationNameExit;
    cout << "Ok can you tell a few details ." << endl;
    cout<<"You name: ";
    cin.ignore();
    getline(cin,name);
    cout<<"From which station: ";
    getline(cin,stationNameEntry);
    cout<<"To which station: ";
    getline(cin,stationNameExit);

    time_t now = time(0);

    tm *ltm = localtime(&now);
    cout<<endl;
    cout<<"*****************************************************"<<endl;
    cout<<"Ticket for "<<name<<"\n "<<stationNameEntry<<"/"<<stationNameExit<<"\t"<<setfill('0') << setw(2) << ltm->tm_mday << "/"<<setfill('0') << setw(2) << ltm->tm_mon + 1 << "/"<<setfill('0') << setw(2) << (ltm->tm_year + 1900) % 100 <<"\n"<<"Ticket Price "<<ticketPrice<<" Rs\nThanks for using Metro Bus Service."<<endl;
    cout<<"****************************************************"<<endl;
    //We are saving the metro ticket in console printed form
    myfile<<"*****************************************************\n";
    myfile<<"Ticket for "<<name<<"\n "<<stationNameEntry<<"/"<<stationNameExit<<"\t"<<setfill('0') << setw(2) << ltm->tm_mday << "/"<<setfill('0') << setw(2) << ltm->tm_mon + 1 << "/"<<setfill('0') << setw(2) << (ltm->tm_year + 1900) % 100 <<"\n"<<"Ticket Price "<<ticketPrice<<" Rs\nThanks for using Metro Bus Service.\n";
    myfile<<"*****************************************************\n";
    myfile.close();
}
