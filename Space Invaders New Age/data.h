#ifndef _DATA_H_
#define _DATA_H_

#include "CONSTANTS.h"

fstream game_controlling_type;

openFile(game_controlling_type, "data/data.sina", ios_base::out);
bool game_controlling_type_writed = false;

#endif;