#include <cmath>

class Arc : public sf::Drawable, public sf::Transformable
{
private:
	sf::VertexArray vert;
	sf::Vector2f center;
	int numVertex;
	
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
	{
		// apply the entity's transform -- combine it with the one that was passed by the caller
		states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

		target.draw(vert, states);
	}

public:
	void fill(int n, sf::Vector2f pos, int rX, int rY, float rotation)
	{
		numVertex = (n/4)+1;
		center.x = pos.x + rX;
		center.y = pos.y + rY;
		vert.setPrimitiveType(sf::LineStrip);
		vert.resize(numVertex);

		sf::Transform T;	
		T.rotate(rotation, center);

		float theta = 0;
		float angle = 360 / (float)n * (M_PI / (float)180);
		for (int i = 0; i < numVertex; i++)
		{
			vert[i].position = T.transformPoint(sf::Vector2f((pos.x + std::cos(theta) * rX), (pos.y + std::sin(theta) * rY)));
			theta += angle;
		}
	}
};
