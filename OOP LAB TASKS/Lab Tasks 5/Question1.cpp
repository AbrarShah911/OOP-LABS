#include <iostream>
#include <string>
using namespace std;

class Engine{
	private:
		bool isRunning;

	public:
		void start(){
			cout << "Engine has started!" << endl;
			this->isRunning = true;
		}

		void stop(){
			cout << "Engine has stopped!" << endl;
			this->isRunning = false;
		}

		~Engine(){
			cout << "Engine Destroyed!" << endl;
		}
};

class Car{
	private:
		Engine engine;

	public:
		void startCar(){
			this->engine.start();
		}

		void stopCar(){
			this->engine.stop();
		}

	~Car(){
		cout << "Car Destroyed!" << endl;
	}
};

int main(){

	Car toyota;

	toyota.startCar();
	toyota.stopCar();

	return 0;		
}