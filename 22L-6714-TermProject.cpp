#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <windows.h>
#include <time.h>
#include <string>
#include <fstream>
using namespace std;

void mainmenu(int grid[][9]);
void print(int grid[][9]);
void newgame(int grid[][9]);
void create(int grid[][9], int count);
void loadgame();
void play(int arr[][9]);
void generate(int grid[][9]);
void delgame();
bool check(int grid[][9], int row, int col, int num);

int main()
{
	int grid[9][9] = { 
		{ 5 , 3 , 4 , 6 , 7 , 8 , 9 , 1 , 2 } ,
		{ 6 , 7 , 2 , 1 , 9 , 5 , 3 , 4 , 8 } ,
		{ 1 , 9 , 8 , 3 , 4 , 2 , 5 , 6 , 7 } ,
		{ 8 , 5 , 9 , 7 , 6 , 1 , 4 , 2 , 3 } ,
		{ 4 , 2 , 6 , 8 , 9 , 3 , 7 , 5 , 1 } ,
		{ 7 , 1 , 3 , 9 , 2 , 4 , 8 , 5 , 6 } ,
		{ 9 , 6 , 1 , 5 , 3 , 7 , 2 , 8 , 4 } ,
		{ 2 , 8 , 7 , 4 , 1 , 9 , 6 , 3 , 5 } ,
		{ 3 , 4 , 5 , 2 , 8 , 6 , 1 , 7 , 9 } ,
	};
	mainmenu(grid);
    return 0;
}

void mainmenu(int grid[][9])
{
	int choice, newcount = 0;
	cout << "\thi, welcome to muhammad hamza's sudoku game!" << endl;
	do {
		cout << "\n\tplease select an option from the menu below:\n" << endl;
		cout << "\t ------------------------\n";
		cout << "\t |      main menu       |\n";
		cout << "\t ------------------------\n";
		cout << "\t | 1.load game          |\n";
		cout << "\t | 2.new game           |\n";
		cout << "\t | 3.delete game        |\n";
		cout << "\t | 0.quit               |\n";
		cout << "\t ------------------------\n";
		cout << "\tenter choice: ";
		cin >> choice;
		if (choice == 1)
		{
			loadgame();
		}
		else if (choice == 2)
		{
			newcount++;
			if (newcount < 4)
			{
				newgame(grid);
			}
			else { cout << "\nyou can only play 3 games!\n"; }
		}
		else if (choice == 3)
		{
			delgame();
		}
		else if (choice == 0)
		{
			cout << "\nthank you, for playing our game!\n" << endl;
		}
		else {
			system("cls");
			cout << "\ninvalid choice, enter again!" << endl;
		}
	} while (choice != 0);
}

void print(int grid[][9])
{
	cout << "\n";
	cout << "\t  -------------------------\n";
	cout << "\t |         sudoku          |\n";
	cout << "\t  -------------------------\n";
	cout << "\t    1 2 3   4 5 6   7 8 9\n";
	for (int i = 0; i < 9; i++)
	{
		if (i == 0 || i == 3 || i == 6)
		{
			cout << "\t  -------------------------\n";
		}
		if (i == 0)cout << "\t1 ";
		if (i == 1)cout << "\t2 ";
		if (i == 2)cout << "\t3 ";
		if (i == 3)cout << "\t4 ";
		if (i == 4)cout << "\t5 ";
		if (i == 5)cout << "\t6 ";
		if (i == 6)cout << "\t7 ";
		if (i == 7)cout << "\t8 ";
		if (i == 8)cout << "\t9 ";
		cout << "| ";
		for (int j = 0; j < 9; j++)
		{
			if (j == 3 || j == 6)
			{
				cout << "| ";
			}
			if (grid[i][j] != 0)
			{
				cout << grid[i][j] << " ";
			}
			else
			{
				cout << "_ ";
			}
		}
		cout << "|\n";
	}
	cout << "\t  -------------------------\n";
}

void newgame(int grid[][9]) 
{
	int choice;
	system("cls");
	do {
		cout << "\n\tplease select an option from the menu below:\n" << endl;
		cout << "\t ------------------------\n";
		cout << "\t |      create new       |\n";
		cout << "\t ------------------------\n";
		cout << "\t | 1.game-1              |\n";
		cout << "\t | 2.game-2              |\n";
		cout << "\t | 3.game-3              |\n";
		cout << "\t | 0.back to mainmenu    |\n";
		cout << "\t ------------------------\n";
		cout << "\tenter choice: ";
		cin >> choice;
		if (choice == 1)
		{
			create(grid, choice);
		}
		else if(choice == 2)
		{
			create(grid, choice);
		}
		else if (choice == 3)
		{
			create(grid, choice);
		}
		else if (choice == 0)
		{
			system("cls");
			cout << "\nback to main menu\n" << endl;
		}
		else {
			system("cls");
			cout << "\ninvalid choice, enter again!" << endl;
		}
	} while (choice != 0);
}

void create(int grid[][9], int choice)
{
	ofstream fout;
	ifstream fin;
	int arr[9][9];
	switch (choice)
	{
		case 1:
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					arr[i][j] = grid[i][j];
				}
			}
			generate(arr);
			fout.open("game1.txt", ios::_Noreplace);
			if (!fout) {
				cout << "game1 already exists!\n";
				system("pause");
			}
			else {
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						fout << arr[i][j];
						fout << " ";
					}
				}
				cout << "game1 created successfully!\n";
				system("pause");
			}
			fout.close();
			system("cls");
			break;
		case 2:
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					arr[i][j] = grid[j][i];
				}
			}
			generate(arr);
			fout.open("game2.txt", ios::_Noreplace);
			if (!fout) {
				cout << "game2 already exists!\n";
				system("pause");
			}
			else {
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						fout << arr[i][j];
						fout << " ";
					}
				}
				cout << "game2 created successfully!\n";
				system("pause");
			}
			fout.close();
			system("cls");
			break;
		case 3:
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					arr[i][j] = grid[i][j];
				}
			}
			int a = 0, b = 3 ;
			for (int n = 0; n < 3; n++)
			{
				for (int i = 0; i < 9; i++)
				{
					int temp = arr[a][i];
					arr[a][i] = arr[b][i];
					arr[b][i] = temp;

				}
				a++; b++;

			}
			generate(arr);
			fout.open("game3.txt", ios::_Noreplace);
			if (!fout) {
				cout << "game3 already exists!\n";
				system("pause");
			}
			else {
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						fout << arr[i][j];
						fout << " ";
					}
				}
				cout << "game3 created successfully!\n";
				system("pause");
			}
			fout.close();
			system("cls");
	}
}

void generate(int arr[][9])
{
	srand(time(NULL));
	int row = 0, col = 0;
	int r[81] = { 0 }, c[81] = { 0 };
	bool already_selected = false;
	for (int i = 0; i < 36; i++)
	{
		do
		{
			already_selected = false;
			row = floor(rand() % 9);
			col = floor(rand() % 9);
			for (int j = 0; j < i; j++)
			{
				if (r[j] == row && c[j] == col)
				{
					already_selected = true;
				}
			}
		} while (already_selected);
		r[i] = row; c[i] = col;
		int temp = arr[row][col];
		arr[row][col] = 0;
	}
}

bool check(int grid[][9], int row, int col, int num)
{
	row--; col--;
	for (int i = 0; i < 9; i++)
	{
		if (grid[i][col] == num) return false;
	}
	for (int j = 0; j < 9; j++)
	{
		if (grid[row][j] == num) return false;
	}
	int strow = floor(row / 3) * 3, stcol = floor(col / 3) * 3;
	for (int i = strow; i < strow + 3; i++)
	{
		for (int j = stcol; j < stcol; j++)
		{
			if (grid[i][j] == num) return false;
		}
	}
	return true;
}

void play(int arr[][9])
{
	//cout << "let's play!\n";
	int r, c, num = 0, x=1;
	bool chk = true, sts = true, flag = true;
	while (chk == true)
	{
		flag = true;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if ((arr)[i][j] == 0)
				{
					flag = false;
				}
			}
		}
		if (flag == true)
		{
			cout << "\ncongratulations! you have completed the puzzle!\n";
			system("pause");
			break;
		}

		print(arr);
		do {
			cout << "enter row number: ";
			cin >> r;
			if (r < 1 || r>9) {
				cout << "invalid number!\n";
			}
		} while (r < 1 || r>9);
		do
		{
			cout << "enter column number: ";
			cin >> c;
			if (c < 1 || c>9) {
				cout << "invalid number!\n";
			}
		} while (c < 1 || c>9);
		sts = true;
		if (arr[r-1][c-1] == 0)
		{
			while (sts == true)
			{
				cout << "enter the number for index (" << r << "," << c << "): ";
				cin >> num;
				if (num < 1 || num > 9)
				{
					cout << "enter a valid number (1 to 9)!\n";
					continue;
				}
				else
				{
					if (check(arr, r, c, num))
					{
						arr[r - 1][c - 1] = num;
						sts = false; 
						system("cls");
						cout << "number entered successfully!\n";
						print(arr);
						cout << "enter 0 to save and exit, 1 to continue playing: ";
						cin >> x;
						if (x == 0) {
							chk = false;
						}
						system("cls");
					}
					else
					{
						system("cls");
						cout << "repetition of a number in same row and column is not allowed!\nplease try again!\n";
						print(arr);
						continue;
					}
				}
			}
		}
		else
		{
			system("cls");
			cout << "enter a valid (empty) row and column number!";
			continue;
		}

	}
	
}

void loadgame()
{
	ofstream fout;
	ifstream fin;
	int choice;
	int arr[9][9]={0};

	do {
		system("cls");
		cout << "\n\tplease select an option from the menu below:\n" << endl;
		cout << "\t ------------------------\n";
		cout << "\t |       load menu       |\n";
		cout << "\t ------------------------\n";
		cout << "\t | 1.game-1              |\n";
		cout << "\t | 2.game-2              |\n";
		cout << "\t | 3.game-3              |\n";
		cout << "\t | 0.back to mainmenu    |\n";
		cout << "\t ------------------------\n";
		cout << "\tenter choice: ";
		cin >> choice;
		if (choice == 1)
		{
			fin.open("game1.txt", ios::in);
			if (!fin) {
				cout << "\ngame1 does not exist!\n";
				system("pause");
			}
			else {
					for (int i = 0; i < 9; i++)
					{
						for (int j = 0; j < 9; j++)
						{
							int num;
							fin >> num;
							arr[i][j] = num;
						}
					}
					system("cls");
					play(arr);
					fout.open("game1.txt");
					for (int i = 0; i < 9; i++)
					{
						for (int j = 0; j < 9; j++)
						{
							fout << arr[i][j];
							fout << " ";
						}
					}
					fout.close();
			}
			fin.close();
		}
		else if (choice == 2)
		{
			fin.open("game2.txt", ios::in);
			if (!fin) {
				cout << "game2 does not exist!\n";
				system("pause");
			}
			else {
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						int num;
						fin >> num;
						arr[i][j] = num;
					}
				}
				system("cls");
				play(arr);
				fout.open("game2.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						fout << arr[i][j];
						fout << " ";
					}
				}
				fout.close();
			}
			fin.close();
		}
		else if (choice == 3)
		{
			fin.open("game3.txt", ios::in);
			if (!fin) {
				cout << "game3 does not exist!\n";
				system("pause");

			}
			else {
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						int num;
						fin >> num;
						arr[i][j] = num;
					}
				}
				system("cls");
				play(arr);
				fout.open("game3.txt");
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						fout << arr[i][j];
						fout << " ";
					}
				}
				fout.close();
			}
			fin.close();
		}
		else if (choice == 0)
		{
			system("cls");
			cout << "\nback to main menu\n" << endl;
		}
		else {
			system("cls");
			cout << "\ninvalid choice, enter again!" << endl;
		}
	} while (choice != 0);
}

void delgame()
{
	ofstream fout;
	ifstream fin;
	int choice, x;

	do {
		system("cls");
		cout << "\n\tplease select an option from the menu below:\n" << endl;
		cout << "\t ------------------------\n";
		cout << "\t |      delete menu      |\n";
		cout << "\t ------------------------\n";
		cout << "\t | 1.game-1              |\n";
		cout << "\t | 2.game-2              |\n";
		cout << "\t | 3.game-3              |\n";
		cout << "\t | 0.back to mainmenu    |\n";
		cout << "\t ------------------------\n";
		cout << "\tenter choice: ";
		cin >> choice;
		if (choice == 1)
		{
			x=remove("game1.txt");
			if (x==0)
			{
				cout << "game1 deleted successsfully!\n";
			}
			else
			{
				cout << "game1 does not exist!\n";
			}
			system("pause");
		}
		else if (choice == 2)
		{
			x=remove("game2.txt");
			if (x==0)
			{
				cout << "game2 deleted successsfully!\n";
			}
			else
			{
				cout << "game2 does not exist!\n";
			}
			system("pause");
		}
		else if (choice == 3)
		{
			x=remove("game3.txt");
			if (x==0)
			{
				cout << "game3 deleted successsfully!\n";
			}
			else
			{
				cout << "game3 does not exist!\n";
			}
			system("pause");
		}
		else if (choice == 0)
		{
			system("cls");
			cout << "\nback to main menu\n" << endl;
		}
		else {
			system("cls");
			cout << "\ninvalid choice, enter again!" << endl;
		}
	} while (choice != 0);
}