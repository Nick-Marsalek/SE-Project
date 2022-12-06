#include "SettingsState.h"

void SettingsState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/pkfont.ttf"))
	{
		throw("ERROR MAINMENUSTATE: Could not load font");
	}
}

void SettingsState::initKeybinds()
{
}

void SettingsState::initButtons()
{
	this->buttons["BACK_TO_MAIN"] = new Button(725, 200, 500, 75,
		&this->font, "Back to Main Menu", sf::Color::White, 72,
		1, 1, sf::Color::Black, 5.f,
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["VOLUME_UP"] = new Button(1110, 370, 100, 75,
		&this->font, "+", sf::Color::White, 72,
		1, 1, sf::Color::Yellow, 2.f,
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["VOLUME_DOWN"] = new Button(700, 370, 100, 75,
		&this->font, "-", sf::Color::White, 72,
		1, 1, sf::Color::Yellow, 2.f,
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
	this->buttons["SAVE_SETTINGS"] = new Button(715, 500, 500, 75,
		&this->font, "Save Settings", sf::Color::White, 72,
		1, 1, sf::Color::Black, 2.f,
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	//sf::Color(70,70,70, 0), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	/*this->buttons["EXIT_STATE"] = new Button(880, 700, 170, 75,
		&this->font, "Quit", sf::Color::White, 72,
		1, 1, sf::Color::Black, 5.f,
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));*/

}

void SettingsState::initText()
{
	if (!this->debugFont.loadFromFile("Fonts/pkfont.ttf"))
	{
		throw("ERROR MAINMENUSTATE: Could not load font");
	}
	this->debugText.setFont(this->debugFont);
	this->debugText.setString("TEST");
	this->debugText.setCharacterSize(15);
	this->debugText.setPosition(0, 0);
	this->debugText.setFillColor(sf::Color::White);
	this->debugText.setScale(2, 2);

	this->volumeDisplay.setFont(this->debugFont);
	this->volumeDisplay.setString(std::to_string(*this->volume));
	this->volumeDisplay.setFillColor(sf::Color::White);
	this->volumeDisplay.setCharacterSize(72);
	this->volumeDisplay.setOutlineColor(sf::Color::Black);
	this->volumeDisplay.setOutlineThickness(5.f);
	this->volumeDisplay.setPosition(sf::Vector2f(1050, 400));

	this->volumeTitle.setFont(this->debugFont);
	this->volumeTitle.setString("Volume:");
	this->volumeTitle.setFillColor(sf::Color::White);
	this->volumeTitle.setCharacterSize(72);
	this->volumeTitle.setOutlineColor(sf::Color::Black);
	this->volumeTitle.setOutlineThickness(5.f);
	this->volumeTitle.setPosition(sf::Vector2f(800, 400));

	this->savedText.setFont(this->debugFont);
	this->savedText.setString("Saved!");
	this->savedText.setFillColor(sf::Color::White);
	this->savedText.setCharacterSize(72);
	this->savedText.setOutlineColor(sf::Color::Black);
	this->savedText.setOutlineThickness(5.f);
	this->savedText.setPosition(sf::Vector2f(860, 600));
	this->showSavedText = false;
}

SettingsState::SettingsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, float *volume)
	: State(window, supportedKeys, states, volume)
{
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->initText();

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color(0, 0 ,0, 0));
}

SettingsState::~SettingsState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		it->second;
	}
}

void SettingsState::endState()
{
	std::cout << "Ending Settings State" << std::endl;
}

void SettingsState::updateSprites()
{
}

void SettingsState::updateInput(const float& dt)
{
}

void SettingsState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView, 0, 0);
	}

	if (this->buttons["BACK_TO_MAIN"]->isActive())
	{
		buttonTransistionSettingsBool = true;
		showSavedText = false;
		/*this->quit = true;*/
	}

	if (this->buttons["VOLUME_UP"]->isActive())
	{
		if (*this->volume < 100)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			*this->volume += 5;
			this->showSavedText = false;
		}
	}

	if (this->buttons["VOLUME_DOWN"]->isActive())
	{
		if (*this->volume > 0)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
			*this->volume -= 5;
			this->showSavedText = false;
		}
	}

	if (this->buttons["SAVE_SETTINGS"]->isActive())
	{
		std::ofstream ofs;
		ofs.open("Config/settings.ini");
		if (ofs.fail())
		{
			throw("Failed to write to settings");
		}
		ofs << *this->volume;
		ofs.close();
		this->showSavedText = true;

	}
}

void SettingsState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateButtons();
	this->updateSprites();
	this->updateText();

	if (buttonTransistionSettingsBool)
		buttonTransition();
}

void SettingsState::updateText()
{
	std::string debugmsg1 = std::to_string(roundf(this->mousePosView.x * 100) / 100);
	std::string debugmsg2 = std::to_string(roundf(this->mousePosView.y * 100) / 100);
	std::string msg = debugmsg1 + " " + debugmsg2;
	//system("cls");
	//std::cout << msg;
	this->debugText.setString(msg);
	this->volumeDisplay.setString(std::to_string((int)(*this->volume)));
}

void SettingsState::buttonTransition()
{
	static float alpha = 1;
	this->background.setFillColor(sf::Color(0, 0, 0, alpha));
	alpha *= 1.1;
	if (alpha >= 255)
	{
		alpha = 1;
		buttonTransistionSettingsBool = false;
		this->background.setFillColor(sf::Color(0, 0, 0, alpha));
		this->quit = true;
	}
}

void SettingsState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void SettingsState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	
	target->draw(this->debugText);
	this->renderButtons(target);
	target->draw(this->volumeDisplay);
	target->draw(this->volumeTitle);
	if (showSavedText)
	{
		target->draw(this->savedText);
	}
		

	target->draw(this->background);

}
