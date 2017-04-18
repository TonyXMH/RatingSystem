///////////////////////////////////////////////////////////////
// Copyright(c) Kingsoft
// 
// FileName : main.h
// Creator  : XINMINGHUI
// Date     : 2017-4-17 17:18:03
// Comment  : a very simple example for two players
//
///////////////////////////////////////////////////////////////
#include<iostream>
#include "ELO.h"
using namespace std;
int main()
{
	using namespace ELO;
	Player playerA("Tony", 2023);
	Player playerB("Tom", 2012);
	cout << (playerA == playerB) << endl;
	Game game(10.0, playerA, playerB);
	Result result(Result::WIN);
	cout << result << endl
		 << game << endl;
	game.UpdatePlayersElo(result);

	cout << playerA << endl
		 << playerB << endl;
	cin.get();
	return 0;
}