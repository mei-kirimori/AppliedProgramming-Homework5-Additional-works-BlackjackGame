#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
enum Card
{
	A=1,
	J = 11,
	Q = 12,
	K = 13
};
class  CardGame
{
public:
	int GetCard(int th);
	int GetWinCount();
	int GetLoseCount();
	int GetDrawCount();
	void SetWinCount(int count);
	void SetLoseCount(int count);
	void SetDrawCount(int count);
	void GameStart();
	void SetDealer();
	void SetCard(int th);
	void ShowCard(int th);
	int TotalCardValue();
	void Dealer17();
private:
	int playerCard[10] = {};
	int winCount;
	int loseCount;
	int drawCount;
	int totalCardValue;
};

 Card CardCharacterconversion(int cardValue);
 void judge(int playerTotal, int dealerTotal, CardGame& player, CardGame& dealer);
 void gamedirector();