#include "GameRules.hpp"

namespace GOL
{

    int GameRules::getLiveNeighbours( int x, int y, int _Life[180][90])
    {
        int liveNeighbours = 0;
        
        try {
            if ( _Life[x - 1][y] == 1)
            {
                liveNeighbours++;
            }
        } catch (...) {
            
        }
        
        try {
            if ( _Life[x + 1][y] == 1)
            {
                liveNeighbours++;
            }
        } catch (...) {
            
        }
        
        try {
            if ( _Life[x][y + 1] == 1)
            {
                liveNeighbours++;
            }
        } catch (...) {
            
        }
        
        try {
            if ( _Life[x][y - 1] == 1)
            {
                liveNeighbours++;
            }
        } catch (...) {
            
        }
        
        try {
            if ( _Life[x - 1][y + 1] == 1)
            {
                liveNeighbours++;
            }
        } catch (...) {
            
        }

        try {
            if ( _Life[x + 1][y + 1] == 1)
            {
                liveNeighbours++;
            }
        } catch (...) {
            
        }
    
        try {
            if ( _Life[x - 1][y - 1] == 1)
            {
                liveNeighbours++;
            }
        } catch (...) {
            
        }

        try {
            if ( _Life[x + 1][y - 1] == 1)
            {
                liveNeighbours++;
            }
        } catch (...) {
            
        }
        
        return liveNeighbours;
    }

    bool GameRules::underpopulation(int liveNeighbours, int status)
    {
        if ( liveNeighbours < 2 && status == 1)
        {
            return true;
        }
        else{
            return false;
        }
    }
    
    bool GameRules::nextGeneration(int liveNeighbours, int status)
    {
        if ( (liveNeighbours == 2 || liveNeighbours == 3) && status == 1)
        {
            return true;
        }
        else{
            return false;
        }
    }

    bool GameRules::overpopulation(int liveNeighbours, int status)
    {
        if ( liveNeighbours > 3 && status == 1)
        {
            return true;
        }
        else{
            return false;
        }
    }

    bool GameRules::reproduction(int liveNeighbours, int status)
    {
        if ( liveNeighbours == 3 && status != 1)
        {
            return true;
        }
        else{
            return false;
        }
    }


}
