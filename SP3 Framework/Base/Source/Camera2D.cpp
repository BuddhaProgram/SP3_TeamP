#include "Camera2D.h"

Camera2D::Camera2D() {

	player = nullptr;
	tileMap = nullptr;

}

Camera2D::~Camera2D() {
}

void Camera2D::SetPlayer(Character& player) {

	this->player = &player;

}

void Camera2D::RemovePlayer() {

	this->player = nullptr;

}

void Camera2D::SetTileMap(TileMap& tileMap) {

	this->tileMap = &tileMap;

}

void Camera2D::RemoveTileMap() {

	tileMap = nullptr;

}

void Camera2D::Update(const double& deltaTime) {

	if (tileMap == nullptr || player == nullptr) {
		cout << "No Player Or TileMap Attached. Unable to update camera 2." << endl;
		return;
	}

	float xRatio = (static_cast<float>(aspectRatio.x) / static_cast<float>(aspectRatio.y));
	float camWidth = xRatio * orthoSize; //Half of our camera's view width

	float deadZoneX = 0.25f;
	float deadZoneY = 0.5f;
	float distanceToPlayerX = player->transform.position.x - transform.position.x; //How far are we from the player.
	float distanceToPlayerY = player->transform.position.y - transform.position.y;
	float maxDistanceToPlayerX = deadZoneX * camWidth; //What is the maximum distance we should be following the player.
	float maxDistanceToPlayerY = deadZoneX * orthoSize;

	if (distanceToPlayerX > maxDistanceToPlayerX) {	
		transform.position.x = player->transform.position.x - maxDistanceToPlayerX;
	} else if (distanceToPlayerX < -maxDistanceToPlayerX) {
		transform.position.x = player->transform.position.x + maxDistanceToPlayerX;
	}

	if (distanceToPlayerY > maxDistanceToPlayerY) {
		transform.position.y = player->transform.position.y - maxDistanceToPlayerY;
	} else if (distanceToPlayerY < -maxDistanceToPlayerY) {
		transform.position.y = player->transform.position.y + maxDistanceToPlayerY;
	}

	//Border of our camera's view
	float rightBorder = transform.position.x + camWidth;
	if (rightBorder > tileMap->GetRightBorder()) {
		transform.position.x = tileMap->GetRightBorder() - camWidth;
	}
	//Border of our camera's view
	float leftBorder = transform.position.x - camWidth;
	if (leftBorder < tileMap->GetLeftBorder()) {
		transform.position.x = tileMap->GetLeftBorder() + camWidth;
	}

	//Border of our camera's view
	float topBorder = transform.position.y + orthoSize;
	if (topBorder > tileMap->GetTopBorder()) {
		transform.position.y = tileMap->GetTopBorder() - orthoSize;
	}
	//Border of our camera's view
	float bottomBorder = transform.position.y - orthoSize;
	if (bottomBorder < tileMap->GetBottomBorder()) {
		transform.position.y = tileMap->GetBottomBorder() + orthoSize;
	}
	

}