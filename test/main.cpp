#include "refactoring-legacy-cpp-code/complex-control-flow/include/example.h"

void runComplexControlFlowExample ()
{
	using namespace ComplexControlFlow;
	Owner (Type::A).process (5);
	Owner (Type::B).process (5);
	Owner (Type::C).process (5);
}

int main (int argc, const char* argv[])
{
	runComplexControlFlowExample ();
}