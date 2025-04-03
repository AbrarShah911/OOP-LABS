#include <iostream>
#include <vector>
using namespace std;

class Media {
protected:
	string title, publicationDate, uniqueID, publisher;
	bool isAvailable;

public:
	Media(string t, string pubDate, string id, string pub)
		: title(t), publicationDate(pubDate), uniqueID(id), publisher(pub), isAvailable(true) {}

	virtual void displayInfo() {
		cout << "Title: " << title << "\nPublication Date: " << publicationDate
			 << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher
			 << "\nAvailability: " << (isAvailable ? "Available" : "Checked Out") << endl;
	}

	void checkOut() {
		if (isAvailable) {
			isAvailable = false;
			cout << title << " has been checked out." << endl;
		} else {
			cout << title << " is already checked out." << endl;
		}
	}

	void returnItem() {
		isAvailable = true;
		cout << title << " has been returned." << endl;
	}

	string getTitle(){
		return this->title;
	}

	virtual ~Media() {}
};

class Book : public Media {
private:
	string author, ISBN;
	int numberOfPages;

public:
	Book(string t, string pubDate, string id, string pub, string auth, string isbn, int pages)
		: Media(t, pubDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

	void displayInfo() override {
		Media::displayInfo();
		cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << endl;
	}
};

class DVD : public Media {
private:
	string director, rating;
	int duration;

public:
	DVD(string t, string pubDate, string id, string pub, string dir, int dur, string rate)
		: Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rate) {}

	void displayInfo() override {
		Media::displayInfo();
		cout << "Director: " << director << "\nDuration: " << duration << " minutes\nRating: " << rating << endl;
	}
};

class CD : public Media {
private:
	string artist, genre;
	int numberOfTracks;

public:
	CD(string t, string pubDate, string id, string pub, string art, int tracks, string gen)
		: Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

	void displayInfo() override {
		Media::displayInfo();
		cout << "Artist: " << artist << "\nTracks: " << numberOfTracks << "\nGenre: " << genre << endl;
	}
};

class Magazine : public Media {
private:
	int issueNumber;

public:
	Magazine(string t, string pubDate, string id, string pub, int issue)
		: Media(t, pubDate, id, pub), issueNumber(issue) {}

	void displayInfo() override {
		Media::displayInfo();
		cout << "Issue Number: " << issueNumber << endl;
	}
};

class Library {
private:
	vector<Media *> collection;

public:
	void addMedia(Media *m) {
		collection.push_back(m);
	}

	void searchByTitle(string t) {
		for (Media *m : collection) {
			if (m->getTitle() == t) {
				m->displayInfo();
				return;
			}
		}
		cout << "Media not found." << endl;
	}
};

int main() {
	Library lib;
	Book b1("White Nights", "1848", "TRAUMA101", "Penguin Classics", "Fyodor Dostoevsky", "123456789", 85);
	DVD d1("Inception", "2010", "D101", "Warner Bros", "Christopher Nolan", 148, "PG-13");
	CD c1("Thriller", "1982", "C201", "Epic Records", "Michael Jackson", 9, "Pop");
	Magazine m1("MAD", "2023", "M301", "DC Comics", 150);

	lib.addMedia(&b1);
	lib.addMedia(&d1);
	lib.addMedia(&c1);
	lib.addMedia(&m1);

	b1.displayInfo();
	d1.checkOut();
	d1.displayInfo();

	lib.searchByTitle("Thriller");

	return 0;
}
