#include <iostream>
#include <iomanip>
#include <string>



int main() {
	std::string studentName;
	double score1, score2, score3, score4, score5;

	std::cout << "Enter the student's name followed by five test scores: ";
	std::getline(std::cin, studentName);

	std::cin >> score1 >> score2 >> score3 >> score4 >> score5;

	double averageScore = (score1 + score2 + score3 + score4 + score5) / 5;

	std::cout << "\nStudent name: " << studentName << std::endl;
	std::cout << "Test scores: " 
		<< std::fixed << std::setprecision(2) << score1 << " "
		<< std::fixed << std::setprecision(2) << score2 << " "
		<< std::fixed << std::setprecision(2) << score3 << " "
		<< std::fixed << std::setprecision(2) << score4 << " "
		<< std::fixed << std::setprecision(2) << score5 << std::endl;
	std::cout << "Average test score: " << std::fixed << std::setprecision(2) << averageScore << std::endl;

	return 0;
}
