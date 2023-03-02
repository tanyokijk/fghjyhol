#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <cstdio>
#include <stdlib.h> 
#include <ctime>
#include <stdio.h>
#include <conio.h>
using namespace std;
#include "дяпік.cpp"

class Game {
private:
	vector <string> wordList;
	string word;
	//string відгадане;
	//vector<string> неправильнібукви;
	//string буква;
	//int спроби = 6;
	string guessed;
public:
	Game()
	{
		ifstream file("слова.txt");
		string слово;
		while (!file.eof())
		{
			file >> слово;
			wordList.push_back(слово);
		}
	}

	void game(int рівень)
	{
		int спроби = 6;
		string вгадуванеСлово;
		int ранд;
		if (рівень == 1)
			word = wordList[rand() % 33];
		if (рівень == 2)
			word = wordList[rand() % 33 + 33];
		if (рівень == 3)
			word = wordList[rand() % 33 + 66];

		int wordLength = word.length();
		cout << word;
		string dispWord(wordLength, '_');

		int found = 0;
		char guess = ' ';
		int tries = 6;
		int flagFound = 0;

		while (tries >= 0) {
			system("cls");
			//cout<<"Загадане слово: "<<endl<<endl;

			for (int i = 0; i < wordLength; i++)
				cout << " " << dispWord[i] << " ";
			cout << endl << endl << endl;

			cout << "Спроби: " << tries << " / " << 6 << endl;
			cout << "Літери: " << guessed<<endl;
			cout<<дяпік[6-спроби];
			//DrawMan(спроби);

			if (found == wordLength) {
				cout << endl;
				cout << "*****************" << endl;
				cout << "*   Ви виграли  *" << endl;
				cout << "*****************" << endl;
				break;
			}

			if (tries == 0) break;

			cout << "Виберіть букву:";
			guess = _getche();
			//cin>>буква;
			guessed = guessed + " " + guess;

			if (dispWord.find(guess) != string::npos) tries++;

			flagFound = 0;
			for (int i = 0; i < wordLength; i++) {
				if (word[i] == guess && dispWord[i] == '_') {
					dispWord[i] = guess;
					found++;
					flagFound = 1;
				}
			}

			if (!flagFound)
				tries--;
		}
		if (found != wordLength) {
			cout << endl;
			cout << "******************" << endl;
			cout << "*   Ви програли  *" << endl;
			cout << "******************" << endl;
			cout << "Загадане слово: " << word << endl;
		}
	}
}tr;

int main() {
	srand(time(0));
	bool game = true;
	Game tr;
	while (game)
	{

		int спроби = 6;
		string буква;
		cout << "               Ласкаво просимо в гру <<Шибениця>>!\n" << endl;
		cout << "На відгадування слова вам даєтся 6 спроб!\n";
		cout << "Якщо ви не відгадали слово ви завжди можете почати з початку!\n";
		cout << "Є 3 рівні складності:\n";
		cout << "1) легкий\n";
		cout << "2) середній\n";
		cout << "3) складний\n";
		cout << "0) вихід\n";
		cout << "Зробіть свій вибір:\n";
		int вибір;
		try
		{
			cin >> вибір;
			if (вибір == 1)
			{
				tr.game(1);
			}
			else if (вибір == 2)
			{
				tr.game(2);
			}
			else if (вибір == 3)
			{
				tr.game(3);
			}
			else if (вибір == 0)
			{
				break;
			}
			else
			{
				throw 0;
			}
		}

		catch (int x)
		{
			if (x == 0)
				cout << "Ви ввели неправильний номер!" << endl;
		}


	}


}