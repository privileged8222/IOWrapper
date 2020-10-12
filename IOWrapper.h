#pragma once

#ifndef IOWrapper_h
#define IOWrapper_h

#include <string>
#include <iostream>
#include <sstream>

namespace IO {
	
	namespace Out {
		template <class T>
		__forceinline void Println( T s ) {
			std::cout << s << std::endl;
		}
		template <class T>
		__forceinline void Print( T s ) {
			std::cout << s;
		}
	};

	namespace In {
		template <class T>
		__forceinline T Get( const char* );
		template <class T>
		__forceinline T Get( );

		template<>
		__forceinline std::string Get<std::string>( const char* msg ) {
			Out::Print( msg );
			std::string s;
			std::getline( std::cin, s );
			return s;
		}

		template<>
		__forceinline std::string Get<std::string>( ) {
			std::string s;
			std::getline( std::cin, s );
			return s;
		}

		template <class T>
		__forceinline T Get( const char* msg ) {
			Out::Print( msg );
			std::stringstream ss( Get<std::string>( ) );
			T v;
			ss >> v;
			return v;
		}

		template <class T>
		__forceinline T Get( ) {
			std::stringstream ss( Get<std::string>( ) );
			T v;
			ss >> v;
			return v;
		}

		__forceinline void Sync( ) {
			std::cin.ignore( );
		}
	};
}

#endif