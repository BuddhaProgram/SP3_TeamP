#ifndef BULLET_INFO_H
#define BULLET_INFO_H

#include "Vector3.h"

class BulletInfo {

public:
	BulletInfo();
	virtual ~BulletInfo();

protected:
	//Indicate the status of this bullet
	bool m_bStatus;
	//The position of the bullet
	Vector3 position;
	//The rotation of the bullet
	Vector3 rotation;
	//The direction of the bullet
	Vector3 direction;
	//The speed of the bullet
	float speed;
	//The lifetime of the bullet
	float lifetime;
	//The damage of the bullet
	int damage;

public:
	//Initialise the BulletInfo instance
	void Init(const Vector3 position, const Vector3 rotation, const float speed, const float lifetime, const int damage = 5);
	
	//Set the status of this BulletInfo instance
	void SetStatus(const bool bStatus);
	//Get the status of this BulletInfo instance
	bool GetStatus(void) const;
	
	//Set the position of this BulletInfo instance
	void SetPosition(const Vector3 position);
	//Get the position of this BulletInfo instance
	Vector3 GetPosition(void) const;
	
	//Set the direction of this BulletInfo instance
	void SetRotation(const Vector3 rotation);
	//Get the direction of this BulletInfo instance
	Vector3 GetRotation(void) const;
	
	//Get the direction of this BulletInfo instance
	Vector3 GetDirection(void) const;

	void CalculateDirection();

	//Set the speed of this BulletInfo instance
	void SetSpeed(const float speed);
	//Get the speed of this BulletInfo instance
	float GetSpeed(void) const;
	
	//Set the damage of this BulletInfo instance
	void SetDamage(float damage);
	//Get the damage of this BulletInfo instance
	int GetDamage() const;

	//Set the lifetime of this BulletInfo instance
	void SetLifetime(const float lifetime);
	//Get the lifetime of this BulletInfo instance
	float GetLifetime(void) const;
	//Update this BulletInfo instance
	void Update(const double dt);

};

#endif