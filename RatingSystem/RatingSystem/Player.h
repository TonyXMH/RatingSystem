///////////////////////////////////////////////////////////////
// Copyright(c) Kingsoft
// 
// FileName : Player.h
// Creator  : XINMINGHUI
// Date     : 2017-4-17 15:33:46
// Comment  : initialize player information. 
//	add set,get,equal,==, <<, functions
///////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

#ifndef __PLAYER_H_
#define __PLAYER_H_
namespace ELO
{
	using namespace std;
	const string	CSZ_DEFAULT_NAME	= "DEFAULT";
	const double	CD_DEFAULT_EOF		= 10000;

	class Player
	{
	public:
		Player(string cszName = CSZ_DEFAULT_NAME, double dElo = CD_DEFAULT_EOF) : m_szName(cszName), m_dElo(dElo) {}
		const string & GetName(void) const
		{
			return m_szName;
		}
		void SetName(const string &szName)
		{
			m_szName = szName;
		}

		const double & GetElo(void) const
		{
			return m_dElo;
		}

		void SetElo(const double &dElo)
		{
			m_dElo = dElo;
		}

		bool Equals(Player &player) const
		{
			return (m_szName == player.GetName()) && (m_dElo == player.GetElo());
		}

		bool operator==(Player &player) const
		{
			return Equals(player);
		}

		bool operator!=(Player &player) const
		{
			return !Equals(player);
		}


	private:
		string m_szName;
		double m_dElo;
	};

	ostream & operator<<(ostream &out, Player &player)
	{
		out << player.GetName() << ' ' << player.GetElo() << endl;
		return out;
	}

};
#endif