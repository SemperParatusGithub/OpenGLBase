#pragma once
#include <iostream>


namespace OpenGLBase
{
	class Texture
	{
	public:
		Texture(const std::string &filepath);
		~Texture();

		inline uint32_t GetID() const { return m_TextureID; }

		inline uint32_t GetWidth() const { return m_Width; }
		inline uint32_t GetHeight() const { return m_Height; }

		void Bind(uint32_t slot = 0) const;
		void UnBind(uint32_t slot = 0) const;

	private:
		uint32_t m_Width, m_Height;
		uint32_t m_TextureID;
	};
}