#include "stdafx.h"
#include "GameObjectManager.h"
#include "Game.h"
GameObjectManager::~GameObjectManager()
{
	//Delete all layers on heap
	for (std::pair<float, Layer*> layer : layers)
	{
		delete (layer.second);
	}
}

void GameObjectManager::addObject(VisibleGameObject *object)
{

	if (nameToZindex.find(object->name) != nameToZindex.cend())
	{
		std::cerr << "Duplicate name" << std::endl;
		return;
	}

	nameToZindex[object->name] = object->get_zindex(); //Map the object's name to it's Z index
	//Find the layer associated with the z index, 
	//if layer doesnt exist
	//then create a new layer and add the object
	//else add the object to the existing layer
	std::map<float, Layer*>::iterator objectLayerMap = layers.find(object->get_zindex());
	if (objectLayerMap == layers.cend())
	{
		Layer *newLayer = new Layer(object->get_zindex(), { object });
		layers[object->get_zindex()] = newLayer;
	}
	else 
	{
		Layer &objectLayer = *(objectLayerMap->second);
		objectLayer.addObject(object);
	}
}

void GameObjectManager::removeObject(const std::string &targetName)
{
	//Find the z index from object's name
	//Find the layer from z index
	//Remove object from the layer
	std::unordered_map<std::string, float>::iterator objectZindex = nameToZindex.find(targetName);
	if (objectZindex == nameToZindex.cend())
	{
		std::cerr << targetName + "Object not found" << std::endl;
		return;
	}

	std::map<float, Layer*>::iterator objectLayerMap = (layers.find(objectZindex->second));
	Layer &objectLayer = *(objectLayerMap->second);
	if (objectLayer.count() == 1)
	{
		delete objectLayerMap->second;
		layers.erase(objectLayerMap);
		return;
	}
	
	objectLayer.removeObject(targetName);
}

VisibleGameObject * GameObjectManager::getObject(const std::string & name)
{

	std::unordered_map<std::string, float>::iterator objectZindex = nameToZindex.find(name);
	if (objectZindex == nameToZindex.cend())
	{
 		std::cerr << name + "Object not found" << std::endl;
		return nullptr;
	}
	std::map<float, Layer*>::iterator objectLayerMap = (layers.find(objectZindex->second));
	Layer &objectLayer = *(objectLayerMap->second);
	return objectLayer.getObject(name);
}

void GameObjectManager::drawAllLayers(sf::RenderWindow & window)
{
	for (std::pair<float, Layer*> layer : layers)
	{
		(layer.second) -> drawLayer(window);
	}
}

void GameObjectManager::updateAllLayers(const float &elapsedTime)
{
	

	for (std::pair<float, Layer*> layer : layers)
	{
		(layer.second)->updateLayer(elapsedTime);
	}
}
