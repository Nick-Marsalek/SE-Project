#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr;
	std::ifstream ifs("Config/settings.ini");
	if (ifs.is_open())
	{
		ifs >> this->volume;
	}
	ifs.close();
}

void Game::initWindow()
{
	std::ifstream ifs("Config/window.ini");
	std::string title = "None";
	//Creates the Window and View; Ititialize the bounds
	sf::VideoMode window_bounds(1920, 1080);

	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;
	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> vertical_sync_enabled;
	}
	ifs.close();

	this->window = new sf::RenderWindow(sf::VideoMode(window_bounds), title, sf::Style::Titlebar | sf::Style::Fullscreen);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initKeys()
{
	std::ifstream ifs("Config/supported_keys.ini");
	if (ifs.is_open())
	{
		std::string key = "";
		int key_value = 0;
		while (ifs >> key >> key_value)
		{
			this->supportedKeys[key] = key_value;

		}
	}
	ifs.close();
	this->supportedKeys["Enter"] = sf::Keyboard::Key::Enter;
	this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
	this->supportedKeys["A"] = sf::Keyboard::Key::A;
	this->supportedKeys["D"] = sf::Keyboard::Key::D;
	this->supportedKeys["W"] = sf::Keyboard::Key::W;
	this->supportedKeys["S"] = sf::Keyboard::Key::S;


	//DEBUG
	for (auto i : this->supportedKeys)
	{
		std::cout << i.first << " " << i.second << std::endl;
	}
}

void Game::initStates()
{
	//this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states, &this->volume));
	this->states.push(new BattleState(this->window, &this->supportedKeys, &this->states, &this->volume));
}


//Contructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initKeys();
	this->initStates();
	
	
}

//Destructor
Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();

}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape) {
				this->window->close();
				break;
			}
		
		}
	}
}

void Game::update()
{
	this->pollEvents();
	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);
		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else
	{
		std::cout << "Ending Application" << std::endl;
		this->window->close();
	}
}



void Game::render()
{
	this->window->clear();
	//Draw here
	if (!this->states.empty())
	{
		this->states.top()->render(this->window);
	}
	this->window->display();
}
