/**
* @file Animation.h
* @version 1.0
* @date 12/13/2020
* @author Nicolás Capel
* @brief Clase de utilidad para Afichmation recordar animaciones.
*/

#ifndef ANIMATION_H
#define ANIMATION_H

#include <initializer_list>

using namespace std;

/**
* @brief Clase de utilidad para Afichmation recordar animaciones.
*/

class Animation {
	friend class Afichmation;
private:
	
	/**
	* @brief Propiedad para recordar el nombre de la animación
	*/
	string name;
	
	/**
	* @brief Propiedad del tipo lista de enteros, contiene una lista de valores que representan en enteros los frames
	*/
	initializer_list<int> frames;
	
	/**
	* @brief Propiedad para recordar si debe estar en loop o no la animación
	*/
	bool loop;
	
	/**
	* @brief Cantidad de fotogramas por segundo de la animación
	*/
	int fps;
	
	/**
	* @brief Número de frame a visualizar en pantalla
	*/
	int frame;
	
	/**
	* @brief Indice de frame actual
	*/
	int indexFrame;
public:
	
	/**
	* @brief Método constructor
	* @param name Nombre de la animación
	* @param frames Lista de enteros que contiene los números de frame de la animación
	* @param fps Cantidad de fotogramas por segundo
	* @param loop Establece si la animación se ejecutará en loop o no
	*/
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
	
	/**
	* @brief Método que realiza el intercambio de frames
	*/
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
