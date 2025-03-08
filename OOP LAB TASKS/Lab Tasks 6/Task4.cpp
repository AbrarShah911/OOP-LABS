#include <iostream>
#include <string>
using namespace std;

// Base class
class Books {
protected:
    string genre;

public:
    Books(string g) : genre(g) {}

    virtual void displayDetails() const {
        cout << "Genre: " << genre << endl;
    }

    virtual ~Books() {}
};


class MysteryBook : public Books {
private:
    string title;
    string author;

public:
    MysteryBook(string t, string a) : Books("Mystery"), title(t), author(a) {}

    void displayDetails() const override {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
        cout << "-------------------------" << endl;
    }
};


class NovelBook : public Books {
private:
    string title;
    string author;

public:
    NovelBook(string t, string a) : Books("Novel"), title(t), author(a) {}

    void displayDetails() const override {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
        cout << "-------------------------" << endl;
    }
};


int main() {

    MysteryBook book1("The Communits Manifesto", "Karl Markx");
    NovelBook book2("White Nights", "Froydyor Dovtesyky");

    cout << "Library Books:" << endl;
    cout << "-------------------------" << endl;
    book1.displayDetails();
    book2.displayDetails();

    return 0;
}
