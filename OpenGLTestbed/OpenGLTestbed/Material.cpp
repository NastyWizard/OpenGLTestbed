#include "Material.h"

Material::Material()
{
	shader = nullptr;
}

Material::~Material()
{
	if (shader != nullptr) 
	{
		delete shader;
		shader = nullptr;
	}
}

void Material::SetShader(Shader* shdr)
{
	shader = shdr;
}

void Material::UseShader()
{
	if (shader != nullptr)shader->UseShader();
}

// UNIFORMS ---------------

void Material::UpdateGlobalUniforms()
{
	SetUniformFloat("time", (float)glfwGetTime());
}

void Material::SetUniformSampler2D(std::string loc, Texture* tex)
{
	SetUniformInt(loc, tex->GetTexture());
}

void Material::SetUniformInt(std::string loc, int n)
{
	int glLoc = glGetUniformLocation(shader->GetShader(), loc.c_str());
	glUniform1i(glLoc, n);
}

void Material::SetUniformFloat(std::string loc, float n)
{
	int glLoc = glGetUniformLocation(shader->GetShader(), loc.c_str());
	glUniform1f(glLoc, n);
}

void Material::SetUniformFloat2(std::string loc, float x, float y)
{
	int glLoc = glGetUniformLocation(shader->GetShader(), loc.c_str());
	glUniform2f(glLoc, x, y);
}

void Material::SetUniformFloat3(std::string loc, float x, float y, float z)
{
	int glLoc = glGetUniformLocation(shader->GetShader(), loc.c_str());
	glUniform3f(glLoc, x, y, z);
}

void Material::SetUniformFloat4(std::string loc, float x, float y, float z, float w)
{
	int glLoc = glGetUniformLocation(shader->GetShader(), loc.c_str());
	glUniform4f(glLoc, x, y, z, w);
}

void Material::SetUniformFloat2(std::string loc, vec2 v)
{
	int glLoc = glGetUniformLocation(shader->GetShader(), loc.c_str());
	glUniform2f(glLoc, v.x, v.y);
}

void Material::SetUniformFloat3(std::string loc, vec3 v)
{
	int glLoc = glGetUniformLocation(shader->GetShader(), loc.c_str());
	glUniform3f(glLoc, v.x, v.y, v.z);
}

void Material::SetUniformFloat4(std::string loc, vec4 v)
{
	int glLoc = glGetUniformLocation(shader->GetShader(), loc.c_str());
	glUniform4f(glLoc, v.x, v.y, v.z, v.w);
}
