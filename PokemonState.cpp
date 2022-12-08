#include "PokemonState.h"


void PokemonState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/pkfont.ttf"))
	{
		throw("ERROR MAINMENUSTATE: Could not load font");
	}
}

void PokemonState::initKeybinds()
{
}

void PokemonState::initButtons()
{
	this->buttons["BACK"] = new Button(850, 500, 230, 75,
		&this->font, "Back", sf::Color::White, 72,
		1, 1, sf::Color::Black, 5.f,
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

PokemonState::PokemonState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, float* volume) 
	: State(window, supportedKeys, states, volume)
{
	this->initFonts();
	this->initButtons();
	this->prompt.setFont(this->font);
	this->prompt.setFillColor(sf::Color::White);
	this->prompt.setCharacterSize(72);
	this->prompt.setOutlineColor(sf::Color::Black);
	this->prompt.setOutlineThickness(5.f);
	this->prompt.setPosition(0, 0);
	std::ifstream ifs;
	ifs.open("Data/pokemonCaught.dat");
	std::string data;
	int numfire = 0, numwater = 0, numgrass = 0, numpika = 0;
	while (ifs >> data)
	{
		if (data == "Cyndaquil") {
			numfire += 1;
		}
		else if (data == "Totodile")
		{
			numwater += 1;
		}
		else if (data == "Chikorita")
		{
			numgrass += 1;
		}
		else if (data == "Pikachu")
		{
			numpika += 1;
		}
	}
	ifs.close();
	this->prompt.setString("Number of Each Pokemon Caught:\n\nCyndaquil: " + std::to_string(numfire) + "\n\nTotodile: " + std::to_string(numwater) + "\n\nChikorita: " + std::to_string(numgrass)+"\n\nPikachu: " + std::to_string(numpika));
	

}

PokemonState::~PokemonState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		it->second;
	}
}

void PokemonState::debugTextInit()
{
	
}

void PokemonState::sprtieInit()
{
}

void PokemonState::endState()
{
}

void PokemonState::updateInput(const float& dt)
{
}

void PokemonState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView, 0, 0);
	}

	if (this->buttons["BACK"]->isActive())
	{
		this->quit = true;
	}

}

void PokemonState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateButtons();
}

void PokemonState::updateDebugText()
{
}

void PokemonState::renderSprites(sf::RenderTarget* target)
{
}

void PokemonState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}

}

void PokemonState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	this->renderButtons(target);
	target->draw(this->prompt);
}
