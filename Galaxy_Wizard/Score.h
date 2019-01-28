#pragma once
#include <list>
#include "tree.h"
#include "basic_types.h"
#include "board.h"

class Score;
using scores_tree = tree<std::list<Score>>;

class Score
{
protected:
	Board board;
	scores_tree score;
public:
	Score();
	~Score();

};

