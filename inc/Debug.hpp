

#ifndef DEBUG_HPP
#define DEBUG_HPP

#define BLACK	"\033[30m"
#define RESET	"\033[0m"
#define RED     "\033[31m"
#define GREEN 	"\033[32m"
#define BLUE 	"\033[34m"
#define YELLOW	"\033[33m"
#define PURPLE	"\033[35m"
#define CYAN	"\033[36m"

#include <string>


class Debug {

	private:
        static std::ofstream _debugfile;
        static bool _debug;
        static bool _nl;

        static void _add_time( void );

	public:
		Debug( std::string str );
		~Debug( void );

        static void add_nl( void );
        static void add_debug( std::string str );
        static void add_debug( int value );

        static void add_debug_nl( std::string str , int value );
        static void add_debug_nl( std::string str );
        static void add_debug_nl( int value );

        static bool check_debug_on();

};


#endif