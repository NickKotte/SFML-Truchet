#include <cmath>
#include "Arc.cpp"

class Pattern : public sf::Drawable, public sf::Transformable
{
private:
	bool inverted;
	float size;
	Arc arc_right;
	Arc arc_left;
	sf::RectangleShape rect;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// apply the entity's transform -- combine it with the one that was passed by the caller
		states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

		// target.draw(rect, states);
		target.draw(arc_right, states);
		target.draw(arc_left, states);
	}
public:

	Pattern(float s) {
		size = s;
		rect.setSize(sf::Vector2f(size, size));
		rect.setFillColor(sf::Color::Black);
		// rect.setOutlineColor(sf::Color::White);
		// rect.setOutlineThickness(1);
		inverted = false;
	}
	void set(sf::Vector2f origin){
		rect.setPosition(origin);
		if (inverted){
			arc_left.fill(360, sf::Vector2f(origin.x,origin.y), size/2, size/2, 270);
			arc_right.fill(360, sf::Vector2f(origin.x, origin.y), size/2, size/2, 90);
		}else{
			arc_left.fill(360, sf::Vector2f(origin.x,origin.y), size/2, size/2, 0);
			arc_right.fill(360, sf::Vector2f(origin.x, origin.y), size/2, size/2, 180);
		}
	}
	void setSize(float s) { size = s; }
	void invert(){ inverted = !inverted; }

};
