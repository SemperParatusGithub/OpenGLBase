#pragma once

#include <iostream>
#include <assert.h>

#include <glad/glad.h>


namespace OpenGLBase
{
	class Framebuffer
	{
	public:
		Framebuffer(uint32_t width, uint32_t height);
		~Framebuffer();

		void Invalidate();

		void Bind();
		void Unbind();

		inline uint32_t GetColorAttachmentRendererID() const { return m_ColorAttachment; }

	private:
		uint32_t m_RendererID = 0;
		uint32_t m_Width, m_Height;
		uint32_t m_ColorAttachment = 0, m_DepthAttachment = 0;
	};
}