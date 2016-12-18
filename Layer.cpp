#include"stdafx.h"
#include "Layer.h"

Layer::Layer(const float & alayer_index) :Layer(alayer_index, {}){}

Layer::~Layer()
{
	for (VisibleGameObject* object : objects)
	{
		delete object;
	}
}

Layer::Layer(const float & alayer_index, std::initializer_list<VisibleGameObject*> avisibleObjects):layer_index(alayer_index), objects(avisibleObjects){}

void Layer::addObject(VisibleGameObject * object)
{
	objects.push_back(object);
}

void Layer::removeObject(const std::string & name)
{
	for (VisibleGameObject* object : objects) 
	{
		if (object->name == name) 
		{
			delete object;
			return;
		}
	}
}

void Layer::drawLayer(sf::RenderWindow &window)
{
	for (VisibleGameObject* object : objects) 
	{
		object->draw(window);
	}
}

void Layer::updateLayer(const float & elapsedTime)
{
	for (VisibleGameObject* object : objects)
	{
		object->update(elapsedTime);
	}
}

VisibleGameObject * Layer::getObject(const std::string & name)
{
	for (VisibleGameObject* object : objects)
	{
		if (object->name == name)
		{
			return object;
		}
	}
	return nullptr;
}

int Layer::count()
{
	return objects.size();
}
