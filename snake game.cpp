#include <conio.h>
#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

int xMax, yMax,			//boundariees
	headx, heady,		//head of the snake
	foodX, foodY,		//food of the snake
	snakeLen = 3,		//length of the snake initially 3
	score;

int bodyX[50], bodyY[50];		//for keeping the position of the body of the snake

bool gameOver = false;		//if true than gameover
bool foodEaten = true;		//if true new food will be generated

enum direction {UP, DOWN, LEFT, RIGHT, STOP};
direction dir = STOP;

void positionCalc()
{
	bodyX[0] = headx;
	bodyY[0] = heady;


	if (dir != STOP)
	{
		//updating the index value in the array with the privious one
		for (int i = (snakeLen - 1); i >= 1 ; --i)
		{
			bodyX[i] = bodyX[i - 1];
			bodyY[i] = bodyY[i - 1];
		}
	}

	//Changing the value of the cordinates for the movement of the snake
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

	//random pposition of food, for the snake
	if (foodEaten)
	{
		/* code */
		foodX = (rand() % (xMax - 2)) + 1;
		foodY = (rand() % (yMax - 2)) + 1;
		foodEaten = false;
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



void display()
{
	system("CLS");
	//loop in Y direction
	for (int i = 1; i <= yMax; ++i)
	{
		//loop in X direction
		for (int j = 1; j <= xMax; ++j)
		{
			//for printiing out the wall at the boundries
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
			case 'a' : dir = LEFT;
					break;
			case 'w' : dir = UP;
					break;
			case 'd' : dir = RIGHT;
					break;
			case 's' : dir = DOWN;
					break;
			case 'x' : gameOver = true;
					break;
		}
	}
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
		Sleep(100);
	}


	return 0;
}
