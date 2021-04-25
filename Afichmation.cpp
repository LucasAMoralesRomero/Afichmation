#include "Afichmation.h"

Afichmation::Afichmation(string path, bool loop, int width, int height){
	texture = new Texture();
	this->width = width;
	this->height = height;
	texture->loadFromFile(path);
	isLooping = loop;
	setTexture(*texture);
	frame = IntRect(0, 0, this->width, this->height);
	setTextureRect(frame);
	playing = false;
	flippedX = false;
	flippedY = false;
	setScale(getScale());
	setOrigin(width / 2, height / 2);
	setPosition((width * getScale().x) / 2, (height * getScale().y) / 2);
	clock.restart();
}

Afichmation::Afichmation(Texture &tex, bool loop, int width, int height) {
	texture = &tex;
	this->width = width;
	this->height = height;
	isLooping = loop;
	setTexture(tex);
	frame = IntRect(0, 0, this->width, this->height);
	setTextureRect(frame);
	playing = false;
	flippedX = false;
	flippedY = false;
	setScale(getScale());
	setOrigin(width / 2, height / 2);
	setPosition((width * getScale().x) / 2, (height * getScale().y) / 2);
	clock.restart();
}

void Afichmation::FlipX(bool isFlipped) {
	flippedX = isFlipped;
}

void Afichmation::FlipY(bool isFlipped) {
	flippedY = isFlipped;
}

bool Afichmation::IsPlaying(string name) {
	return playing;
}

void Afichmation::Play(string name) {
	if (animation->name == name) {
		return;
	} else {
		list<Animation>::iterator it = animations.begin();
		while(it != animations.end()) {
			if (name == it->name) {
				animation = &(*it);
				animation->finish = false;
			}
			it++;
		}
	}
}

void Afichmation::Add(string name, initializer_list<int> frames, int fps, bool loop) {
	animation = new Animation(name, frames, fps, loop);
	animations.push_back(*animation);
}

void Afichmation::setPosition(float x, float y) { Sprite::setPosition(x, y); }

void Afichmation::setPosition(const Vector2f &position) { Sprite::setPosition(position); }

void Afichmation::setScale(float factorx, float factory) {
	Sprite::setScale(factorx, factory);
}

void Afichmation::setScale(const Vector2f &factors) { 
	setScale(factors.x, factors.y);
}

const Vector2f &Afichmation::getScale() {
	return Sprite::getScale();
}

void Afichmation::SetCurrentFrame() {
	if (!animation->finish) {
		int x = width * animation->frame;
		int y = 0;
		while (x > (texture->getSize().x - width)) {
			y++;
			x -= texture->getSize().x;
		}
		frame.left = x;
		frame.top = y * height;
		animation->NextFrame();
		setTextureRect(frame);	
	}
}

void Afichmation::UpdateScale() {
	if (flippedX && getScale().x > 0) setScale(-getScale().x, getScale().y);
	if (!flippedX && getScale().x < 0) {
		int aux = getScale().x * 100;
		float finalAux = (-1 * (aux)) / 100.f;
		setScale(finalAux, getScale().y);
	}
	if (flippedY && getScale().y > 0) setScale(getScale().x, -getScale().y);
	if (!flippedY && getScale().y < 0) {
		int aux = getScale().y * 100;
		float finalAux = (-1 * (aux)) / 100.f;
		setScale(getScale().x, finalAux);
	}
}

void Afichmation::Update() {
	UpdateScale();
	if (!animation->finish) {
		if (clock.getElapsedTime().asSeconds() > 1.0f / animation->fps) {
			SetCurrentFrame();
			clock.restart();
		}
	}
}
