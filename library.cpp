#include <iostream>
#include <fstream>
using namespace std;

class temp
{
    string id ,student, author, name, search;
    fstream file;
    public:
    void addBooks();
    void extractBook();
    void showAll();
}obj;

int main()
{
    char choice;
    cout <<"--------THE LIBRARY MANAGEMENT SYSTEM---------"<<endl; 
    cout <<"----------------------------------------------"<<endl;
    cout << "1-show all the books available"<<endl;
    cout << "2-extract a book"<<endl;
    cout << "3-add a book(admin)"<<endl;
    cout << "4-exit"<<endl;
    cout << "----------------------------------------------"<<endl;
    cout << "enter your choice :: ";
    cin >> choice;
    cout << "----------------------------------------------"<<endl;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.showAll();
        break;
    case '2':
        cin.ignore();
        obj.extractBook();
        break;
    case '3':
        cin.ignore();
        obj.addBooks();
        break;
    case '4':
        return 0;
        break;
    default:
        cout << "invalid input detected !! ";
        break;
    }

    return 0;
}
void temp ::addBooks()
{
    cout << "\n enter book id : ";
    getline(cin, id);
    cout << "\n enter book name : ";
    getline(cin, name);
    cout << "\n enter authors name : ";
    getline(cin, author);

    file.open("bookData.txt", ios ::out | ios ::app);
    file << id << "*" << name << "*" << author << endl;
    file.close();
}
void temp :: showAll()
{
    file.open("bookData.txt", ios ::in);
    getline(file, id, '*');
    getline(file, name, '*');
    getline(file, author, '\n');
    cout << "\n\n";
    cout << "\t\t book id \t\t\t book name \t\t\t author name " << endl;
    while (!file.eof())
    {
        cout << "\t\t" << id << "\t\t\t" << name << "\t\t\t" << author << endl;

        getline(file, id, '*');
        getline(file, name, '*');
        getline(file, author, '\n');
    }
    file.close();
}
void temp ::extractBook()
{

    showAll();
    cout << "enter the book id :";
    getline(cin, search);
    getline(file, id, '*');
    getline(file, name, '*');
    getline(file, author, '\n');

    cout << "\n\n";
    cout << "\t\t book id \t\t\t book name \t\t\t author name " << endl;
    while (!file.eof())
    {
        if (search == id)
        {
            cout << "\t\t" << id << "\t\t\t" << name << "\t\t\t" << author << endl;
            cout <<"book extracted successfully...!";
        }
        getline(file, id, '*');
        getline(file, name, '*');
        getline(file, author, '\n');
    }
    file.close();
}
//prateek saha