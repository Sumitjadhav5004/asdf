#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
    string name;
    string dob;
    string telephone;

    // Constructor
    Person(string n, string d, string t) : name(n), dob(d), telephone(t) {}
};

bool compareByName(const Person &a, const Person &b) {
    return a.name < b.name;
}

bool compareByDob(const Person &a, const Person &b) {
    return a.dob < b.dob;
}

bool compareByTelephone(const Person &a, const Person &b) {
    return a.telephone < b.telephone;
}

int main() {
    vector<Person> records;

    // Adding some sample records
    records.emplace_back("John Doe", "1990-01-15", "123-456-7890");
    records.emplace_back("Alice Smith", "1985-08-22", "987-654-3210");
    records.emplace_back("Bob Johnson", "1995-04-10", "555-123-4567");

    // Sorting records by Name
    sort(records.begin(), records.end(), compareByName);

    // Displaying sorted records
    cout << "Sorted by Name:\n";
    for (const auto &person : records) {
        cout << "Name: " << person.name << ", DOB: " << person.dob << ", Telephone: " << person.telephone << "\n";
    }

    // Searching for a record by Name
    string searchName = "Alice Smith";
    auto it = find_if(records.begin(), records.end(), [searchName](const Person &p) {
        return p.name == searchName;
    });

    if (it != records.end()) {
        cout << "\nRecord Found:\n";
        cout << "Name: " << it->name << ", DOB: " << it->dob << ", Telephone: " << it->telephone << "\n";
    } else {
        cout << "\nRecord not found.\n";
    }

    return 0;
}
