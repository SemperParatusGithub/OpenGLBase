#pragma once
#include <iostream>


class Texture
{
public:
	Texture(const std::string &filepath);
	~Texture();

	unsigned int GetID() const;

	void Bind(uint32_t slot = 0) const;
	void UnBind() const;

private:

	unsigned int m_TextureID;
	unsigned char *m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
};