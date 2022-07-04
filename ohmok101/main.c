#include "game_engine.h"
#include "main.h"
#include "main_UI.h"
#include "Rank.h"

void firi();

int main() {
	char a = NULL;
	a = sound_check2();
	MainSound(a);
	system("mode con cols=64 lines=20");
	CursorView();
	firi();
	return 0;
}
void Game_start() {
	system("cls");
	char sound_check1 = sound_check();
	int level = 0;
	int key = NULL;
	print_game1();
ONE:
	gotoxy(1, 4);
	print_game1();
	key = _getch();
	if (key == 32) {
		level = 1;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) {
			if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto TWO;
		}
		else goto ONE;
	}
	if (key == 27) firi();

TWO:
	gotoxy(1, 4);
	print_game2();
	key = _getch();
	if (key == 32) {
		level = 2;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) goto TWO;
		else if (key == 72) {
			if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto ONE;
		}
		else goto TWO;
	}
	if (key == 27) firi();
EXIT: {
	system("cls");
	switch (level) {
	case 1: Ch_single();
	case 2: multi_mode();
	}

	}


}



void AI_Practice() {
	system("cls");
	single_mode_Practice();
}
void AI_Normal() {
	system("cls");
	single_mode_Normal();
}
void AI_Hard() {
	system("cls");
	single_mode_Hard();
}


void CursorView()//콘솔커서 지우기
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void textcolor(int color_number)//콘솔출력 색 변경
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
void gotoxy(int x, int y)//좌표이동
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void firi() {
	char sound_check1 = sound_check();
	int level = 0;
	int key = NULL;
	system("cls");
	print_main1();

ONE:
	gotoxy(1, 4);
	print_main1();
	key = _getch();
	if (key == 32) {
		level = 1;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) goto TWO;
		else goto ONE;
	}
	if (key == 27) goto ONE;
	else goto ONE;
TWO:
	gotoxy(1, 4);
	print_main2();
	if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC);
	key = _getch();
	if (key == 32) {
		level = 2;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) goto THREE;
		else if (key == 72) { if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto ONE; }
		else goto ONE;
	}
	if (key == 27) goto TWO;
	else goto TWO;
THREE:
	gotoxy(1, 4);
	print_main3();
	if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC);
	key = _getch();
	if (key == 32) {
		level = 3;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) goto FOUR;
		else if (key == 72) goto TWO;
		else goto TWO;
	}
	if (key == 27) goto THREE;
	else goto THREE;
FOUR:
	gotoxy(1, 4);
	print_main4();
	if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC);
	key = _getch();
	if (key == 32) {
		level = 4;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) {
			if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto FIVE;
		}
		else if (key == 72) goto THREE;
		else goto THREE;
	}
	if (key == 27) goto FOUR;
	else goto FOUR;

FIVE:
	gotoxy(1, 4);
	print_main5();
	key = _getch();
	if (key == 32) {
		level = 5;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 72) goto FOUR;
		else goto FIVE;
	}
	if (key == 27) goto FIVE;
	else goto FIVE;

EXIT: {
	system("cls");
	switch (level) {
	case 1: Game_start();
	case 2: How_To_Play();
	case 3: Options();
	case 4: rankout();
	case 5: exit(1);
	}

	}
}