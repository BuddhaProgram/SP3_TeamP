#include "BulletInfo.h"
#include "Mtx44.h"

BulletInfo::BulletInfo() : m_bStatus(false), speed(0), lifetime(0) {
}

BulletInfo::~BulletInfo() {
}

//Initialise the BulletInfo instance
void BulletInfo::Init(const Vector3 position, const Vector3 rotation, const float speed, const float lifetime, const int damage) {

	this->position = position;
	SetRotation(rotation);
	this->speed = speed;
	this->lifetime = lifetime;
	this->damage = damage;
	SetStatus(true);

}


//Set the status of this BulletInfo instance
void BulletInfo::SetStatus(const bool bStatus) {

	this->m_bStatus = bStatus;

}


//Get the status of this BulletInfo instance
bool BulletInfo::GetStatus(void) const {

	return m_bStatus;

}

//Set the position of this BulletInfo instance
void BulletInfo::SetPosition(const Vector3 position) {

	this->position = position;

}

//Get the position of this BulletInfo instance
Vector3 BulletInfo::GetPosition(void) const {

	return position;

}

//Set the direction of this BulletInfo instance
void BulletInfo::SetRotation(const Vector3 rotation) {

	this->rotation = rotation;
	CalculateDirection();

}

Vector3 BulletInfo::GetRotation() const {

	return this->rotation;

}

//Get the direction of this BulletInfo instance
Vector3 BulletInfo::GetDirection(void) const {

	return direction;

}
	
//Set the speed of this BulletInfo instance
void BulletInfo::SetSpeed(const float speed) {

	this->speed = speed;

}

//Get the speed of this BulletInfo instance
float BulletInfo::GetSpeed(void) const {

	return speed;

}

//Set the damage of this BulletInfo instance
void BulletInfo::SetDamage(float damage) {

	this->damage = damage;

}
	
//Get the damage if this BulletInfo instance
int BulletInfo::GetDamage() const {

	return this->damage;

}

//Set the lifetime of this BulletInfo instance
void BulletInfo::SetLifetime(const float lifetime) {

	this->lifetime = lifetime;

}

//Get the lifetime of this BulletInfo instance
float BulletInfo::GetLifetime(void) const {

	return this->lifetime;

}

//Update this BulletInfo instance
void BulletInfo::Update(const double dt) {

	//Check if the bullet is active
	if (GetStatus() == true) {
		//Update the position of the bullet
		SetPosition(GetPosition() + GetDirection() * GetSpeed() * dt);

		//Update the lifetime
		SetLifetime(GetLifetime() - dt);

		//Check if the lifetime is gone
		if (GetLifetime() < 0) {
			SetStatus(false);
		}
	}

}

void BulletInfo::CalculateDirection() {

	enum AXIS {
		X,
		Y,
		Z,

		NUM_AXIS,
	};

	Mtx44 rotationMatrix[NUM_AXIS];
	rotationMatrix[X].SetToRotation(rotation.x, 1, 0, 0);
	rotationMatrix[Y].SetToRotation(rotation.y, 0, 1, 0);
	rotationMatrix[Z].SetToRotation(rotation.z, 0, 0, 1);

	Mtx44 directionMatrix;
	directionMatrix.SetToTranslation(0, 0, 1); //Taking positive Z to be forward.
	directionMatrix = rotationMatrix[Y] * rotationMatrix[X] * rotationMatrix[Z] * directionMatrix;
	this->direction.Set(directionMatrix.a[12], directionMatrix.a[13], directionMatrix.a[14]);

}