#pragma once
#include "stdafx.h"
#include "VisibleGameObject.h"
class Layer 
{

private:
	std::vector<VisibleGameObject*> objects;
public:
	Layer(const float &alayer_index);
	~Layer();
	Layer(const float &alayer_index, std::initializer_list<VisibleGameObject*> avisibleObjects);
	const float layer_index;
	void addObject(VisibleGameObject *object);
	void removeObject(const std::string &name);
	void drawLayer(sf::RenderWindow &window);
	void updateLayer(const float &elapsedTime);
	VisibleGameObject* getObject(const std::string &name);
	int count();
};