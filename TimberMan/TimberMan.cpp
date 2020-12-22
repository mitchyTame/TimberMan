// TimberMan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
  //Include imported Libraries
#include <iostream>
#include<sstream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	VideoMode vm(960, 540);

	// Create and open a window for the game
	// RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

	// Low res code
	RenderWindow window(vm, "Timber!!!");
	View view(sf::FloatRect(0, 0, 1920, 1080));
	window.setView(view);



	//Create a background texture
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png");

	//attach a texture to a sprite
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);

	//Create a tree texture
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);

	//Prepare the  Bee
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	bool beeActive = false;
	float beeSpeed = 0.0f;

	//Prepare the clouds
	Texture textureCloud;
	textureCloud.loadFromFile("graphics/cloud.png");
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;

	Sprite spriteCloud1;
	Sprite spriteCloud2;
	Sprite spriteCloud3;

	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);

	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;

	//Timing
	Clock clock;

	//Pausing
	bool paused = true;


	//HUD
	String levelName;
	String playerName;
	Text messageText;
	Text scoreText;
	Font font;

	//Loads
	font.loadFromFile("fonts/KOMIKAP.tff");

	//Set Strings
	messageText.setFont(font);
	scoreText.setFont(font);
	messageText.setString("Press enter to start");
	scoreText.setString("Score = 0");

	messageText.setCharacterSize(75);
	scoreText.setCharacterSize(100);

	messageText.setFillColor(Color::White);
	scoreText.setFillColor(Color::Red);




	while (window.isOpen())
	{
		/*
		* Handle players input
		*/
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			paused == true ? paused = false : paused = true;
		}
		Time dt = clock.restart();
		if (!paused)
		{
			if (!beeActive)
			{
				//Bee Speed
				srand((int)time(0) * 10);
				beeSpeed = (rand() % 200) + 200;
				srand((int)time(0) * 10);
				float height = (rand() % 300) + 500;
				spriteBee.setPosition(2000, height);
				beeActive = true;
			}
			else {
				spriteBee.setPosition(
					spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()),
					spriteBee.getPosition().y);

				if (spriteBee.getPosition().x < -100)
				{
					beeActive = false;
				}
			}

			//Clouds
			if (!cloud1Active)
			{
				srand((int)time(0) * 10);
				cloud1Speed = (rand() % 200);
				srand((int)time(0) * 10);
				float height = (rand() % 150) - 150;
				spriteCloud1.setPosition(-200, height);
				cloud1Active = true;
			}
			else {
				spriteCloud1.setPosition(
					spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()),
					spriteCloud1.getPosition().y);
				if (spriteCloud1.getPosition().x > 1920)
				{
					cloud1Active = false;
				}
			}

			if (!cloud2Active)
			{
				srand((int)time(0) * 20);
				cloud2Speed = (rand() % 200);
				srand((int)time(0) * 20);
				float height = (rand() % 300) - 150;
				spriteCloud2.setPosition(-200, height);
				cloud2Active = true;
			}
			else {
				spriteCloud2.setPosition(
					spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()),
					spriteCloud2.getPosition().y
				);
				if (spriteCloud2.getPosition().x > 1920)
				{
					cloud2Active = false;
				}
			}

			if (!cloud3Active)
			{
				srand((int)time(0) * 30);
				cloud3Speed = (rand() % 200);
				srand((int)time(0) * 30);
				float height = (rand() % 450) - 150;
				spriteCloud2.setPosition(-200, height);
				cloud3Active = true;
			}
			else {
				spriteCloud3.setPosition(
					spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()),
					spriteCloud3.getPosition().y
				);
				if (spriteCloud3.getPosition().x > 1920)
				{
					cloud3Active = false;
				}
			}
		}
		
		//Draw the scene
		window.clear();
		window.draw(spriteBackground);
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);
		window.draw(spriteTree);
		window.draw(spriteBee);
		window.display();

		

	}
	
	return 0;

}


