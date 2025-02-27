#include <iostream>
#include <string>
#include <utility> // for std::pair
using namespace std;

//Forward declarations for ease of understanding which classes are to be used
class Ball;
class Goal;
class Team;
class Game;
class Robot;

class Ball{
	private:
		int ballX;
		int ballY;

	public:
		Ball(int x, int y): ballX(x), ballY(y){}

		int getX(){
			return ballX;
		}

		int getY(){
			return ballY;
		}

		void move(int dx, int dy){
			ballX = ballX + dx;
			ballY = ballY + dy;
		}

		std::pair<int,int> getPosition(){
			return{ballX, ballY};
		}
};

class Robot{
	private:
		string name;
		int hits;

	public:
		Robot(string robotName) : name(robotName), hits(0) {}

		void hitBall(Ball &ball, int ballX, int ballY, const string &direction){
			hits++;
			ball.move(ballX, ballY);
			cout<< "Ball is hit in " << direction << " direction." << endl;
		}

		int returnHits(){
			return hits;
		}
};

class Goal{
	private:
		int goalX;
		int goalY;

	public:
		Goal(int x = 3, int y = 3): goalX(x), goalY(y){}

		bool isGoalReached(Ball &ball){
			if((ball.getX() == goalX) && (ball.getY() == goalY)){
				cout << "Goal is reached!" << endl;	
				return true;	
			}else{
				cout << "Goal is NOT reached!" << endl;
				return false;
			}
		}
};

class Team{
	private:
		string teamName;
		Robot *player;

	public:
		Team(string name, Robot* r) : teamName(name), player(r) {}
		Robot* getPlayer() { return player; }
};

class Game{
	private:
		Robot player1{"Player One"};
		Robot player2{"Player Two"};

		Team teamOne{"Team One", &player1};
		Team teamTwo{"Team Two", &player2};

		Goal myGoal;
		Ball myBall{0, 0};

	public:
		void startGame(){
			int x1;
			int y1;
			cout << "Team One please enter your hitting coordinates!" <<endl;
			cin >> x1 >> y1;	
			teamOne.getPlayer()->hitBall(myBall, x1, y1, "forward");
			myGoal.isGoalReached(myBall);

			int x2;
			int y2;
			cout << "Team Two please enter your hitting coordinates!" <<endl;
			cin >> x2 >> y2;	
			teamOne.getPlayer()->hitBall(myBall, x2, y2, "forward");
			myGoal.isGoalReached(myBall);
		}

		void play(){
			while (!myGoal.isGoalReached(myBall)){
			int x1;
			int y1;
			cout << "Team One please enter your hitting coordinates!" <<endl;
			cin >> x1 >> y1;	
			teamOne.getPlayer()->hitBall(myBall, x1, y1, "forward");
			if (myGoal.isGoalReached(myBall)){
				break;
			}

			int x2;
			int y2;
			cout << "Team Two please enter your hitting coordinates!" <<endl;
			cin >> x2 >> y2;	
			teamTwo.getPlayer()->hitBall(myBall, x2, y2, "forward");
			if(myGoal.isGoalReached(myBall)){
				break;
			}
		}
	}

		void declareWinner(){
			if(teamOne.getPlayer()->returnHits() > teamTwo.getPlayer()->returnHits()){
				cout << "Team one (even tough they may have lesser goals) WINS!" << endl;
			}else{
				cout << "Team two (even tough they may have lesser goals) WINS!" << endl;
			}
		}
};


int main(){

	Game myGame;
	myGame.startGame();
	myGame.play();
	myGame.declareWinner();

	return 0;
}