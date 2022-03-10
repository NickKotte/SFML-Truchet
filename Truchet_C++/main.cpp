#include <SFML/Graphics.hpp>
#include "Pattern.cpp"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
using namespace std;

//g++ -framework sfml-window -framework sfml-graphics -framework sfml-system main.cpp -o main && ./main

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 16;
	srand (time(NULL));
	unsigned int microsecond = 1000000;
	float gridSize = 100.f;
	float scale = 100.f;
	float tileSize = scale/2.f;
	float tileOrigin = tileSize/2.f;
	sf::RenderWindow window(sf::VideoMode(gridSize*scale, gridSize*scale), "Truchet", sf::Style::Default, settings);

	vector< vector<Pattern> > patterns;
	for (int i = 0; i<gridSize; i++){
		vector<Pattern> newRow;
		patterns.push_back(newRow);
		for (int j = 0; j < gridSize; j++){
			patterns[i].push_back(Pattern(scale));
			patterns[i][j].set(sf::Vector2f(i*scale, j*scale));
		}
	}
	int randX, randY;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			window.close();
		}
		window.clear();
		for (int k = 0; k < 35; k++ ){
			randX = rand() % (int)(gridSize);
			randY = rand() % (int)(gridSize);
			patterns[randX][randY].invert();
		}
		for (int i = 0; i<gridSize; i++){
			for (int j = 0; j < gridSize; j++){
				patterns.at(i).at(j).set(sf::Vector2f(i*scale, j*scale));
				patterns[i][j].setSize(scale);
				window.draw(patterns[i][j]);
			}
		}
		usleep(0.005 * microsecond);

		scale -= 0.1;
		window.display();
	}

	return 0;
}
