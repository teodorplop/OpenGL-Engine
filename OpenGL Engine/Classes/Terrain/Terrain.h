#pragma once

#include "../RawModel.h"
#include "../Texture.h"
#include "../Utils/Math/Matrix4.h"

class Terrain {
private:
	static float size;
	static int cells;

	Matrix4 worldMatrix;
	RawModel* model;
	Texture* texture;

	void GenerateModel();

public:
	Terrain(int gridX, int gridZ, Texture* texture);
	~Terrain();

	const Matrix4& GetWorldMatrix() const;
	RawModel* GetModel();
	Texture* GetTexture();
};