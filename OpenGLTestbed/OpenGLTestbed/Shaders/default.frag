#version 330 core
out vec4 FragColor;
varying vec3 vPos;

void main()
{
	FragColor =  vec4(vPos, 1.0f);
}