#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"

#include <iostream>

namespace GOL
{
    GameOverState::GameOverState(GameDataRef data) : _data(data)
    {

    }

    void GameOverState::Init()
    {
        this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
        this->_data->assets.LoadTexture("Game Over", GAME_OVER_FILEPATH);

        _background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
        _ending.setTexture(this->_data->assets.GetTexture("Game Over"));
        
        _ending.setPosition((SCREEN_WIDTH / 2) - (_ending.getGlobalBounds().width / 2), (_ending.getGlobalBounds().height / 2) - 800);
    }

    void GameOverState::HandleInput()
    {
        sf::Event event;

        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
        }
    }

    void GameOverState::Update(float dt)
    {
        
    }

    void GameOverState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Black);

        this->_data->window.draw(this->_background);
        
        this->_data->window.draw(this->_ending);

        this->_data->window.display();
    }
}
