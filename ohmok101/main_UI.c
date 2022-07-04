#include "game_engine.h"
#include "main.h"
#include "main_UI.h"
#include "Rank.h"

void print_main1() {
	system("cls");
	printf("\n");
	printf(" ■■■■  ■■  ■■ ■■■      ■■■  ■■■■  ■■   ■■\n");
	printf("■■  ■■ ■■  ■■ ■■■■  ■■■■ ■■  ■■ ■■  ■■\n");
	printf("■■  ■■ ■■■■■ ■■ ■■■■ ■■ ■■  ■■ ■■■■\n");
	printf("■■  ■■ ■■  ■■ ■■   ■■   ■■ ■■  ■■ ■■  ■■\n");
	printf(" ■■■■  ■■  ■■ ■■          ■■  ■■■■  ■■   ■■\n\n\n");
	char** getmode = (char**)malloc(sizeof(char*) * 20);
	getmode[0] = "    <Select Mode with Space>\n\n";
	getmode[1] = "         ▶ 게임 시작 ◀";
	getmode[2] = "            조작 방법";
	getmode[3] = "            게임 옵션";
	getmode[4] = "            랭크 전적";
	getmode[5] = "            게임 종료";
	printf("\n\t\t%29s", getmode[0]);
	for (int i = 1; i < 6; i++)
		printf("\t\t%s\n", getmode[i]);
}
void print_main2() {
	system("cls");
	printf("\n");
	printf(" ■■■■  ■■  ■■ ■■■      ■■■  ■■■■  ■■   ■■\n");
	printf("■■  ■■ ■■  ■■ ■■■■  ■■■■ ■■  ■■ ■■  ■■\n");
	printf("■■  ■■ ■■■■■ ■■ ■■■■ ■■ ■■  ■■ ■■■■\n");
	printf("■■  ■■ ■■  ■■ ■■   ■■   ■■ ■■  ■■ ■■  ■■\n");
	printf(" ■■■■  ■■  ■■ ■■          ■■  ■■■■  ■■   ■■\n\n\n");
	char** getmode = (char**)malloc(sizeof(char*) * 20);
	getmode[0] = "    <Select Mode with Space>\n\n";
	getmode[1] = "            게임 시작";
	getmode[2] = "         ▶ 조작 방법 ◀";
	getmode[3] = "            게임 옵션";
	getmode[4] = "            랭크 전적";
	getmode[5] = "            게임 종료";
	printf("\n\t\t%29s", getmode[0]);
	for (int i = 1; i < 6; i++)
		printf("\t\t%s\n", getmode[i]);
}
void print_main3() {
	system("cls");
	printf("\n");
	printf(" ■■■■  ■■  ■■ ■■■      ■■■  ■■■■  ■■   ■■\n");
	printf("■■  ■■ ■■  ■■ ■■■■  ■■■■ ■■  ■■ ■■  ■■\n");
	printf("■■  ■■ ■■■■■ ■■ ■■■■ ■■ ■■  ■■ ■■■■\n");
	printf("■■  ■■ ■■  ■■ ■■   ■■   ■■ ■■  ■■ ■■  ■■\n");
	printf(" ■■■■  ■■  ■■ ■■          ■■  ■■■■  ■■   ■■\n\n\n");
	char** getmode = (char**)malloc(sizeof(char*) * 20);
	getmode[0] = "    <Select Mode with Space>\n\n";
	getmode[1] = "            게임 시작";
	getmode[2] = "            조작 방법";
	getmode[3] = "         ▶ 게임 옵션 ◀";
	getmode[4] = "            랭크 전적";
	getmode[5] = "            게임 종료";
	printf("\n\t\t%29s", getmode[0]);
	for (int i = 1; i < 6; i++)
		printf("\t\t%s\n", getmode[i]);
}
void print_main4() {
	system("cls");
	printf("\n");
	printf(" ■■■■  ■■  ■■ ■■■      ■■■  ■■■■  ■■   ■■\n");
	printf("■■  ■■ ■■  ■■ ■■■■  ■■■■ ■■  ■■ ■■  ■■\n");
	printf("■■  ■■ ■■■■■ ■■ ■■■■ ■■ ■■  ■■ ■■■■\n");
	printf("■■  ■■ ■■  ■■ ■■   ■■   ■■ ■■  ■■ ■■  ■■\n");
	printf(" ■■■■  ■■  ■■ ■■          ■■  ■■■■  ■■   ■■\n\n\n");
	char** getmode = (char**)malloc(sizeof(char*) * 20);
	getmode[0] = "    <Select Mode with Space>\n\n";
	getmode[1] = "            게임 시작";
	getmode[2] = "            조작 방법";
	getmode[3] = "            게임 옵션";
	getmode[4] = "         ▶ 랭크 전적 ◀";
	getmode[5] = "            게임 종료";
	printf("\n\t\t%29s", getmode[0]);
	for (int i = 1; i < 6; i++)
		printf("\t\t%s\n", getmode[i]);
}
void print_main5() {
	system("cls");
	printf("\n");
	printf(" ■■■■  ■■  ■■ ■■■      ■■■  ■■■■  ■■   ■■\n");
	printf("■■  ■■ ■■  ■■ ■■■■  ■■■■ ■■  ■■ ■■  ■■\n");
	printf("■■  ■■ ■■■■■ ■■ ■■■■ ■■ ■■  ■■ ■■■■\n");
	printf("■■  ■■ ■■  ■■ ■■   ■■   ■■ ■■  ■■ ■■  ■■\n");
	printf(" ■■■■  ■■  ■■ ■■          ■■  ■■■■  ■■   ■■\n\n\n");
	char** getmode = (char**)malloc(sizeof(char*) * 20);
	getmode[0] = "    <Select Mode with Space>\n\n";
	getmode[1] = "            게임 시작";
	getmode[2] = "            조작 방법";
	getmode[3] = "            게임 옵션";
	getmode[4] = "            랭크 전적";
	getmode[5] = "         ▶ 게임 종료 ◀";
	printf("\n\t\t%29s", getmode[0]);
	for (int i = 1; i < 6; i++)
		printf("\t\t%s\n", getmode[i]);
}


void print_game1() { system("cls"); gotoxy(1, 5); printf("\n\n\t\t\t <게임모드 선택>\n\n\n\t\t         ▶ 싱글 모드 ◀\n\n\t\t\t    멀티 모드\n"); }
void print_game2() { system("cls"); gotoxy(1, 5); printf("\n\n\t\t\t <게임모드 선택>\n\n\n\t\t            싱글 모드\n\n\t\t\t ▶ 멀티 모드 ◀\n"); }


void print_sound1() { gotoxy(1, 5); printf("\n\n\n\t\t\t  <효과음 설정>\n\n\t\t            ▶ ON  ◀    \n\t\t\t       OFF    \n\t\t\t"); }
void print_sound2() { gotoxy(1, 5); printf("\n\n\n\t\t\t  <효과음 설정>\n\n\t\t               ON    \n\t\t\t    ▶ OFF ◀    \n\t\t\t"); }
void print_bug_report() { gotoxy(1, 15); printf("\t버그 제보 : sdc9703 @ naver.com"); }
void print_Options_check1() { gotoxy(1, 5); printf("\n\n\n\t\t\t  <소리 설정>\n\n\t\t       ▶ 효과음 설정 ◀      \n\t\t          배경음 설정    \n\t\t\t"); }
void print_Options_check2() { gotoxy(1, 5); printf("\n\n\n\t\t\t  <소리 설정>\n\n\t\t          효과음 설정    \n\t\t       ▶ 배경음 설정 ◀     \n\t\t\t"); }
void print_Bgm1() { gotoxy(1, 5); printf("\n\n\n\t\t\t  <배경음 설정>\n\n\t\t            ▶ ON  ◀    \n\t\t\t       OFF    \n\t\t\t"); }
void print_Bgm2() { gotoxy(1, 5); printf("\n\n\n\t\t\t  <배경음 설정>\n\n\t\t               ON    \n\t\t\t    ▶ OFF ◀    \n\t\t\t"); }
char sound_check() {
	FILE* fp = NULL;
	char check;
	fp = fopen("SoundEffect.txt", "r");
	if (fp == NULL) {
		printf("error");
		exit(1);
	}
	else {
		check = fgetc(fp);
		fclose(fp);
	}
	return check;
}
char sound_check2() {
	FILE* fp = NULL;
	char check;
	fp = fopen("Bgm.txt", "r");
	if (fp == NULL) {
		printf("error");
		exit(1);
	}
	else {
		check = fgetc(fp);
		fclose(fp);
	}
	return check;
}
void Options() {
	system("cls");
	char sound_check1 = sound_check();
	int key;
	int choice = 0;
	printf("\n\t※게임 설정\n\n\t메인메뉴로 가려면 esc");
	if (sound_check() == '0') printf("\n\t◎현재 효과음 OFF");
	else if (sound_check() == '1') printf("\n\t◎현재 효과음 ON");
	if (sound_check2() == '0') printf("\n\t◎현재 배경음 OFF");
	else if (sound_check2() == '1') printf("\n\t◎현재 배경음 ON");

ONE:
	print_Options_check1();
	print_bug_report();
	key = _getch();
	if (key == 32) {
		choice = 1;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) {
			if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto TWO;
		}
		else goto ONE;
	}
	if (key == 27) {
		back_menu();
	}

TWO:
	print_Options_check2();
	print_bug_report();
	key = _getch();
	if (key == 32) {
		choice = 0;	//소리OFF
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 72){if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto ONE; }
		else goto TWO;
	}
	if (key == 27) {
		back_menu();
	}
EXIT:
	if (choice == 1)
		Options_Effect();
	else if (choice == 0)
		Options_Bgm();
	else
		back_menu();
}
void Options_Effect() {
	system("cls");
	char sound_check1 = sound_check();
	int key;
	FILE* fp = NULL;
	char buffer[200];
	int ON_OFF = 1;
	printf("\n\t※게임 설정\n\n\t메인메뉴로 가려면 esc");
	if (sound_check() == '0') {
		printf("\n\t◎현재 효과음 OFF");
		goto TWO;
	}
	else if (sound_check() == '1') {
		printf("\n\t◎현재 효과음 ON");
		goto ONE;
	}

ONE:
	print_sound1();
	print_bug_report();
	printf("\n\t출처 : sellbuymusic");
	key = _getch();
	if (key == 32) {
		ON_OFF = 1;	//소리 ON
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) { if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto TWO; }
		else goto ONE;
	}
	if (key == 27) {
		back_menu();
	}

TWO:
	print_sound2();
	print_bug_report();
	printf("\n\t출처 : sellbuymusic");
	key = _getch();
	if (key == 32) {
		ON_OFF = 0;	//소리OFF
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 72) {
			if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto ONE;
		}
		else goto TWO;
	}
	if (key == 27) {
		back_menu();
	}
EXIT:
	fp = fopen("SoundEffect.txt", "w+");
	if (fp == NULL) {
		printf("error");
		exit(1);
	}
	fprintf(fp, "%d", ON_OFF);
	fclose(fp);

	Options();
}
void Options_Bgm() {
	system("cls");
	char sound_check1 = sound_check();
	int key;
	FILE* fp = NULL;
	char buffer[200];
	int ON_OFF = 1;
	printf("\n\t※게임 설정\n\n\t메인메뉴로 가려면 esc");
	if (sound_check2() == '0') {
		printf("\n\t◎현재 배경음 OFF");
		goto TWO;
	}
	else if (sound_check2() == '1') {
		printf("\n\t◎현재 배경음 ON");
		goto ONE;
	}

ONE:
	print_Bgm1();
	print_bug_report();
	printf("\n\t출처 : [로스트아크ㅣOST] 04_창천 (Chang Chun) \n\tLOST ARK Soundtrack (Vol.3 In-Game Track)");
	key = _getch();
	if (key == 32) {
		ON_OFF = 1;	//소리 ON
		MainSound('1');
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) {
			if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto TWO;
		}
		else goto ONE;
	}
	if (key == 27) {
		back_menu();
	}

TWO:
	print_Bgm2();
	print_bug_report();
	printf("\n\t출처 : [로스트아크ㅣOST] 04_창천 (Chang Chun) \n\tLOST ARK Soundtrack (Vol.3 In-Game Track)");
	key = _getch();
	if (key == 32) {
		ON_OFF = 0;	//소리OFF
		MainSound('0');
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 72) {
			if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto ONE;
		}
		else goto TWO;
	}
	if (key == 27) {
		back_menu();
	}
EXIT:
	fp = fopen("Bgm.txt", "w+");
	if (fp == NULL) {
		printf("error");
		exit(1);
	}
	fprintf(fp, "%d", ON_OFF);
	fclose(fp);

	Options();
}
void MainSound(char a)
{
	openBgm.lpstrElementName = TEXT("bgm3.wav"); //파일 오픈
	openBgm.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
	dwID = openBgm.wDeviceID;
	if (a == '1')		//재생신호시 재생
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm); //음악 반복 재생
	else	//재생 정지 신호시 정지
		mciSendCommand(dwID, MCI_PAUSE, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm);		//재생 정지
}


void How_To_Play() {
	system("cls");
	char key;
	FILE* fp = NULL;
	char buffer[200];
	fp = fopen("Sample.txt", "r");

	if (fp == NULL) {
		printf("error");
		exit(1);
	}
	else {
		while (fgets(buffer, sizeof(buffer), fp) != NULL) {
			printf("%s", buffer);
			memset(buffer, 0, sizeof(buffer));
		}
		fclose(fp);
	}

	//char** get_rules = (char**)malloc(sizeof(char*) * 100);
	printf("\n\n\t              메인메뉴로 가려면 esc");
	key = _getch();
	if (key == 27) {
		back_menu();
	}
	else How_To_Play();
}


void back_menu() {
	system("cls");
	firi();
}

void print_single1() { system("cls"); gotoxy(1, 5); printf("\n\n\t\t\t  <난이도 선택>\n\n\t\t         ▶ 연습 모드 ◀\n\n\t\t\t    노멀 모드\n\n\t\t\t    하드 모드"); }
void print_single2() { system("cls"); gotoxy(1, 5); printf("\n\n\t\t\t  <난이도 선택>\n\n\t\t            연습 모드\n\n\t\t\t ▶ 노멀 모드 ◀\n\n\t\t\t    하드 모드"); }
void print_single3() { system("cls"); gotoxy(1, 5); printf("\n\n\t\t\t  <난이도 선택>\n\n\t\t            연습 모드\n\n\t\t\t    노멀 모드\n\n\t\t\t ▶ 하드 모드 ◀"); }

void print_warnnig() {
	textcolor(4);
	printf("\n\n\n\t\t 다시하기 | 메인메뉴 | 게임종료\n\t\t    선택시 패배로 간주됩니다");
	textcolor(15);
}

void print_pause1() {
	system("cls");
	printf("\n\n\t\t\t   <일시정지>\n\n\n\t\t\t ▶ 계속하기 ◀\n\n\n\t\t\t    다시하기\n\n\n\t\t\t    메인메뉴\n\n\n\t\t\t    게임종료");
}
void print_pause2() {
	system("cls");
	printf("\n\n\t\t\t   <일시정지>\n\n\n\t\t\t    계속하기 \n\n\n\t\t\t ▶ 다시하기 ◀\n\n\n\t\t\t    메인메뉴\n\n\n\t\t\t    게임종료");
}
void print_pause3() {
	system("cls");
	printf("\n\n\t\t\t   <일시정지>\n\n\n\t\t\t    계속하기 \n\n\n\t\t\t    다시하기\n\n\n\t\t\t ▶ 메인메뉴 ◀\n\n\n\t\t\t    게임종료");
}
void print_pause4() {
	system("cls");
	printf("\n\n\t\t\t   <일시정지>\n\n\n\t\t\t    계속하기 \n\n\n\t\t\t    다시하기\n\n\n\t\t\t    메인메뉴\n\n\n\t\t\t ▶ 게임종료 ◀");
}

void print_afvic1() {
	system("cls"); gotoxy(1, 5); printf("\n\n\n\t\t\t   <메뉴선택>\n\n\t\t         ▶ 다시하기 ◀\n\n\t\t\t    메인메뉴\n\n\t\t\t    게임종료");
}
void print_afvic2() {
	system("cls"); gotoxy(1, 5); printf("\n\n\n\t\t\t   <메뉴선택>\n\n\t\t            다시하기\n\n\t\t\t ▶ 메인메뉴 ◀\n\n\t\t\t    게임종료");
}
void print_afvic3() {
	system("cls"); gotoxy(1, 5); printf("\n\n\n\t\t\t   <메뉴선택>\n\n\t\t            다시하기\n\n\t\t\t    메인메뉴\n\n\t\t\t ▶ 게임종료 ◀");
}