#ifndef GRAPHICS_MANAGER_H
#define GRAPHICS_MANAGER_H

#include "SingletonTemplate.h"
#include "ShaderProgram.h"
#include "MatrixStack.h"
#include <GL/glew.h>

typedef map<string, ShaderProgram*> ShaderMap;

class GraphicsManager : public Singleton<GraphicsManager> {

	friend class Singleton<GraphicsManager>;

private:
	//Variable(s)
	unsigned int vertexArrayID;
	ShaderMap shaderMap;
	ShaderProgram* activeShader;

	//Constructor(s) & Destructor
	GraphicsManager();
	virtual ~GraphicsManager();

	//Private Function(s)
	ShaderProgram* GetShader(const string& shaderName);
	bool ClearShaders();	

public:
	//Enum(s)
	enum class MODE {
		MODE_CULLING,
		MODE_BLENDING,
		MODE_WIREFRAME,
		MODE_DEPTH_TEST,
		//MODE_STENCIL_TEST,
	};

	//MVP
	MS modelStack, viewStack, projectionStack;

	//Shader
	bool HasShader(const string& shaderName) const;
	bool SetActiveShader(const string& shaderName);
	bool AddShader(const string& shaderName, const string& vertexShader, const string& fragmentShader);
	bool RemoveShader(const string& shaderName);
	ShaderProgram* GetActiveShader();

	//Others
	void Update();
	void SetBackgroundColor(float red, float green, float blue, float alpha);
	
	//Enable Modes
	template <MODE mode>
	void Enable() {
		throw std::exception("Unrecognisable Mode!");
	}

	template <>
	void Enable<MODE::MODE_CULLING>() {
		glEnable(GL_CULL_FACE);
	}

	template <>
	void Enable<MODE::MODE_BLENDING>() {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	template <>
	void Enable<MODE::MODE_WIREFRAME>() {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	template <>
	void Enable<MODE::MODE_DEPTH_TEST>() {
		glEnable(GL_DEPTH_TEST);
	}
	
	//Disable Modes
	template <MODE mode>
	void Disable() {
		throw std::exception("Unrecognisable Mode!");
	}

	template <>
	void Disable<MODE::MODE_CULLING>() {
		glDisable(GL_CULL_FACE);
	}

	template <>
	void Disable<MODE::MODE_BLENDING>() {
		glDisable(GL_BLEND);
	}

	template <>
	void Disable<MODE::MODE_WIREFRAME>() {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	template <>
	void Disable<MODE::MODE_DEPTH_TEST>() {
		glDisable(GL_DEPTH_TEST);
	}
		
};

#endif