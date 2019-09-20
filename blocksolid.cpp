#include "blocksolid.hpp"

namespace Voxot {
BlockSolid::BlockSolid() {}
BlockSolid::~BlockSolid() {}

bool BlockSolid::isVisible() {
	return true;
}

bool BlockSolid::isSolid() {
	return true;
}

void BlockSolid::FaceUp(PoolVector3Array *data, int x, int y, int z) {
	data->push_back(Vector3(x, y + 1, z + 1));
	data->push_back(Vector3(x, y + 1, z));
	data->push_back(Vector3(x + 1, y + 1, z + 1));

	data->push_back(Vector3(x, y + 1, z));
	data->push_back(Vector3(x + 1, y + 1, z));
	data->push_back(Vector3(x + 1, y + 1, z + 1));
}

void BlockSolid::FaceDown(PoolVector3Array *data, int x, int y, int z) {
	data->push_back(Vector3(x, y, z));
	data->push_back(Vector3(x + 1, y, z + 1));
	data->push_back(Vector3(x + 1, y, z));

	data->push_back(Vector3(x, y, z + 1));
	data->push_back(Vector3(x + 1, y, z + 1));
	data->push_back(Vector3(x, y, z));
}

void BlockSolid::FaceNorth(PoolVector3Array *data, int x, int y, int z) {
	data->push_back(Vector3(x, y + 1, z + 1));
	data->push_back(Vector3(x + 1, y, z + 1));
	data->push_back(Vector3(x, y, z + 1));

	data->push_back(Vector3(x, y + 1, z + 1));
	data->push_back(Vector3(x + 1, y + 1, z + 1));
	data->push_back(Vector3(x + 1, y, z + 1));
}

void BlockSolid::FaceSouth(PoolVector3Array *data, int x, int y, int z) {
	data->push_back(Vector3(x + 1, y, z));
	data->push_back(Vector3(x + 1, y + 1, z));
	data->push_back(Vector3(x, y + 1, z));

	data->push_back(Vector3(x, y, z));
	data->push_back(Vector3(x + 1, y, z));
	data->push_back(Vector3(x, y + 1, z));
}

void BlockSolid::FaceWest(PoolVector3Array *data, int x, int y, int z) {
	data->push_back(Vector3(x + 1, y, z + 1));
	data->push_back(Vector3(x + 1, y + 1, z + 1));
	data->push_back(Vector3(x + 1, y + 1, z));

	data->push_back(Vector3(x + 1, y + 1, z));
	data->push_back(Vector3(x + 1, y, z));
	data->push_back(Vector3(x + 1, y, z + 1));
}

void BlockSolid::FaceEast(PoolVector3Array *data, int x, int y, int z) {
	data->push_back(Vector3(x, y, z));
	data->push_back(Vector3(x, y + 1, z));
	data->push_back(Vector3(x, y + 1, z + 1));

	data->push_back(Vector3(x, y, z + 1));
	data->push_back(Vector3(x, y, z));
	data->push_back(Vector3(x, y + 1, z + 1));
}
} // namespace Voxot