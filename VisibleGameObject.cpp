#include "stdafx.h"

#include "VisibleGameObject.h"

//VisibleGameObject::VisibleGameObject(const std::string & aname, const float & az_index, Sprite & aobjectSprite):VisibleGameObject(aname, az_index, aobjectSprite, 0, 0){}
VisibleGameObject::VisibleGameObject(const std::string & aname, const float & az_index, sf::Sprite *aobjectSprite, const float &ax, const float &ay) : name(aname), z_index(az_index), objectSprite(aobjectSprite), x(ax), y(ay)
{
	
	if (objectSprite)
	{
		textureRect = objectSprite->getTextureRect();
		width = textureRect.width;
		height = textureRect.height;
		objectSprite->setPosition(sf::Vector2f(ax, ay));
	}
}

void VisibleGameObject::draw(sf::RenderWindow & window)
{
	
	if (objectSprite)
	{
		objectSprite ->setTextureRect(textureRect);
		objectSprite -> setPosition(sf::Vector2f(x, y));
		window.draw(*objectSprite);
	}
}

void VisibleGameObject::update(const float & deltaTime){}

int VisibleGameObject::getWidth()
{
	
	return width;
}

int VisibleGameObject::getHeight()
{
	return height;
}

sf::Vector2f VisibleGameObject::getPosition()
{
	return sf::Vector2f(x, y);
}

float VisibleGameObject::get_zindex()
{
	return z_index;
}

void VisibleGameObject::setSprite(sf::Sprite * sprite)
{
	objectSprite = sprite;
}

sf::Vector2f VisibleGameObject::getCenter()
{
	return sf::Vector2f(x + (getWidth() / 2.0f), y + (getHeight() / 2.0f));
}

void VisibleGameObject::setPosition(const float & ax, const float & ay)
{
	x = ax; y = ay;	
}

void VisibleGameObject::set_zindex(const float & az_index)
{
	z_index = az_index;
}

sf::Sprite* VisibleGameObject::getSprite()
{
	return objectSprite;
}

void VisibleGameObject::setTextureRect(sf::IntRect rect)
{
	textureRect = rect;
	width = textureRect.width;
	height = textureRect.height;
}
