#include "Object.h"
#include "PlayerCharacter.h"

//#define BUTTON_UP 0
//#define BUTTON_DOWN 1

#include <vector>

using namespace std;

GLuint program;

Object triangle;
Object triangle1;

vector<Object> Particles;

board Boardobj;

float scaleVal;

Player controller;

unsigned char keyState[255];

void keyBoard(unsigned char key, int x, int y)
{
	keyState[key] = BUTTON_DOWN;
}

void keyBoard_Up(unsigned char key, int x, int y)
{
	keyState[key] = BUTTON_UP;
}

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

void init()
{
	glEnable(GL_DEPTH_TEST);

	ShaderLoader ShaderLoader;
	program = ShaderLoader.CreateProgram("Assets/Shaders/TriangleShader.vs", "Assets/Shaders/TriangleShader.fs");

	GLfloat vertices[] = {
		// Positions // Colors //texture coords
		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, // TLeft
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // TRight
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, //BRight
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, //Bleft
	};

	GLuint indices[] = {
		0, 1, 2, // First Triangle
		0, 2, 3 // Second Triangle
	};

	GLfloat vertices1[] = {
		//position //color
		0.5f, -0.5f, 0.0f, 1.0, 0.0, 0.0f,// Left
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,// Right
		0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f// Top
	};

	GLuint indices1[] = {
		0, 1, 2, // First Triangle
		0, 2, 3 // Second Triangle
	};
	int w = 0;
	for (int y = 0; y < 50; ++y)
	{
		for (int x = 0; x < 50; ++x)
		{
			++w;
			triangle.CreateObject(vertices, sizeof(vertices), indices, sizeof(indices), "Assets/Images/wall.jpg", program, x, y);
			Particles.push_back(triangle);
		}
	}
	for (int i = 0; i < Particles.size(); ++i)
	{
		cout << Particles[i].X << ", " << Particles[i].Y << endl;
	}
}

void render(void)
{
	GLfloat currentTime = glutGet(GLUT_ELAPSED_TIME);
	currentTime = currentTime / 1000;

	glUseProgram(program);
	GLint currentTimeLocation = glGetUniformLocation(program, "currentTime");
	glUniform1f(currentTimeLocation, currentTime);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 1.0); //red

	for (int y = 0; y < 50; ++y)
	{
		for (int x = 0; x < 50; ++x)
		{
			Particles[50 * y + x].RenderObject(program);
		}
	}

	glutSwapBuffers();
}

void update()
{
	glutPostRedisplay();

	glutKeyboardFunc(keyBoard);
	glutKeyboardUpFunc(keyBoard_Up);


	glm::mat4 view;

	GLfloat currentFrame = 0;
	GLfloat previousFrame;
	GLfloat deltaTime;

	GLfloat cameraSpeed = 0.5;
	GLfloat speed;

	previousFrame = currentFrame;

	currentFrame = glutGet(GLUT_ELAPSED_TIME);
	currentFrame = currentFrame / 1000;

	deltaTime = currentFrame = previousFrame;

	speed = cameraSpeed * deltaTime;

	if (keyState[(unsigned char)'w'] == BUTTON_DOWN)
	{
		cameraPos += cameraFront * speed;
	}
	if (keyState[(unsigned char)'s'] == BUTTON_DOWN)
	{
		cameraPos -= cameraFront * speed;
	}
	if (keyState[(unsigned char)'a'] == BUTTON_DOWN)
	{
		cameraPos += cameraFront * speed;
	}
	if (keyState[(unsigned char)'d'] == BUTTON_DOWN)
	{
		cameraPos += cameraFront * speed;
	}

	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(700, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Minesweeper");

	glewInit();
	init();

	glutDisplayFunc(render);
	glutIdleFunc(update);
	glutMainLoop();

	return(0);
}