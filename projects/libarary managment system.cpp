#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Book {
public:
    int id; string title, author; bool isIssued;
    Book(int i, string t, string a) : id(i), title(t), author(a), isIssued(false) {}
    void display() { cout << "ID:" << id << ", Title:" << title << ", Author:" << author << ", Issued:" << (isIssued ? "Yes":"No") << endl; }
};

vector<Book> library;
queue<int> issuedQueue;
stack<int> returnedStack;

void addBook() {
    int id; string t,a;
    cout << "ID: "; cin >> id; cin.ignore();
    cout << "Title: "; getline(cin, t);
    cout << "Author: "; getline(cin, a);
    library.push_back(Book(id, t, a));
    cout << "Book Added!\n";
}

void displayBooks() {
    if(library.empty()){ cout << "No Books!\n"; return; }
for(size_t i = 0; i < library.size(); i++) {
    library[i].display();
}
}

int main() {
    int choice;
    do {
        cout << "\n1.Add Book \n2.Display \n3.Exit\nChoice: "; cin >> choice;
        switch(choice){
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: break;
            default: cout << "Invalid\n";
        }
    } while(choice!=3);
}
