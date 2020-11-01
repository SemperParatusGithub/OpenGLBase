#pragma once

#include <iostream>

#ifndef TEXTURE_H
#define TEXTURE_H

class Texture
{
public:
	Texture(const std::string &filepath);
	~Texture();

	unsigned int GetID() const;

	void Bind(uint32_t slot = 0) const;
	void UnBind();

private:

	unsigned int m_TextureID;
	unsigned char *m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
};

#endif // TEXTURE_H