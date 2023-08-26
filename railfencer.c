#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define CONS 54
#define IMGSIZEOFFSET 34


int charInt(char c) { //FUNÇÃO QUE FAZ COM QUE OS VALORES DE C QUE VAO DE -127 A 127, SEJAM DE 0 A 255
		int temp;
		if (c < 0) {
			temp = c;
			temp = 256 - (temp * (-1));
			return temp;
		}
		else {
			temp = c;
			return temp;
		}
}

int main() {
	
	FILE *fpo;
	FILE *fpw;
	fpo = fopen("./imagem.bmp", "r");
	fpw = fopen("./result.bmp", "w");
	
	int Y;
	printf("KEY:");
	scanf("%d", &Y);
	
	if (Y < 2) Y = 3;
	
	int *m;
	int *q;
	
	m = (int*)malloc(sizeof(int*));
	q = (int*)malloc(sizeof(int*));
	
	*m = 0;
	*q = (2 * Y) - 2;
	
	int k[Y];
	int i = 0;
	while (i < Y) {
			k[i] = *q - *m;
			*m = *m + 2;
			i++;
	}
	k[Y - 1] = k[0];
	
	free(m);
	free(q);
	
	//Copiando o header da imagem FUNCIONA
	char c;
	for(i = 0; i < CONS; i++) {
		c = fgetc(fpo);
		fputc(c, fpw);
	}
	
	//Calculando o tamanho do array de pixels (em bytes) FUNCIONA
	int len = 0;
	fseek(fpo, IMGSIZEOFFSET, SEEK_SET);
	for(i = 0; i < 4; i++) {
		c = fgetc(fpo);
		len = len + charInt(c) * pow(256, i);
		//printf("%d,", len);
	}
	len = len + CONS; 
	
	printf("NUMBER OF BYTES:%d\n", len);
	printf("APPLYING CIPHER...\n");
	
	fseek(fpo, CONS, SEEK_SET);
	int temp; 
	int l = 0, n = Y - 1;
	int j = 0;
	for(i = CONS; i < (CONS + Y) && i < len; i++) {
		temp = i;
		do {
			c = fgetc(fpo);
			if ((j % 2) == 0) {
				fputc(c, fpw);
				i = i + k[l];
				fseek(fpo, i, SEEK_SET);	
			}
			else {
				fputc(c, fpw);
				i = i + k[n];
				fseek(fpo, i, SEEK_SET);
			}
			j++;
		} while (i < len);
		l = l + 1;
		n = n - 1;
		i = temp;
		j = 0;
	}
	printf("DONE\n");
	
	fclose(fpo);
	fclose(fpw);

	return 0;
}
