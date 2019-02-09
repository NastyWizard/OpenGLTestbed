#pragma once
#include <vector>

class MeshPrimitives 
{

public:
	static void Create2DRect(float width, float height, std::vector<float> &vertArray, std::vector<unsigned int> &indexArray, std::vector<float> &uvArray, std::vector<float> &normalArray);
	static void CreateBox(float width, float height, float length, std::vector<float> &vertArray, std::vector<unsigned int> &indexArray, std::vector<float> &uvArray, std::vector<float> &normalArray);

};