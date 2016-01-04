#pragma once
#include "struct.h"
using namespace std;

// TODO
struct Voxel
{
	point3 origin;
	float edge_size;
	int potentiel;
};

class Octree
{
private:
	int depth;
	Octree *childrens;
	OctreeState state;
	
	point3* GetBounds(const Voxel &v);
	Voxel* Subdivise(const Voxel &v);
protected:
	Voxel voxel;
public:
	Octree();
	Octree(const point3& origin, const int size);
	~Octree();
	void Init(const Sphere& s);
};

