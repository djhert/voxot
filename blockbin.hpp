#ifndef _BLOCKBIN_H_
#define _BLOCKBIN_H_
#include "block.hpp"
#include <map>
#include <memory>

namespace Voxot {
class BlockBin {
	using _bbin = std::map<int, Block *>;

public:
	static bool Register(int, Block *);

	static Block *Get(int);

private:
	static _bbin _blocks;
};
} // namespace Voxot

#endif
