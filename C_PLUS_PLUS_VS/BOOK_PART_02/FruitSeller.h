#pragma once
class FruitSeller
{
private:
	int myMoney;
	int numOfFruit;
	int APPLE_PRICE;
public:
	bool InitSeller(int money, int numFruit, int price);
	int SellFruit(int money, int numFruit);
	int GetFruitePrice() const;
	void ShowInfo();
};