#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	int lineCount = 0;
	int fileCount = 1;
	ofstream logFile("Log1.txt");

	if (!logFile.is_open()) {
		cout << "Failed to create file!" << endl;
		return 1;
	}

	string line;
	cout << "Enter lines (type END to stop):" << endl;

	while (true) {
		getline(cin, line);

		if (line == "END") {
			break;
		}

		logFile << line << endl;
		lineCount++;

        if (lineCount == 10) {
			logFile.close();
			fileCount++;
			lineCount = 0;

			string fileName = "Log" + to_string(fileCount) + ".txt";
			logFile.open(fileName);

			if (!logFile.is_open()) {
				cerr << "Failed to create " << fileName << endl;
				return 1;
			}
		}
	}

	logFile.close();
	cout << "Input saved. " << fileCount << " file(s) created." << endl;

	return 0;
}
