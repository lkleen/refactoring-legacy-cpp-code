#include <iostream>
namespace ComplexControlFlow
{

enum class Type : int
{
	A,
	B,
	C
};

class BaseImplementation
{
public:

	virtual ~BaseImplementation () = default;

	int process (int value) const
	{
		value *= 10;
		return calculateValue (value);
	}

protected:
	virtual int calculateValue (int value) const = 0;
};

class TypeAImplementation : public BaseImplementation
{
protected:
	int calculateValue (int value) const final override
	{
		return value + 1;
	}
};

class TypeBImplementation : public BaseImplementation
{
protected:
	int calculateValue (int value) const final override
	{
		return value + 2;
	}
};

class TypeCImplementation : public BaseImplementation
{
protected:
	int calculateValue (int value) const final override
	{
		return value + 3;
	}
};

class Owner
{
public:
	Owner (Type type)
		: impl (createImplementationFor (type))
	{}

	~Owner ()
	{
		delete impl;
	}

	void process (int value) const
	{
		using namespace std;
		cout << "input: " << value << " output: " << impl->process (value) << endl;
	}

private:

	BaseImplementation* createImplementationFor (Type type)
	{
		switch (type)
		{
		case ComplexControlFlow::Type::A:
			return new TypeAImplementation;
		case ComplexControlFlow::Type::B:
			return new TypeBImplementation;
		case ComplexControlFlow::Type::C:
			return new TypeCImplementation;
		default:
			return nullptr;
		}
	}

	const BaseImplementation* impl;
	
};


}


