#ifndef _BLOCKSOLID_H_
#define _BLOCKSOLID_H_

#include "block.hpp"
#include "blockbin.hpp"
#include "voxot.hpp"

using namespace godot;

namespace Voxot {

class BlockSolid : public Block {
public:
	bool isVisible() override;
	bool isSolid() override;

	BlockSolid();
	~BlockSolid();

protected:
	void FaceUp(PoolVector3Array *, int, int, int) override;
	void FaceDown(PoolVector3Array *, int, int, int) override;
	void FaceNorth(PoolVector3Array *, int, int, int) override;
	void FaceSouth(PoolVector3Array *, int, int, int) override;
	void FaceWest(PoolVector3Array *, int, int, int) override;
	void FaceEast(PoolVector3Array *, int, int, int) override;

private:
	static bool registered;
};
} // namespace Voxot

#endif