#include <mutex>

#include <stdio.h>

#define synchronized(x) if ( synchronized_helper __helper{x} )

class synchronized_helper {

	std::mutex & obj;

public:

	synchronized_helper(std::mutex & _obj) : obj( _obj ) {
		printf( "synchronized_helper lock\n" );
		obj.lock();
	}

	~synchronized_helper() {
		printf( "synchronized_helper unlock\n" );
		obj.unlock();
	}

	operator bool() { return true; }

private:

	synchronized_helper(const synchronized_helper & other);
	synchronized_helper & operator =(const synchronized_helper & other);

};

int main() {
	std::mutex m;
	synchronized ( m ) {
		printf( "in synchronized\n" );
	}
	return 0;
}

