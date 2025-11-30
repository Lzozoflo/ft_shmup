
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include "Debug.hpp"


std::ofstream Debug::_debugfile;
bool Debug::_debug = false;
bool Debug::_nl = true;

Debug::~Debug( void ) {
    this->_debugfile.close();
    Debug::_debug = false;
}


Debug::Debug( std::string str ) {

    this->_debug = true;

    this->_debugfile.open(str.c_str());

    this->_debugfile << "Years-month-day - hour-min-sec.\n\n";
    this->_add_time();
    this->_debugfile << "Debug start.\n\n";
}

void Debug::_add_time( void ) {
    if (!Debug::check_debug_on())
        return;
    std::time_t t = std::time(NULL);
    std::tm* info = std::localtime(&t);

    Debug::_debugfile   << (1900 + info->tm_year) << "-"
                        << (1 + info->tm_mon)  << "-"
                        << info->tm_mday << " - "
                        << info->tm_hour << "-"
                        << info->tm_min << "-"
                        << info->tm_sec << " ";

}

bool Debug::check_debug_on(){
    return (Debug::_debug);
}

void Debug::add_debug( std::string str ){
    if (!Debug::check_debug_on())
        return;
    if (Debug::_nl)
        Debug::_add_time();
    Debug::_debugfile << str;
    Debug::_nl = false;
}

void Debug::add_debug( int value ){
    if (!Debug::check_debug_on())
        return;
    if (Debug::_nl)
        Debug::_add_time();
    Debug::_debugfile << value;
    Debug::_nl = false;
}

void Debug::add_debug_nl( std::string str , int value ){
    if (!Debug::check_debug_on())
        return;
    if (Debug::_nl)
        Debug::_add_time();
    Debug::_debugfile << str << value << "\n";
    Debug::_nl = true;
}

void Debug::add_debug_nl( std::string str ){
    if (!Debug::check_debug_on())
        return;
    if (Debug::_nl)
        Debug::_add_time();
    Debug::_debugfile << str << "\n";
    Debug::_nl = true;
}

void Debug::add_debug_nl( int value ){
    if (!Debug::check_debug_on())
        return;
    if (Debug::_nl)
        Debug::_add_time();
    Debug::_debugfile << value << "\n";
    Debug::_nl = true;
}

void Debug::add_nl( void ){
    if (!Debug::check_debug_on())
        return;
    Debug::_debugfile << "\n";
    Debug::_nl = true;
}
