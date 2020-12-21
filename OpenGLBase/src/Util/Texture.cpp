#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <glad/glad.h>


namespace OpenGLBase
{
	Texture::Texture(const std::string &filepath)
	{
		stbi_set_flip_vertically_on_load(1);
		unsigned char *data;
		int width, height, bpp;

		data = stbi_load(filepath.c_str(), &width, &height, &bpp, STBI_rgb_alpha);

		m_Width = static_cast<uint32_t>(width);
		m_Height = static_cast<uint32_t>(height);

		glCreateTextures(GL_TEXTURE_2D, 1, &m_TextureID);
		glTextureStorage2D(m_TextureID, 1, GL_RGBA8, m_Width, m_Height);

		glTextureParameteri(m_TextureID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_TextureID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTextureParameteri(m_TextureID, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTextureParameteri(m_TextureID, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTextureSubImage2D(m_TextureID, 0, 0, 0, m_Width, m_Height, GL_RGBA, GL_UNSIGNED_BYTE, data);

		if (data)
			stbi_image_free(data);
		else
			std::cout << "Failed to load Texture: " << filepath << std::endl;
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &m_TextureID);
	}

	void Texture::Bind(uint32_t slot) const
	{
		glBindTextureUnit(slot, m_TextureID);
	}

	void Texture::UnBind(uint32_t slot) const
	{
		glBindTextureUnit(slot, m_TextureID);
	}
}