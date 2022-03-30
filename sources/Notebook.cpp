   /*
    Author: Nadav Moyal
    */

#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <string>
#include <map>


using namespace std;
namespace ariel

{
const int MaxChar=125;
const int MinChar=32;
const int LineLen=100;
                
    /*
    'write' - receives a position (page, line and column), direction (horizontal or vertical), 
    and a string that represents what needs to be written, and writes the string in a notebook in the appropriate place.
    If we have already written, or deleted to the specified location, the function will throw an error.
    */
    void Notebook::write(int page,  int row,  int col, Direction dir,const std::string & s)
    {
        int len= s.length();
        if(page < 0 || row < 0 || col < 0 ){
            throw runtime_error("Error:negative input for page / row / col.");
        }
        for(int i=0;i<len;i++){
            if ( (s[(unsigned int)i] > MaxChar ) || (s[(unsigned int)i] < MinChar ) ){
                throw runtime_error("Error:unsupported char input.");   
            }
        }
        if ((col >= LineLen) || ( col + len  >=  LineLen && dir == Direction::Horizontal)){
            throw runtime_error ("Error: Exception in column number, out of range.");
            } 
        if(dir== Direction::Horizontal){
        //case:Horizontal
            int i=0;
            while(i<len){
                if (s[(unsigned int)i] == '~')
                 {
                    throw runtime_error("Error: This place is already written");
                 }
                    if (book[page][row][col+i] == '~')
                        {
                        throw runtime_error("Error: This place is already written");
                        }
                      
                            if (MinChar <= book[page][row][col + i]) 
                            {
                                if(book[page][row][col + i] <= MaxChar){
                                        if (book[page][row][col + i] == '_')
                                            {      
                                            book[page][row][col + i] = s[(unsigned int)i];
                                            }
                                        else
                                            {
                                            throw runtime_error("Error: This place is already written");
                                            }
                                }
                            }
                            else
                            {
                                book[page][row][col + i] = s[(unsigned int)i];
                            }
            i++;
            }
        }
        else {
        //case:Vertical
            int i=0;
            while(i<len){
                if (s[(unsigned int)i] == '~')
                 {
                    throw runtime_error("Error: This place is already written");
                 }
                if (book [page][row + i][col] == '~')
                {
                    throw runtime_error("Error: This place is already written");
                }
                            if (MinChar <= book[page][row+i][col]) 
                            {
                                if(book[page][row+i][col] <= MaxChar){
                                        if (book[page][row+i][col] == '_')
                                            {      
                                            book[page][row+i][col] = s[(unsigned int)i];
                                            }
                                        else
                                            {
                                            throw runtime_error("Error: This place is already written");
                                            }
                                }
                            }
                            else
                            {
                                book[page][row+i][col] = s[(unsigned int)i];
                            }
                i++;
            }
        }  
    }  

    /*
    read - Receives position (page, row and column), direction (horizontal or vertical),
     and number of characters, reads what is written in the notebook at the given position and length,
     and returns a string. The letter in each box on the board is the last letter written there.
    */
    string Notebook::read(int page,  int row,  int col, Direction dir,int len){
        if(len < 0 ||page < 0 || row < 0 || col < 0 ){
            throw runtime_error("Error:negative input for page / row / col / length to read.");
        }
        if (col >= LineLen){
            throw runtime_error ("Error: Exception in column number, out of range.");
        }  
     
        if (col + len > LineLen && dir == Direction::Horizontal)
        {
            throw runtime_error ("Error: Exception in column number, out of range.");
        }
    
        string result;
        int i=0;
        if (dir == Direction::Vertical)
        {
            while(i<len){
                if (MinChar > book[page][row + i][col] || MaxChar+2 <=book[page][row + i][col] )
                    {
                        result += '_';    
                    }
                else
                    {
                        result += book[page][row + i][col];
                    }   
                i++;
            }
        }
        else
        {
            while(i<len){
                if (MinChar > book[page][row][col + i] ||  MaxChar+2 <= book[page][row][col + i])
                    {
                        result += '_';
                    }
                else
                    {
                        result += book[page][row][col + i];
                    }
                i++;
            }
        }
        return result;
    }
    /*
    erase - Gets a position (page, row and column), direction (horizontal or vertical),
    and number of characters,and deletes what is written in the relevant position and direction.
    Since we are writing with a pen, the function will place the characters '~' in place of the characters
    */
	void Notebook::erase(int page,  int row,  int col,Direction dir,int len){
        if(len < 0 ||page < 0 || row < 0 || col < 0 ){
            throw runtime_error("Error:negative input for page / row / col / length to read.");
        }
        if (col >= LineLen || (col + len >= LineLen && dir == Direction::Horizontal)) {
            throw runtime_error ("Error: Exception in column number, out of range.");
        }  
            int i =0;
            if (dir == Direction::Vertical)           
            {
                while(i < len){
                    book[page][row + i][col] = '~';
                    i++;
                }
            }
            else
            {
                while(i < len){
                    book[page][row][col + i] = '~';
                    i++;
                }
            }
    }
    /*
    show - Gets a page number and presents it in a convenient way to read.
    */
	void Notebook::show(int page){
     if (page <= -1 )
        {
        throw runtime_error("Error:negative input for page / row / col.");
        }
    cout << book[page][0][0]; 
   }
}