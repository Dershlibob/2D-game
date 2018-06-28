#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include <iostream>
#include <vector>

#include "ShaderLoader.h"
#include "Board.h"
#include "soil\SOIL.h"

using namespace std;


class Object
{
public:
	GLuint vbo, vao, ebo, texture;
	GLint width, height;

	glm::mat4 trans;

	float X = -0.5;
	float Y = 0.5;
	
	int w = 0;

	void CreateObject(GLfloat Array[], GLint ArraySize, GLuint Indices[], GLint IndicesSize, const char* TextureAdress, GLuint program, int x, int y);
	void RenderObject(GLuint& program);
	void UpdateObject(void);
};

#endif // _OBJECT_H_