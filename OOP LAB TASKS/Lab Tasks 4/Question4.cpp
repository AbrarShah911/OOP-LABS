#include <iostream>
#include <string>
using namespace std;

class Book {
private:
	string author;
	string title;
	double price;
	string publisher;
	int stock;

public:
    // Constructor
    Book(string auth, string tit, double pr, std::string pub, int stk) 
		: author(auth), title(tit), price(pr), publisher(pub), stock(stk) {}


	void searchBook(string& searchTitle,string& searchAuthor) {
		if (searchTitle == title && searchAuthor == author) {
			cout << "Book found:\n";
			displayBook();
		} else {
			cout << "Book not available in inventory." << std::endl;
		}
	}


	void displayBook() const {
		cout << "Title: " << title << "\n" << "Author: " << author << "\n" << "Price: " << price << "\n" << "Publisher: " << publisher << "\n" << "Stock Available: " << stock << std::endl;
	}


	void purchaseBook(int copies) {
		if (copies <= stock) {
			cout << "Total Cost: " << (copies * price) << endl;
			stock -= copies;
		} else {
			cout << "Copies not in stock." << endl;
		}
	}
};

int main() {
	Book book("Scooby Dooby Doo", "Shaggy", 20.09, "London", 100);

	string searchTitle, searchAuthor;
	cout << "book title: ";
	getline(cin, searchTitle);
	cout << "author name: ";
	getline(cin, searchAuthor);

	book.searchBook(searchTitle, searchAuthor);

	int copies;
	cout << "Enter number of copies required: ";
	cin >> copies;

	book.purchaseBook(copies);

	return 0;
}