#ifndef _VBLOCK_H_
#define _VBLOCK_H_

namespace Voxot {
class VBlock {
public:
	virtual bool isVisible();
	virtual bool isSolid();
};
} // namespace Voxot

#endif