#include <iostream>
#include <string>
using namespace std;

int main() {
    int i, a[3], hra = 5, da = 2, ta = 180, pf = 12, p[3], ab[3], t[3];
    long d[3], r[3];
    string b[3], c[3];

    cout << "This is our company data:-\n";
    cout << "-------------------------------------\n";
    cout << "Some basic information which applies to all employees:-\n";
    cout << "HRA= " << hra << "%" << endl;
    cout << "DA= " << da << "%" << endl;
    cout << "TA= Rs." << ta << endl;
    cout << "PF= " << pf << "%" << endl;

    cout << "\n-------------------------------------\n";

    for (i = 0; i < 3; i++) {
        cout << "Employee ID: ";
        cin >> a[i];
        cout << "Employee Name: ";
        cin >> b[i];
        cout << "Department: ";
        cin >> c[i];
        cout << "Salary: ";
        cin >> d[i];
        cout << "No. of Present Days: ";
        cin >> p[i];
        cout << "No. of Absent Days: ";
        cin >> ab[i];
        t[i] = p[i] + ab[i];
        cout << "--------------------------------------------\n";
    }

    cout << "\n";

    // Table header
    cout << "Emp ID\tEmp Name\tDepartment\tSalary\tHRA\tDA\tTA\tPF\tNet Salary\tPresent Days\tAbsent Days\n";

    for (i = 0; i < 3; i++) {
        cout << a[i] << "\t";
        cout << b[i] << "\t\t";
        cout << c[i] << "\t\t";
        cout << d[i] << "\t";
        cout << hra << "%\t";
        cout << da << "%\t";
        cout << "Rs." << ta << "\t";
        cout << pf << "%\t";
        
        // Calculate Net Salary
        r[i] = (hra * d[i] / 100) + (da * d[i] / 100) + (ta * p[i]) - (pf * d[i] / 100);
        cout << r[i] << "\t\t";
        cout << p[i] << "\t\t";
        cout << ab[i] << "\n";
    }

    return 0;
}
