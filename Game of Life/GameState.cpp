#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "GameOverState.hpp"
#include<time.h>

#include <iostream>

namespace GOL
{
    GameState::GameState(GameDataRef data) : _data(data)
    {

    }

    void GameState::Init()
    {
        this->_data->assets.LoadTexture("STOP", STOP_BUTTON_FILEPATH);
        
        _Stop.setTexture(this->_data->assets.GetTexture("STOP"));
        
        _Stop.setPosition(10, 10);
        
        
        _Boarder.setSize(sf::Vector2f(1800, 900));
        
        _Boarder.setOutlineColor(sf::Color::Red);
        
        _Boarder.setOutlineThickness(1);
        
        _Boarder.setFillColor(sf::Color::Transparent);
        
        _Boarder.setPosition(sf::Vector2f(60, 90));
        
        
        srand(time(0));
        
        
        for ( int i = 0; i < 180; i++ )
        {
            for ( int j = 0; j < 90; j ++ )
            {
               _Life[i][j] = std::rand() % 10;
            }
        }
        
        
        for ( int i = 0; i < 180; i++ )
        {
            for ( int j = 0; j < 90; j++ )
            {
                _Board[i][j].setSize(sf::Vector2f(10, 10));
                if( _Life[i][j] == 1)
                {
                    _Board[i][j].setFillColor(sf::Color::White);
                }
                else{
                    _Board[i][j].setFillColor(sf::Color::Transparent);
                }
                _Board[i][j].setPosition(sf::Vector2f( 60 + (10 * i), 90 + (10 * j) ));
            }
        }
        
    }

    void GameState::HandleInput()
    {
        sf::Event event;

        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
            
            if (this->_data->input.IsSpriteClicked(this->_Stop, sf::Mouse::Left, this->_data->window))
            {
                // Switch To Game Over
                this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
            }
        }
    }

    void GameState::Update(float dt)
    {
        
        std::vector<int> xToDie;
        std::vector<int> yToDie;
        
        std::vector<int> xToBeBorn;
        std::vector<int> yToBeBorn;

        
        for( int i = 0; i < 180; i++ )
        {
            for( int j = 0; j < 90; j ++)
            {
                int liveNeighbours = this->_data->rules.getLiveNeighbours(i, j, _Life);
                if ( this->_data->rules.underpopulation(liveNeighbours, _Life[i][j]))
                {
                    xToDie.push_back(i);
                    yToDie.push_back(j);
                }
                else if ( this->_data->rules.nextGeneration(liveNeighbours, _Life[i][j]))
                {
                    
                }
                else if ( this->_data->rules.overpopulation(liveNeighbours, _Life[i][j]))
                {
                    xToDie.push_back(i);
                    yToDie.push_back(j);
                }
                else if ( this->_data->rules.reproduction(liveNeighbours, _Life[i][j]))
                {
                    xToBeBorn.push_back(i);
                    yToBeBorn.push_back(j);
                }
            }
        }
        
        for (int i = 0; i < xToDie.size(); ++i)
        {
            _Life[xToDie.at(i)][yToDie.at(i)] = 0;
        }
        
        for (int i = 0; i < xToBeBorn.size(); ++i)
        {
            _Life[xToBeBorn.at(i)][yToBeBorn.at(i)] = 1;
        }
        
        for ( int i = 0; i < 180; i++ )
        {
            for ( int j = 0; j < 90; j++ )
            {
                if( _Life[i][j] == 1)
                {
                    _Board[i][j].setFillColor(sf::Color::White);
                }
                else{
                    _Board[i][j].setFillColor(sf::Color::Transparent);
                }
            }
        }
        
        
    }

    void GameState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Black);
        
        this->_data->window.draw(this->_Stop);
        
        this->_data->window.draw(this->_Boarder);
        
        for ( int i = 0; i < 180; i++ )
        {
            for ( int j = 0; j < 90; j++ )
            {
                this->_data->window.draw(this->_Board[i][j]);
            }
        }

        this->_data->window.display();
    }
}
