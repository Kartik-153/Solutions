#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>
using namespace std;

class BookItem {
public:
    int identifier;
    string book_id;
    string goodreads_book_id;
    string best_book_id;
    int books_count;
    string isbn;
    string authors;
    string original_publication_year;
    string title;
    string language_code;
    string average_rating;
    string ratings_count;
    string work_ratings_count;
    string work_text_reviews_count;
    string ratings_1;
    string ratings_2;
    string ratings_3;
    string ratings_4;
    string ratings_5;
    string image_url;
    string small_image_url;
    bool isborrowed;
    string borrowerName;
    string borrowedDate;
    string dueDate;
};

class MagazineItem {
public:
    int identifier;
    string publication;
    string rank;
    string totalPaid;
    string wordRate;
    string daysToBePaid;
    string paymentDifficulty;
    string rank_totalPaid;
    string rank_wordRate;
    string rank_daysToBePaid;
    string rank_paymentDifficulty;
    bool isBorrowed;
    bool isElectronic;
    string borrowerName;
    string borrowedDate;
    string dueDate;
};

class journalItem {
public:
    string title_A;
    string title_B;
    string title_C;
    bool isBorrowed;
    bool isElectronic;
    string borrowerName;
    string borrowedDate;
};

class LibraryUser {
public:
    string name;
    string userType;
    LibraryUser(string name,string userType):name (name) , userType( userType){};
};

#define SIZE 10000

BookItem books[SIZE];
int length_books = 0;
MagazineItem magazine[SIZE];
int length_magazine = 0;
journalItem journal[SIZE];
int length_journal = 0;

bool compareIgnoreCase(const string& str1, const string& str2);
string calculateDueDate(const string& userType) {
    time_t currentTime = time(nullptr);
    struct tm* dueDate = localtime(&currentTime);

    if (userType == "student") {
        // Students have a one-month lending period
        dueDate->tm_mon += 1;
    } else if (userType == "teacher") {
        // Teachers have a six-month lending period
        dueDate->tm_mon += 6;
    } else {
        // Default to one month for other user types
        dueDate->tm_mon += 1;
    }
    // Normalize the due date
    mktime(dueDate);
    // Convert the due date to a string in the format "YYYY-MM-DD"
    stringstream ss;
    ss << dueDate->tm_year + 1900 << '-';
    ss << (dueDate->tm_mon + 1) << '-';
    ss << dueDate->tm_mday;

    return ss.str();
}
void readBooks(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open " << filename << endl;
        return;
    }
    string line;
    getline(file, line);
    int count = 1;
    while (getline(file, line)) {
        BookItem item;
        item.identifier = count++;
        stringstream ss(line);

        getline(ss, item.book_id, ',');
        getline(ss, item.goodreads_book_id, ',');
        getline(ss, item.best_book_id, ',');
        string token;
        if(getline(ss, token,',')){
            int val=stoi(token);
            item.books_count=val;
        }
        getline(ss, item.isbn, ',');
        getline(ss, item.authors, ',');
        getline(ss, item.original_publication_year, ',');
        getline(ss, item.title, ',');
        getline(ss, item.language_code, ',');
        getline(ss, item.average_rating, ',');
        getline(ss, item.ratings_count, ',');
        getline(ss, item.work_ratings_count, ',');
        getline(ss, item.work_text_reviews_count, ',');
        getline(ss, item.ratings_1, ',');
        getline(ss, item.ratings_2, ',');
        getline(ss, item.ratings_3, ',');
        getline(ss, item.ratings_4, ',');
        getline(ss, item.ratings_5, ',');
        getline(ss, item.image_url, ',');
        getline(ss, item.small_image_url, ',');
        // Initialize other members as needed.
        item.isborrowed = false;
        item.borrowerName = "";
        item.borrowedDate = "";
        item.dueDate = "";
        books[length_books++] = item;
    }
    file.close();
}

void readMagazines(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open " << filename << endl;
        return;
    }
    string line;
    getline(file, line);
    int count = 1;
    while (getline(file, line)) {
        MagazineItem item;
        item.identifier = count++;
        stringstream ss(line);

        getline(ss, item.publication, ',');
        getline(ss, item.rank, ',');
        getline(ss, item.totalPaid, ',');
        getline(ss, item.wordRate, ',');
        getline(ss, item.daysToBePaid, ',');
        getline(ss, item.paymentDifficulty, ',');
        getline(ss, item.rank_totalPaid, ',');
        getline(ss, item.rank_wordRate, ',');
        getline(ss, item.rank_daysToBePaid, ',');
        getline(ss, item.rank_paymentDifficulty, ',');
        // Initialize other members as needed.
        item.isBorrowed = false;
        item.borrowerName = "";
        item.borrowedDate = "";
        item.dueDate = "";
        magazine[length_magazine++] = item;
    }
    file.close();
}

void readJournals(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        journalItem item;
        stringstream ss(line);
        getline(ss, item.title_A, ',');
        getline(ss, item.title_B, ',');
        getline(ss, item.title_C, ',');
        // Initialize other members as needed.
        item.isBorrowed = false;
        item.isElectronic = false;
        item.borrowerName = "";
        item.borrowedDate = "";
        journal[length_journal++] = item;
    }
    file.close();
}

void BuyMagazine() {
    // Allow the user to choose a magazine
    cout << "Available Magazines:" << endl;
    for (int i = 0; i < length_magazine; ++i) {
        cout << i + 1 << ". " << magazine[i].publication << endl;
    }
    int choice;
    cout << "Enter the number of the magazine you want to buy: ";
    cin >> choice;
    // Check if the choice is valid
    if (choice >= 1 && choice <= length_magazine) {
        // Mark the selected magazine as bought
        magazine[choice - 1].isBorrowed = true;
        magazine[choice - 1].borrowerName = "Purchased";
        magazine[choice - 1].borrowedDate = "Current Date"; // You can set the actual date here
        magazine[choice - 1].dueDate = "Not Applicable";
        cout << "You have successfully purchased the magazine: " << magazine[choice - 1].publication << endl;
    } else {
        cout << "Invalid magazine choice." << endl;
    }
}

void BuyJournal() {
    // Allow the user to choose a journal
    cout << "Available Journals:" << endl;
    for (int i = 0; i < length_journal; ++i) {
        cout << i + 1 << ". " << journal[i].title_A << " | " << journal[i].title_B << " | " << journal[i].title_C << endl;
    }
    int choice;
    cout << "Enter the number of the journal you want to buy: ";
    cin >> choice;
    // Check if the choice is valid
    if (choice >= 1 && choice <= length_journal) {
        // Mark the selected journal as bought
        journal[choice - 1].isBorrowed = true;
        journal[choice - 1].borrowerName = "Purchased";
        journal[choice - 1].borrowedDate = "Current Date"; // You can set the actual date here
        cout << "You have successfully purchased the journal." << endl;
    } else {
        cout << "Invalid journal choice." << endl;
    }
}
void borrowItem() {
    string userName, userType, itemType;
    BookItem item;
    cout << "What do you want to borrow/buy (book/magazine/journal): ";
    cin >> itemType;
    
    LibraryUser newUser(userName,userType);

    if (itemType == "book" || itemType == "magazine") {
        string dueDate = calculateDueDate(userType);

        if (itemType == "book") {
            // Allow the user to choose a book
            cout << "Available Books:" << endl;
            for (int i = 0; i < length_books; ++i) {
                cout << i + 1 << ". " << books[i].title << endl;
            }
            int choice;
            cout << "Enter the number of the book you want to borrow: ";
            cin >> choice;
            // Check if the choice is valid
            if (choice >= 1 || choice <= length_books) {
                // Mark the selected book as borrowed
                books[choice - 1].isborrowed = true;
                books[choice - 1].borrowerName = userName;
                books[choice - 1].borrowedDate = "Current Date"; // You can set the actual date here
                books[choice - 1].dueDate = dueDate;
                cout << "You have successfully borrowed the book: " << books[choice - 1].title << endl;
                cout<<"Number of books available are: " << item.books_count--<<endl;
                // Print the due date for the book
                cout << "Due Date: " << books[choice - 1].dueDate << endl;
            } else {
                cout << "Invalid book choice." << endl;
            }
        } else if (itemType == "magazine") {
            // Allow the user to buy a magazine
            BuyMagazine();
            // Print the due date for the magazine if bought
            cout << "Due Date: " << magazine[length_magazine - 1].dueDate << endl;
        }
    } else if (itemType == "journal") {
        // Allow the user to buy a journal
        BuyJournal();
    } else {
        cout << "Invalid item type." << endl;
    }
}

int main() {
    readBooks("book.csv");
    readMagazines("magazines.csv");
    readJournals("journals.csv");
    LibraryUser* user;
    LibraryUser** userRecord= new LibraryUser*[100];
    int count=0;
    int ch;
    cout<<"Enter ch value :";
    cin>>ch;
    int x = 0;
    while(ch>0 && ch<5){
    int ch;
    cout<<" -----Enter your choices please------\n =>1 To Register yourself \n =>2 To Search an Item \n =>3 To borrow an item \n =>4 Exit"<<endl;
    cin>>ch;
    BookItem item;
    MagazineItem _item_;
    journalItem __item__;
    string userName, userType, itemType; 
    cin.ignore();
    switch(ch) {
        case 1:
                cout << "Enter user name: ";
                getline(cin, userName);
                cout << "Enter user type (student/faculty): ";
                cin >> userType;
                if(count==0) {
                    userRecord[count] = new LibraryUser(userName, userType);
                    count++;
                    cout<<userName<<" User Successfuly registered  as "<<userType<<endl;
                }
                else {
                    cout<<"test"<<endl;
                    bool flag=true;
                    for(int i=0;i<count;i++) {
                        if(userRecord[i]->name==userName && userRecord[i]->userType==userType) {
                                user=userRecord[i];
                                flag=false;
                        }
                    }
                     if(flag==false) {
                        cout<<userName<<" user Already registered "<<endl;
                        }
                    else {
                        cout<<"test1";
                        userRecord[count]=new LibraryUser(userName,userType);
                        count++;
                    }
                }
                break;
        case 2:
                cout << " Enter Item Type(Books, Magazines or Journels): " << endl;
                getline(cin, itemType);
               
                if(itemType == "Books") {
                    string __title__;
                    getline(cin, __title__);
                    for(int i = 0; i < length_books; i++) {
                        if(books[i].title==__title__) {
                            x = i;
                            break;
                        }
                    }
                    cout << books[x].identifier << endl;
                    cout << books[x].borrowedDate << endl;
                    cout << books[x].borrowerName << endl;
                    cout << books[x].dueDate << endl;
                }
                else if(itemType=="Magazines") {
                    // write code for magazines
                    x = 0;
                    string temp_publication;
                    getline(cin, temp_publication);
                    for(int i = 0; i < length_magazine; i++) {
                        if(magazine[i].publication == temp_publication) {
                            x = i;
                        }
                    }
                    cout << magazine[x].identifier << endl;
                    cout << magazine[x].borrowedDate << endl;
                    cout << magazine[x].borrowerName << endl;
                    cout << magazine[x].dueDate << endl;
                }
                else {
                    // write a similar code for journels.
                    x = 0;
                    string temp_title_A;
                    cout << "Enter the Title A of the journal:" << endl;
                    getline(cin, temp_title_A);
                    for(int i = 0; i < length_journal; i++) {
                        if(journal[i].title_A == temp_title_A) {
                            x = i;
                            break;
                        }
                    }
                    cout << journal[x].isBorrowed << endl;
                    cout << journal[x].borrowedDate << endl;
                    cout << journal[x].borrowerName << endl;
                }
                break;
        case 3:
                borrowItem();
                break;
        case 4: return 0;
                default:cout<<"Thanks for coming"<<endl;
                break;
    }
    }
    return 0;
}