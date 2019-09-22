#ifndef _BLOCKAIR_H_
#define _BLOCKAIR_H_

#include "block.hpp"
#include "blockbin.hpp"
#include "voxot.hpp"
#include <memory>

using namespace godot;

namespace Voxot {
class Chunk;

class BlockAir : public Block {
public:
	bool isVisible() override;
	bool isSolid() override;

	BlockAir();
	~BlockAir();

	void Draw(Chunk *, PoolVector3Array *, int, int, int) override;

	static BlockAir *Create();

private:
	static bool registered;
};
} // namespace Voxot

#endif