#ifndef AFICHMATION_H
#define AFICHMATION_H

#include <iostream>

#include <list>
#include <initializer_list>
#include <string>
#include <SFML/Graphics.hpp>
#include "Animation.h"

using namespace std;
using namespace sf;

class Afichmation : public Sprite {
private:
	Texture *texture;
	Clock clock;
	list<Animation> animations;
	Animation *animation;
	bool flippedX;
	bool flippedY;
	bool isLooping;
	bool playing;
	int width, height;
	IntRect frame;
	void SetCurrentFrame();
	void UpdateScale();
public:
	Afichmation() {}
	Afichmation(string name, bool loop, int width, int height);
	~Afichmation() {}
	void FlipX(bool isFlipped);
	void FlipY(bool isFlipped);
	void Add(string name, initializer_list<int> frames, int fps, bool loop);
	void Play(string name);
	bool IsPlaying(string name);
	void Update();
	void setPosition(float x, float y);
	void setPosition(const Vector2f &position);
	void setScale(float factorx, float factory);
	void setScale(const Vector2f &factors);
	const Vector2f &getScale();
};
#endif
