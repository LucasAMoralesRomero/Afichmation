/**
* @file Afichmation.h
* @version 1.0
* @date 12/13/2020
* @author Nicol�s Capel
* @brief Clase Afichmation para utilizaci�n de spritesheets con SFML 2.5, incluye clase Animation. Hereda de Sprite.
* @code
	Afichmation anim("", true, 32, 32);
	anim.Add("idle", {0, 1, 2, 3, 4}, 8, true);
	anim.Play("idle");
* @endcode
*/


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

/**
* @brief Clase que se encarga de ejecutar las animaciones, hereda de Sprite por ende incorpora todos sus m�todos y propiedades
*/

class Afichmation : public Sprite {
private:
	
	/**
	* @brief Propiedad para contener la textura del spritesheet
	*/
	Texture *texture;
	
	/**
	* @brief Propiedad reloj para actualizaci�n del spritesheet (control de FPS)
	*/
	Clock clock;
	
	/**
	* @brief Propiedad que almacena una lista de animaciones (aqu� se guardan las animaciones seteadas con Add)
	*/
	list<Animation> animations;
	
	/**
	* @brief Propiedad que almacena la animaci�n que se est� utilizando actualmente
	*/
	Animation *animation;
	
	/**
	* @brief Propiedad bandera que sirve saber si el sprite se debe voltear en horizontal o no
	*/
	bool flippedX;
	
	/**
	* @brief Propiedad bandera que sirve saber si el sprite se debe voltear en vertical o no
	*/
	bool flippedY;
	
	/**
	* @brief Propiedad bandera que sirve saber si el sprite est� ejecutando una animaci�n en loop
	*/
	bool isLooping;
	
	/**
	* @brief Propiedad bandera que sirve saber se est� ejecutando una animaci�n actualmente
	*/
	bool playing;
	
	/**
	* @brief Propiedades que sirven para recordar el ancho y alto de los frames
	*/
	int width, height;
	
	/**
	* @brief Propiedad que permite recordar el frame actual
	*/
	IntRect frame;
	
	/**
	* @brief M�todo que establece el frame actual
	*/
	void SetCurrentFrame();
	
	/**
	* @brief M�todo que actualiza las escalas del sprite
	*/
	void UpdateScale();
	
public:
	
	/**
	* @brief Constructor por defecto (no se implementa)
	*/
	Afichmation() {}
	
	/**
	* @brief Constructor.
	* @param path Ruta al archivo de sprites
	* @param loop Establece la animaci�n en loop
	* @param width Ancho del frame
	* @param height Alto del frame
	*/
	Afichmation(string path, bool loop, int width, int height);
	
	/**
	* @brief Destructor de clase (no se implementa)
	*/
	~Afichmation() {}
	
	/**
	* @brief Esteblece si el personaje se voltea en horizontal, o no.
	* @param isFlipped Si/No
	*/
	void FlipX(bool isFlipped);
	
	/**
	* @brief Esteblece si el personaje se voltea en vertical, o no.
	* @param isFlipped Si/No
	*/
	void FlipY(bool isFlipped);
	
	/**
	* @brief A�ade una animaci�n a la lista
	* @param name Nombre de la animaci�n
	* @param frames Frames que componen a la animaci�n -> {0, 1, 2, 3} por ejemplo
	* @param fps Fotogramas por segundo de la animaci�n
	* @param loop Establece si la animaci�n se reproducir� en loop
	*/
	void Add(string name, initializer_list<int> frames, int fps, bool loop);
	
	/**
	* @brief Establece la animaci�n a ejecutar.
	* @param name Nombre que se le asign� a la animaci�n
	*/
	void Play(string name);
	
	/**
	* @brief M�todo de consulta para saber si se est� ejecutando alguna animaci�n.
	* @param name El nombre de la animaci�n que nos interesa saber si se est� ejecutando
	* @return Si/No
	*/
	bool IsPlaying(string name);
	
	/**
	* @brief M�todo de actualizaci�n de estados de la clase
	*/
	void Update();
	
	/**
	* @brief M�todo sobreescrito de Sprite
	* @param x Flotante para la componente X
	* @param y Flotante para la componente Y
	*/
	void setPosition(float x, float y);
	
	/**
	* @brief M�todo sobreescrito de Sprite
	* @param position La posici�n en formato de Vector2f, de solo lectura
	*/
	void setPosition(const Vector2f &position);
	
	/**
	* @brief M�todo sobreescrito de Sprite
	* @param factorx Flotante para la componente X
	* @param factory Flotante para la componente Y
	*/
	void setScale(float factorx, float factory);
	
	/**
	* @brief M�todo sobreescrito de Sprite
	* @param factors La escala en formato de Vector2f, de solo lectura
	*/
	void setScale(const Vector2f &factors);
	
	/**
	* @brief M�todo sobreescrito de Sprite
	* @param Retorna la escala del sprite en formato Vector2f
	*/
	const Vector2f &getScale();
	
	/**
	* @brief Establece velocidad de desplazamiento
	* @param Vector2f velocidad
	*/
	
};
#endif
