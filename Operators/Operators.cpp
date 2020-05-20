#include<iostream>

struct Vector2
{
	float x, y;

	Vector2(float x, float y)
		: x(x), y(y) {}

	Vector2 Add(const Vector2& vector) const
	{
		return Vector2(x + vector.x, y + vector.y);
	}

	Vector2 operator+(const Vector2& vector) const
	{
		return Add(vector);
	}

	Vector2 Multiply(const Vector2& vector) const
	{
		return Vector2(x * vector.x, y * vector.y);
	}

	Vector2 operator*(const Vector2& vector) const
	{
		return Multiply(vector);
	}

	bool operator==(const Vector2& vector) const
	{
		return x == vector.x && y == vector.y;
	}
};

std::ostream& operator<<(std::ostream& stream, const Vector2& vector)
{
	stream << vector.x << ", " << vector.y;
	return stream;
}

int main()
{
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 powerup(1.1f, 1.1f);

	Vector2 result1 = position.Add(speed.Multiply(powerup));
	Vector2 result2 = position + speed * powerup;

	std::cout << result2 << std::endl;
}