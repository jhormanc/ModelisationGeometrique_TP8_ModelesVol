#include "Octree.h"]

Octree::Octree()
{
	childrens = new Octree[8];
}

Octree::Octree(const point3& origin, const int size)
{
	voxel.origin = origin;
	voxel.edge_size = size;
	childrens = new Octree[8];
}

Octree::~Octree()
{

}

void Octree::Init(const Sphere& s)
{
	
}

point3* Octree::GetBounds(const Voxel &v)
{
	float delta = v.edge_size * 0.5f;

	return new point3[8]
	{
		point3(v.origin.x + delta, v.origin.y + delta, v.origin.z + delta),
		point3(v.origin.x - delta, v.origin.y + delta, v.origin.z + delta),
		point3(v.origin.x + delta, v.origin.y - delta, v.origin.z + delta),
		point3(v.origin.x - delta, v.origin.y - delta, v.origin.z + delta),
		point3(v.origin.x + delta, v.origin.y + delta, v.origin.z - delta),
		point3(v.origin.x - delta, v.origin.y + delta, v.origin.z - delta),
		point3(v.origin.x + delta, v.origin.y - delta, v.origin.z - delta),
		point3(v.origin.x - delta, v.origin.y - delta, v.origin.z - delta)
	};
}

Voxel* Octree::Subdivise(const Voxel &v)
{
	float delta = v.edge_size * 0.25f;
	float size = 2.f * delta;

	return new Voxel[8]
	{ 
		Voxel { point3(v.origin.x + size, v.origin.y + size, v.origin.z + size), delta },
		Voxel { point3(v.origin.x - size, v.origin.y + size, v.origin.z + size), delta },
		Voxel { point3(v.origin.x + size, v.origin.y - size, v.origin.z + size), delta },
		Voxel { point3(v.origin.x - size, v.origin.y - size, v.origin.z + size), delta },
		Voxel { point3(v.origin.x + size, v.origin.y + size, v.origin.z - size), delta },
		Voxel { point3(v.origin.x - size, v.origin.y + size, v.origin.z - size), delta },
		Voxel { point3(v.origin.x + size, v.origin.y - size, v.origin.z - size), delta },
		Voxel { point3(v.origin.x - size, v.origin.y - size, v.origin.z - size), delta }
	};
}
