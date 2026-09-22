#pragma once

#include <Spore\Object.h>
#include <Spore\RenderWare\RenderStats.h>

namespace RenderWare
{
	class ILayer
		: public IRefCount
	{
	public:
		virtual ~ILayer();

		// viewer = const cViewer* const*.
		virtual void DrawLayer(uint32_t flags, uint32_t layerNumber, const void* const* viewer, RenderStats* stats) = 0;
	};
	ASSERT_SIZE(ILayer, 0x4);
}
