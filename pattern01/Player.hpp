class Player
{
public:
	float playerMovex1, playerMovey1, playerMovex2, playerMovey2;
	Player()
	{
		playerMovey1 = 0.0f;
		playerMovey2 = 0.1f;
		playerMovex1 = 0.1f;
		playerMovex2 = 0.0f;
	}
	~Player()
	{

	}

	void isKeyPressed()
	{
		playerMovex1 = 1.6f;
		playerMovex2 = 1.0f;
		playerMovey1 = 1.0f;
		playerMovey2 = 1.6f;
	}

	void isKeyUnpressed()
	{
		playerMovex1 = 0.6f;
		playerMovex2 = 0.0f;
		playerMovey1 = 0.0f;
		playerMovey2 = 0.6f;
	}

};