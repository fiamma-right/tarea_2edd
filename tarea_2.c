#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct noodle{
    struct noodle *link_f;
	struct noodle *link_b;
	char nombre[51];
	char title[51];
	char content[257];
	int current;
} Node;

/****typedef struct cmd{
	char cmd1[19];
	char cmd2[20];
	char cmd3[20];
}cmd;****/

/***Modifiqué para que agregue una diapo en cualquier parte del programa
inmediatamente despues de la diapo actual, tal como lo indica el enunciado***/

Node * open_presentation(FILE *fap){
	char temp[257];
	int ide = 0, state = 0, we_are_in = 0;
	Node *final = NULL;
	while ((fscanf(fap, "%c", &temp[ide])) == 1){
		if (state == 0 && temp[ide] == '\n'){
			temp[ide] = '\0';
			state = 1;
			Node *temp_2 = (*Node)malloc(sizeof(Node));
			strcpy(temp_2->nombre, temp);
			ide = 0;
		}
		else if (state == 1 && &temp[ide] == '\n'){
			temp[ide] = '\0';
			state = 2;
			strcpy(temp_2->title, temp);
			ide = 0;
		}
		else if (state == 2 && &temp[ide] == '\n'){
			temp[ide] = '\0';
			state = 0;
			strcpy(temp_2->content, temp);
			temp_2->current = we_are_in;
			ide = 0;
			we_are_in++
			if(final == NULL){
				final = temp_2;
			}
			else{
				while(final->link_f != NULL){
					final = final->link_f;
				}
				final->link_f = temp_2;
				temp_2->link_b = final;
			}
		}
	}
	while(final->link_b != NULL){
		final = final->link_b;
	}
	return final;
}

void new_canvas(Node *a){
	if (a->link_f == NULL){
		a->link_f = (*Node)malloc(sizeof(Node));
	}
	else{
		Node *temp_1 = a, *temp_2 = a;
		temp_1 = temp_1->link_f
		a = (*Node)malloc(sizeof(Node));
		temp_1->link_b = a;
		temp_2->link_f = a;
		a = temp_2;
	}	
}

void watch_canvas(Node* a){
	printf("%d\n%s\n%s\n", a->current, a->title, a->content);
}

void set_title(char *new_title, Node *a){
	strcpy(a->title, new_title);
}

void set_content(char *new_content, Node *a){
	strcpy(a->content, new_content);
}

void next_canvas(Node *a){
	a = a->link_f;
}

void prev_canvas(Node *a){
	a = a->link_b;
}

void delete_canvas(Node *a){
	Node *temp_1 = a, *temp_2 = a;
	temp_1 = temp_1->link_b;
	temp_2 = temp_2->link_f;
	temp_1->link_f = temp_2;
	temp_2->link_b = temp_1;
	a = temp_2;
	(a->current)--;
	while(temp_2->link_f != NULL){
		temp_2 = temp_2->link_f;
		(temp_2->current)--;
	}
}

int main(){
/**{
	node *a;
	cmd *com;
	FILE *fp;
	char *cmd, *par;
	ssize_t len1, len2;
	com->cmd1 ="NUEVA_PRESENTACION";
	While(getdelim(**cmd, *len1, ' ', fp)=!-1){
		if (getdelim(**par, *len2, ' ', fp) =! -1){
			if ( strcmp(*cmd,com->cmd1) ==0)
				nueva_presentacion(*par, *a);
		}
	}
	return 0;
}**/
	FILE *fap;
	char asd[1000];
	return 0;
}
