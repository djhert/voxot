#include "block.hpp"

namespace Voxot {

bool Block::isSolid() {
	return false;
}

bool Block::isVisible() {
	return false;
}

void Block::Draw(Chunk *chunk, PoolVector3Array *data, int x, int y, int z) {
	FaceNorth(data, x, y, z);
	FaceSouth(data, x, y, z);
	FaceUp(data, x, y, z);
	FaceDown(data, x, y, z);
	FaceWest(data, x, y, z);
	FaceEast(data, x, y, z);
}

void Block::FaceUp(PoolVector3Array *data, int x, int y, int z) {
}

void Block::FaceDown(PoolVector3Array *data, int x, int y, int z) {
}

void Block::FaceNorth(PoolVector3Array *data, int x, int y, int z) {
}

void Block::FaceSouth(PoolVector3Array *data, int x, int y, int z) {
}

void Block::FaceWest(PoolVector3Array *data, int x, int y, int z) {
}

void Block::FaceEast(PoolVector3Array *data, int x, int y, int z) {
}
} // namespace Voxot