#pragma once

#include "Vulkan.h"

#include <memory>
#include <vector>

namespace Vulkan
{
	class Application
	{
	public:
		NON_COPIABLE(Application)

		explicit Application();
		virtual ~Application();

		virtual void Run() = 0;

	protected:
		void DrawFrame();
		void CreatePhysicalDevice();
		void CreateGraphicsPipeline();
		void CreateInstance();
		void QueueSubmit(VkCommandBuffer commandBuffer);
		void Present(uint32_t imageIndex);
		virtual void UpdateUniformBuffer(uint32_t imageIndex) = 0;

		virtual void Render(VkFramebuffer framebuffer, VkCommandBuffer commandBuffer, uint32_t imageIndex) = 0;
		virtual void OnKeyChanged(int key, int scancode, int action, int mods) = 0;
		virtual void OnCursorPositionChanged(double xpos, double ypos) = 0;
		virtual void OnMouseButtonChanged(int button, int action, int mods) = 0;
		virtual void OnScrollChanged(double xoffset, double yoffset) = 0;

		size_t currentFrame{};

		std::unique_ptr<class Window> window;
		std::unique_ptr<class Instance> instance;
		std::unique_ptr<class Device> device;
		std::unique_ptr<class Surface> surface;
		std::unique_ptr<class SwapChain> swapChain;
		std::unique_ptr<class GraphicsPipeline> graphicsPipeline;
		std::unique_ptr<class CommandBuffers> commandBuffers;
		std::unique_ptr<class DescriptorsManager> descriptorsManager;

		// Per image in swap chain specific components
		std::vector<std::unique_ptr<class Framebuffer>> swapChainFrameBuffers;
		std::vector<std::unique_ptr<class Buffer>> uniformBuffers;
		std::vector<std::unique_ptr<class Semaphore>> imageAvailableSemaphores;
		std::vector<std::unique_ptr<class Semaphore>> renderFinishedSemaphores;
		std::vector<std::unique_ptr<class Fence>> inFlightFences;
	};
}
