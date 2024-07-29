#include <graphics.h>
#include <time.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

int endf(int first_snake_score, int second_snake_score, int winer); // функция вывода результата

int check_walls(int x[], int y[]); // функция проверки на столкновение с стенами

int check_tail(int x[], int y[], int x2[], int y2[], int length2); // функция проверки на столкновение с хвостом противоположной змейки

int check_own_tail(int x[], int y[], int length); // функция проверки на столкновение с собственным хвостом

int main(){
	
	int s1_collor, s2_collor, place_collor, whals_collor, apple_collor;
	
	cout << "Collors: BLACK 0, BLUE 1, GREEN 2, CYAN 3, RED 4, MAGENTA 5, BROWN 6, LIGHTGRAY 7, DARKGRAY 8,\n LIGHTBLUE 9, LIGHTGREEN 10, LIGHTCYAN 11, LIGHTRED 12, LIGHTMAGENTA 13, YELLOW 14, WHITE 15\n";
	cout << "\nEnter collor for place: ";
	cin >> place_collor;
	cout << "\nEnter collor for walls: ";
	cin >> whals_collor;
	cout << "\nEnter collor for apple: ";
	cin >> apple_collor;
	cout << "\nEnter collor for 1st snake: ";
	cin >> s1_collor;
	cout << "\nEnter collor for 2nd snake: ";
	cin >> s2_collor;
	
    int rx=180, ry=180, x[200], y[200], d, d2;
    int x2[200], y2[200];
    for(int i = 0; i < 200 ; i++){
        x[i]=0;
        y[i]=0;
    }
    
    for(int i = 0; i < 200 ; i++){
        x2[i] = 0;
        y2[i] = 0;
    }
    
    int first_snake_score = 0; // начальный счёт
    int second_snake_score = 0;

    int dir = 1; // направления
    int dir2 = 1;
    initwindow(647, 492);
    
    x[0] = 200, y[0] = 200; // начальное положение змей
    x2[0] = 400, y2[0] = 200;
    
    d = 1; // сторона движения
    d2 = 1;
    int length = 1;
    int length2 = 1;

    for(;;){
        setfillstyle(1, place_collor); // рисование поля
        bar(0, 0, 640, 480);
        setfillstyle(1, whals_collor);
        bar(0, 0, 640, 10);
        bar(0, 0, 10, 480);
        bar(0, 480, 640, 470);
        bar(630, 10, 640, 480);
        
        if(x[0]==rx && y[0]==ry){ // проверка на сЪедание яблока 1 змеёй
            length += 1;
            first_snake_score += 1;
			rx = ((rand() % 62) + 1) * 10;
            ry = ((rand() % 46) + 1) * 10;
        }
        
        if(x2[0]==rx && y2[0]==ry){ // проверка на сЪедание яблока 2 змеёй
            length2 += 1;
            second_snake_score += 1;
			rx = ((rand() % 62) + 1) * 10;
            ry = ((rand() % 46) + 1) * 10;
        }
        setfillstyle(1,apple_collor);
        bar(rx,ry,rx+10,ry+10);
        
        if(GetAsyncKeyState('D')) {
            d = 1; // движение вправо
        }
        else if(GetAsyncKeyState('A')) {
            d = 2; // движение влево
        }
        else if(GetAsyncKeyState('W')) {
            d = 3; // движение вверх
        }
        else if(GetAsyncKeyState('S')) {
            d = 4; // движение вниз
        }
        else{ 
        	d = 0;
		}
        
        if(GetAsyncKeyState(VK_RIGHT)){
            d2 = 1;
        }
        else if(GetAsyncKeyState(VK_LEFT)){
            d2 = 2;
        }
        else if(GetAsyncKeyState(VK_UP)){
            d2 = 3;
        }
        else if(GetAsyncKeyState(VK_DOWN)) {
            d2 = 4;
        }
        else{
            d2 = 0;
        }

        switch(d){
            case 0:
                if(dir == 1){
                    x[0] = x[0] + 10;
                }
                else if(dir == 2){
                    x[0] = x[0] - 10;
                }
                else if(dir == 3){
                    y[0] = y[0] - 10;
                }
                else if(dir == 4) {
                    y[0] = y[0] + 10;
                }
                else{
                    d = 0;
                }
                break;
            case 1:
                x[0] = x[0] + 10;
                dir = 1;
                break;
            case 2:
                x[0] = x[0] - 10;
                dir = 2;
                break;
            case 3:
                dir = 3;
                y[0] = y[0] - 10;
                break;
            case 4:
                dir = 4;
                y[0] = y[0] + 10;
                break;
        }

        switch(d2){
            case 0:
                if(dir2 == 1){
                    x2[0] = x2[0] + 10;
                }
                else if(dir2 == 2){
                    x2[0] = x2[0] - 10;
                }
                else if(dir2 == 3){
                    y2[0] = y2[0] - 10;
                }
                else if(dir2 == 4) {
                    y2[0] = y2[0] + 10;
                }
                else{
                    d2 = 0;
                }
                break;
            case 1:
                x2[0] = x2[0] + 10;
                dir2 = 1;
                break;
            case 2:
                x2[0] = x2[0] - 10;
                dir2 = 2;
                break;
            case 3:
                dir2 = 3;
                y2[0] = y2[0] - 10;
                break;
            case 4:
                dir2 = 4;
                y2[0] = y2[0] + 10;
                break;
        }
        
        for(int i = 0; i < length; i++){   // рисование хвоста 1 змейки
            setfillstyle(1, s1_collor);    // цвет 2 змейки
            bar(x[i], y[i], x[i]+10, y[i]+10);
        }
        
        for(int i = 199; i > 0; i--){     // движение хвоста 1 змейки
            x[i] = x[i - 1];
            y[i] = y[i - 1];
        }

        for(int i = 0; i < length2; i++) {   // рисование хвоста 2 змейки
            setfillstyle(1, s2_collor);      // цвет 2 змейки
            bar(x2[i], y2[i], x2[i] + 10, y2[i] + 10);
        }

        for(int i = 199; i > 0; i--) {   // движение хвоста 2 змейки
            x2[i] = x2[i - 1];
            y2[i] = y2[i - 1];
        }

        delay(100);
		
		if(check_walls(x, y) == 1){
			if(check_walls(x2, y2) == 1){
				endf(first_snake_score, second_snake_score, 2);
			}
			if(check_tail(x2, y2, x, y, length) == 1){
				endf(first_snake_score, second_snake_score, 2);
			}
			if(check_own_tail(x2, y2, length2) == 1){
				endf(first_snake_score, second_snake_score, 2);
			}
			endf(first_snake_score, second_snake_score, 1);
		}
		
		if(check_walls(x2, y2) == 1){
			if(check_tail(x, y, x2, y2, length2) == 1){
				endf(first_snake_score, second_snake_score, 2);
			}
			if(check_own_tail(x, y, length) == 1){
				endf(first_snake_score, second_snake_score, 2);
			}
			endf(first_snake_score, second_snake_score, 0);
		}
		
		if(check_own_tail(x, y, length) == 1){
			if(check_own_tail(x2, y2, length2) == 1){
				endf(first_snake_score, second_snake_score, 2);
			}
			if(check_tail(x2, y2, x, y, length) == 1){
				endf(first_snake_score, second_snake_score, 2);
			}
			endf(first_snake_score, second_snake_score, 1);
		}
		
		if(check_own_tail(x2, y2, length2) == 1){
			if(check_tail(x, y, x2, y2, length2) == 1){
				endf(first_snake_score, second_snake_score, 2);
			}
			endf(first_snake_score, second_snake_score, 0);
		}
		
		if(check_tail(x, y, x2, y2, length2) == 1){
			if(check_tail(x2, y2, x, y, length) == 1){
				endf(first_snake_score, second_snake_score, 2);
			}
			endf(first_snake_score, second_snake_score, 1);
		}
		
		if(check_tail(x2, y2, x, y, length) == 1){
			endf(first_snake_score, second_snake_score, 0);
		}
		
		if(x2[0] == x[0] && y2[0] == y[0]){ // проверка на сталкивание головами
        	endf(first_snake_score, second_snake_score, 2);
		} 
    }
}

int endf(int first_snake_score, int second_snake_score, int winer){
	
	closegraph();
    system("cls");
    
    if(winer == 0){
        cout << "The first snake won\n";
        cout << "First snake score is : " << first_snake_score;
        cout << "\nSecond snake score is : " << second_snake_score;
    }
    
    else if(winer == 1){
        cout << "The second snake won\n";
        cout << "First snake score is : " << first_snake_score;
        cout << "\nSecond snake score is : " << second_snake_score;
    }
    
    else if(winer == 2){
        cout << "Draw\n";
        cout << "First snake score is : " << first_snake_score;
        cout << "\nSecond snake score is : " << second_snake_score;
    }
    
    getch();
    return 0;
}

int check_walls(int x[], int y[]){
	if(x[0] >= 640 || x[0] <= 0 || y[0] <= 0 || y[0] >= 480){
		return 1;
	}
	return 0;
}

int check_tail(int x[], int y[], int x2[], int y2[], int length2){
	for(int i = 1; i < length2; i++){
        if(x[0] == x2[i] && y[0] == y2[i]){
            return 1;
        }
    }
    return 0;
}

int check_own_tail(int x[], int y[], int length){
	for(int i = 2; i < length; i++){
        if(x[0] == x[i] && y[0] == y[i]){
            return 1;
        }
    }
    return 0;
}
