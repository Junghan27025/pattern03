using namespace std;
class Player {

public:

	float playerX;
	float playerY;
	Player() {
		playerX = 0;
		playerY = 0;
	};
	~Player()  {};

	void upPressed() {
		playerY = 0.3f;
	}
	void downPressed() {
		playerY = -0.3f;
	}
	void rightPressed() {
		playerX = 0.45f;
	}
	void leftPressed() {
		playerX = -0.45f;
	}
	void firstPressed() {
		playerY = 0.0f;
		playerX = -0.45f;
	}
	void secondPressed() {
		playerY = 0.0f;
		playerX = 0.0f;
	}
	void thirdPressed() {
		playerY = 0.0f;
		playerX = 0.45f;
	}
	
};