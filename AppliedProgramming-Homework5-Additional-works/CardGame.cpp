#include "CardGame.h"

int CardGame::GetCard(int th)
{
	return playerCard[th];
}
int CardGame::GetWinCount()
{
	return winCount;
}
int CardGame::GetLoseCount()
{
	return loseCount;
}
int CardGame::GetDrawCount()
{
	return drawCount;
}
void CardGame::SetWinCount(int count)
{
	winCount += count;
}
void CardGame::SetLoseCount(int count)
{
	loseCount += count;
}
void CardGame::SetDrawCount(int count)
{
	drawCount += count;
}

Card CardCharacterconversion(int cardValue)
{
	if (cardValue==1)
	{
		return A;
	}
	else if (cardValue==11)
	{
		return J;
	}
	
	else if (cardValue==12)
	{
		return Q;
	}
	else if (cardValue==13)
	{
		return K;
	}
	else
	{
		return static_cast<Card>(cardValue);
	}
}

void CardGame::SetCard(int th)
{
	playerCard[th] = rand() % 13 + 1;
}

void CardGame::ShowCard(int th)
{
	Card card = CardCharacterconversion(playerCard[th]);
	cout << "card ";
	switch (card)
	{
	case A:
		cout << "A" << endl;
		break;
	case J:
		cout << "J" << endl;
		break;
	case Q:
		cout << "Q" << endl;
		break;
	case K:
		cout << "K" << endl;
		break;
	default:
		cout << playerCard[th] << endl;
		break;
	}
}

void CardGame::SetDealer()
{
	SetCard(0);
	SetCard(1);
}
int CardGame::TotalCardValue()
{
	totalCardValue = 0;
    int aceCount = 0;

    for (int i = 0; i < 10 && playerCard[i] != 0; i++)
    {
        if (playerCard[i] == A)
        {
            totalCardValue += 11;
            aceCount++;
        }
        else if (playerCard[i] >= J)
        {
            totalCardValue += 10;
        }
        else
        {
            totalCardValue += playerCard[i];
        }
    }

    while (totalCardValue > 21 && aceCount > 0)
    {
        totalCardValue -= 10;
        aceCount--;
    }

    return totalCardValue;
}

void CardGame::Dealer17()
{
	while (TotalCardValue() < 17)
	{
		for (int i = 2; i < 10; i++)
		{
			if (playerCard[i] == 0)
			{
				SetCard(i);
				ShowCard(i);
				cout << "dealerTotal: " << TotalCardValue() << endl;
				break;
			}
		}
	}
}
////////////////////////////////////
void CardGame::GameStart()
{
	cout << "Welcome to the Blackjack Game!" << endl;
	
	SetCard(0);
	SetCard(1);
	cout << "Your cards are " << endl;
	ShowCard(0);
	ShowCard(1);
	cout << "Total: " << TotalCardValue() << endl;
	cout << "==============================" << endl;
	for (int choice = 0, i = 2; choice != 2;i++)
	{
		cout << "hit or stand?" << endl << "1. hit" << endl << "2. stand" << endl;
		cout << "input comand ";
		cin >> choice;


		if (choice == 1)
		{
			if (i >= 10)
			{
				cout << "No more cards available." << endl;
				break;
			}

			SetCard(i);
			ShowCard(i);
			cout << "Total: " << TotalCardValue() << endl;

			if (TotalCardValue() > 21)
			{
				cout << "Bust! You lose." << endl;
				loseCount++;
				break;
			}
		}

	}
	
}

void judge(int playerTotal, int dealerTotal, CardGame& player, CardGame& dealer)
{
	cout << "==============================" << endl;
	if (22 <= playerTotal && 22 <= dealerTotal)
	{
		player.SetDrawCount(1);
		cout << "Draw!" << endl;
		return;
	}
	else if(22>=playerTotal&&22<=dealerTotal)
	{
		player.SetWinCount(1);
		cout << "dealer bust! " ;
		cout << "You win!" << endl;
		return;
	}
	else if (22 <= playerTotal && 22 >= dealerTotal)
	{
		player.SetLoseCount(1);
		cout << "player bust! ";
		cout << "You lose!" << endl;
		return;
	}
	else if (playerTotal == dealerTotal)
	{
		player.SetDrawCount(1);
		cout << "Draw!" << endl;
		return;
	}
	else if (playerTotal > dealerTotal)
	{
		player.SetWinCount(1);
		cout << "You win!" << endl;
		return;
	}
	else 
	{
		player.SetLoseCount(1);
		cout << "You lose!" << endl;
	}
}

void gamedirector()
{
	CardGame player;
	CardGame dealer;
	player.GameStart();
	dealer.SetDealer();
	cout << "==============================" << endl;
	cout << "dealers card: " << endl;
	dealer.ShowCard(0);
	dealer.ShowCard(1);
	cout << "The dealer draws until reaching 17." << endl;
	dealer.Dealer17();
	judge(player.TotalCardValue(), dealer.TotalCardValue(), player, dealer);
}