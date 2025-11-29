

#ifndef DEBUG_HPP
#define DEBUG_HPP


#include <string>


class Debug {

	private:
        static std::ofstream _debugfile;
        static bool _debug;

        static void _add_time( void );

	public:
		Debug( std::string str );
		~Debug( void );

        static void add_debug( std::string str );
        static void add_debug( int value );
        static bool check_debug_on();

};


#endif