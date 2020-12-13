#ifndef ANIMATION_H
#define ANIMATION_H

#include <initializer_list>

using namespace std;

class Animation {
	friend class Afichmation;
private:
	string name;
	initializer_list<int> frames;
	bool loop;
	int fps;
	int frame;
	int indexFrame;
public:
	Animation(string name, initializer_list<int> frames, int fps, bool loop) {
		this->name = name;
		this->frames = frames;
		this->loop = loop;
		this->fps = fps;
		indexFrame = 0;
		for (int i : frames){
			indexFrame++;
			this->frame = i;
			break;
		}
	}
	
	void NextFrame() {
		int c = 0;
		for (int i : frames){
			this->frame = i;
			c++;
			if (indexFrame == frames.size()) {
				indexFrame = 0;
			}
			if (c > indexFrame) {
				indexFrame++;
				break;
			}
		}
	}
	
};
#endif
