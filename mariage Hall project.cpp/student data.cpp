#include <iostream>
#include <fstream>

using namespace std;

class Student {
private:
    char name[100];
    int roll_number;
    float marks;

public:
    void inputDetails() {
        cout << "Enter name: ";
        cin.ignore();
        cin.getline(name, 100);
        cout << "Enter roll number: ";
        cin >> roll_number;
        cout << "Enter marks: ";
        cin >> marks;
    }

    void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll_number << endl;
        cout << "Marks: " << marks << endl;
    }

    void writeToFile(const char* filename) const {
        ofstream outFile(filename, ios::app);
        if (!outFile) {
            cout << "File could not be opened!" << endl;
            return;
        }
        outFile << name << endl;
        outFile << roll_number << endl;
        outFile << marks << endl;
        outFile.close();
    }

    void readFromFile(const char* filename) {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "File could not be opened!" << endl;
            return;
        }

        while (true) {
            inFile.getline(name, 100);
            if (!inFile) break;
            inFile >> roll_number;
            if (!inFile) break;
            inFile >> marks;
            if (!inFile) break;
            inFile.ignore();

            displayDetails();
            cout << "-------------------" << endl;
        }

        inFile.close();
    }
};

int main() {
    Student student;
    const char* filename = "students.txt";

    // Input student details
    student.inputDetails();

    // Write student details to file
    student.writeToFile(filename);

    // Read and display student details from file
    cout << "Reading from file:" << endl;
    student.readFromFile(filename);

    return 0;
}
