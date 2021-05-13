
#include "EmployeeDB.h"

EmployeeDB::EmployeeDB() {
    EmpBinaryTree();
}

void EmployeeDB::insertEmployee(Employee a) {
    db.insertEmployee(a);
}

bool EmployeeDB::deleteEmployee(Employee a) {
	if (db.searchEmployee(a) == true) {
		db.remove(a);
		return true;
	}
	else {
		return false;
	}
}

Employee EmployeeDB::searchEmployee(string a) {
    return db.getEmployee(a);
}

void EmployeeDB::displayRecords() {
    db.displayInOrder();
}






