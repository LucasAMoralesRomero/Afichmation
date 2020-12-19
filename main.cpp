#include <SFML/Graphics.hpp>
#include "Afichmation.h"

using namespace sf;

int main(int argc, char *argv[]){
	RenderWindow *w = new RenderWindow(VideoMode(640,480),"Ejemplo de SFML");
	w->setFramerateLimit(60);
	
	Afichmation anim("spritesheet.png", true, 26, 30);
	anim.Add("idle", {0, 1, 2, 1, 0}, 8, false);
	anim.Add("run", {3, 4, 5, 4}, 8, true);
	anim.Add("falls of", {6}, 8, true);
	anim.Add("stairs", {7, 8}, 8, true);
	anim.Play("idle");
	
	anim.setScale(Vector2f(2.f, 2.f));
	
	while(w->isOpen()) {
		Event e;
		while(w->pollEvent(e)) {
			if(e.type == Event::Closed)
				w->close();	
			if (Keyboard::isKeyPressed(Keyboard::A)) {
				anim.Play("run");
				anim.FlipX(true);
				anim.move(-2, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::D)) {
				anim.Play("run");
				anim.FlipX(false);
				anim.setPosition(anim.getPosition().x + 2, anim.getPosition().y);
			}
			if (Keyboard::isKeyPressed(Keyboard::W)) {
				anim.Play("stairs");
				anim.FlipY(true);
				anim.setPosition(anim.getPosition().x, anim.getPosition().y - 1);
			}
			if (Keyboard::isKeyPressed(Keyboard::S)) {
				anim.Play("falls of");
				anim.FlipY(false);
				anim.setPosition(anim.getPosition().x, anim.getPosition().y + 4);
			}
			if (Keyboard::isKeyPressed(Keyboard::I)) {
				anim.Play("idle");
			}
			if (Keyboard::isKeyPressed(Keyboard::Z)) {
				anim.setScale(anim.getScale().x + 1.f, anim.getScale().x + 1.f);
			}
			if (Keyboard::isKeyPressed(Keyboard::X)) {
				anim.setScale(anim.getScale().x - 1.f, anim.getScale().x - 1.f);
			}
			if (Keyboard::isKeyPressed(Keyboard::R)) {
				anim.setRotation(anim.getRotation() + 1.f);
			}
			if (Keyboard::isKeyPressed(Keyboard::Q)) {
				anim.setRotation(anim.getRotation() - 1.f);
			}
		}
		anim.Update();
		w->clear(Color(255,255,255,255));
		w->draw(anim);
		w->display();
	}
	return 0;
}

