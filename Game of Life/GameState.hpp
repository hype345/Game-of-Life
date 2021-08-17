#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"


namespace GOL
{
    class GameState : public State
    {
    public:
        GameState(GameDataRef data);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;
        
        sf::Sprite _Stop;
        
        sf::RectangleShape _Boarder;
        
        sf::RectangleShape _Board[180][90];
        
        int _Life[180][90];
    };
}
