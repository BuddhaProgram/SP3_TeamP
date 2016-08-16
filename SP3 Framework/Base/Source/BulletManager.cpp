#include "BulletManager.h"

BulletManager::BulletManager(unsigned int numBullets) {

	bulletIndex = 0;
	for (unsigned int i = 0; i < numBullets; ++i) {
		bulletList.push_back(BulletInfo());
	}

}

BulletManager::~BulletManager() {
}

BulletInfo& BulletManager::FetchBulletInfo() {

	size_t vectorSize = bulletList.size();

	if (vectorSize == 0) {
		bulletList.push_back(BulletInfo());
		return bulletList.back();
	}

	vector<BulletInfo>::iterator iter = std::next(bulletList.begin(), bulletIndex);
	int endIndex = bulletIndex;

	do {
		if (iter == bulletList.end()) {
			iter = bulletList.begin();
		}
		if (iter->GetStatus() == false) {
			bulletIndex = (bulletIndex + 1) % vectorSize;
			return *iter;
		}
		++iter;
		bulletIndex = (bulletIndex + 1) % vectorSize;
	} while (bulletIndex != endIndex);

	for (unsigned int n = 0; n < (vectorSize + 1) / 2; ++n) {
		bulletList.push_back(BulletInfo());
	}

	return *(std::next(bulletList.begin(), bulletIndex += 1));

}

void BulletManager::ClearBulletInfo() {

	vector<BulletInfo>::iterator iter = bulletList.begin();
	while (iter != bulletList.end()) {
		iter = bulletList.erase(iter);
	}
	bulletIndex = 0;

}

void BulletManager::Update(double deltaTime) {

	for (vector<BulletInfo>::iterator iter = bulletList.begin(); iter != bulletList.end(); ++iter) {
		if (iter->GetStatus() == true) {
			iter->Update(deltaTime);
		}
	}

}

vector<BulletInfo>& BulletManager::GetBulletInfos() {

	return this->bulletList;

}