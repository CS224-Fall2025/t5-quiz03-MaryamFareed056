#include <iostream>
using namespace std;

class Employee {

    private:
    // static int count;

    protected:
        string name;
        double salary;


    public:
        static int employeeCount;
        
        Employee (string n, double s) {
            name = n;
            salary = s;
            employeeCount++;
        }

        virtual void displayInfo() const {
            cout << "Name: " << name << ", ";
            cout << "Salary: " << salary << endl;

        }

        static void showTotalEmployees() { // static funcTionnn! test by diresctly calling using scope resolution in main 
            cout << "Total employees created: " << employeeCount;
            
        }

        virtual ~Employee() = default;


};

int Employee::employeeCount = 0;

class Staff : public Employee {

    private:
        string department;

    public:

        Staff(string n, double s, string d) {
            Employee::Employee(n, s);
            department = d;
        }

        virtual void displayInfo() const override {
            cout << "Name: " << name << " (Staff), " ;
            cout << "Salary: " << salary << endl;
            
        }

};


class Faculty : public Employee {

    private:
        string department;

    public:

        Faculty(string n, double s, string d) {
            Employee::Employee(n, s);
            department = d;
        }

        virtual displayInfo() const override {
            cout << "Name: " << name << " (Faculty), " ;
            cout << "Salary: " << salary << endl;
        }

};




int main() {

    int n_employees;
    cout << " ENter number of employees: " << endl;
    cin >> n_employees;




    char employee_type;
    string _name;
    double _salary;
    string _department;

    Employee* employees[];

    for (int i = 0; i < n_employees; i++){
        cout << "Enter Employee type (Staff - s; Faculty - f): " << endl;
        cin >> employee_type;

        if (employee_type == 's') {
            employees[i] = new Staff(_name, _salary, _department);
        }

        else if (employee_type == 'f') {
            employees[i] = new Faculty(_name, _salary, _department);
        }
    }

    for (int i = 0; i < n_employees; i++){ 

        employees[i].displayInfo();
        Employee::showTotalEmployees();

    }

    for (int i = 0; i < n_employees; i++){ 

        delete employees[i];
       

    } 


    return 0;
}