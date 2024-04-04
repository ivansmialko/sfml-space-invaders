#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class ShapeObject : public GameObject
{
public:
	enum EShapeType
	{
		EST_SHAPE_UNKNOWN,
		EST_SHAPE_CIRCLE,
		EST_SHAPE_CONVEX,
		EST_SHAPE_RECTANGLE
	};

	enum ECircleShapeParam
	{
		ECSP_RADIUS,
		ECSP_POINT_COUNT
	};

private:
	static const double DEFAULT_RADIUS;

	sf::Shape* _shape { nullptr };
	EShapeType _shape_type { EST_SHAPE_UNKNOWN };

	void initCircle();

public:
	ShapeObject() {}
	~ShapeObject();

	void init(EShapeType in_shape_type);
	void setShapeParam(ECircleShapeParam in_param, double in_value);
	void setFillColor(char in_r, char in_g, char in_b, char in_a = 255);
	void setOutlineColor(char in_r, char in_g, char in_b, char in_a = 255);
	virtual void setX(double in_x) override;
	virtual void setY(double in_y) override;

	virtual void render() override;
};