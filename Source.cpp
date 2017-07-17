#include <iostream>
#include <windows.h>
using namespace std;
//Global variable as needed to be accessed by multiple methods.
const int width = 50, height = 24;
char screen[width][height];



int startup() {
	char snowflake = '*', floor = '^', emptySpace = '0';

	//Startup initialzation to set the array to a base image.
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			screen[j][i] = emptySpace;
		}
	}
	for (int i = 0; i < width; i++) {
		screen[i][height - 1] = floor;
	}

	return 0;
}

int printScreen() {
	//Print screen.
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << screen[j][i];
		}
		cout << endl;
	}
	return 0;
}

int main() {
	char snowflake = '*', floor = '^', emptySpace = '0', setsnow = '+', tempSnowflake = '%';
	
	startup();
	

	//Runs this while loop for as long as the program is running.
	int snowfallIterationCounter = 0;
	int delayTime = 300;
	while (true) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				//Snowflake falling logic.
				if (screen[j][i] == snowflake) {
					if (screen[j][i + 1] == emptySpace) {
						//Sets as temp snowflake to allow for all snowflakes to move at the same time.
						screen[j][i + 1] = tempSnowflake;
						screen[j][i] = emptySpace;
					}
					else if (screen[j][i + 1] == floor) {
						//Becomes set snow meaning it can no longer move.
						screen[j][i] = setsnow;
					}
					else if (screen[j][i + 1] == setsnow) {
						//Snow falls to the side of set snow.
						//Falls right by default.
						if (screen[j + 1][i + 1] == emptySpace && screen[j + 1][i + 2] == floor) {
							screen[j + 1][i + 1] = snowflake;
							screen[j][i] = emptySpace;
						}
						//Falls left if right is already filled with something.
						else if (screen[j - 1][i + 1] == emptySpace && screen[j - 1][i + 2] == floor) {
							screen[j - 1][i + 1] = snowflake;
							screen[j][i] = emptySpace;
						}
						//If it cannot fall to either side it sets on top of the set snow.
						else {
							screen[j][i] = setsnow;
						}
					}
				}
			}
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (screen[j][i] == tempSnowflake) {
					//Sets tempsnowflakes to actual snowflakes for display.
					screen[j][i] = snowflake;
				}
			}
		}

		
		printScreen();
		snowfallIterationCounter++;

		if (snowfallIterationCounter > 2) {
			int newSnowflakePos;
			newSnowflakePos = rand() % width;
			screen[newSnowflakePos][0] = snowflake;
			snowfallIterationCounter = 0;
		}


		Sleep(delayTime);
	}
	return 0;
}