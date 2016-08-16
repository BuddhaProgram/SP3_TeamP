#ifndef SCENE_H
#define SCENE_H

#include <string>

using std::string;

class Scene {

public:
	//Virtual Function(s)
	virtual void Initialise() = 0;
	virtual void Update(const double& deltaTime) = 0;
	virtual void Render() = 0;
	virtual void Exit() = 0;

	//Constructor(s) & Destructor
	Scene() {}
	virtual ~Scene() {}

};

#endif