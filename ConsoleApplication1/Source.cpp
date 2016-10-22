#include <boost/python.hpp>  
using namespace boost::python;

int main()
{
	auto code = R"str(
import math, sys
print("Python version " + sys.version)
print(math.gcd(120, 80))
	)str";
	try {
		Py_Initialize();
		object main_module = import("__main__");
		object globals(main_module.attr("__dict__"));
		object result = exec(code, globals, globals);
	}
	catch (error_already_set) {
		PyErr_Print();
	}
}