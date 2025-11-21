// Clase 3 - Colores y Graficos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Compilar como x86

#include <iostream>
#include "graphics.h"

//agregar libreria compilada
#pragma comment(lib,"graphics.lib")

//definición del prototipo de la función
int DibujarMarioBros();

int main()
{
    initwindow(700, 500);
    DibujarMarioBros();
}

// Utilidad: dibujar un píxel ampliado tipo "pixel art"
void pixel(int x, int y, int size, int color) {
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    bar(x * size, y * size, x * size + size - 1, y * size + size - 1);
}

int DibujarMarioBros() {
    // Ajusta la ruta a BGI si tu implementación lo requiere
    //int gd = DETECT, gm;
    //initgraph(&gd, &gm, "");

    // Fondo
    setbkcolor(COLOR(135, 206, 235)); // azul cielo
    cleardevice();

    // Parámetros del sprite
    int s = 10;   // tamaño del píxel (escala)
    int ox = 40;  // offset X
    int oy = 20;  // offset Y

    // Colores (WinBGI: COLOR(r,g,b))
    int C_NEGRO = BLACK;
    int C_ROJO = COLOR(220, 40, 40);
    int C_AZUL = COLOR(40, 80, 200);
    int C_MARON = COLOR(150, 75, 0);
    int C_PIEL = COLOR(255, 220, 180);
    int C_BLANCO = WHITE;
    int C_AMARILLO = COLOR(255, 210, 0);

    // Función lambda para colocar el pixel con offsets y escala
    auto P = [&](int x, int y, int color) {
        pixel(ox + x, oy + y, s, color);
        };

    // Pixel art de Mario (estilo 16x16 aproximado)
    // Referencia libre inspirada en sprites clásicos (no exacta)
    // Sombrero
    for (int x : {4, 5, 6, 7, 8, 9, 10}) P(x, 0, C_ROJO);
    for (int x : {3, 4, 5, 6, 7, 8, 9, 10, 11}) P(x, 1, C_ROJO);
    for (int x : {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}) P(x, 2, C_ROJO);

    // Borde sombrero
    for (int x : {3, 4, 5, 6, 7, 8, 9, 10, 11}) P(x, 3, C_ROJO);

    // Cara y pelo
    P(3, 4, C_MARON); P(4, 4, C_MARON); P(5, 4, C_MARON); P(6, 4, C_MARON); P(7, 4, C_MARON);
    P(8, 4, C_MARON); P(9, 4, C_MARON); P(10, 4, C_MARON); P(11, 4, C_MARON);

    // Frente y ojos
    P(4, 5, C_PIEL); P(5, 5, C_PIEL); P(6, 5, C_PIEL); P(7, 5, C_PIEL); P(8, 5, C_PIEL);
    P(9, 5, C_PIEL); P(10, 5, C_PIEL);
    P(5, 6, C_NEGRO); P(8, 6, C_NEGRO); // ojos
    P(4, 6, C_PIEL); P(6, 6, C_PIEL); P(7, 6, C_PIEL); P(9, 6, C_PIEL); P(10, 6, C_PIEL);

    // Nariz y bigote
    P(6, 7, C_PIEL); P(7, 7, C_PIEL); P(8, 7, C_PIEL);
    P(5, 8, C_MARON); P(6, 8, C_MARON); P(7, 8, C_MARON); P(8, 8, C_MARON); P(9, 8, C_MARON);

    // Borde cara inferior
    for (int x : {4, 5, 6, 7, 8, 9, 10}) P(x, 9, C_PIEL);

    // Body: camisa roja y overol azul
    // Cuello rojo
    for (int x : {5, 6, 7, 8, 9}) P(x, 10, C_ROJO);

    // Torso rojo
    for (int x : {4, 5, 6, 7, 8, 9, 10}) P(x, 11, C_ROJO);

    // Tirantes azul
    P(4, 12, C_AZUL); P(10, 12, C_AZUL);
    P(4, 13, C_AZUL); P(10, 13, C_AZUL);
    for (int x : {5, 6, 7, 8, 9}) P(x, 13, C_AZUL);

    // Botones amarillos
    P(5, 12, C_AMARILLO); P(9, 12, C_AMARILLO);

    // Overol parte baja
    for (int x : {4, 5, 6, 7, 8, 9, 10}) P(x, 14, C_AZUL);

    // Brazos (piel) y guantes blancos
    P(3, 12, C_PIEL); P(11, 12, C_PIEL);
    P(2, 13, C_BLANCO); P(12, 13, C_BLANCO);
    P(2, 14, C_BLANCO); P(12, 14, C_BLANCO);

    // Piernas y zapatos
    for (int x : {5, 6, 8, 9}) P(x, 15, C_AZUL);
    P(4, 16, C_MARON); P(5, 16, C_MARON); // zapato izq
    P(9, 16, C_MARON); P(10, 16, C_MARON); // zapato der

    // Sombra simple bajo zapatos
    setcolor(COLOR(100, 180, 240));
    setfillstyle(SOLID_FILL, COLOR(100, 180, 240));
    bar((ox + 3) * s, (oy + 17) * s, (ox + 12) * s, (oy + 18) * s);

    // Texto
    setcolor(BLACK);
    outtextxy(20, 10, (char*)"Mario Bros (pixel art) - graphics.h");

    getch();
    closegraph();
    return 0;
}

