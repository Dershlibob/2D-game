#include "Object.h"

void Object::CreateObject(GLfloat Array[], GLint ArraySize, GLuint Indices[], GLint IndicesSize, const char* TextureAdress, GLuint program, int x, int y)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, ArraySize, Array, GL_STATIC_DRAW);

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, IndicesSize, Indices, GL_STATIC_DRAW);


	glGenTextures(1, &texture);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glVertexAttribPointer(
		0,	// layout location on vertex shader.
		3,	// vertices
		GL_FLOAT,	// type of data
		GL_FALSE,	// is data Normalized?
		8 * sizeof(GLfloat),	// Stride
		(GLvoid*)0);	// offset
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(
		1,
		3,
		GL_FLOAT, GL_FALSE,
		8 * sizeof(GLfloat),
		(GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(
		2,
		2,
		GL_FLOAT,
		GL_FALSE,
		8 * sizeof(GLfloat),
		(GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	unsigned char* image = SOIL_load_image("Assets/Images/Block.png", &width, &height, 0, SOIL_LOAD_RGBA);
	 

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

}

void Object::RenderObject(GLuint& program)
{
	glm::vec4 vec(1.0f, 1.0f, 1.0f, 1.0f);
	glm::mat4 translation;
	translation = glm::translate(translation, glm::vec3(X, Y, 0.0f));
	vec = translation * vec;
	translation = glm::rotate(translation, glm::radians(180.0f), glm::vec3(0.0, 0.0, 1.0));
	translation = glm::scale(translation, glm::vec3(0.05f, 0.05f, 0.05f));
	
	GLuint transformLoc = glGetUniformLocation(program, "transform");
	GLint projLoc = glGetUniformLocation(program, "projection");
	GLint modelLoc = glGetUniformLocation(program, "model");
	GLint viewLoc = glGetUniformLocation(program, "view");

	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(translation));

	glBindVertexArray(vao);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1i(glGetUniformLocation(program, "texture"), 0);


	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Object::UpdateObject()
{

}