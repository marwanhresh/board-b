#include<iostream>
#include"Direction.hpp"
#include<vector>
using namespace std;
namespace  ariel
{ 
    class Board {
       vector<string>board;
    public:
    Board(){
    }
    void post (unsigned int row ,unsigned int column,Direction d,string s);
    string read(unsigned int row , unsigned int column,Direction d,unsigned int size);
    void show();
};
} 
