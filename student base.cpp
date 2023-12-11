
/*Develop a program in C++ to create a database of student‘s information
system containing the following information: Name, Roll number, Class,
Division, Date of Birth, Blood group, Contact address, Telephone number,
Driving license no. and other. Construct the database with suitable member
functions. Make use of constructor, default constructor, copy constructor,
destructor, static member functions, friend class, this pointer, inline code and
dynamic memory allocation operators-new and delete as well as exception
handling*/

#include <iostream>
using namespace std;

class Person {
private:
    string name, bg, add, tele, dlo, dob;

public:
    Person() : name(""), bg(""), add(""), tele(""), dlo(""), dob("") {}

    Person(const Person &p) {
        name = p.name;
        bg = p.bg;
        add = p.add;
        tele = p.tele;
        dlo = p.dlo;
        dob = p.dob;
    }

    ~Person() {}

    friend class Student;
};

class Student {
private:
    int roll;
    string className;
    char *div;

public:
    static int count;
    Student() : roll(0), className(""), div(nullptr) {
        count++;
    }

    Student(const Student &s) {
        roll = s.roll;
        className = s.className;
        div = new char(*(s.div));
        count++;
    }

    ~Student() {
        delete div;
        count--;
    }

    void acceptStudent(Person &p) {
        cout << "Enter name: ";
        cin >> p.name;
        cout << "Enter blood group: ";
        cin >> p.bg;
        cout << "Enter address: ";
        cin >> p.add;
        cout << "Enter telephone: ";
        cin >> p.tele;
        cout << "Enter driving license number: ";
        cin >> p.dlo;
        cout << "Enter date of birth: ";
        cin >> p.dob;

        cout << "Enter roll: ";
        cin >> roll;
        cout << "Enter class name: ";
        cin >> className;

        char division;
        cout << "Enter division: ";
        cin >> division;
        div = new char(division);
    }

    void displayStudent(const Person &p) {
        cout << "Name: " << p.name << endl;
        cout << "Blood group: " << p.bg << endl;
        cout << "Address: " << p.add << endl;
        cout << "Telephone: " << p.tele << endl;
        cout << "Driving license number: " << p.dlo << endl;
        cout << "Date of birth: " << p.dob << endl;

        cout << "Roll: " << roll << endl;
        cout << "Class name: " << className << endl;
        cout << "Division: " << *div << endl;
        cout << endl;
    }

    static int getCount() {
        return count;
    }
};

int Student::count = 0;

int main() {
    Person p;
    Student s;

    while (true) {
        int ch;
        cout << "Enter 1 - Enter a student | 2 - Display the current student | 0 - Exit" << endl;
        cin >> ch;

        if (ch == 1) {
            s.acceptStudent(p);
        } else if (ch == 2) {
            s.displayStudent(p);
        } else if (ch == 0) {
            cout << "EXIT" << endl;
            break;
        }
    }

    cout << "Total students: " << Student::getCount() << endl;

    return 0;
}
