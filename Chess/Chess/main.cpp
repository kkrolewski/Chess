#include <iostream>
#include <thread>
#include <chrono>
#include "Game.h"

using namespace std;

int main() {
	thread t1([]() {this_thread::sleep_for(chrono::seconds(2)); cout << "Witaj w menu gry w Szachy" << endl; });
	thread t2([]() {this_thread::sleep_for(chrono::seconds(4)); cout << "Podaj imiona graczy:" << endl; });
	t1.join();
	t2.join();
	string bialy, czarny;
	cout << "Gracz bialy:" << endl;
	cin >> bialy; 
	cout << "Gracz czarny:" << endl;
	cin >>  czarny;
	Game newGame;
	int color= newGame.play();
	if (color == 0) {
		cout << czarny << " wygral!!! Gratulacje" << endl;
	}
	else {
		cout << bialy << " wygral!!! Gratulacje" << endl;
	}
	return 0;
}