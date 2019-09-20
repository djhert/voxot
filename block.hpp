#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "voxot.hpp"

using namespace godot;

namespace Voxot {

class Chunk;

class Block {
public:
	virtual bool isVisible();
	virtual bool isSolid();

	Block() = default;
	~Block() = default;
	virtual void Draw(Chunk *, PoolVector3Array *, int, int, int);

protected:
	virtual void FaceUp(PoolVector3Array *, int, int, int);
	virtual void FaceDown(PoolVector3Array *, int, int, int);
	virtual void FaceNorth(PoolVector3Array *, int, int, int);
	virtual void FaceSouth(PoolVector3Array *, int, int, int);
	virtual void FaceWest(PoolVector3Array *, int, int, int);
	virtual void FaceEast(PoolVector3Array *, int, int, int);
};
} // namespace Voxot

#endif