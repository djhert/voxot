#ifndef _BLOCKBIN_H_
#define _BLOCKBIN_H_
#include "block.hpp"
#include "vblock.hpp"
#include <functional>
#include <map>
#include <memory>
#include <vector>

namespace Voxot {

class BlockBin {
	using _bbin = std::map<std::string, VBlock *>;
	using _bvec = std::map<std::string, std::function<VBlock *()> >;

public:
	static bool Register(std::string, std::function<VBlock *()>);

	static bool Init();

	static Block *Get(std::string);

private:
	static void add(std::string, VBlock *);
	static _bbin _blocks;
	static _bvec _storage;
};

} // namespace Voxot
#endif
