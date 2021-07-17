#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "punto.h"
# define M 50

int run_test_case(char *tc_id);
void riordina(Punto *p, char coordinata, char criterio, int num, char output_fname[]);
void a_crescente(Punto *p, int num, char output_fname[]);
void a_decrescente(Punto *p, int num, char output_fname[]);
void o_crescente(Punto *p, int num, char output_fname[]);
void o_decrescente(Punto *p, int num, char output_fname[]);
int confronta_punti(Punto *p1, Punto *p2, int n);