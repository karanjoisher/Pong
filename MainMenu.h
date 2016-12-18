#pragma once


struct Button 
{
	Button(sf::Sprite *abuttonSprite = nullptr,sf::Sprite *ahoverSprite = nullptr, sf::Font *font = nullptr,sf::Sound *amouseOver = nullptr, sf::Sound *amouseClick = nullptr,void(*acallback)() = nullptr, const float &ax = 0, const float &ay = 0) :buttonSprite(abuttonSprite), hoverSprite(ahoverSprite), callback(acallback), x(ax), y(ay), focus(false),currentSprite(buttonSprite),mouseClick(amouseClick),mouseOver(amouseOver)
	{
		text.setFillColor(defaultColor);
		if (font) { text.setFont(*font); }
	}
	bool focus;
	float x, y;
	sf::FloatRect clickableArea;
	sf::Color defaultColor;
	sf::Color hoverColor;
	sf::Sprite *buttonSprite;
	sf::Sprite *currentSprite;
	sf::Sprite *hoverSprite;
	sf::Sound *mouseOver;
	sf::Sound *mouseClick;
	sf::Text text;
	
	void setTextAtCenter();
	void setPosition(const float &x, const float &y);
	void draw(sf::RenderWindow &window);
	bool onFocus(sf::Vector2i mousePos);
	bool serviceClick(sf::Vector2f mouseClick);
	void(*callback)();
};



class MainMenu {
	static Button* buttons[];
	static Button playButton;
	static Button difficultyDisplay;
	static Button gamePoints;
	static Button incrementPointsButton;
	static Button decrementPointsButton;
	static Button decrementDifficultyButton;
	static Button incrementDifficultyButton;
	static Button AIButton;
public:
	static void setup();
	static void show(sf::RenderWindow& window);	
};