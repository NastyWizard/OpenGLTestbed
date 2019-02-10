#include "MeshPrimitives.h"

void MeshPrimitives::Create2DRect(float width, float height, std::vector<float> &vertArray, std::vector<unsigned int> &indexArray, std::vector<float> &uvArray, std::vector<float> &normalArray)
{
	//  x					y			 z
	float vertices[] =
	{
		width / 2.0f,		height / 2.0f,	.0f, // top right
		width / 2.0f,	-height / 2.0f,	.0f, // bottom right
		-width / 2.0f,	-height / 2.0f,	.0f, // bottom left
		-width / 2.0f,	height / 2.0f,	.0f// top left
	};

	float uvs[] =
	{
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f
	};

	float normals[] =
	{
		0.0f,	0.0f,	-1.0f,
		0.0f,	0.0f,	-1.0f,
		0.0f,	0.0f,	-1.0f,
		0.0f,	0.0f,	-1.0f,
	};

	unsigned int indices[] =
	{
		0,1,3,
		1,2,3
	};

	vertArray.clear();
	indexArray.clear();
	uvArray.clear();
	normalArray.clear();

	for (int i = 0; i < 12; i++)
	{
		vertArray.push_back(vertices[i]);
		normalArray.push_back(normals[i]);
	}


	for (int i = 0; i < 8; i++)
		uvArray.push_back(uvs[i]);

	for (int i = 0; i < 6; i++)
		indexArray.push_back(indices[i]);

}

void MeshPrimitives::CreateBox(float width, float height, float length, std::vector<float>& vertArray, std::vector<unsigned int>& indexArray, std::vector<float>& uvArray, std::vector<float>& normalArray)
{
	const int numVerts = 24;
	const int numIndices = 36;

	VertexData vertices[numVerts];
	int indices[numIndices];

	float xMin = -width / 2.0f, xMax = width / 2.0f;
	float yMin = -height / 2.0f, yMax = height / 2.0f;
	float zMin = -length / 2.0f, zMax = length / 2.0f;

	//front
	int side = 0;
	vertices[0].pos.x = xMin; vertices[0].pos.y = yMax; vertices[0].pos.z = zMax; vertices[0].uv.x = 0; vertices[0].uv.y = 1;
	vertices[1].pos.x = xMax; vertices[1].pos.y = yMax; vertices[1].pos.z = zMax; vertices[1].uv.x = 1; vertices[1].uv.y = 1;
	vertices[2].pos.x = xMin; vertices[2].pos.y = yMin; vertices[2].pos.z = zMax; vertices[2].uv.x = 0; vertices[2].uv.y = 0;
	vertices[3].pos.x = xMax; vertices[3].pos.y = yMin; vertices[3].pos.z = zMax; vertices[3].uv.x = 1; vertices[3].uv.y = 0;
	for (int i = 0; i < 4; i++)
		vertices[4 * side + i].norm.Set(0, 0, 1);

	//back
	side = 1;
	vertices[4 * side + 0] = vertices[1]; vertices[4 * side + 0].pos.z = zMin;	vertices[4 * side + 0].uv = vertices[0].uv;
	vertices[4 * side + 1] = vertices[0]; vertices[4 * side + 1].pos.z = zMin; vertices[4 * side + 1].uv = vertices[1].uv;
	vertices[4 * side + 2] = vertices[3]; vertices[4 * side + 2].pos.z = zMin; vertices[4 * side + 2].uv = vertices[2].uv;
	vertices[4 * side + 3] = vertices[2]; vertices[4 * side + 3].pos.z = zMin; vertices[4 * side + 3].uv = vertices[3].uv;
	for (int i = 0; i < 4; i++)
		vertices[4 * side + i].norm.Set(0, 0, -1);

	//right
	side = 2;
	vertices[4 * side + 0] = vertices[1]; vertices[4 * side + 0].uv = vertices[0].uv;
	vertices[4 * side + 1] = vertices[4]; vertices[4 * side + 1].uv = vertices[1].uv;
	vertices[4 * side + 2] = vertices[3]; vertices[4 * side + 2].uv = vertices[2].uv;
	vertices[4 * side + 3] = vertices[6]; vertices[4 * side + 3].uv = vertices[3].uv;
	for (int i = 0; i < 4; i++)
		vertices[4 * side + i].norm.Set(1, 0, 0);

	//left
	side = 3;
	vertices[4 * side + 0] = vertices[5]; vertices[4 * side + 0].uv = vertices[0].uv;
	vertices[4 * side + 1] = vertices[0]; vertices[4 * side + 1].uv = vertices[1].uv;
	vertices[4 * side + 2] = vertices[7]; vertices[4 * side + 2].uv = vertices[2].uv;
	vertices[4 * side + 3] = vertices[2]; vertices[4 * side + 3].uv = vertices[3].uv;
	for (int i = 0; i < 4; i++)
		vertices[4 * side + i].norm.Set(-1, 0, 0);

	//bottom
	side = 4;
	vertices[4 * side + 0] = vertices[2]; vertices[4 * side + 0].uv = vertices[0].uv;
	vertices[4 * side + 1] = vertices[3]; vertices[4 * side + 1].uv = vertices[1].uv;
	vertices[4 * side + 2] = vertices[7]; vertices[4 * side + 2].uv = vertices[2].uv;
	vertices[4 * side + 3] = vertices[6]; vertices[4 * side + 3].uv = vertices[3].uv;
	for (int i = 0; i < 4; i++)
		vertices[4 * side + i].norm.Set(0, -1, 0);

	//bottom
	side = 5;
	vertices[4 * side + 0] = vertices[5]; vertices[4 * side + 0].uv = vertices[0].uv;
	vertices[4 * side + 1] = vertices[4]; vertices[4 * side + 1].uv = vertices[1].uv;
	vertices[4 * side + 2] = vertices[0]; vertices[4 * side + 2].uv = vertices[2].uv;
	vertices[4 * side + 3] = vertices[1]; vertices[4 * side + 3].uv = vertices[3].uv;
	for (int i = 0; i < 4; i++)
		vertices[4 * side + i].norm.Set(0, 1, 0);

	for (side = 0; side < 6; side++) 
	{
		indices[6 * side + 0] = 4 * side + 0;
		indices[6 * side + 1] = 4 * side + 2;
		indices[6 * side + 2] = 4 * side + 1;
		indices[6 * side + 3] = 4 * side + 1;
		indices[6 * side + 4] = 4 * side + 2;
		indices[6 * side + 5] = 4 * side + 3;
	}

	for (int i = 0; i < numIndices; i++) 
	{
		if (i < numVerts) 
		{
			vertArray.push_back(vertices[i].pos.x);
			vertArray.push_back(vertices[i].pos.y);
			vertArray.push_back(vertices[i].pos.z);

			uvArray.push_back(vertices[i].uv.x);
			uvArray.push_back(vertices[i].uv.y);

			normalArray.push_back(vertices[i].norm.x);
			normalArray.push_back(vertices[i].norm.y);
			normalArray.push_back(vertices[i].norm.z);
		}

		indexArray.push_back(indices[i]);

	}

}
