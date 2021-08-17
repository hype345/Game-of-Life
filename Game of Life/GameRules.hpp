#pragma once

namespace GOL
{
    class GameRules
    {
    public:
        int getLiveNeighbours( int x, int y, int _Life[180][90] );
        
        bool underpopulation( int liveNeighbours, int status );
        
        bool nextGeneration( int liveNeighbours, int status );
        
        bool overpopulation( int liveNeighbours, int status);
        
        bool reproduction( int liveNeighbours, int status );
    };
}
