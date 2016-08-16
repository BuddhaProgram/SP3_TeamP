#ifndef CAMERA_2D_H
#define CAMERA_2D_H

#include "Camera.h"
#include "Character.h"

class Camera2D : public Camera {

private:
	//Variable(s)
	Character* player;
	TileMap* tileMap;

public:
	//Constructor(s) & Destructor
	Camera2D();
	virtual ~Camera2D();

	void SetPlayer(Character& player);
	void RemovePlayer();
	
	void SetTileMap(TileMap& tileMap);
	void RemoveTileMap();
	
	//Virtual Function(s)
	virtual void Update(const double& deltaTime);

};

#endif