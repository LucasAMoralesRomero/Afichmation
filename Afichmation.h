/**
* @file Afichmation.h
* @version 1.0
* @date 12/13/2020
* @author Nicolás Capel
* @brief Clase Afichmation para utilización de spritesheets con SFML 2.5, incluye clase Animation. Hereda de Sprite.
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
* @brief Clase que se encarga de ejecutar las animaciones, hereda de Sprite por ende incorpora todos sus métodos y propiedades
*/

class Afichmation : public Sprite {
private:
	
	/**
	* @brief Propiedad para contener la textura del spritesheet
	*/
	Texture *texture;
	
	/**
	* @brief Propiedad reloj para actualización del spritesheet (control de FPS)
	*/
	Clock clock;
	
	/**
	* @brief Propiedad que almacena una lista de animaciones (aquí se guardan las animaciones seteadas con Add)
	*/
	list<Animation> animations;
	
	/**
	* @brief Propiedad que almacena la animación que se está utilizando actualmente
	*/
	Animation *animation;
	
	/**
	* @brief Propiedad bandera que sirve saber si el sprite está ejecutando una animación en loop
	*/
	bool isLooping;
	
	/**
	* @brief Propiedad bandera que sirve saber si el sprite se debe voltear en horizontal o no
	*/
	bool flippedX;
	
	/**
	* @brief Propiedad bandera que sirve saber si el sprite se debe voltear en vertical o no
	*/
	bool flippedY;
	
	/**
	* @brief Propiedad bandera que sirve saber se está ejecutando una animación actualmente
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
	* @brief Método que establece el frame actual
	*/
	void SetCurrentFrame();
	
	/**
	* @brief Método que actualiza las escalas del sprite
	*/
	void UpdateScale();
	
public:
	
	/**
	* @brief Constructor por defecto (no se implementa)
	*/
	Afichmation() {}
	
	/**
	* @brief Constructor.
	* @param path Ruta al archivo de spritesheet
	* @param loop Establece la animación en loop
	* @param width Ancho del frame
	* @param height Alto del frame
	*/
	Afichmation(string path, bool loop, int width, int height);
	
	/**
	* @brief Sobrecarga de constructor.
	* @param tex Textura para aplicar al sprite
	* @param loop Establece la animación en loop
	* @param width Ancho del frame
	* @param height Alto del frame
	*/
	Afichmation(Texture &tex, bool loop, int width, int height);
	
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
	* @brief Añade una animación a la lista
	* @param name Nombre de la animación
	* @param frames Frames que componen a la animación -> {0, 1, 2, 3} por ejemplo
	* @param fps Fotogramas por segundo de la animación
	* @param loop Establece si la animación se reproducirá en loop
	*/
	void Add(string name, initializer_list<int> frames, int fps, bool loop);
	
	/**
	* @brief Establece la animación a ejecutar.
	* @param name Nombre que se le asignó a la animación
	*/
	void Play(string name);
	
	/**
	* @brief Método de consulta para saber si se está ejecutando alguna animación.
	* @param name El nombre de la animación que nos interesa saber si se está ejecutando
	* @return Si/No
	*/
	bool IsPlaying(string name);
	
	/**
	* @brief Método de actualización de estados de la clase
	*/
	void Update();
	
	/**
	* @brief Método sobreescrito de Sprite
	* @param x Flotante para la componente X
	* @param y Flotante para la componente Y
	*/
	void setPosition(float x, float y);
	
	/**
	* @brief Método sobreescrito de Sprite
	* @param position La posición en formato de Vector2f, de solo lectura
	*/
	void setPosition(const Vector2f &position);
	
	/**
	* @brief Método sobreescrito de Sprite
	* @param factorx Flotante para la componente X
	* @param factory Flotante para la componente Y
	*/
	void setScale(float factorx, float factory);
	
	/**
	* @brief Método sobreescrito de Sprite
	* @param factors La escala en formato de Vector2f, de solo lectura
	*/
	void setScale(const Vector2f &factors);
	
	/**
	* @brief Método sobreescrito de Sprite
	* @param Retorna la escala del sprite en formato Vector2f
	*/
	const Vector2f &getScale();
	
};
#endif
