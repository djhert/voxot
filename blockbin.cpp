#include "blockbin.hpp"

namespace Voxot {

BlockBin::_bbin BlockBin::_blocks = [] {
	_bbin ret;
	return ret;
}();

bool BlockBin::Register(int key, Block *block) {
	if (auto it = _blocks.find(key); it == _blocks.end()) {
		_blocks[key] = block;
		return true;
	}
	return false;
}

Block *BlockBin::Get(int key) {
	if (auto it = _blocks.find(key); it != _blocks.end()) {
		return _blocks[key];
	}
	return NULL;
}
} // namespace Voxot