#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
using namespace std;

class staff
{

protected:
    string name, address;

public:
    virtual void show() = 0;
    staff() {}
};

class emp : public staff

{
protected:
    int emp_id, sal, group_id;

    void menu();

public:
    emp() {}
};

class manager : protected emp
{

private:
    string qul;
    int no_of_worker;

protected:
    void m_insert();
    void m_display();
    void m_modify();
    void m_del();
    void m_search();
    void add_msal();
    void m_group();
    void m_ygroup();

public:
    friend manager operator+(manager, manager);
    void show() {}

    manager(int a)
    {
        system("cls");
        int test_id, found = 0;
        fstream file;
        cout << "\n\nInsert Record";
        cout << "\n\nManager ID : ";
        cin >> emp_id;
        cout << "\n\nManager Name : ";
        cin >> name;
        cout << "\n\n Qualification : ";
        cin >> qul;
        cout << "\n\nno of worker : ";
        cin >> no_of_worker;

        cout << "\n\nManager Sallary : ";
        cin >> sal;
        cout << "\n\nManager Address : ";
        cin >> address;
        cout << "\n\nManager Group ID : ";
        cin >> group_id;
        file.open("anilmemp.txt", ios::out | ios::app);
        file << " " << emp_id << " " << name << " " << qul << " " << no_of_worker << " " << sal << " " << address << " " << group_id << "\n";
        file.close();

        cout << "\n\n\n\t\t\tNew Record Inserted Successfully...";
    }
    manager() {}
};
class worker : protected emp
{
protected:
    virtual void e_menu();
    void e_insert();
    void e_display();
    void e_search();
    void e_group();
    void add_esal();
    void e_ygroup();
    void e_modify();
    void e_del();

public:
    friend worker operator+(worker, worker);
    void show() {}

    worker(int a)
    {

        system("cls");
        int test_id, found = 0;
        fstream file;
        cout << "\n\n\t\t\t\tInsert Record";
        cout << "\n\n\nWorker ID : ";
        cin >> emp_id;
        cout << "\n\nWorker Name : ";
        cin >> name;
        cout << "\n\nWorker Sallary : ";
        cin >> sal;
        cout << "\n\nWorker Address : ";
        cin >> address;
        cout << "\n\nWorker Group ID : ";
        cin >> group_id;
        file.open("anilemp.txt", ios::out | ios::app);
        file << " " << emp_id << " " << name << " " << sal << " " << address << " " << group_id << "\n";
        file.close();

        cout << "\n\n\n\t\t\tNew Record Inserted Successfully...";
    }
    worker() {}

    ~worker()
    {
    }
};

class log;

class child : private manager, worker
{
private:
    void child_menu();
    void login(log x);
    void login();
    void admin_menu();
    void m_menu();
    void e_menu();
    void manager_menu();

public:
    void show() {}
    void main_menu(log x);
    child() {}
    ~child() {}

} obj;

class log
{

public:
    static string userc;
    static string passc;

public:
    friend class child;
};
string log::passc = "anil";
string log::userc = "anil";

void intro()
{
    system("cls");
    cout << "\n\n\n\n\n\n\n";
    cout << "\t\t\t==============================";
    cout << "\n\t\t\t==============================";
    cout << "\n\n\t\t\t  Employee Management System";
    cout << "\n\n\t\t\t==============================";
    cout << "\n\t\t\t==============================";
    getch();

    system("cls");
    cout << "\n\n\n";
    cout << "\t\t\t====================================";
    cout << "\n\t\t\t====================================";
    cout << "\n\n\t\t\t\t    Introduction";
    cout << "\n\n\t\t\t====================================";
    cout << "\n\t\t\t====================================";
    cout << "\n\n\n\t\t\t Section :	2020 BCS";
    cout << "\n\t\t\t Teacher :	Mr. Vinal Patel";
    cout << "\n\t\t\t Institute :	ABV-IIITM";
    cout << "\n\n\t\t\t====================================";
    cout << "\n\t\t\t====================================";
    getch();

    system("cls");
    cout << "\n\n\n\n\n";
    cout << "\t\t========================================";
    cout << "\n\n\t\t\tOOPL ACADEMIC PROJECT";
    cout << "\n\t\t========================================";
    cout << "\n\n\n\t\t\tsubmitted by-";
    cout << "\n\t\t\t  Anil Kumar, 2020BCS-011";
    cout << "\n\t\t\t  Anuj Pingua, 2020BCS-012";
    cout << "\n\t\t\t  Gokuwada Nagendra, 2020BCS-035";
    cout << "\n\t\t\t  Neetu Kumari, 2020BCS-052";
    cout << "\n\n\n\t\t\tsubmitted to-";
    cout << "\n\n\t\t\t  prof. Vinal Patel";
    cout << "\n\n\t\t========================================";
    cout << "\n\t\t========================================";
    cout << "\n\n\tPress enter to continue.......";
    getch();
}

void child::login(log x)
{

p:
    system("cls");
    char ch;
    string user, pass;
    cout << "\n\n\n\n\n";
    cout << "\t\t\t==============================";
    cout << "\n\n\t\t\t\tLogin Process";
    cout << "\n\n\t\t\t==============================";
    cout << "\n\n\n Enter User Name : ";
    cin >> user;
    cout << "\n\n Enter Password : ";
    for (int i = 1; i <= 4; i++)
    {
        ch = getch();
        pass += ch;
        cout << "*";
    }
    if (user == x.userc && pass == x.passc)
    {
        cout << "\n\n\n\t\t\tCongratulation Login Successfully...";
        cout << "\n\n\n\t\t\t\t\tLoading";
        for (int i = 1; i <= 4; i++)
        {

            cout << ".";
        }
        admin_menu();
    }
    else if (user != x.userc && pass == x.passc)
    {
        cout << "\n\n\n Your User Name is Wrong....";
        getch();
        goto p;
    }
    else if (user == x.userc && pass != x.passc)
    {
        cout << "\n\n\n Your Password is Wrong....";
        getch();
        goto p;
    }
    else
    {
        cout << "\n\n\n User Name & Password Both are Wrong....";
    }
}
void child::login()
{

p:
    system("cls");
    char ch;
    string user, pass;
    cout << "\n\n\n\n\n";
    cout << "\t\t\t==============================";
    cout << "\n\n\t\t\t\tLogin Process";
    cout << "\n\n\t\t\t==============================";
    cout << "\n\n\n Enter User Name : ";
    cin >> user;
    cout << "\n\n Enter Password : ";
    for (int i = 1; i <= 5; i++)
    {
        ch = getch();
        pass += ch;
        cout << "*";
    }
    if ((user == "manager" || user == "worker") && pass == "iiitm")
    {
        cout << "\n\n\n\t\t\tCongratulation Login Successfully...";
        cout << "\n\n\n\t\t\t\t\tLoading";
        for (int i = 1; i <= 4; i++)
        {

            cout << ".";
        }
        if (user == "manager")
        {
            manager_menu();
        }
        else
        {
            worker::e_menu();
        }
    }

    else
    {
        cout << "\n\n\n User Name or Password  are Wrong....";
    }
}

void child::main_menu(log x)
{
p:
    int choice;
    system("cls");
    cout << "\n\n\t\t\t======================";
    cout << "\n\n\t\t\t     LOGIN SCREEN";
    cout << "\n\n\t\t\t======================";
    cout << "\n\n 1. Admin";
    cout << "\n 2. Manager";
    cout << "\n 3. Worker";
    cout << "\n 4. Exit";
    cout << "\n\n Enter Your Choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        login(x);
        break;
    case 2:
        login();
        break;
    case 3:
        login();
        break;
    case 4:
        exit(0);
    default:
        cout << "\n\n Invalid Value...Please Try Again...";
    }
    getch();
    goto p;
}

void worker::e_menu()
{
p:
    int choice;
    system("cls");

    cout << "\n\n\t\t\t======================";
    cout << "\n\n\t\t\t   worker Control Panel";
    cout << "\n\n\t\t\t======================";
    cout << "\n 1. Check your Details";
    cout << "\n 2. Check your group";
    cout << "\n 3. Exit";
    cout << "\n\n Enter Your Choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        e_search();
        break;

    case 2:
        e_ygroup();
        break;
    case 3:
        exit(0);
        break;

    default:
        cout << "\n\n Invalid Value...Please Try Again...";
    }
    getch();
    goto p;
}
void child ::admin_menu()
{
p:
    system("cls");
    int x;
    cout << "\n\n\t\t\t======================";
    cout << "\n\n\t\t\t  Admin Control Panel";
    cout << "\n\n\t\t\t======================";
    cout << "\n\n\n 1. manegers";
    cout << "\n 2. workers";
    cout << "\n 3. Exit";
    cout << "\n\n Your Choice : ";
    cin >> x;
    switch (x)
    {
    case 1:
        obj.m_menu();

        break;

    case 2:
        obj.e_menu();
        break;

    case 3:
        exit(0);
    default:
        cout << "\n\n Invalid Value...Please try Again...";
    }
    getch();
    goto p;
}
void child ::e_menu()
{

p:
    system("cls");
    int x;
    cout << "\n\n\t\t\t======================";
    cout << "\n\n\t\t\t  Admin Control Panel ";
    cout << "\n\n\t\t\t======================";
    cout << "\n\n\t\t\t  workers ";
    cout << "\n\n\t\t\t======================";
    cout << "\n\n\n 1. Insert Record";
    cout << "\n 2. Display Record";
    cout << "\n 3. Search Record";
    cout << "\n 4. Modify Record";
    cout << "\n 5. Delete Record";
    cout << "\n 6. group search";
    cout << "\n 7. add salary";
    cout << "\n 8. Exit";
    cout << "\n\n Your Choice : ";
    cin >> x;
    switch (x)
    {
    case 1:
        e_insert();
        break;
    case 2:
        e_display();
        break;

    case 3:
        e_search();
        break;
    case 4:
        e_modify();
        break;
    case 5:
        e_del();
        break;
    case 6:
        e_group();
        break;

    case 7:
        add_esal();
        break;

    case 8:
        exit(0);
    default:
        cout << "\n\n Invalid Value...Please try Again...";
    }
    getch();
    goto p;
}

void child ::m_menu()
{

p:
    system("cls");
    int x;
    cout << "\n\n\t\t\t======================";
    cout << "\n\n\t\t\t  Admin Control Panel ";
    cout << "\n\n\t\t\t======================";
    cout << "\n\n\t\t\t  managers ";
    cout << "\n\n\t\t\t======================";
    cout << "\n\n\n 1. Insert Record";
    cout << "\n 2. Display Record";
    cout << "\n 3. Search Record";
    cout << "\n 4. Modify Record";
    cout << "\n 5. Delete Record";
    cout << "\n 6. group search";
    cout << "\n 7. add salary";
    cout << "\n 8. Exit";
    cout << "\n\n Your Choice : ";
    cin >> x;
    switch (x)
    {
    case 1:
        m_insert();
        break;
    case 2:
        m_display();
        break;

    case 3:
        m_search();
        break;
    case 4:
        m_modify();
        break;
    case 5:
        m_del();
        break;
    case 6:
        m_group();
        break;
    case 7:
        add_msal();
        break;

    case 8:
        exit(0);
    default:
        cout << "\n\n Invalid Value...Please try Again...";
    }
    getch();
    goto p;
}

void child::manager_menu()
{
p:
    system("cls");
    int x;
    cout << "\n\n\t\t\t======================";
    cout << "\n\n\t\t\t  manager Control Panel";
    cout << "\n\n\t\t\t======================";
    cout << "\n\n\n 1. Insert Record";
    cout << "\n 2. Display Record";
    cout << "\n 3. Search Record";
    cout << "\n 4. Modify Record";
    cout << "\n 5. group search";
    cout << "\n 6. add salary";
    cout << "\n\n\t\tsearch your information";
    cout << "\n\n 7. Check your Details";
    cout << "\n 8. Check your group";

    cout << "\n 9. Exit";
    cout << "\n\n Your Choice : ";
    cin >> x;
    switch (x)
    {
    case 1:
        e_insert();
        break;
    case 2:
        e_display();
        break;

    case 3:
        e_search();
        break;
    case 4:
        e_modify();
        break;

    case 5:
        e_group();
        break;

    case 6:
        add_esal();
        break;

    case 7:

        m_search();
        break;

    case 8:
        m_ygroup();
        break;

    case 9:
        exit(0);
    default:
        cout << "\n\n Invalid Value...Please try Again...";
    }
    getch();
    goto p;
}
void worker::e_insert()
{
    worker a(1);
}

void worker::e_display()
{
    system("cls");
    fstream file;
    cout << "\n\n\t\t\t\tDisplay Record";
    file.open("anilemp.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Openning Error...";
        return;
    }
    file >> emp_id >> name >> sal >> address >> group_id;
    while (!file.eof())
    {
        cout << "\n\nWorker ID : " << emp_id;
        cout << "\n\nWorker Name : " << name;
        cout << "\n\nWorker Salary : " << sal;
        cout << "\n\nWorker Address : " << address;
        cout << "\n\nGroup ID : " << group_id;
        file >> emp_id >> name >> sal >> address >> group_id;
    }
    file.close();
}

void worker::e_search()
{
    system("cls");
    fstream file;
    int emp_idd, found = 0;
    cout << "\n\n\t\t\t\tSearch Record";
    file.open("anilemp.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Openning Error...";
        return;
    }
    else

    {
        cout << "\n\n Worker ID For Search : ";
        cin >> emp_idd;
        file >> emp_id >> name >> sal >> address >> group_id;
        while (!file.eof())
        {
            if (emp_idd == emp_id)
            {
                system("cls");
                cout << "\n\n\t\t\t\tSearch Record";
                cout << "\n\nWorker ID : " << emp_id;
                cout << "\n\nWorker Name : " << name;
                cout << "\n\nWorker Salary : " << sal;
                cout << "\n\nWorker Address : " << address;
                cout << "\n\nGroup ID : " << group_id;
                found++;
            }
            file >> emp_id >> name >> sal >> address >> group_id;
        }
        file.close();
        if (found == 0)
            cout << "\n\n Worker ID Can't Found...";
    }
}

void worker::e_group()
{
    system("cls");
    fstream file;
    int group_idd, found = 0, count = 0;
    cout << "\n\n\t\t\t\tSearch Record";
    file.open("anilemp.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Openning Error...";
        return;
    }
    else

    {
        cout << "\n\n group ID For Search : ";
        cin >> group_idd;
        system("cls");
        cout << "\n\n\t\t\t\tSearch Record";
        file >> emp_id >> name >> sal >> address >> group_id;
        while (!file.eof())
        {
            if (group_idd == group_id)
            {

                cout << "\n\nGroup ID : " << group_id;
                cout << "\n\nWorker ID : " << emp_id;
                cout << "\n\nWorker Name : " << name;
                cout << "\n\nWorker Salary : " << sal;

                cout << endl;
                count++;
                found++;
            }
            file >> emp_id >> name >> sal >> address >> group_id;
        }
        cout << "\n\n\n\t\tNo of worker in group:" << count;
        file.close();
        if (found == 0)
            cout << "\n\n group ID Can't Found...";
    }
}

void worker::e_ygroup()
{
    system("cls");
    fstream file;
    int group_idd, emp_idd, found = 0, count = 0;
    cout << "\n\n\t\t\t\tSearch Record";
    file.open("anilemp.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Openning Error...";
        return;
    }
    else

    {
        cout << "\n\n Enter your worker ID : ";
        cin >> emp_idd;
        system("cls");
        cout << "\n\n\t\t\t\tSearch Record";

        file >> emp_id >> name >> sal >> address >> group_id;
        while (!file.eof())
        {
            if (emp_idd == emp_id)
            {
                cout << "\nYour group ID:" << group_id;
                group_idd = group_id;
            }
            file >> emp_id >> name >> sal >> address >> group_id;
        }
        file.close();

        file.open("anilemp.txt", ios::in);

        cout << "\n\n\t Workers in your group.....\n\n";

        file >> emp_id >> name >> sal >> address >> group_id;
        while (!file.eof())
        {
            if (group_idd == group_id)
            {

                cout << "\n\nGroup ID : " << group_id;
                cout << "\n\nWorker ID : " << emp_id;
                cout << "\n\nWorker Name : " << name;
                cout << "\n\nWorker Salary : " << sal;

                cout << endl;

                count++;
                found++;
            }
            file >> emp_id >> name >> sal >> address >> group_id;
        }
        cout << "\n\n\n\t\tNo of worker in group:" << count;
        file.close();
        if (found == 0)
            cout << "\n\n group ID Can't Found...";
    }
}

void worker::e_modify()
{
    system("cls");
    int sall, test_id, found = 0;
    string name1, address1;
    fstream file, file1;
    cout << "\n\n\t\t\t\tModify Record";
    file.open("anilemp.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Openning Error...";
        return;
    }
    cout << "\n\n Worker ID For Modify : ";
    cin >> test_id;
    file1.open("anilemp1.txt", ios::app | ios::out);
    file >> emp_id >> name >> sal >> address >> group_id;
    while (!file.eof())
    {
        if (test_id == emp_id)
        {
            system("cls");
            cout << "\n\n\t\t\t\tModify Record";
            cout << "\n\nWorker Name  : ";
            cin >> name1;
            cout << "\n\nWorker Salary : ";
            cin >> sall;
            cout << "\n\nWorker Address : ";
            cin >> address1;
            file1 << " " << emp_id << " " << name1 << " " << sall << " " << address1 << " " << group_id << "\n";
            found++;
        }
        else
        {
            file1 << " " << emp_id << " " << name << " " << sal << " " << address << " " << group_id << "\n";
        }
        file >> emp_id >> name >> sal >> address >> group_id;
    }
    file.close();
    file1.close();
    remove("anilemp.txt");
    rename("anilemp1.txt", "anilemp.txt");

    if (found == 0)
        cout << "\n\n Worker ID Can't Found...";
    else
        cout << "\n\n\t\t\t Record Modify Successfully...";
}

void worker::e_del()
{
    system("cls");
    int test_id, found = 0;
    fstream file, file1;
    cout << "\n\n\t\t\t\tDelete Record";
    file.open("anilemp.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Openning Error...";
        return;
    }
    cout << "\n\nWorker ID For Delete : ";
    cin >> test_id;
    file1.open("anilemp1.txt", ios::app | ios::out);
    file >> emp_id >> name >> sal >> address >> group_id;
    while (!file.eof())
    {
        if (test_id == emp_id)
        {
            cout << "\n\n Record Deleted Successfully...";
            found++;
        }
        else
        {
            file1 << " " << emp_id << " " << name << " " << sal << " " << address << " " << group_id << "\n";
        }
        file >> emp_id >> name >> sal >> address >> group_id;
    }
    file.close();
    file1.close();
    remove("anilemp.txt");
    rename("anilemp1.txt", "anilemp.txt");

    if (found == 0)
        cout << "\n\n Worker ID Can't Found...";
}

void manager::m_insert()
{
    manager a(1);
}
void manager::m_display()
{
    system("cls");
    fstream file;
    cout << "\n\n\t\t\t\tDisplay Record";
    file.open("anilmemp.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Openning Error...";

        return;
    }
    file >> emp_id >> name >> qul >> no_of_worker >> sal >> address >> group_id;
    while (!file.eof())
    {
        cout << "\n\nManager ID : " << emp_id;
        cout << "\n\nManager Name : " << name;
        cout << "\n\nQualification : " << qul;
        cout << "\n\nno 0f worker : " << no_of_worker;
        cout << "\n\nManager Salary : " << sal;
        cout << "\n\nManager Address : " << address;
        cout << "\n\nGroup ID : " << group_id;
        file >> emp_id >> name >> qul >> no_of_worker >> sal >> address >> group_id;
    }
    file.close();
}

void manager::m_search()
{
    system("cls");
    fstream file;
    int emp_idd, found = 0;
    cout << "\n\n\t\t\t\tSearch Record";
    file.open("anilmemp.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Openning Error...";
        return;
    }
    else

    {
        cout << "\n\nManager ID For Search : ";
        cin >> emp_idd;
        file >> emp_id >> name >> qul >> no_of_worker >> sal >> address >> group_id;
        while (!file.eof())
        {
            if (emp_idd == emp_id)
            {
                system("cls");
                cout << "\n\nSearch Record";
                cout << "\n\nManager ID : " << emp_id;
                cout << "\n\nManager Name : " << name;
                cout << "\n\nQualification : " << qul;
                cout << "\n\nno 0f worker : " << no_of_worker;
                cout << "\n\nManager Salary : " << sal;
                cout << "\n\nManager Address : " << address;
                cout << "\n\nGroup ID : " << group_id;
                found++;
            }
            file >> emp_id >> name >> qul >> no_of_worker >> sal >> address >> group_id;
        }
        file.close();
        if (found == 0)
            cout << "\n\n Maneger ID Can't Found...";
    }
}
void manager::m_group()
{
    system("cls");
    fstream file;
    int group_idd, found = 0, count = 0;
    cout << "\n\n\t\t\t\tSearch Record";
    file.open("anilmemp.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Openning Error...";
        return;
    }
    else

    {
        cout << "\n\ngroup ID For Search : ";
        cin >> group_idd;
        system("cls");
        cout << "\n\n\t\t\t\tSearch Record";
        file >> emp_id >> name >> qul >> no_of_worker >> sal >> address >> group_id;
        while (!file.eof())
        {
            if (group_idd == group_id)
            {
                cout << "\n\nGroup ID : " << group_id;
                cout << "\n\nManager ID : " << emp_id;
                cout << "\n\nManager Name : " << name;
                cout << "\n\nQualification : " << qul;
                cout << "\n\nno 0f worker : " << no_of_worker;
                cout << "\n\nManager Salary : " << sal;

                cout << endl;

                found++;
                count++;
            }
            file >> emp_id >> name >> qul >> no_of_worker >> sal >> address >> group_id;
        }
        cout << "\n\n\n\t\tNo of manager in group:" << count;
        file.close();
        if (found == 0)
            cout << "\n\n Maneger ID Can't Found...";
    }
}

void manager::m_ygroup()
{
    system("cls");
    fstream file;
    int group_idd, emp_idd, found = 0, count = 0;
    cout << "\n\n\t\t\t\tSearch Record";
    file.open("anilmemp.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Openning Error...";
        return;
    }
    else

    {
        cout << "\n\nEnter your manager ID : ";
        cin >> emp_idd;
        system("cls");
        cout << "\n\nSearch Record";
        file >> emp_id >> name >> qul >> no_of_worker >> sal >> address >> group_id;

        while (!file.eof())
        {
            if (emp_idd == emp_id)
            {
                cout << "\nYour group ID:" << group_id;
                group_idd = group_id;
            }
            file >> emp_id >> name >> qul >> no_of_worker >> sal >> address >> group_id;
        }

        file.close();

        file.open("anilmemp.txt", ios::in);

        cout << "\n\n\t Manager in your group.....\n\n";
        file >> emp_id >> name >> qul >> no_of_worker >> sal >> address >> group_id;
        while (!file.eof())
        {
            if (group_idd == group_id)
            {
                cout << "\n\nGroup ID : " << group_id;
                cout << "\n\nManager ID : " << emp_id;
                cout << "\n\nManager Name : " << name;
                cout << "\n\nno 0f worker : " << no_of_worker;
                cout << "\n\nManager Salary : " << sal;

                cout << endl;

                found++;
                count++;
            }
            file >> emp_id >> name >> qul >> no_of_worker >> sal >> address >> group_id;
        }
        cout << "\n\n\n\t\tNo of manager in group:" << count;
        file.close();
        if (found == 0)
            cout << "\n\n Maneger ID Can't Found...";
    }
}

void manager::m_modify()
{
    system("cls");
    int sal1, no_of_worker1, test_id, found = 0;
    string name1, address1;
    fstream file, file1;
    cout << "\n\n\t\t\t\tModify Record";
    file.open("anilmemp.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Openning Error...";
        return;
    }
    cout << "\n\nManeger ID For Modify : ";
    cin >> test_id;
    file1.open("anilmemp1.txt", ios::app | ios::out);
    file >> emp_id >> name >> qul >> no_of_worker >> sal >> address >> group_id;
    while (!file.eof())
    {
        if (test_id == emp_id)
        {
            system("cls");
            cout << "\n\n\t\t\t\tModify Record";
            cout << "\n\nManager Name : ";
            cin >> name1;
            cout << "\n\nno of worker : ";
            cin >> no_of_worker1;
            cout << "\n\nManager Salary : ";
            cin >> sal1;
            cout << "\n\nManager Address : ";
            cin >> address1;
            file1 << " " << emp_id << " " << name1 << " " << qul << " " << no_of_worker1 << " " << sal1 << " " << address1 << " " << group_id << "\n";
            found++;
        }
        else
        {

            file1 << " " << emp_id << " " << name << " " << qul << " " << no_of_worker << " " << sal << " " << address << " " << group_id << "\n";
        }
        file >> emp_id >> name >> qul >> no_of_worker >> sal >> address >> group_id;
    }
    file.close();
    file1.close();
    remove("anilmemp.txt");
    rename("anilmemp1.txt", "anilmemp.txt");

    if (found == 0)
        cout << "\n\n Manager ID Can't Found...";
    else
        cout << "\n\n\t\t\t Record Modify Successfully...";
}

void manager::m_del()
{
    system("cls");
    int test_id, found = 0;
    fstream file, file1;
    cout << "\n\n\t\t\t\tDelete Record";
    file.open("anilmemp.txt", ios::in);

    if (!file)
    {
        cout << "\n\n File Openning Error...";
        return;
    }
    cout << "\n\nManager ID For Delete : ";
    cin >> test_id;
    file1.open("anilmemp1.txt", ios::app | ios::out);
    file >> emp_id >> name >> qul >> no_of_worker >> sal >> address >> group_id;
    while (!file.eof())
    {
        if (test_id == emp_id)
        {
            cout << "\n\n Record Deleted Successfully...";
            found++;
        }
        else
        {
            file1 << " " << emp_id << " " << name << " " << qul << " " << no_of_worker << " " << sal << " " << address << " " << group_id << "\n";
        }
        file >> emp_id >> name >> qul >> no_of_worker >> sal >> address >> group_id;
    }
    file.close();
    file1.close();
    remove("anilmemp.txt");
    rename("anilmemp1.txt", "anilmemp.txt");

    if (found == 0)
        cout << "\n\n Manager ID Can't Found...";
}

worker operator+(worker a, worker b)
{

    worker x;
    x.sal = a.sal + b.sal;

    return x;
}

void worker ::add_esal()
{
    system("cls");
    int n;
    cout << "\n\nnumber of worker you want to add sallary : ";
    cin >> n;
    worker sum;
    sum.sal = 0;
    worker ad;

    for (int i = 0; i < n; i++)
    {
    P:
        int emp_idd, found = 0;
        fstream file;
        file.open("anilemp.txt", ios::in);
        cout << "\nenter worker ID : ";
        cin >> emp_idd;
        file >> emp_id >> name >> sal >> address >> group_id;
        while (!file.eof())
        {
            if (emp_idd == emp_id)
            {
                ad.sal = sal;
                found++;
            }
            file >> emp_id >> name >> sal >> address >> group_id;
        }
        file.close();

        if (found == 0)
        {
            cout << "\nworker ID not found....\n\n";
            goto P;
        }
        else
        {

            sum = sum + ad;
        }
    }

    cout << "\n\n\tsum of sallary:" << sum.sal;
}

manager operator+(manager a, manager b)
{

    manager x;
    x.sal = a.sal + b.sal;
    return x;
}
void manager ::add_msal()
{
    system("cls");
    int n;
    cout << "\n\nnumber of manager you want to add sallary : ";
    cin >> n;
    manager sum;
    sum.sal = 0;
    manager ad;

    for (int i = 0; i < n; i++)
    {
    P:
        int emp_idd, found = 0;
        fstream file;
        file.open("anilmemp.txt", ios::in);
        cout << "\nenter manager ID : ";
        cin >> emp_idd;
        file >> emp_id >> name >> qul >> no_of_worker >> sal >> address >> group_id;
        while (!file.eof())
        {
            if (emp_idd == emp_id)
            {
                ad.sal = sal;
                found++;
            }
            file >> emp_id >> name >> qul >> no_of_worker >> sal >> address >> group_id;
        }
        file.close();

        if (found == 0)
        {
            cout << "\nmanager ID not found....\n\n";
            goto P;
        }
        else
        {

            sum = sum + ad;
        }
    }

    cout << "\n\n\tsum of sallary:" << sum.sal;
}

main()
{

    log x;
    intro();
    obj.main_menu(x);
}



