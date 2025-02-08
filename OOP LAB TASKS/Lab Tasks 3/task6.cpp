#include <iostream>
#include <vector>
using namespace std;

class Matrix {
	private:
		int rows, cols;
		vector<vector<int>> matrix; // 2D vector Array for storing a matrix.

	public:
		// Constructor
		Matrix(int r, int c) : rows(r), cols(c), matrix(r, vector<int>(c, 0)) {}

		int getRows(){
			return rows;
		}

		int getCols(){
			return cols;
		}

	void setElement(int i, int j, int value) {
		if (i >= 0 && i < rows && j >= 0 && j < cols) {
			matrix[i][j] = value;
		} else {
			cout << "Invalid index!" << endl;
		}
	}

	void display() const {
		for (const auto &row : matrix) {
			for (int val : row) {
				cout << val << " ";
			}
			cout << endl;
		}
	}

	// Modified plus operator to plus 2 matricies. YES I HAVE DONE THIS IT IS NOT FULLY AI GENERATED.
	Matrix operator+(const Matrix &myMatrix) {
		if (rows != myMatrix.rows || cols != myMatrix.cols) {
			cout << "Matrices cannot be added" << endl;
			return *this;
		}

		Matrix result(rows, cols);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				result.matrix[i][j] = matrix[i][j] + myMatrix.matrix[i][j];
			}
		}
		return result;
	}

	// Modified the multiplication operator to multiply 2 matrices.
	Matrix operator*(const Matrix &myMatrix) {
		if (cols != myMatrix.rows) {
			cout << "Matrices cannot be multiplied" << endl;
			return *this; // Returns a pointer refrence to this instance so that it can be used for further operations.
		}
		Matrix result(rows, myMatrix.cols);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < myMatrix.cols; ++j) {
				for (int k = 0; k < cols; ++k) {
					result.matrix[i][j] += matrix[i][k] * myMatrix.matrix[k][j];
				}
			}
		}
		return result;
		}
};

int main() {
	Matrix A(2, 2), B(2, 2);
	A.setElement(0, 0, 1);
	A.setElement(0, 1, 2);
	A.setElement(1, 0, 3);
	A.setElement(1, 1, 4);

	B.setElement(0, 0, 5);
	B.setElement(0, 1, 6);
	B.setElement(1, 0, 7);
	B.setElement(1, 1, 8);

	cout << "Matrix A:" << endl;
	A.display();

	cout << "Matrix B:" << endl;
	B.display();

	Matrix C = A + B;
	cout << "A + B:" << endl;
	C.display();

	Matrix D = A * B;
	cout << "A * B:" << endl;
	D.display();

	return 0;
}