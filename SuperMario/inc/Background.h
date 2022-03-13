#pragma once
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Graphics/RenderWindow.hpp"

class Background
{
public:
	/**
	 * @brief 从文件中加载纹理
	 * @param textureFile 纹理文件路径
	*/
	Background(const std::string & textureFile);

	/**
	 * @brief 从文件中加载纹理，可以创建截取矩形指定加载纹理的大小
	 * @param textureFile 纹理文件路径
	 * @param originX 设置截取矩形的X坐标
	 * @param originY 设置截取矩形的Y坐标
	 * @param width 设置截取的宽度
	 * @param height 设置截取的高度
	*/
	Background(const std::string & textureFile,int originX,int originY,int width,int height);

	/**
	 * @brief 
	 * @param image 从图片流中加载纹理
	*/
	Background(const sf::Image & image);  //从image中加载纹理
	/**
	 * @brief 绘制背景纹理
	 * @param mainWindow 主窗口指针
	*/
	void draw(sf::RenderWindow* mainWindow);

	/**
	 * @brief 绘制背景纹理
	 * @param mainWindow 主窗口指针
	 * @param repeatX 纹理在X方向上重复的次数
	 * @param repeatY 纹理在Y方向上重复的次数
	*/
	void draw(sf::RenderWindow* mainWindow,int repeatX,int repeatY);

	/**
	 * @brief 设置背景可见性
	 * @param isVisible 是否可见
	*/
	void SetVisible(bool isVisible);

	/**
	 * @brief 更新背景
	*/
	void Update();

	~Background();
	Background(const Background&) = delete;  
	Background & operator=(const Background&) = delete;
private:
	sf::Texture m_backgroundTexture;  //背景纹理
	bool m_isVisible = false;
};
