#pragma once

#include "../Vulkan/Application.h"

namespace Tracer
{
	class RayTracer : public Vulkan::Application
	{
	public:
		RayTracer();
		~RayTracer();
		
	private:
		void Render(VkFramebuffer framebuffer, VkCommandBuffer commandBuffer) override;
		std::unique_ptr<class Menu> menu;
	};
}