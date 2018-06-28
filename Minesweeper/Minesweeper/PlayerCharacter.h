#ifndef __PLAYER_CHARACTER__
#define __PLAYER_CHARACTER__

#include "Object.h"
#include "Shapes.h"

#define BUTTON_UP 0
#define BUTTON_DOWN 1

class Player
{
	void Init();
	ShaderLoader ShaderLoad;
	Shapes PlayerShape;
	GLfloat program; //ShaderLoad.CreateProgram("Assets/Shaders/TriangleShader.vs", "Assets/Shaders/TriangleShader.fs");
	
	Object PlayerController;

public:
	void Update();

	unsigned char keyState[255];
};
#endif // __PLAYER_CHARACTER__
