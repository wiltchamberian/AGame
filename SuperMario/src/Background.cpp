#include "Background.h"
#include <SFML/Graphics/RectangleShape.hpp>

Background::Background(const std::string& textureFile)
{
	m_backgroundTexture.loadFromFile(textureFile);
}

Background::Background(const std::string& textureFile, int originX, int originY, int width, int height)
{
	m_backgroundTexture.loadFromFile(textureFile,sf::IntRect(originX,originY,width,height));
}

Background::Background(const sf::Image& image)
{
	m_backgroundTexture.loadFromImage(image);
}

Background::~Background()
{

}

void Background::draw(sf::RenderWindow* mainWindow)
{
	_ASSERT_EXPR(mainWindow != nullptr,"main window cant be null");
	sf::Vector2u textureSize = m_backgroundTexture.getSize();
	float rectWidth = static_cast<float>(textureSize.x);
	float rectHeight = static_cast<float>(textureSize.y);
	sf::RectangleShape textureShape(sf::Vector2f(rectWidth, rectHeight));
	textureShape.setTexture(&m_backgroundTexture);
	if(m_isVisible)
		mainWindow->draw(textureShape);
}

void Background::draw(sf::RenderWindow* mainWindow, int repeatX, int repeatY)
{
	_ASSERT_EXPR(mainWindow != nullptr, "main window cant be null");
	m_backgroundTexture.setRepeated(true);
	sf::Vector2u textureSize = m_backgroundTexture.getSize();
	float rectWidth = static_cast<float>(textureSize.x);
	float rectHeight = static_cast<float>(textureSize.y);
	sf::RectangleShape textureShape(sf::Vector2f(rectWidth * repeatX, rectHeight * repeatY));
	textureShape.setTextureRect(sf::IntRect(0,0,rectWidth * repeatX,rectHeight * repeatY));
	textureShape.setTexture(&m_backgroundTexture);
	if (m_isVisible)
		mainWindow->draw(textureShape);

}

void Background::SetVisible(bool isVisible)
{
	m_isVisible = isVisible;
}

void Background::Update()
{

}

