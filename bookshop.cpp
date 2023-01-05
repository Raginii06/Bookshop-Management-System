
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;
//*******************************************************
// CLASSNAME:bookshop
//*******************************************************
class bookshop
{
public:
    void control_panel();
    void add_book();
    void show_books();
    void check_book();
    void update_book();
    void del_book();
};
//*******************************************************
// functioncontrolpanelwhichprovidestheessentialinterface
// betweentheuserandthelibrary
//*******************************************************
void bookshop::control_panel()
{
    system("cls");
    cout << "\n\n\t\t\t*************************************" << endl;
    cout << "\n\n\t\t\t*************************************" << endl;
    cout << "\n\n\t\t\tWELCOME TO LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << "\n\n\t\t\t*************************************" << endl;
    cout << "\n\n\t\t\t*************************************" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "\n\n\t\t\t*********THECONTROLPANEL**********";
    cout << "" << endl;
    cout << "" << endl;
    cout << "\n\t\tEnter the number of choice of operation you want to be executed" << endl;
    cout << "" << endl;
    cout << "\n\n\t\t\t\tControl Panel";
    cout << "\n1.Add New Book";
    cout << "\n2.Display Books";
    cout << "\n3.Check Specific Book";
    cout << "\n4.Update Book";
    cout << "\n5.Delete Book";
    cout << "\n6.Exit";
}
//*******************************************************
// function addbook which isused to take inputs from the user
// and store them in a file of name "book"
//*******************************************************
void bookshop::add_book()
{
    system("cls");
    fstream file;
    int no_copy;
    string b_name;
    string a_name;
    string b_id;
    cout << "\n\n\t\t\t\tADD New Book";
    cout << "\n\nBook ID:";
    cin >> b_id;
    cout << "\n\nBook Name:";
    cin >> b_name;
    cout << "\n\nAuthor Name:";
    cin >> a_name;
    cout << "\n\nNo. of Copies:";
    cin >> no_copy;
    // file handling
    // ios::out ensures writing and ios::append esures appending so that the
    // previous data written into the file is not overwritten and is not lost
    file.open("book.txt", ios::out | ios::app);
    file << "" << b_id << "" << b_name << "" << a_name << "" << no_copy << "\n";
    cout << "\nTHE BOOK RECORD HAS BEEN ADDED" << endl;
    cout << "PRESS ANY KEY IN ORDER TO GET BACK TO THE MENU" << endl;
    file.close();
}
void bookshop::show_books()
{
    system("cls");
    fstream file;
    int no_copy;
    string b_name;
    string b_id;
    string a_name;
    cout<<"\n\n\t\t\t\tShow All Books";
    // Here file is opened in ios::inmode since in this case we are
    // only reading from the file hence no need for ios::outmode
    file.open("book.txt", ios::in);
    // to ensure that the file is opened without any error and
    // for aswift output
    if (!file)
    {
        cout << "\n\nFile Openning Error...";
    }
    else
    {
        cout << "\n\nBookID BookAuthor No.ofCopies\n\n";
        file >> b_id >> b_name >> a_name >> no_copy;
        // this command reads aline from the file "book" and stores its values
        // in respective variables
        while (!file.eof())
        {
            // this command means that until the end of file is reached we are
            // required to print the details of the books since they are stored in
            // respective variables
            cout << "" << b_id << "" << b_name << "" << a_name << "\t\t" << no_copy << "\n\n";
            // the next line in the file gets stored with this following sentence:
            file >> b_id >> b_name >> a_name >> no_copy;
        }
        file.close();
    }
}
void bookshop::check_book()
{
    system("cls");
    fstream file;
    int no_copy;
    int count = 0;
    string b_id;
    string b_name;
    string a_name;
    string b_idd;
    cout << "\n\n\t\t\t\tCheck Specific Book";
    // Here file is opened in ios::inmode since in this case we are
    // only checking whether the book record is present or not
    // hence ios::out is not used
    file.open("book.txt", ios::in);
    // to ensure that the file is opened without any error and
    // for aswift output
    if (!file)
    {
        cout << "\n\nFile Openning Error...";
    }
    else
    {
        cout << "\n\nBookID:";
        cin >> b_idd;
        file >> b_id >> b_name >> a_name >> no_copy;
        // this loop basically matches the bookid of each book with the bookid
        // entered by the user and if it matches it increases the counter
        // if the counter remains null then it implies the book record is absent.
        while (!file.eof())
        {
            if (b_idd == b_id)
            {
                system("cls");
                cout << "\n\n\t\t\t\tCheck Specific Book";
                cout << "\n\nBookID:" << b_id;
                cout << "\n\nName:" << b_name;
                cout << "\n\nAuthor:" << a_name;
                cout << "\n\nNo. of Copies:" << no_copy;
                count++;
                break;
            }
            file >> b_id >> b_name >> a_name >> no_copy;
        }
        file.close();
        if (count == 0)
        {
            cout << "\n\nBookID Not Found...";
        }
    }
}
void bookshop::update_book()
{
    system("cls");
    fstream file;
    fstream file1;
    int no_copy;
    int no_co;
    int count = 0;
    string b_name;
    string b_na;
    string a_name;
    string a_na;
    string b_idd;
    string b_id;
    cout << "\n\n\t\t\t\tUpdate Book Record";
    // in this case we will be creating a temporary file where in all the records wil be added
        // one by one and the book record that needs to be changed will be edited by matching its bookid from the one which is entered by the user.
            // temporary file created in writing modes its going to be written from
            // input of the actual file.
            file1.open("book1.txt", ios::app | ios::out);
    // actual file opened in read modes ince its going to be simply read from
    file.open("book.txt", ios::in);
    // to ensure that the file is opened without any error and
    // for aswift output
    if (!file)
    {
        cout << "\n\nFile Openning Error...";
    }
    else
    {
        cout << "\n\nBookID:";
        cin >> b_id;
        file >> b_idd >> b_name >> a_name >> no_copy;
        while (!file.eof())
        {
            // this code of line will match the bookid entered by the user from that stored in the
                // database and will modify its contents as per the requests of the user and then
                // additinthetemporaryfile.
                if (b_id == b_idd)
            {
                system("cls");
                cout << "\n\nUpdate Book Record";
                cout << "\n\nNew Book Name:";
                cin >> b_na;
                cout << "\n\nAuthor Name:";
                cin >> a_na;
                cout << "\n\nNo. of Copies:";
                cin >> no_co;
                file1 << "" << b_id << "" << b_na << "" << a_na << "" << no_co << "\n";
                count++;
            }
            else
                // the book records which are not required to be changed still have to be
                    // entered in the temporary file hence this line is for that purpose.
            file1 << "" << b_idd << "" << b_name << "" << a_name << "" << no_copy << "\n";
            file >> b_idd >> b_name >> a_name >> no_copy;
        }
        if (count == 0)
        {
            cout << "\n\nBookID Not Found...";
        }
    }
    file.close();
    file1.close();
    // since the actual file remains useless to us as it not updated therefore deleting it
        remove("book.txt");
    // and renaming the temporary file to its original name for later purposes.
    rename("book1.txt", "book.txt");
}
void bookshop::del_book()
{
    system("cls");
    fstream file;
    fstream file1;
    int no_copy;
    int count = 0;
    string b_id;
    string b_idd;
    string b_name;
    string a_name;
    cout << "\n\n\t\t\t\tDelete Book Record";
    // in this case we will be creating a temporary file where in all the records will be added
        // one by one and the book record that needs to be deleted will be skipped by matchingits
            // book id with that of the id entered by the user.
            // temporary file created in writing mode since its going to be written from
            // input of the actual file.
            file1.open("book1.txt", ios::app | ios::out);
    // actual file opened in read mode since its going to be simply read from
    file.open("book.txt", ios::in);
    if (!file)
    {
        cout << "\n\nFile Openning Error...";
    }
    else
    {
        cout << "\n\nBookID:";
        cin >> b_id;
        file >> b_idd >> b_name >> a_name >> no_copy;
        // this loop basically ensures that with each traversal the book record
        // gets added to the temporary file and when the bookid entered by the
        // user matches with the bookid of the book that entry will get skipped
        while (!file.eof())
        {
            if (b_id == b_idd)
            {
                system("cls");
                cout << "\n\n\t\t\t\tDelete Book Record";
                cout << "\n\nOne Book is Deleted Successfully...";
                count++;
            }
            else
                file1 << "" << b_idd << "" << b_name << "" << a_name << "" << no_copy << "\n";
            file >> b_idd >> b_name >> a_name >> no_copy;
        }
        if (count == 0)
        {
            cout << "\n\nBook ID Not Found...";
        }
    }
    file.close();
    file1.close();
    // since the actual file remains useless to us as its not updated therefore deleting it
        remove("book.txt");
    // and renaming the temporary file to its original name for later purposes.
    rename("book1.txt", "book.txt");
}
main()
{
    int choice;
    char x;
    bookshop b;
// ensures infinite loop
p:
    b.control_panel();
    cout << "\n\nYour Choice:";
    cin >> choice;
    switch (choice)
    {
    case1:
        do
        {
            b.add_book();
            cout << "\n\nDo You Want to Add another Book:";
            cout << "\nfor yes ENTER'y'";
            cout << "\nfor no ENTER'n'";
            cin >> x;
        } while (x == 'y');
        break;
    case 2:
        b.show_books();
        break;
    case 3:
        b.check_book();
        break;
    case 4:
        b.update_book();
        break;
    case 5:
        b.del_book();
        break;
    case 6:
        exit(0);
    default:
        cout << "\n\nInvalid Value...Please Try Again...";
    }
    getch();
    goto p;
}
