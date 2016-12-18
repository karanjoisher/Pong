#pragma once
class VisibleGameObject {
public:
	VisibleGameObject(const std::string & aname, const float & az_index, sf::Sprite *aobjectSprite = nullptr, const float & x = 0, const float & y = 0);
	
	const std::string name;
	virtual	void draw(sf::RenderWindow &window);
	virtual void update(const float &deltaTime);
	
	int getWidth() ;
	int getHeight() ;
	sf::Vector2f getPosition();
	sf::Vector2f getCenter();
	float get_zindex();
	sf::Sprite* getSprite();
	void setTextureRect(sf::IntRect rect);
	void setSprite(sf::Sprite *sprite);
	virtual void setPosition(const float &ax, const float &ay);
	void set_zindex(const float &az_index);
	sf::IntRect textureRect;
private:
	float x,  y;
	int width, height;
	sf::Sprite *objectSprite;
	float z_index;
};