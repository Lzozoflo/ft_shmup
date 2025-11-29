

#ifndef WINDOWN_HPP
#define WINDOWN_HPP

#define BLACK	"\033[30m"
#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN 	"\033[32m"
#define BLUE 	"\033[34m"
#define YELLOW	"\033[33m"
#define PURPLE	"\033[35m"
#define CYAN	"\033[36m"

#include <string>

class Windown {

	private:

	public:
		Windown(int ac, char **av);
		~Windown( void );

};



#endif
