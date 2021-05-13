
#ifndef EMPLOYEEDB_H_
#define EMPLOYEEDB_H_

#include "EmpBinaryTree.h"
#include <string>

class EmployeeDB {
private:
    EmpBinaryTree db;
public:
    EmployeeDB();
    void insertEmployee(Employee);
    bool deleteEmployee(Employee);
    Employee searchEmployee(string);
    void displayRecords();
};

#endif /* EMPLOYEEDB_H_ */
