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

	void qPressed() {
		playerX = -0.45f;
		playerY = 0.3f;
	}
	void wPressed() {
		playerX = 0;
		playerY = 0.3f;
	}
	void ePressed() {
		playerX = 0.45f;
		playerY = 0.3f;
	}
	void aPressed() {
		playerX = -0.45f;
		playerY = 0;
	}
	void sPressed() {
		playerX = 0;
		playerY = 0;
	}
	void dPressed() {
		playerX = 0.45f;
		playerY = 0;
	}
	void zPressed() {
		playerX = -0.45f;
		playerY = -0.3f;
	}
	void xPressed() {
		playerX = 0;
		playerY = -0.3f;
	}
	void cPressed() {
		playerX = 0.45f;
		playerY = -0.3f;
	}
};