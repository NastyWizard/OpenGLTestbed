#pragma once
#include "Shader.h"
#include <glad\glad.h>
#include <GLFW\glfw3.h>


Shader* testShader;

void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
void ProcessInput(GLFWwindow *window);
void Init();
void Update();
void RenderScreen();
void ClearScreen();
//class Main 
//{
//};