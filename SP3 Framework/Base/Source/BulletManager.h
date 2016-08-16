#ifndef BULLET_MANAGER_H
#define BULLET_MANAGER_H

#include "BulletInfo.h"
#include <vector>

using std::vector;

class BulletManager {

private:
	//Variable(s)
	int bulletIndex;

public:
	//Variable(s)
	vector<BulletInfo> bulletList;

	//Function(s)
	BulletInfo& FetchBulletInfo();
	void ClearBulletInfo();
	void Update(double deltaTime);
	vector<BulletInfo>& GetBulletInfos();

	//Constructor & Destructor
	BulletManager(unsigned int numBullets = 16);
	~BulletManager();

};

#endif