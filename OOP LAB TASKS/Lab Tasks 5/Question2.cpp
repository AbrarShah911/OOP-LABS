#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car{

	private:
		string name;

	public:
		Car(string n): name(n){
			cout << "Car Created!" << endl;
		}

		string getName(){
			return this->name;
		}

	~Car(){
		cout << "Car Destroyed!" << endl;
	}
};

class Garage{
	private:
		vector<Car*> cars;

	public:
		void parkCar(Car* car){
			cars.push_back(car);
			cout << "Car is added to collection" << endl;
		}

		void listCars(){
			for(const auto& car: cars){
				cout << car->getName() << endl;
			}
		}

		~Garage(){}
};

int main(){

	Garage g;
	Car* car1 = new Car("Toyota");
	Car* car2 = new Car("Honda");

	g.parkCar(car1);
	g.parkCar(car2);

	g.listCars();

	return 0;
}