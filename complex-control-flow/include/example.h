#include <iostream>
namespace ComplexControlFlow
{

enum class State : int
{
	insertCoins,
	validateCoins,
	rejectCoins,
	releaseCandies,
};

enum class Type : int
{
	A,
	B,
	C
};

class BaseImplementation
{
public:
	BaseImplementation (Type type) 
		: type (type)
	{}

	int process (int value) const
	{
		value *= 10;
		return calculateValue (value);
	}

protected:
	int calculateValue (int value) const
	{
		switch (type)
		{
		case Type::A:
			return value + 1;
			break;
		case Type::B:
			return value + 2;
			break;
		case Type::C:
			return value + 3;
			break;
		default:
			return -1;
		}
	}
private:
	const Type type;
};

class Owner
{
public:
	Owner (Type type)
		: impl (BaseImplementation (type))
	{}

	void process (int value) const
	{
		using namespace std;
		cout << "input: " << value << " output: " << impl.process (value) << endl;
	}

private:
	const BaseImplementation impl;
};


}


