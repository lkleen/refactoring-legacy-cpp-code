# Legacy code issues and refactoring techniques
sources: https://github.com/lkleen/refactoring-legacy-cpp-code
## blackbox implementations and untestable code
### problem description
- paramter-less interfaces
- invisible states
### example
```cpp
class Untestable 
{
public:    
    void myMethod ()
    {
        switch (myMember):
        case 0:
            doThis ();
            myMember++;
            value++;
            break;
        case 1:
            doThat ();
            if (value >= 0)
                value -= 2;
            myMember--;
            break;
        default:
            myMember = 0;
            break;
    }

    void doThis () {/*...*/}

    void doThat () {/*...*/}
private:
    int myMember = 0;
    int value = 4
}
```
### solution pattern
- move private members to parameter objects (struct Parameter / struct Context)
- make methods const, pass mutable parameter objetcs
## complex control pathes
### problem description
- each method call checks conditions to determine what to execute
### example
```cpp
class AllPurposeImplementation
{
public:
	AllPurposeImplementation (Type type) 
		: type (type)
	{}

	int process (int value) const
	{
		value *= 10;
		
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
```
## hidden statemachines
### problem description
- deeply nested control structures defined by states
- higher debugging effort (more code to read)
### example 
