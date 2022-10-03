#include <bits/stdc++.h>

using namespace std;

struct employee
{
    string first_name;
    string last_name;
    string employeeid;
    float basic_salary;
    int allowance;
} employee[11];
int n = 0;

int findEmployeeSalary(string empid)
{
    int flag = -1;
    string employeeid;
    employeeid = empid;
    for (int i = 0; i < n; i++)
    {
        if (employee[i].employeeid == employeeid)
        {
            flag = i;
            break;
        }
    }
    int calc = employee[flag].basic_salary + (employee[flag].basic_salary * employee[flag].allowance) / 100;
    if (flag != -1)
    {
        return calc;
    }
    else
    {
        cout << "Your ID doesnt exist\n";
        return 0;
    }
}
void printEmployeeDetail(int i)
{
    cout << "Name: " + employee[i].first_name + employee[i].last_name+"\n";
    cout << "ID: " << employee[i].employeeid << "\n";
    cout << "Salary: " << findEmployeeSalary(employee[i].employeeid) << "\n";
    cout << "Allowance %: " << employee[i].allowance << "\n";
    cout << "\n";
}
void createEmployee()
{
    string first_name;
    string last_name;
    string employeeid;
    int nc = 0, flag = 1;
    float basic_salary;

    cout << "Enter the employee id: ";
    cin >> employeeid;
    for (int i = 0; i < n; i++)
    {

        if (employee[i].employeeid == employeeid)
        {
            cout << "ID already exists" << endl;
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        employee[n].employeeid = employeeid;

        cout << "Enter Your first name ";
        cin >> first_name;
        employee[n].first_name = first_name;

        cout << "Enter Your last name ";
        cin >> last_name;
        employee[n].last_name = last_name;

        cout << "Enter Your salary ";
        cin >> basic_salary;
        employee[n].basic_salary = basic_salary;

        cout << "What is allowance providedin % ? ";
        cin >> nc;
        employee[n].allowance = nc;

        n++;
        cout << "\n\nRecord Resgistered\n\n\n";
    }
}
void findEmployeeById()
{
    int flag = -1;
    string employeeid;
    cout << "enter Your employeeid:";
    cin >> employeeid;

    for (int i = 0; i < n; i++)
    {
        if (employee[i].employeeid == employeeid)
        {
            flag = i;
            break;
        }
    }
    if (flag != -1)
    {
        printEmployeeDetail(flag);
    }
    else
        cout << "Your ID doesnt exist\n";
}
void findEmployeeByName()
{
    string name;
    int flag = 1;
    cout << "Enter the employee name: ";
    fflush(stdin);
    getline(cin, name);
    for (int i = 0; i < n; i++)
    {
        if (employee[i].first_name + " " + employee[i].last_name == name)
        {
            flag = 0;
            printEmployeeDetail(i);
        }
    }
    if (flag)
        cout << "This name is not found" << endl;
}

int main()
{
    int ch, close = 0;
    cout << "Please enter task\n"
            "1. ADD a employee\n"
            "2. Find Employee By Id\n"
            "3. Find Employee By Name\n"
            "4. Find Employee Salary\n"
            "5. End Task\n";
    cin >> ch;
    if (ch == 1)
    {
        createEmployee();
    }
    else if (ch == 2)
    {
        findEmployeeById();
    }
    else if (ch == 3)
    {
        findEmployeeByName();
    }
    else if (ch == 4)
    {
        cout << "ENter employee id: ";
        string id;
        cin >> id;
        cout << "\n\nSalary of this employee is " << findEmployeeSalary(id) << endl
             << "\n\n";
    }
    else if (ch == 5)
    {
        close = 1;
    }

    if (!close)
        main();
}
