#pragma once

struct Position {
	int x;
	int y;

	Position(int x, int y);
	Position();
};

inline Position operator+(Position a, Position b) {
	Position sum(a.x + b.x, a.y + b.y);
	return sum;
}

inline Position operator-(Position a, Position b) {
	Position sum(a.x - b.x, a.y - b.y);
	return sum;
}

inline bool operator==(Position a, Position b) {
	return (a.x == b.x && a.y == b.y);
}