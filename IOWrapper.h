#pragma once

#ifndef IOWrapper_h
#define IOWrapper_h

#include <string>
#include <iostream>
#include <sstream>

namespace IO {
	
	namespace Out {
		template <class T>
		__forceinline void __stdcall Println( T s ) {
			std::cout << s << std::endl;
		}
		template <class T>
		__forceinline void __stdcall Print( T s ) {
			std::cout << s;
		}
	};

	namespace In {
		template <class T>
		__forceinline T __stdcall Get( const char* );
		template <class T>
		__forceinline T __stdcall Get( );

		template<>
		__forceinline std::string __stdcall Get<std::string>( const char* msg ) {
			Out::Print( msg );
			std::string s;
			std::getline( std::cin, s );
			return s;
		}

		template<>
		__forceinline std::string __stdcall Get<std::string>( ) {
			std::string s;
			std::getline( std::cin, s );
			return s;
		}

		template <class T>
		__forceinline T __stdcall Get( const char* msg ) {
			Out::Print( msg );
			std::stringstream ss( Get<std::string>( ) );
			T v;
			ss >> v;
			return v;
		}

		template <class T>
		__forceinline T _stdcall Get( ) {
			std::stringstream ss( Get<std::string>( ) );
			T v;
			ss >> v;
			return v;
		}

		__forceinline void __stdcall Sync( ) {
			std::cin.ignore( );
		}
	};
}

#endif