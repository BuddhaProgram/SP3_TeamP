#include "TextureManager.h"
#include "GL\glew.h"
#include "LoadTGA.h"

//Constructor(s) & Destructor
TextureManager::TextureManager() {
}

TextureManager::~TextureManager() {

	Clear();

}

//Private Function(s)
bool TextureManager::Clear() {

	for (TextureMap::iterator mapIter = textureMap.begin(); mapIter != textureMap.end(); ++mapIter) {
		glDeleteTextures(1, &mapIter->second);
	}

	while (textureMap.size() > 0) {
		textureMap.erase(textureMap.begin());
	}
	
}

//User Interface
TextureID TextureManager::GetTexture(const string& textureName) {

	TextureMap::iterator mapIter = textureMap.find(textureName);
	if (mapIter == textureMap.end()) {
		return 0;
	}

	return mapIter->second;

}

bool TextureManager::CheckTextureExist(const string& textureName) const {

	return textureMap.count(textureName) != 0;

}

bool TextureManager::AddTexture(const string& textureName, const string& filePath) {

	if (CheckTextureExist(textureName)) {
		cout << "Unable to add texture: " << textureName << " as it already exist in the TextureManager.\n Please ensure that all textures have unique names." << endl;
		return false;
	}

	TextureID textureID = LoadTGA(filePath.c_str());
	textureMap.insert(pair<string, TextureID>(textureName, textureID));

	return true;

}

bool TextureManager::RemoveTexture(const string& textureName) {

	TextureMap::iterator mapIter = textureMap.find(textureName);
	if (mapIter == textureMap.end()) {
		cout << "Unable to remove texture: " << textureName << " as it doesn't exist in TextureManager." << endl;
		return false;
	}

	textureMap.erase(mapIter);

	return true;

}