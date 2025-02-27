#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Catalog {
	private:
    	int index;

	public:
    	Catalog() : index(0) {}
    	~Catalog() {}
};

class Book {
	private:
		bool isLoaned;
		int ISBN;

	public:
		Book(int isbn, bool isloaned = false) : ISBN(isbn), isLoaned(isloaned){}

		void loanBook(){
			isLoaned = true;
		}

		int getISBN(){
			return ISBN;
		}

		bool getLoanStatus(){
			return isLoaned;
		}

		~Book() {}
};

class Library {
	private:
		vector<Book*> books;
		string name;
		Catalog cat;

    public:
		Library(string library) : name(library) {}

		void addBook(Book* book) {
			books.push_back(book);
			cout << "Book ISBN " << book->getISBN() << " added to library." << endl;
		}

		void removeBook(Book* book) {
			for (auto i = books.begin(); i != books.end(); ++i) {
			if (*i == book) {
				books.erase(i);
				cout << "Book ISBN " << book->getISBN() << " is removed from library." << endl;
				return;
				}
			}
			cout << "Book not found!" << endl;
		}

		void listBooks() {
			cout << "Books in Library: " << name << endl;
			for (const auto& book : books) {
				cout << "ISBN: " << book->getISBN() << ", Loaned: " << (book->getLoanStatus() ? "Yes" : "No") << endl;
			}
		}

		void findBookInCatalog(int isbn){
			for(const auto& book: books){
				if(book->getISBN() == isbn){
					cout<< "Book Found!" << endl;
				}
			}
			cout << "Book not Found!" << endl;
		}

		~Library() {
    		cout << "Library " << this->name << " deleted!" << endl;
		}
};

int main() {
	Library lib("National Library");

	Book* book1 = new Book(3483948);
	Book* book2 = new Book(3958356);

	lib.addBook(book1);
	lib.addBook(book2);

	lib.listBooks();

	book1->loanBook();
	cout << "After loaning book1:" << endl;
	lib.listBooks();

	lib.removeBook(book1);
	lib.listBooks();

	delete book1;
	delete book2;

	return 0;
}
