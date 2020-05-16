#include <conio.h>
#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

int xMax, yMax,			//boundaries
	headx, heady,		//head of the snake
	foodX, foodY,		//food of the snake
	snakeLen = 3,		//length of the snake initially 3
	score;

int bodyX[50], bodyY[50];		//for keeping the position of the body of the snake

bool gameOver = false;		//if true than game over
bool foodEaten = true;		//if true new food will be generated

enum direction {UP, DOWN, LEFT, RIGHT, STOP};
direction dir = STOP;

void positionCalc()
{
	bodyX[0] = headx;
	bodyY[0] = heady;


	if (dir != STOP)
	{
		//updating the index value in the array with the previous one
		for (int i = (snakeLen - 1); i >= 1 ; --i)
		{
			bodyX[i] = bodyX[i - 1];
			bodyY[i] = bodyY[i - 1];
		}
	}

	//Changing the value of the coordinates for the movement of the snake
	switch(dir)
	{
		case LEFT : --headx;
				break;
		case UP : --heady;
				break;
		case RIGHT : ++headx;
				break;
		case DOWN : ++heady;
				break;
	}



	//If the snake eats the food
	if (headx == foodX && heady == foodY)
	{
		/* code */
		foodEaten = true;
		score += 10;

		//increasing the length of the snake
		bodyX[snakeLen] = bodyX[snakeLen - 1];
		bodyY[snakeLen] = bodyY[snakeLen - 1];
		snakeLen++;
	}

	//random position of food, for the snake
	if (foodEaten)
	{
		/* code */
		foodX = (rand() % (xMax - 2)) + 1;
		foodY = (rand() % (yMax - 2)) + 1;
		foodEaten = false;
	}

    //if snake touches the boundary
	if(headx == 1 || heady == 1 || headx == xMax || heady == yMax)
    {
        gameOver = true;
    }

    //if snake touches its body
    for(int i=1;i<snakeLen;i++)
    {
        if(headx == bodyX[i] && heady == bodyY[i])
            gameOver = true;
    }
}

void getInput()
{
	cout << "\n\t------------------------------------------";
	cout << "\n\t--------WELCOME TO THE SNAKE GAME---------";
	cout << "\n\t------------------------------------------";
	cout << "\n\n\tEnter the height of your playground : ";
	cin >> xMax;
	cout << "\n\tEnter the width of your playground : ";
	cin >> yMax;

	//head of the snake to be at the center of the playground
	headx = (xMax / 2);
	heady = (yMax / 2);

	bodyX[0] = headx;
	bodyY[0] = heady;

	bodyX[1] = bodyX[0];
	bodyY[1] = bodyY[0] + 1;

	bodyX[2] = bodyX[1];
	bodyY[2] = bodyY[1] + 1;
}

/*
   bool directionAccessibility(char input) checks whether the direction entered by the user is
   accessible by the snake or not as per its current direction(value of dir). For instance, take a
   case where the snake is moving towards RIGHT. If the player tries to move LEFT, the snake would
   retrace its path moving through its own body. This is not a possible case and would result in
   GAME OVER as the head will touch the body. This function will make that direction inaccessible
   and the snake will keep moving in its current direction.
*/

bool directionAccessibility(char input)
{
    direction checkDir;
    switch(input)
    {
        case 'a' : checkDir = RIGHT;
					break;
        case 'w' : checkDir = DOWN;
					break;
		case 'd' : checkDir = LEFT;
					break;
		case 's' : checkDir = UP;
					break;
    }
    if(checkDir != dir)
        return true;
    else
        return false;

}

void display()
{
	system("CLS");
	//loop in Y direction
	for (int i = 1; i <= yMax; ++i)
	{
		//loop in X direction
		for (int j = 1; j <= xMax; ++j)
		{
			//for printing out the wall at the boundaries
			if (i == 1 || i == yMax || j == 1 || j == xMax)
			{
				cout << "#";
			}

			else
			{
				//for printing body of the snake
				bool bodyPrinted = false;
				for (int k = 1; k < snakeLen; ++k)
				{
					/* code */
					if (j == bodyX[k] && i == bodyY[k])
					{
						cout<<"o";
						bodyPrinted = true;
					}
				}
				if (bodyPrinted)
				{
					continue;
				}

				//for printing head of the snake
				if(headx == j && heady == i)
				{
					cout << "O";
				}

				//for printing the food of the snake
				else if(foodX == j && foodY == i)
				{
					cout << "+";
				}
				else
					cout << " ";
			}
		}
		cout << endl;
	}
}

void input()
{
	if (kbhit())
	{
		switch(getch())
		{
			case 'a' : if(directionAccessibility('a'))
			             dir = LEFT;
					  break;
			case 'w' : if(directionAccessibility('w'))
			             dir = UP;
                      break;
			case 'd' : if(directionAccessibility('d'))
			             dir = RIGHT;
					  break;
			case 's' : if(directionAccessibility('s'))
			             dir = DOWN;
					  break;
			case 'x' : gameOver = true;
					break;
		}
	}
}

void gameOverDisplay()
{
    system("CLS");
    cout << "\n\t-------------------------------------------";
    cout << "\n\t-----------------GAMEOVER------------------";
    cout << "\n\t-------------------------------------------";
    cout << "\n\t Score :"<< score<< "\n\n\n\n";

}

int main()
{
	/* code */
	getInput();
	while(!gameOver)
	{
		display();
		input();
		positionCalc();
		Sleep(50);
	}

	if(gameOver)
    {
        gameOverDisplay();
    }


	return 0;
}
