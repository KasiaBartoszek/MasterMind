#include "RankingEntry.h"



RankingEntry::RankingEntry()
{
}


RankingEntry::~RankingEntry()
{
}

 bool RankingEntry::operator<(const RankingEntry &re1)const
{
	return this->score > re1.score;
}

RankingEntry::RankingEntry(std::string name, int time, int score) : name(name), time(time), score(score) {}
