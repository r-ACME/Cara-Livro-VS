#ifndef CARALIVROPOSTAGENS_H_INCLUDED
#define CARALIVROPOSTAGENS_H_INCLUDED

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "define.h"
#include "data.h"
#include "lista.h"
#include "graph.h"
#include "caralivropattern.h"
#include "caralivrocadastro.h"
#include "caralivroverusuarios.h"
#include "caralivroveramigos.h"






bool_t criar_postagem(pointer_t* current_user);
bool_t ver_curtir_postagens(pointer_t* current_user, pointer_t* current_profile);








#endif // DATA_H_INCLUDED