#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Logger {
private:
	vector<string> logs;
	const size_t MAX_LOGS = 10;

	void addLog(const string& severity, const string& module, const string& message) {
		string fullLog = "[" + severity + "] [" + module + "] " + message;
		if (logs.size() >= MAX_LOGS) {
			logs.erase(logs.begin()); // remove oldest
		}
		logs.push_back(fullLog);
	}

public:
	void logInfo(const string& module, const string& message) {
		addLog("INFO", module, message);
	}

	void logWarning(const string& module, const string& message) {
		addLog("WARNING", module, message);
	}

	void logError(const string& module, const string& message) {
		addLog("ERROR", module, message);
	}

	friend class Auditor;
};

class Auditor {
private:
	string id;
	string password;

	bool authenticate(const string& inputID, const string& inputPass) const {
		return inputID == id && inputPass == password;
	}

public:
	Auditor(string i, string p) : id(i), password(p) {}

	vector<string> getLogs(const Logger& logger, const string& inputID, const string& inputPass) {
		if (authenticate(inputID, inputPass)) {
			return logger.logs;
		} else {
			cout << "Access Denied: Invalid credentials.\n";
			return {};
		}
	}
};

int main() {
	Logger logger;

	logger.logInfo("He's Here", "YOU GON GET SOME BABY");
	logger.logWarning("BAHIR MILO TUM", "APNE KHUD KO ZIYADA HI SAMAJ RAHA HAI!");
	logger.logError("Matter ho gaya", "Daddy woh jo hai na...mey ne LC500 ko mehran mey maardiya and now hes speaking bad words in urdu daddy please jaldi aaein.");

	for (int i = 4; i < 7; ++i) {
		logger.logInfo("System", "Log message #" + to_string(i));
	}

	Auditor auditor("admin", "admin"); // hehe lol

	vector<string> logs = auditor.getLogs(logger, "admin", "admin");

	cout << "\n--- Retrieved Logs (" << logs.size() << ") ---\n";
	for (const string& log : logs) {
		cout << log << "\n";
	}

	auditor.getLogs(logger, "admin", "admin");

	return 0;
}
