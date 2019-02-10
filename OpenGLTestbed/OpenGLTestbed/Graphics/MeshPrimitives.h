#pragma once
#include "../Math/VectorMath.h"
#include <vector>

class MeshPrimitives 
{

private:
	struct VertexData 
	{
		vec3 pos, norm;
		vec2 uv;
	};

public:
	static void Create2DRect(float width, float height, std::vector<float> &vertArray, std::vector<unsigned int> &indexArray, std::vector<float> &uvArray, std::vector<float> &normalArray);
	static void CreateBox(float width, float height, float length, std::vector<float> &vertArray, std::vector<unsigned int> &indexArray, std::vector<float> &uvArray, std::vector<float> &normalArray);

};