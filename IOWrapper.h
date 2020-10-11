#pragma once

#include <string>
#include <iostream>
#include <sstream>

namespace IO {
	
	namespace Out {
		template <class T>
		static void Println( T s ) {
			std::cout << s << std::endl;
		}
		template <class T>
		static void Print( T s ) {
			std::cout << s;
		}
	};

	namespace In {
		template <class T>
		inline T Get( const char* );
		template <class T>
		inline T Get( );

		template<>
		inline std::string Get<std::string>( const char* msg ) {
			Out::Print( msg );
			std::string s;
			std::getline( std::cin, s );
			return s;
		}

		template<>
		inline std::string Get<std::string>( ) {
			std::string s;
			std::getline( std::cin, s );
			return s;
		}

		template <class T>
		inline T Get( const char* msg ) {
			Out::Print( msg );
			std::stringstream ss( Get<std::string>( ) );
			T v;
			ss >> v;
			return v;
		}

		template <class T>
		inline T Get( ) {
			std::stringstream ss( Get<std::string>( ) );
			T v;
			ss >> v;
			return v;
		}

		inline void Sync( ) {
			std::cin.ignore( );
		}
	};
}