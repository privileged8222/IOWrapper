#include "IOWrapper.h"

#include <vector>


int main( ) {

	int m = IO::In::Get<int>( ); // Reads line with given template datatype

	std::vector<std::string> names{ };

	for ( int i = 0; i < m; i++ ) {
		std::string name;
		std::cin >> name;
		names.push_back( name );
	}

	for ( std::string name : names ) {
		IO::Out::Println( name ); // Prints with new line
	}

	IO::In::Sync( ); // Call this after std::cin

	std::string y = IO::In::Get<std::string>( "Was that interesting?: " );
	IO::Out::Print( "You said: " + y ); // Prints without new line
}