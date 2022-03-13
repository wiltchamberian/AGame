#pragma once
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Graphics/RenderWindow.hpp"

class Background
{
public:
	/**
	 * @brief ���ļ��м�������
	 * @param textureFile �����ļ�·��
	*/
	Background(const std::string & textureFile);

	/**
	 * @brief ���ļ��м����������Դ�����ȡ����ָ����������Ĵ�С
	 * @param textureFile �����ļ�·��
	 * @param originX ���ý�ȡ���ε�X����
	 * @param originY ���ý�ȡ���ε�Y����
	 * @param width ���ý�ȡ�Ŀ��
	 * @param height ���ý�ȡ�ĸ߶�
	*/
	Background(const std::string & textureFile,int originX,int originY,int width,int height);

	/**
	 * @brief 
	 * @param image ��ͼƬ���м�������
	*/
	Background(const sf::Image & image);  //��image�м�������
	/**
	 * @brief ���Ʊ�������
	 * @param mainWindow ������ָ��
	*/
	void draw(sf::RenderWindow* mainWindow);

	/**
	 * @brief ���Ʊ�������
	 * @param mainWindow ������ָ��
	 * @param repeatX ������X�������ظ��Ĵ���
	 * @param repeatY ������Y�������ظ��Ĵ���
	*/
	void draw(sf::RenderWindow* mainWindow,int repeatX,int repeatY);

	/**
	 * @brief ���ñ����ɼ���
	 * @param isVisible �Ƿ�ɼ�
	*/
	void SetVisible(bool isVisible);

	/**
	 * @brief ���±���
	*/
	void Update();

	~Background();
	Background(const Background&) = delete;  
	Background & operator=(const Background&) = delete;
private:
	sf::Texture m_backgroundTexture;  //��������
	bool m_isVisible = false;
};
