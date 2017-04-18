///////////////////////////////////////////////////////////////
// Copyright(c) Kingsoft
// 
// FileName : Game.h
// Creator  : XINMINGHUI
// Date     : 2017-4-17 16:08:25
// Comment  : represent one game with two players and update Elo
//
///////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include "Player.h"
#include "Result.h"
#ifndef __GAME_H_
#define __GAME_H_
namespace ELO
{
	using namespace std;

	class Game
	{
	public:
		Game(double dHardness, Player &playerA, Player &playerB) : m_cdHARDNESS(dHardness), m_playerA(playerA), m_playerB(playerB) {}
		Player &GetPlayerA(void) const
		{
			return m_playerA;
		}
		Player &GetPlayerB(void) const 
		{
			return m_playerB;
		}
		void SetPlayerA(Player &playerA)		//transmit reference and we needn't overload Player operator= function
		{
			m_playerA = playerA;
		}
		void SetPlayerB(Player &playerB)
		{
			m_playerB = playerB;
		}

		bool Equals(Game &game)
		{
			return (m_playerA == game.GetPlayerA()) && (m_playerB == game.GetPlayerB()) && (m_cdHARDNESS == game.m_cdHARDNESS);
		}
		bool operator==(Game &game)
		{
			return Equals(game);
		}
		bool operator!=(Game &game)
		{
			return !Equals(game);
		}

		double PlayerAWinningProbability(void)
		{
			return 1.0 / (1.0 + pow(10, (m_playerB.GetElo() - m_playerA.GetElo()) / 400.0));
		}

		void UpdatePlayersElo(const Result &result)
		{
			m_playerA.SetElo(m_playerA.GetElo() + m_cdHARDNESS * (result.GetOutcomeAsDouble() - PlayerAWinningProbability()));
			m_playerB.SetElo(m_playerB.GetElo() + m_cdHARDNESS * (1 - result.GetOutcomeAsDouble() - (1 - PlayerAWinningProbability())));

		}
	public:
		const double m_cdHARDNESS;
	private:
		Player &m_playerA;
		Player &m_playerB;

	};

	ostream & operator<<(ostream &out, Game &game)
	{
		out << game.GetPlayerA() << game.GetPlayerB() << endl;
		return out;
	}
};
#endif // !__GAME_H_
