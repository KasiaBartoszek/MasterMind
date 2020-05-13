#pragma once
#include <string>

class RankingEntry
{

	std::string name;
	int time, score;

public:
	RankingEntry();
	RankingEntry(std::string name, int time, int score);
	~RankingEntry();
	 bool operator <(const RankingEntry &re1) const;
	std::string getName()
	{
		return name;
	}
	int getTime()
	{
		return time;
	}
	int getScore()
	{
		return score;
	}
	void setTime(int time) 
	{
		this->time = time;
	}
	void setName(std::string name)
	{
		this->name = name;
	}
	void setScore(int score)
	{
		this->score = score;
	}
};

