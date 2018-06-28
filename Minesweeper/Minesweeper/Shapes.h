#ifndef _SHAPES_H_
#define _SHAPES_H_

class Shapes
{
public:
	enum ShapeEnum
	{
		SQUARE,
		TRIANGLE
	};

	GLfloat SquareVert[32] = {
		// Positions // Colors //texture coords
		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, // TLeft
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // TRight
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, //BRight
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, //Bleft
	};

	GLuint SquareInd[6] = {
		0, 1, 2, // First Triangle
		0, 2, 3 // Second Triangle
	};

	GLfloat TriangleVert[18] = {
		0.5f, -0.5f, 0.0f, 1.0, 0.0, 0.0f,// Left
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,// Right
		0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f// Top
	};

	GLuint TriangleInd[6] = {

		0, 1, 2, // First Triangle
		0, 2, 3 // Second Triangle
	};
};


#endif // !_SHAPES_H_