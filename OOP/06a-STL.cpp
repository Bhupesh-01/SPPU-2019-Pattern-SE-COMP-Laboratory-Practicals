/*
C6a : Write C++ program using STL for sorting and searching user defined records such as 
personal records (Name, DOB, Telephone number etc) using vector container.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct PersonalRecord {
    std::string name;
    std::string dob; // Date of Birth
    std::string telephone;
};

// Comparator function for sorting by name
bool compareByName(const PersonalRecord &a, const PersonalRecord &b) {
    return a.name < b.name;
}

// Function to search by name
std::vector<PersonalRecord>::iterator searchByName(std::vector<PersonalRecord> &records, const std::string &name) {
    return std::find_if(records.begin(), records.end(), [&name](const PersonalRecord &record) {
        return record.name == name;
    });
}

int main() {
    std::vector<PersonalRecord> records = {
        {"Alice", "1990-01-01", "1234567890"},
        {"Bob", "1992-02-02", "0987654321"},
        {"Charlie", "1991-03-03", "1122334455"}
    };

    // Sort records by name
    std::sort(records.begin(), records.end(), compareByName);

    std::cout << "Sorted Records:\n";
    for (const auto &record : records) {
        std::cout << "Name: " << record.name << ", DOB: " << record.dob << ", Telephone: " << record.telephone << '\n';
    }

    // Search for a record by name
    std::string nameToSearch = "Bob";
    auto it = searchByName(records, nameToSearch);

    if (it != records.end()) {
        std::cout << "\nRecord found:\n";
        std::cout << "Name: " << it->name << ", DOB: " << it->dob << ", Telephone: " << it->telephone << '\n';
    } else {
        std::cout << "\nRecord not found for name: " << nameToSearch << '\n';
    }

    return 0;
}
