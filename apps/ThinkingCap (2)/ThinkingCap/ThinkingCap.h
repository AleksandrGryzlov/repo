#pragma once
#include <string>
class ThinkingCap
{
private:
	string redSentence;
	string blueSentence;
public:
	void insertToRedSlot(string newSentence) {
		redSentence = newSentence;
	}
};

