// Copyright 2023 Justus Zorn

#ifndef ANOMALY_RENDERER_SHADER_H
#define ANOMALY_RENDERER_SHADER_H

#include <string>

#include <glad/glad.h>

#include <Renderer/Window.h>

class Shader {
public:
	Shader(Window& window, const std::string& vertex, const std::string& fragment);
	Shader(const Shader&) = delete;
	~Shader();

	Shader& operator=(const Shader&) = delete;

	void use() const;

	GLint get_uniform_location(const char* name);
	void set(GLint location, float f);
	void set(GLint location, float x, float y);

private:
	GLuint program;
};

#endif
