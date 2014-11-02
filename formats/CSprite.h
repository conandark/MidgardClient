#ifndef _CSPRITE_H
#define _CSPRITE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "../common/FileStream.h"

class CSprite///Handler for SPR files
{
    public:
        CSprite(FileStream &stream, sf::Color* pPalette = 0);
        virtual ~CSprite();

        sf::Texture* GetTexture(uint16_t wIndex);
        uint16_t GetTextureCount();
        bool IsValid();

    private:
        bool bValid;
        uint16_t wVersion;
        std::vector<sf::Texture*> vTextures;

        void fetchBmp(FileStream &flstream, sf::Image* pImage, sf::Color* pPalette);
        void fetchTga(FileStream &flstream, sf::Image* pImage);
};
#endif//_CSPRITE_H
