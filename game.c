/*
My first "game" in my first year(he year is not over yet)


*/


#include<stdio.h>
#include <windows.h>
#include<time.h>




 
typedef struct{
 	int x_mov;
	int y_mov;
 }mov;
 
 typedef struct{
 	int x_bicho;
	int y_bicho;
 }movbicho;
 
 typedef struct{
 	int muerte; //0 esta vivo, 1 esta muerto
 }dead;
 
 typedef struct{
 	
 	int esquivados;
	int intentos;
 }leader;
 
leader decor;
mov game;
movbicho bixo;
dead fin;
 
  void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
 
 void dec(int m,int s);
 void lop();
 void base();
 void lizq();
 void lder();
 void movimiento();


int main(){
	MessageBox(0, "Usa las fechas para poder moverte(<-,->,up,down) ", "Información", 0); 
	game.x_mov=12;
	game.y_mov=16;
	lop();
	//lizq();
	//lder();
	//base();
	//bicho();
	//movimiento();


	return 0;
}

void lizq(){
	
	int i;
	for(i=1;i<=18;i++){
		gotoxy(1,i);
		printf("*");
	}
	
}

void lder(){
	int i;
	for(i=1;i<=18;i++){
		gotoxy(25,i);
		printf("*");
	}
	
}

void base(){
	int i;
	for(i=1;i<=25;i++){
		gotoxy(i,19);
		printf("*");
	}
	lder();
	lizq();
	
	
}

void movimiento(){
	system("cls");
    
	
	//while(true){ // sin restriccion de movimiento.
	if(GetAsyncKeyState(VK_RIGHT)){ //movimiento a la derecha
	system("cls");	//con esto se borra el movimiento anterior
	//llamamos a la escena porque se borro con el cls
	base();
	game.x_mov +=1;
	gotoxy(game.x_mov,game.y_mov);
	
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
	printf("X");
	}
	
	else if(GetAsyncKeyState(VK_LEFT)){// movimiento a la izquierda		
	system("cls");//con esto se borra el movimiento anterior
	base();
	
	gotoxy(game.x_mov,game.y_mov);
	game.x_mov--;

	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
	printf("X");
	//eliminacion(&x,&y)
	}	
	
	else if(GetAsyncKeyState(VK_UP)){// movimiento hacia arriba
	system("cls");//con esto se borra el movimiento anterior

	base();
	
	gotoxy(game.x_mov,game.y_mov-1);
	game.y_mov -=1;
	
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
	printf("X");	
	}
	
	else if(GetAsyncKeyState(VK_DOWN)){ //movimient o hacia abajo
	system("cls"); //con esto se borra el movimiento anterior

	base();
	
	gotoxy(game.x_mov,game.y_mov+1);
	game.y_mov +=1;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2); 
	printf("X");
	
	}
	
	
	
		
	//}
	
	
}


void enemy(){ //(no terminado)
	//int x_bicho,y_bicho,aux;
	//while(1){
 //for para x
 int aux;

    srand(time(NULL));

    //for(bixo.y_bicho=4;bixo.y_bicho<=18;bixo.y_bicho++){ //for para y


    
        if(bixo.y_bicho== 20){
    	bixo.x_bicho = 2 + rand() % (23);
    	bixo.y_bicho=0;
    	decor.esquivados++;
	}
    bixo.y_bicho++;
	gotoxy (bixo.x_bicho,bixo.y_bicho);
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 4); 
	printf("O\r");
	Sleep(100);
	system("cls");

	base();
	
	if (game.x_mov == bixo.x_bicho && game.y_mov == bixo.y_bicho){
	MessageBox(0, "Has muerto ", "Información", 0); 
	printf("\n\tHas muerto\n\t");
	fin.muerte=1;
}
	aux=1;
	
	}
	
    
		
	
	
	


/*

void eliminacion(){

	
	if (game.x_mov == bixo.x_bicho && game.y_mov == bixo.y_bicho){
	MessageBox(0, "Has muerto ", "Información", 0); 
	printf("\n\tHas muerto\n\t");
	fin.muerte=1;
}
	}
*/


void lop(){
    int m=0,s=0;
	fin.muerte=0;
	char op;
	bixo.x_bicho = 12;
	do{
		
	base();
	
	movimiento();
	dec(m,s);
	enemy();
	//eliminacion();	
		
		
	}while(fin.muerte==0);
	
	printf("El juego termino");
	printf("\nQuieres jugar de nuevo?: (S/N)");
	scanf("%c", &op);
	fflush(stdin);
	if(op == 'S' || op == 's'){
		decor.intentos++;
		bixo.x_bicho = 0;
        bixo.y_bicho=0;
        game.x_mov=12;
	    game.y_mov=16;
	    decor.esquivados=0;
		lop();
	}else{
	/*
	Total points,etc
	*/
	
	}
	
	
}


void dec(int m,int s){
	/*
	Leaderboard
    Tiempo:	
	Esquivados: 
	Intentos: 
	*/
	
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 11);
	gotoxy(40,4);
	printf("LeaderBoard");
	s++;
	if(s<59){
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 11);
		gotoxy(40,5);
	    printf("Tiempo: 00:%02i",s);//It doesn't work
	    gotoxy(40,6);
	    printf("Esquivados: %i",decor.esquivados);// se basara cuando se la pelota llegue al fin
	    gotoxy(40,7);
	    printf("Intentos: %i", decor.intentos);
	    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
	}else if(s>59){
		m++;
		s=0;
		printf("%02i:%02i " ,m,s);
		
	}
	
	
}

