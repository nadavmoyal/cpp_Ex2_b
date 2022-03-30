#include "Direction.hpp"
#include <iostream>
#include <string>
#include <map>

using namespace std;
namespace ariel{
    class Notebook
    {
private:
        map< int, map< int, char[100]>> book ;
public:
	void write( int page,  int row,  int col, Direction dir,const std::string & s);
        string read(int page,  int row,  int col, Direction dir,int len);
	void erase( int page,  int row,  int col, Direction dir,int len);
	void show( int page);

};

};
