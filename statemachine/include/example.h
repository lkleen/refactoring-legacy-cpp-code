namespace ComplexControlFlow
{

enum class State : int
{
	insertCoins,
	validateCoins,
	rejectCoins,
	releaseCandies,
};

struct Coins
{
	bool counterfeit;
};

struct Context
{
	Coins coins;
	bool coinsInserted;
	bool coinsValidated;
	bool coinsRejected;
	bool candiesReleased;
};

class Example
{
public:
	void process (Context& state) const
	{
		if (state.coinsInserted)
		{
			if (state.coins.counterfeit)
				
		}

	}
private:

};

}


