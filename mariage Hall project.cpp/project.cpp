#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Event {
protected:
    string name;
    string date;
    string startTime;
    string endTime;
    double price;
public:
    Event(const string& name, const string& date, const string& startTime, const string& endTime, double price) 
    : name(name), date(date), startTime(startTime), endTime(endTime), price(price) {}

    virtual void displayDetails() const {
        cout << "Event: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Start Time: " << startTime << endl;
        cout << "End Time: " << endTime << endl;
        cout << "Price: $" << price << endl;
    }

    virtual void saveToFile(ofstream& file) const {
        file << "Event: " << name << endl;
        file << "Date: " << date << endl;
        file << "Start Time: " << startTime << endl;
        file << "End Time: " << endTime << endl;
        file << "Price: $" << price << endl;
    }
};

class Wedding : public Event {
private:
    string bride;
    string groom;
public:
    Wedding(const string& name, const string& date, const string& startTime, const string& endTime, 
            double price, const string& bride, const string& groom) 
    : Event(name, date, startTime, endTime, price), bride(bride), groom(groom) {}

    void displayDetails() {
        Event::displayDetails();
        cout << "Bride: " << bride << endl;
        cout << "Groom: " << groom << endl;
    }

    void saveToFile(ofstream& file)  {
        Event::saveToFile(file);
        file << "Bride: " << bride << endl;
        file << "Groom: " << groom << endl;
    }
};

class Birthday : public Event {
private:
    string celebrant;
    int age;
public:
    Birthday(const string& name, const string& date, const string& startTime, const string& endTime, 
             double price, const string& celebrant, int age) 
    : Event(name, date, startTime, endTime, price), celebrant(celebrant), age(age) {}

    void displayDetails()  {
        Event::displayDetails();
        cout << "Celebrant: " << celebrant << endl;
        cout << "Age: " << age << endl;
    }

    void saveToFile(ofstream& file) {
        Event::saveToFile(file);
        file << "Celebrant: " << celebrant << endl;
        file << "Age: " << age << endl;
    }
};

class Booking {
private:
    string eventName;
    string date;
    string startTime;
    double price;
public:
    Booking(const string& eventName, const string& date, const string& startTime, double price)
    : eventName(eventName), date(date), startTime(startTime), price(price) {}

    void displayDetails() const {
        cout << "Booking for Event: " << eventName << endl;
        cout << "Date: " << date << endl;
        cout << "Start Time: " << startTime << endl;
        cout << "Price: $" << price << endl;
    }

    void saveToFile(ofstream& file) const {
        file << "Booking for Event: " << eventName << endl;
        file << "Date: " << date << endl;
        file << "Start Time: " << startTime << endl;
        file << "Price: $" << price << endl;
    }
};

class MenuList {
public:
    static void display() {
        cout << "1. Add Wedding Event" << endl;
        cout << "2. Add Birthday Event" << endl;
        cout << "3. Display All Events" << endl;
        cout << "4. Book Event" << endl;
        cout << "5. Display Booking Details" << endl;
        cout << "6. Save Events and Bookings to File" << endl;
        cout << "7. Exit" << endl;
    }
};

class EventManager {
private:
    static const int MAX_EVENTS = 100;
    static const int MAX_BOOKINGS = 100;
    Event* events[MAX_EVENTS];
    Booking* bookings[MAX_BOOKINGS];
    int numEvents;
    int numBookings;
public:
    EventManager() : numEvents(0), numBookings(0) {}

    ~EventManager() {
        for (int i = 0; i < numEvents; ++i) {
            delete events[i];
        }
        for (int i = 0; i < numBookings; ++i) {
            delete bookings[i];
        }
    }

    void addEvent(Event* event) {
        if (numEvents < MAX_EVENTS) {
            events[numEvents++] = event;
            cout << "Event added successfully." << endl;
        } else {
            cout << "Cannot add more events. Maximum capacity reached." << endl;
        }
    }

    void bookEvent(const string& eventName, const string& date, const string& startTime, double price) {
        if (numBookings < MAX_BOOKINGS) {
            bookings[numBookings++] = new Booking(eventName, date, startTime, price);
            cout << "Event booked successfully." << endl;
        } else {
            cout << "Cannot book more events. Maximum capacity reached." << endl;}
    }

    void displayEvents() const {
        if (numEvents == 0) {
            cout << "No events to display." << endl;
            return;
        }

        for (int i = 0; i < numEvents; ++i) {
            events[i]->displayDetails();
            cout << endl;
        }
    }

    void displayBookings() const {
        if (numBookings == 0) {
            cout << "No bookings to display." << endl;
            return;
        }

        for (int i = 0; i < numBookings; ++i) {
            bookings[i]->displayDetails();
            cout << endl;
        }
    }

    void saveEventsAndBookingsToFile(const string& filename) const {
        ofstream file("file.texr",ios::app);
        if (file.is_open()) {
            for (int i = 0; i < numEvents; ++i) {
                events[i]->saveToFile(file);
                file << endl;
            }
            for (int i = 0; i < numBookings; ++i) {
                bookings[i]->saveToFile(file);
                // file << endl;
            }
            cout << "Events and bookings saved to file: " << filename << endl;
        } else {
            cout << "Unable to open file: " << filename << endl;
        }
    }
};

void signup() {
    string name, username, email, password;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your username: ";
    getline(cin, username);
    cout << "Enter your email: ";
    getline(cin, email);
    cout << "Enter your password: ";
    getline(cin, password);
    
    ofstream outFile("users.txt", ios::app);
    if (outFile.is_open()) {
        outFile << name << "\t" << username << "\t" << email << "\t" << password << endl;
        outFile.close();
        cout << "User created successfully!" << endl;
    }
    else {
        cout << "Error opening file" << endl;
    }
}

bool login() {
    string username, password;
    cout << "Enter your username: ";
    getline(cin, username);cout<<endl;
    cout << "Enter your password: ";
    getline(cin, password);
    cin.ignore();
    ifstream inFile("users.txt");
    string line;
    while (getline(inFile, line)) {
        string name, username_from_file, email, password_from_file;
        istringstream iss(line);
        iss >> name >> username_from_file >> email >> password_from_file;
        if (username == username_from_file && password == password_from_file) {
            cout << "Login successful! Welcome " << name << endl;
            return true;
        }
    }
    cout << "Invalid username or password" << endl;
    return false;
}

void changePassword()
{
	string user_name, new_password;
	cout<<"Enter username : ";
	cin>>user_name;
	ifstream inFile("users.txt");
	ofstream outFile("temp.txt");
    string line;
    while (getline(inFile, line)) {
        string name, username_from_file, email, password_from_file;
        istringstream iss(line);
        iss >> name >> username_from_file >> email >> password_from_file;
        if (user_name == username_from_file) {
            cout << "Enter new password : ";
            cin>>new_password;
            outFile << name << "\t" << username_from_file << "\t" << email << "\t" << new_password << endl;
        }
        else
        {
        	outFile << name << "\t" << username_from_file << "\t" << email << "\t" << password_from_file << endl;
		}
    }
	inFile.close();
	outFile.close();
	
	remove("users.txt");
	rename("temp.txt","users.txt");
	
}

void deleteAccount()
{
	string user_name;
	cout<<"Enter username : ";
	cin>>user_name;
	ifstream inFile("users.txt");
	ofstream outFile("temp.txt");
    string line;
    while (getline(inFile, line)) {
        string name, username_from_file, email, password_from_file;
        istringstream is(line);
        is >> name >> username_from_file >> email >> password_from_file;
        if (user_name == username_from_file) {
            cout << "User deleted successfully";
        }
        else
        {
        	outFile << name << "\t" << username_from_file << "\t" << email << "\t" << password_from_file << endl;
		}
    }
	inFile.close();
	outFile.close();
	
	remove("users.txt");
	rename("temp.txt","users.txt");
	
}

int main() {
   int lchoice;
    cout << "Enter your choice:" << endl;
    cout << "1. Signup" << endl;
    cout << "2. Login" << endl;
    cin >> lchoice;
    cin.ignore(); // to clear the input buffer
    
    switch (lchoice) {
        case 1:
            signup();
            break;
        case 2:
            if (login()) {
                // do something after login
                cout << "Enter your choice:" << endl;
			    cout << "1. Change Password" << endl;
			    cout << "2. Delete Account" << endl;
                cin>>lchoice;
                if(lchoice==1)
                {
                	changePassword();
				}
				else if(lchoice==2)
				{
					deleteAccount();
				}
				else
				{
					cout<<"Wrong choice...!";
				}
            }
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
    EventManager eventManager;
    int choice;

    do {
        MenuList::display();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        switch(choice) {
            case 1: {
                string name, date, startTime, endTime, bride, groom;
                double price;
                cout << "Enter Wedding Event Details:" << endl;
                cout << "Name: "; getline(cin, name);
                cout << "Date: "; getline(cin, date);
                cout << "Start Time: "; getline(cin, startTime);
                cout << "End Time: "; getline(cin, endTime);
                cout << "Price: $"; cin >> price;
                cin.ignore(); // Clear the input buffer
                cout << "Bride: "; getline(cin, bride);
                cout << "Groom: "; getline(cin, groom);
                eventManager.addEvent(new Wedding(name, date, startTime, endTime, price, bride, groom));
                break;
            }
            case 2: {
                string name, date, startTime, endTime, celebrant;
                int age;
                double price;
                cout << "Enter Birthday Event Details:" << endl;
                cout << "Name: "; getline(cin, name);
                cout << "Date: "; getline(cin, date);
                cout << "Start Time: "; getline(cin, startTime);
                cout << "End Time: "; getline(cin, endTime);
                cout << "Price: $"; cin >> price;
                cin.ignore(); // Clear the input buffer
                cout << "Celebrant: "; getline(cin, celebrant);
                cout << "Age: "; cin >> age;
                eventManager.addEvent(new Birthday(name, date, startTime, endTime, price, celebrant, age));
                break;
            }
            case 3:
                eventManager.displayEvents();
                break;
            case 4: {
                string eventName, date, startTime;
                double price;
                cout << "Enter Booking Details:" << endl;
                cout << "Event Name: "; getline(cin, eventName);
                cout << "Date: "; getline(cin, date);
                cout << "Start Time: "; getline(cin, startTime);
                cout << "Price: $"; cin >> price;
                eventManager.bookEvent(eventName, date, startTime, price);
                break;
            }
            case 5:
                eventManager.displayBookings();
                break;
            case 6:
                eventManager.saveEventsAndBookingsToFile("saved_events_and_bookings.txt");
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
