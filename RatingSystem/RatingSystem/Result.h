///////////////////////////////////////////////////////////////
// Copyright(c) Kingsoft
// 
// FileName : Result.h
// Creator  : XINMINGHUI
// Date     : 2017-4-17 16:36:53
// Comment  : show a game result and convert the result to numric value to update the ELO
//
///////////////////////////////////////////////////////////////

#include <iostream>

#ifndef __RESUTL_H_
#define __RESUTL_H_
namespace ELO
{
	using namespace std;

	class Result
	{
	public:
		enum Possbility
		{
			WIN,
			DRAW,
			LOSE
		};
	private:
		Possbility m_outcome;
	public:
		Result(const Possbility &outcome = DRAW) : m_outcome(outcome) {}

		const Possbility & GetOutcome()const
		{
			return m_outcome;
		}
		void SetOutcome(const Possbility &outcome)
		{
			m_outcome = outcome;
		}

		bool Equals(Result &result)const 
		{
			return (m_outcome == result.GetOutcome());
		}
		bool operator==(Result &result)const
		{
			return Equals(result);
		}
		bool operator!=(Result &result)const
		{
			return !Equals(result);
		}
		double GetOutcomeAsDouble() const
		{
			double dRet = 0.0;

			switch (m_outcome)
			{
			case Result::WIN:
				dRet = 1.0;
				break;
			case Result::DRAW:
				dRet = 0.5;
				break;
			case Result::LOSE:
				dRet = 0.0;
				break;
			default:
				break;
			}

			return dRet;
		}

	

	};

	ostream & operator<<(ostream &out, Result &result)
	{
		switch (result.GetOutcome())
		{
		case Result::WIN:
			out << "WIN" << endl;
			break;
		case Result::DRAW:
			out << "DRAW" << endl;
			break;
		case Result::LOSE:
			out << "LOSE" << endl;
			break;
		default:
			break;
		}
		return out;
	}
};



#endif // !__RESULT_H_
