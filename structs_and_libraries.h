#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdbool.h>
#include <inttypes.h>
#include <dirent.h>

#ifndef COREWARSINTERPRETER_INIT_GLOBALS_H
#define COREWARSINTERPRETER_INIT_GLOBALS_H

typedef struct  {
    bool initialized;
    uint16_t stack_id;
    uint16_t AX, BX, CX, DX, SI, DI, BP, SP, CS, DS, SS, ES, IP, Energy, Flags; // Registers
    uint8_t INT86h_used, INT87h_used;
    char* code;
    uint16_t code_size;
} Survivor;

typedef struct {
    Survivor survivors[2];
    bool living_survivors[2];
    uint16_t shared_memory_id;
    char* name;
    double points;
    bool is_zombie;
} Team;

typedef struct {
    char values[0x10000];
} Segment;

struct Player_Tracker {
    bool is_zombie;
    int32_t team_id;
    int32_t survivor_position;
};

#endif //COREWARSINTERPRETER_INIT_GLOBALS_H
