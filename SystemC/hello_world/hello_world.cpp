#include <iostream>
#include <systemc.h>

using namespace std;

SC_MODULE (hello_world) {
	SC_CTOR (hello_world) {
		// Empty constructor
	}

	void print_hello(void) {
		cout << "Hello World" << endl;
	}
};

int sc_main(int argc, char** argv) {
	hello_world hello("HELLO");
	hello.print_hello();
	return(0);
}
