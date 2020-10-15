#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include "Servicios.h"
#include "Bicicleta.h"
#include "Color.h"
#include "Tipo.h"

int validaciones_validarRodado(int idRodado);

int validaciones_ValidarColorValido(eColor colores[], int tam, int id);

int validaciones_ValidarTipoValido(eTipo tipos[], int tam, int id);

int validaciones_ValidarBicicleta(eBicicleta bicis[], int tam, int idBicicleta);

int validaciones_ValidarServicio(eServicio servicios[], int tam, int idServicio);
#endif // VALIDACIONES_H_INCLUDED
