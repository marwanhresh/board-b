#include "Board.hpp"
#include <limits>

ariel::Board::Board() : _minRow(std::numeric_limits<unsigned int>::max()), _minColumn(std::numeric_limits<unsigned int>::max()), _maxRow(0), _maxColumn(0) {}


void ariel::Board::post(unsigned int row, unsigned int column, Direction dir, string message)
{

    _minRow = min(row, _minRow);
    _minColumn = min(column, _minColumn);

    if(dir == Direction::Horizontal)
    {

        _maxColumn = max((unsigned int)(column + message.length()) , _maxColumn);
        _maxRow = max(row + 1, _maxRow);
        for(unsigned int i = 0; i < message.length(); i++)
        {
            _board[row][column + i] = message[i] != '\n' ? message[i] : '_'; // if message[i] is '\n' we will add '_' otherwise we will add message[i]
        }
    }
    else
    {

        _maxRow = max((unsigned int)(row + message.length()) ,_maxRow);
        _maxColumn = max(column + 1, _maxColumn);
        for(unsigned int i = 0; i < message.length(); i++)
        {
            _board[row + i][column] = message[i] != '\n' ? message[i] : '_'; // if message[i] is '\n' we will add '_' otherwise we will add message[i]
        }
    }
}

string ariel::Board::read(unsigned int row, unsigned int column, Direction dir, unsigned int length)
{
     string message = "";
    if(dir == Direction::Horizontal)
    {
        for(unsigned int i = 0; i < length; i++)
        {
            if(_board.find(row) != _board.end() && _board[row].find(i + column) != _board[row].end())
            {
                message += _board[row][i + column];
            }
            else
            {
                message += '_';
            }
        }
    }
    else
    {
        for(unsigned int i = 0; i < length; i++)
        {
            if(_board.find(row + i) != _board.end() && _board[row + i].find(column) != _board[row + i].end())
            {
                message += _board[row + i][column];
            }
            else
            {
                message += '_';
            }
        }
    }
    return message;
}

void ariel::Board::show()
{
    for(unsigned int i = _minRow ; i < _maxRow; i++)
    {
        cout.fill('0');
        cout.width(5);
        cout << i << ": " << read(i, _minColumn, Direction::Horizontal, _maxColumn - _minColumn) << endl;
    }
}
