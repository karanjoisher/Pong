#pragma once
#include "Layer.h"

class GameObjectManager {
private:
	struct layerOrdering{
		bool operator()(const float& a, const float& b) const {
			return a < b;
		}
	};
	

	std::map<float, Layer*, layerOrdering> layers; //Float is the layer number, Layer* is the associated layer
	std::unordered_map<std::string, float> nameToZindex; 
	sf::Clock frameClock;
public:
	~GameObjectManager();
	void addObject(VisibleGameObject*);
	void removeObject(const std::string&);
	VisibleGameObject* getObject(const std::string &name);
	void drawAllLayers(sf::RenderWindow &window);
	void updateAllLayers(const float &elapsedTime);
};