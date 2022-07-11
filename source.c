#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define L_MAX 10
#define C_MAX 10
#define TRUE_RETURN 1
#define FALSE_RETURN -1
char matriz[L_MAX][C_MAX];
int l,c;
int sl,sc;
int i;
int last_l;
int last_c;
int control = 1;
int pos[2];
void iniciaMatriz(){
	for(sl = 0;sl < L_MAX;sl++){
		for(sc = 0; sc < C_MAX;sc++){
			matriz[sl][sc] = '!';
		}
	}
	return;
}
void renderizaMatriz(){
	system("cls");
	for(sl = 0;sl < L_MAX;sl++){
		for(sc = 0;sc < C_MAX;sc++){
			printf("[%c]",matriz[sl][sc]);
		}
		printf("\n");
	}
}
int verificaMatriz(int pos[]){
	int cont = 0;
	if(pos[0] < 0){
		l++;
		cont++;
	}
	if(pos[1] < 0){
		c++;
		cont++;
	}
	if(pos[0] > L_MAX){
		cont++;
		l--;
	}
	if(pos[1] > C_MAX){
		c--;
		cont++;
	}
	if(cont == 0){
		return TRUE_RETURN;
	}	
	return FALSE_RETURN;
}
void mudaPosicao(char key_pressed){
	if(verificaMatriz(pos) == TRUE_RETURN){
		
		if(key_pressed == 'd' || key_pressed == 'D'){
			last_l = l;
			last_c = c;
			matriz[l][++c] = '#';
			matriz[last_l][last_c] = '!';
			pos[0] = l;
			pos[1] = c;
		}
		else if(key_pressed == 'A' || key_pressed == 'a'){
			last_l = l;
			last_c = c;
			matriz[l][--c] = '#';
			matriz[last_l][last_c] = '!';
			pos[0] = l;
			pos[1] = c;
		}
		else if(key_pressed == 's' || key_pressed == 'S'){
			last_l = l;
			last_c = c;
			matriz[++l][c] = '#';
			matriz[last_l][last_c] = '!';
			pos[0] = l;
			pos[1] = c;
		}
		else if(key_pressed == 'w' || key_pressed == 'W'){
			last_l = l;
			last_c = c;
			matriz[--l][c] = '#';
			matriz[last_l][last_c] = '!';
			pos[0] = l;
			pos[1] = c;
		}	
	}
}

int main(){
	iniciaMatriz();
	matriz[0][0] = '#';
	pos[0] = pos[1] = last_l = last_c = 0;
	renderizaMatriz();
	while(control != 0){
		if(kbhit()){
			mudaPosicao(getch());
			renderizaMatriz();
		}	
	}
	return 0;
}