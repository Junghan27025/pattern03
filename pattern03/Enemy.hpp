class Enemy {
private:
    float firstY = 0.3f;
    float firstX = 0.45f;

public:
    float enemyX[3]; 
    float enemyY[3];
    float enemy1X[3];
    float enemy1Y[3];

    Enemy() {
        for (int i = 0; i < 3; i++) {
            enemyX[i] = 1;   
            enemyY[i] = firstY; 
            firstY -= 0.3f;
            enemy1X[i] = firstX;
            firstX -= 0.45f;
            enemy1Y[i] = 1;
        }

    };
    ~Enemy() {};

 
    void enemyMove() {   
        if (enemyX[0] <= -1)
        {
            enemyX[0] = 1;
        }
        else
        {
            enemyX[0] -= 0.009f;
        }
        if (enemyX[1] <= -1)
        {
            enemyX[1] = 1;
        }
        else
        {
            enemyX[1] -= 0.008f;
        }
        if (enemyX[2] <= -1)
        {
            enemyX[2] = 1;
        }
        else
        {
            enemyX[2] -= 0.007f;
        }
        if (enemy1Y[0] <= -1)
        {
            enemy1Y[0] = 1;
        }
        else
        {
            enemy1Y[0] -= 0.006f;
        }
        if (enemy1Y[1] <= -1)
        {
            enemy1Y[1] = 1;
        }
        else
        {
            enemy1Y[1] -= 0.007f;
        }
        if (enemy1Y[2] <= -1)
        {
            enemy1Y[2] = 1;
        }
        else
        {
            enemy1Y[2] -= 0.005f;
        }
    }
    
};