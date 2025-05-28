#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;



void displayRecord()
{
    ifstream read("attendence.txt");

    char line[30];

    while (read.getline(line, 30))
    {
        cout << line << endl;
    }


    cout << "====================================================" << endl;

}



void addStudentRecord()
{

    ofstream write("attendence.txt", ios::app);

    int id = 0;
    char name[20], status[20];
    cout << "Enter the student ID  ";
    cin >> id;

    cout << "Enter the student Name  ";
    cin >> name;

    cout << "Enter the student Status  ";
    cin >> status;

    cin.ignore();

    write << id << "  " << name << "  " << status << endl;

    write.close();

    cout << "Data Written successfully" << endl;

    cout << "====================================================" << endl;

}

void searchId()
{
    int id = 0;
    cout << "Enter the ID to search: ";
    cin >> id;

    ifstream read("attendence.txt");

    if (!read)
    {
        cout << "Error in opening file" << endl;
        return;
    }

    int fileid = 0;
    char name[20], status[20];
    bool flag = false;

    while (read >> fileid >> name >> status)
    {
        if (fileid == id)
        {
            flag = true;
            cout << "Student Found:" << endl;
            cout << "ID: " << fileid << ", Name: " << name << ", Status: " << status << endl;
            break;
        }
    }

    if (!flag)
    {
        cout << "Student not found" << endl;
    }

    read.close();
    cout << "====================================================" << endl;

}

void updateData()
{
    ofstream write("temp.txt",ios::app);
    ifstream read("attendence.txt");

    int id = 0;
    char status[20];
     
    cout << "Enter the Id to update  ";
    cin >> id;
    cin.ignore();
    cout << "Enter the status  ";
    cin >> status;

    int fileId = 0;
    char name[10],status1[10];
    bool flag = false;

    while (read >> fileId >> name >> status1)
    {
        if (id == fileId)
        {
            flag = true;
            
            write << id << " " << name << " " << status << endl;
        }
        else
        {
            write << fileId << " " << name << " " << status1 << endl;
        }
    }
    if (flag == false)
    {
        cout << "ID not found" << endl;
    }
    read.close();
    write.close();

    ofstream main("attendence.txt");
    ifstream copy("temp.txt");

    char ch;
    while (copy.get(ch))
    {
        main.put(ch);
    }

    main.close();
    copy.close();

    remove("temp.txt");

    cout << "====================================================" << endl;
    cout << "Data updated successfully" << endl;
}

void deleteData()
{
    ifstream read("attendence.txt");
    ofstream write("temp.txt");

    int id = 0;
    cout << "Enter the ID to delete the record  ";
    cin >> id;

    int fileId = 0;
    char name[20], status[20];
    bool flag = false;

    while (read >> fileId >> name >> status)
    {
        if (fileId == id)
        {
            flag = true;
        }
        else
        {
            write << fileId<<"  " << name<<"  " << status<<endl;
        }
    }


    if (flag == false)
    {
        cout << "It not found in the record" << endl;
    }

    read.close();
    write.close();


    ifstream copy("temp.txt");
    ofstream main("attendence.txt");
    char ch;
    while (copy.get(ch))
    {
        main.put(ch);
    }

    copy.close();
    main.close();

    remove("temp.txt");

    if (flag == true)
    {
        cout << "Data Deleted successfully" << endl;
        cout << "====================================================" << endl;
    }
    else
    {
        cout << "====================================================" << endl;
        return;
    }
   
}

int main()
{
    int choice = 0;
    cout << "===============Welcome To The Student Attendence Managment=============" << endl;

    while (true)
    {
        cout << "1. Add Student Data\n2. Display Data\n3. Search Student by ID\n4. Update Data\n5. Delete Record\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "====================================================" << endl;

        if (choice == 1)
        {
            addStudentRecord();
        }
        else if (choice == 2)
        {
            displayRecord();
        }
        else if (choice == 3)
        {
            searchId();
        }
        else if (choice == 4)
        {
            updateData();
        }
        else if (choice == 5)
        {
            deleteData();
        }
        else if (choice == 6)
        {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Try again." << endl;
            cout << "====================================================" << endl;
        }
    }
   
    return 0;
}