#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <random>
#include <cstdlib>
using namespace std;

class Blend{
	public:
			void blendProcess(){
				cout << "Blending Juice!!" << endl;
				for(int i = 0; i < 5 ;i++){
						cout << "Blending proccess going on for " << (i+1) << " sconds\n";
						this_thread::sleep_for(std::chrono::seconds(1));;
				}
				cout << "Blended!" << endl;
			}
};


class Grind{
	public:
			void grindProcess(){
					cout << "Grinding juice" << endl;
					this_thread::sleep_for(std::chrono::seconds(5)); 
					cout << "Grinding complete!" << endl;
				}
};

class JuiceMaker {
private:
	Blend blender;
	Grind grinder;
	vector<string> fruits = {"Kayla", "Ambrood", "Saib", "Aam", "Annannaas"};
public:
    void blendJuice() {
		cout << "Selecting fruits for blending..." << endl;
		int index = rand() % fruits.size();
		cout << "Selected fruit: " << fruits[index] << endl;
		blender.blendProcess();
    }

    void grindJuice() {
        std::cout << "Grinding the blended juice..." << endl;
        grinder.grindProcess();
    }
};

int main(){
	srand(time(0));
	JuiceMaker juicer;
	juicer.blendJuice();
	juicer.grindJuice();
	return 0;
}