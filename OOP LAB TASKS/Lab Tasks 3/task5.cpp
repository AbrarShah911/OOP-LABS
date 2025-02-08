#include <iostream>
#include <string>
using namespace std;

class Book {
private:
	string bookName;
	string isbn;
	string author;
	string publisher;

public:
	// Constructor
	Book(string bookName, string isbn, string author, string publisher) {
		this->bookName = bookName;
		this->isbn = isbn;
		this->author = author;
		this->publisher = publisher;
	}

		Book() {
		this->bookName = "";
		this->isbn = "";
		this->author = "";
		this->publisher = "";
	}

	// Query methods (Getters)
	string getBookName() const {
		return this->bookName;
	}

	string getISBN() const {
		return this->isbn;
	}

	string getAuthor() const {
		return this->author;
	}

	string getPublisher() const {
		return this->publisher;
	}

	string getBookInfo() const {
		return "Book Name: " + this->bookName + "\nISBN: " + this->isbn +
			"\nAuthor: " + this->author + "\nPublisher: " + this->publisher;
	}
};

int main() {
	Book books[3];

	books[0] = Book("White nights", "978-0743273565", "Froydor Dovetesky", "leMe");
	books[1] = Book("The Metamorphosis", "978-0061120084", "Franz Kafka", "leMe");
	books[2] = Book("1984", "978-0451524935", "George Orwell", "Signet Classic");
	

	for (int i = 0; i < 3; i++) {
		cout << "Book " << i + 1 << " Information:\n";
		cout << books[i].getBookInfo() << "\n\n";
	}

    return 0;
}
