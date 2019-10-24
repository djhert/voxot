#ifndef _VOXOT_H_
#define _VOXOT_H_

#include <atomic>
#include <cmath>
#include <string>
#include <thread>

#include <gdutil/gdnativedef.hpp>
#include <gdutil/gdnregistry.hpp>

#include <ArrayMesh.hpp>
#include <CollisionShape.hpp>
#include <ConcavePolygonShape.hpp>
#include <Dictionary.hpp>
#include <Godot.hpp>
#include <Mesh.hpp>
#include <MeshInstance.hpp>
#include <Node.hpp>
#include <PackedScene.hpp>
#include <PoolArrays.hpp>
#include <Resource.hpp>
#include <ResourceLoader.hpp>
#include <SceneTree.hpp>
#include <Spatial.hpp>
#include <SpatialMaterial.hpp>
#include <StaticBody.hpp>

namespace Voxot {
enum Direction {
	Up = 0,
	Down = 1,
	North = 2,
	South = 3,
	West = 4,
	East = 5
};

struct UVTile {
	int X;
	int Y;
};
} // namespace Voxot
#endif