
#include <iostream>
#include <string>
#include <random> //random_string function
#include "EmployeeDB.h"

using namespace std;

//Generates a random string using a look up table
//takes length and returns string
//SOURCE -> https://inversepalindrome.com/blog/how-to-create-a-random-string-in-cpp
std::string random_string(std::size_t length)
{
    const std::string CHARACTERS = "abcdefghijklmnopqrstuvwxyz";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    std::string random_string;

    for (std::size_t i = 0; i < length; ++i)
    {
        random_string += CHARACTERS[distribution(generator)];
    }

    return random_string;
}

int main(int argc, const char * argv[]) {

    EmployeeDB dataBase;

    string name;
    string number;
    string date;
    string searchE;
    string deleteE;

    //Creating and Inserting Employees
    for (int i = 1; i <= 10; i++) {

        string name = random_string(5); //generate random strings
        number = to_string(i);
        date = to_string(i + 10);

        Employee person(name, number, date); //create Employee

        dataBase.insertEmployee(person);
        cout << endl;
    }

    cout << "Displaying Employees" << endl;
    dataBase.displayRecords();
    cout << endl;

    //Searching for an Employee
    cout << "Employee to search: ";
    getline(cin, searchE);
    Employee tempSearch = dataBase.searchEmployee(searchE);
    cout << "Printing Employee information: " << endl;
    cout << tempSearch.getName() << endl;
    cout << tempSearch.getNumber() << endl;
    cout << tempSearch.getHireDate() << endl << endl;


    //Deleting an Employee
    cout << "Employee to remove: ";
    getline(cin, deleteE);
    Employee tempDelete = dataBase.searchEmployee(deleteE);

    if (dataBase.deleteEmployee(tempDelete) == true) {
        cout << "Employee deleted" << endl;
    }
    else {
        cout << "Employee not found" << endl;
    }

    cout << endl;
    cout << "Displaying Employees" << endl;
    dataBase.displayRecords();


    return 0;
}



