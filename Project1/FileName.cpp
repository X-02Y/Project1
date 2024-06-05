#include<iostream>
#include<random>
using namespace std;
int AVG_HEIGHT;
int BASE_HEIGHT;
int RANDMEASURE;
int main()
{
	cout << "please input the average height of the map" << endl;
	cin >> AVG_HEIGHT;
	cout << "please input the base height of the map" << endl;
	cin >> BASE_HEIGHT;
	cout << "please input the random measure of the map(from 0 to 0.1 recommended)" << endl;
	cin >> RANDMEASURE;

	string input;
	cout << "please enter the command: for random generating, input 'random', else, input 'id'" << endl;
	cin >> input;
	float first_map[10][10];
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0, 1);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			first_map[i][j] = dis(gen);
		}
	}
	if (input == "id") {
		cout<<"please enter 100 numbers between 0 and 1 to simulate the battlefield" << endl;
		float g;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> g;
				first_map[i][j] = g;
			}
		}
	}
	float second_map[100][100];
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			int x = i / 10;
			int y = j / 10;
			float x1 = i / 10.0 - x;
			float y1 = j / 10.0 - y;
			second_map[i][j] = RANDMEASURE*dis(gen) + (1 - x1) * (1 - y1) * first_map[x][y] + x1 * (1 - y1) * first_map[x + 1][y] + (1 - x1) * y1 * first_map[x][y + 1] + x1 * y1 * first_map[x + 1][y + 1];
		}
	}
	float third_map[1000][1000];
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			int x = i / 10;
			int y = j / 10;
			float x1 = i / 10.0 - x;
			float y1 = j / 10.0 - y;
			third_map[i][j] = RANDMEASURE * dis(gen)+ (1 - x1) * (1 - y1) * second_map[x][y] + x1 * (1 - y1) * second_map[x + 1][y] + (1 - x1) * y1 * second_map[x][y + 1] + x1 * y1 * second_map[x + 1][y + 1];
		}
	}
	float final_map[1000][1000];
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			final_map[i][j] = AVG_HEIGHT + (third_map[i][j] - 0.5) * 2 * BASE_HEIGHT;
		}
	}
	cout << "please enter the position of friendly squad (x,y)" << endl;
	int x, y;
	cin >> x >> y;
	//写入文件

	cout << "enter the size of the squad" << endl;
	cin >> x;
	//写入文件

	int t,ti;
	cout << "please enter the type of enemy and position and appear time (t,x,y,ti)" << endl;
	cin >> t >> x >> y>>ti;
	//写入文件

	cout << "Set time limit for the mission" << endl;
	cin >> t;
	//写入文件

	cout << "Set squad settings, set a professional by input 1, else input 0" << endl;
	bool prof;
	cin >> prof;
	//写入文件

	cout << "Set the difficuly by input two float (a,b), a stands for additional hit chance for enemy, b stands for additional hit chance for friendly " << endl;
	cout << "Caution: to preserve the original purpose of this game, input a and b is 1 is recommended for first time playing this game" << endl;
	float a, b;
	cin >> a, b;
	//写入文件



	return 0;
}