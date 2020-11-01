#pragma once
#include <string>
#include <unordered_map>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#ifndef SHADER_H
#define SHADER_H

//  Basic shader class for OpenGL Shaders
// USAGE: 
//	Shader shader(Shader::LoadFromGLSLFiles("res/shaders/Basic.vert.glsl", "res/shaders/Basic.frag.glsl"));
//  shader->Bind();
//	shader->SetUniformMat4("u_Uniform", glm::mat4(1));
//	shader->UnBind();


namespace OpenGLBase
{
	struct ShaderSource
	{
		std::string vertexSource;
		std::string fragmentSource;
	};

	class Shader
	{
	public:
		Shader(const ShaderSource &source);
		~Shader();

		void Bind() const;
		void UnBind() const;
		inline GLuint GetID() const { return m_ShaderID; }

		void SetUniform1i(const std::string &name, int value);
		void SetUniform1f(const std::string &name, float value);
		void SetUniform1d(const std::string &name, double value);

		void SetUniform2i(const std::string &name, int v1, int v2);
		void SetUniform2f(const std::string &name, float v1, float v2);
		void SetUniform2d(const std::string &name, double v1, double v2);

		void SetUniform3f(const std::string &name, float v1, float v2, float v3);

		void SetUniform4i(const std::string &name, int v0, int v1, int v2, int v3);
		void SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3);
		void SetUniform4d(const std::string &name, double v0, double v1, double v2, double v3);

		void SetUniformMat2f(const std::string &name, const glm::mat2 &matrix);
		void SetUniformMat3f(const std::string &name, const glm::mat3 &matrix);
		void SetUniformMat4f(const std::string &name, const glm::mat4 &matrix);

		static ShaderSource LoadFromGLSLFile(std::string filepath);
		static ShaderSource LoadFromGLSLFiles(std::string vertexPath, std::string fragmentPath);

	private:
		GLuint CreateShader(const std::string &vertexShader, const std::string &fragmentShader);
		GLuint CompileShader(GLenum type, const std::string &source);
		GLint GetUniformLocation(const std::string &name) const;

	private:
		GLuint m_ShaderID;
		mutable std::unordered_map<std::string, int> m_UniformLocationCache;
	};
}
#endif // SHADER_H