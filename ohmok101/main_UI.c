#include "game_engine.h"
#include "main.h"
#include "main_UI.h"
#include "Rank.h"

void print_main1() {
	system("cls");
	printf("\n");
	printf(" �����  ���  ��� ����      ����  �����  ���   ���\n");
	printf("���  ��� ���  ��� �����  ����� ���  ��� ���  ���\n");
	printf("���  ��� ������ ��� ����� ��� ���  ��� �����\n");
	printf("���  ��� ���  ��� ���   ���   ��� ���  ��� ���  ���\n");
	printf(" �����  ���  ��� ���          ���  �����  ���   ���\n\n\n");
	char** getmode = (char**)malloc(sizeof(char*) * 20);
	getmode[0] = "    <Select Mode with Space>\n\n";
	getmode[1] = "         �� ���� ���� ��";
	getmode[2] = "            ���� ���";
	getmode[3] = "            ���� �ɼ�";
	getmode[4] = "            ��ũ ����";
	getmode[5] = "            ���� ����";
	printf("\n\t\t%29s", getmode[0]);
	for (int i = 1; i < 6; i++)
		printf("\t\t%s\n", getmode[i]);
}
void print_main2() {
	system("cls");
	printf("\n");
	printf(" �����  ���  ��� ����      ����  �����  ���   ���\n");
	printf("���  ��� ���  ��� �����  ����� ���  ��� ���  ���\n");
	printf("���  ��� ������ ��� ����� ��� ���  ��� �����\n");
	printf("���  ��� ���  ��� ���   ���   ��� ���  ��� ���  ���\n");
	printf(" �����  ���  ��� ���          ���  �����  ���   ���\n\n\n");
	char** getmode = (char**)malloc(sizeof(char*) * 20);
	getmode[0] = "    <Select Mode with Space>\n\n";
	getmode[1] = "            ���� ����";
	getmode[2] = "         �� ���� ��� ��";
	getmode[3] = "            ���� �ɼ�";
	getmode[4] = "            ��ũ ����";
	getmode[5] = "            ���� ����";
	printf("\n\t\t%29s", getmode[0]);
	for (int i = 1; i < 6; i++)
		printf("\t\t%s\n", getmode[i]);
}
void print_main3() {
	system("cls");
	printf("\n");
	printf(" �����  ���  ��� ����      ����  �����  ���   ���\n");
	printf("���  ��� ���  ��� �����  ����� ���  ��� ���  ���\n");
	printf("���  ��� ������ ��� ����� ��� ���  ��� �����\n");
	printf("���  ��� ���  ��� ���   ���   ��� ���  ��� ���  ���\n");
	printf(" �����  ���  ��� ���          ���  �����  ���   ���\n\n\n");
	char** getmode = (char**)malloc(sizeof(char*) * 20);
	getmode[0] = "    <Select Mode with Space>\n\n";
	getmode[1] = "            ���� ����";
	getmode[2] = "            ���� ���";
	getmode[3] = "         �� ���� �ɼ� ��";
	getmode[4] = "            ��ũ ����";
	getmode[5] = "            ���� ����";
	printf("\n\t\t%29s", getmode[0]);
	for (int i = 1; i < 6; i++)
		printf("\t\t%s\n", getmode[i]);
}
void print_main4() {
	system("cls");
	printf("\n");
	printf(" �����  ���  ��� ����      ����  �����  ���   ���\n");
	printf("���  ��� ���  ��� �����  ����� ���  ��� ���  ���\n");
	printf("���  ��� ������ ��� ����� ��� ���  ��� �����\n");
	printf("���  ��� ���  ��� ���   ���   ��� ���  ��� ���  ���\n");
	printf(" �����  ���  ��� ���          ���  �����  ���   ���\n\n\n");
	char** getmode = (char**)malloc(sizeof(char*) * 20);
	getmode[0] = "    <Select Mode with Space>\n\n";
	getmode[1] = "            ���� ����";
	getmode[2] = "            ���� ���";
	getmode[3] = "            ���� �ɼ�";
	getmode[4] = "         �� ��ũ ���� ��";
	getmode[5] = "            ���� ����";
	printf("\n\t\t%29s", getmode[0]);
	for (int i = 1; i < 6; i++)
		printf("\t\t%s\n", getmode[i]);
}
void print_main5() {
	system("cls");
	printf("\n");
	printf(" �����  ���  ��� ����      ����  �����  ���   ���\n");
	printf("���  ��� ���  ��� �����  ����� ���  ��� ���  ���\n");
	printf("���  ��� ������ ��� ����� ��� ���  ��� �����\n");
	printf("���  ��� ���  ��� ���   ���   ��� ���  ��� ���  ���\n");
	printf(" �����  ���  ��� ���          ���  �����  ���   ���\n\n\n");
	char** getmode = (char**)malloc(sizeof(char*) * 20);
	getmode[0] = "    <Select Mode with Space>\n\n";
	getmode[1] = "            ���� ����";
	getmode[2] = "            ���� ���";
	getmode[3] = "            ���� �ɼ�";
	getmode[4] = "            ��ũ ����";
	getmode[5] = "         �� ���� ���� ��";
	printf("\n\t\t%29s", getmode[0]);
	for (int i = 1; i < 6; i++)
		printf("\t\t%s\n", getmode[i]);
}


void print_game1() { system("cls"); gotoxy(1, 5); printf("\n\n\t\t\t <���Ӹ�� ����>\n\n\n\t\t         �� �̱� ��� ��\n\n\t\t\t    ��Ƽ ���\n"); }
void print_game2() { system("cls"); gotoxy(1, 5); printf("\n\n\t\t\t <���Ӹ�� ����>\n\n\n\t\t            �̱� ���\n\n\t\t\t �� ��Ƽ ��� ��\n"); }


void print_sound1() { gotoxy(1, 5); printf("\n\n\n\t\t\t  <ȿ���� ����>\n\n\t\t            �� ON  ��    \n\t\t\t       OFF    \n\t\t\t"); }
void print_sound2() { gotoxy(1, 5); printf("\n\n\n\t\t\t  <ȿ���� ����>\n\n\t\t               ON    \n\t\t\t    �� OFF ��    \n\t\t\t"); }
void print_bug_report() { gotoxy(1, 15); printf("\t���� ���� : sdc9703 @ naver.com"); }
void print_Options_check1() { gotoxy(1, 5); printf("\n\n\n\t\t\t  <�Ҹ� ����>\n\n\t\t       �� ȿ���� ���� ��      \n\t\t          ����� ����    \n\t\t\t"); }
void print_Options_check2() { gotoxy(1, 5); printf("\n\n\n\t\t\t  <�Ҹ� ����>\n\n\t\t          ȿ���� ����    \n\t\t       �� ����� ���� ��     \n\t\t\t"); }
void print_Bgm1() { gotoxy(1, 5); printf("\n\n\n\t\t\t  <����� ����>\n\n\t\t            �� ON  ��    \n\t\t\t       OFF    \n\t\t\t"); }
void print_Bgm2() { gotoxy(1, 5); printf("\n\n\n\t\t\t  <����� ����>\n\n\t\t               ON    \n\t\t\t    �� OFF ��    \n\t\t\t"); }
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
	printf("\n\t�ذ��� ����\n\n\t���θ޴��� ������ esc");
	if (sound_check() == '0') printf("\n\t������ ȿ���� OFF");
	else if (sound_check() == '1') printf("\n\t������ ȿ���� ON");
	if (sound_check2() == '0') printf("\n\t������ ����� OFF");
	else if (sound_check2() == '1') printf("\n\t������ ����� ON");

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
		choice = 0;	//�Ҹ�OFF
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
	printf("\n\t�ذ��� ����\n\n\t���θ޴��� ������ esc");
	if (sound_check() == '0') {
		printf("\n\t������ ȿ���� OFF");
		goto TWO;
	}
	else if (sound_check() == '1') {
		printf("\n\t������ ȿ���� ON");
		goto ONE;
	}

ONE:
	print_sound1();
	print_bug_report();
	printf("\n\t��ó : sellbuymusic");
	key = _getch();
	if (key == 32) {
		ON_OFF = 1;	//�Ҹ� ON
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
	printf("\n\t��ó : sellbuymusic");
	key = _getch();
	if (key == 32) {
		ON_OFF = 0;	//�Ҹ�OFF
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
	printf("\n\t�ذ��� ����\n\n\t���θ޴��� ������ esc");
	if (sound_check2() == '0') {
		printf("\n\t������ ����� OFF");
		goto TWO;
	}
	else if (sound_check2() == '1') {
		printf("\n\t������ ����� ON");
		goto ONE;
	}

ONE:
	print_Bgm1();
	print_bug_report();
	printf("\n\t��ó : [�ν�Ʈ��ũ��OST] 04_âõ (Chang Chun) \n\tLOST ARK Soundtrack (Vol.3 In-Game Track)");
	key = _getch();
	if (key == 32) {
		ON_OFF = 1;	//�Ҹ� ON
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
	printf("\n\t��ó : [�ν�Ʈ��ũ��OST] 04_âõ (Chang Chun) \n\tLOST ARK Soundtrack (Vol.3 In-Game Track)");
	key = _getch();
	if (key == 32) {
		ON_OFF = 0;	//�Ҹ�OFF
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
	openBgm.lpstrElementName = TEXT("bgm3.wav"); //���� ����
	openBgm.lpstrDeviceType = TEXT("mpegvideo"); //mp3 ����
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
	dwID = openBgm.wDeviceID;
	if (a == '1')		//�����ȣ�� ���
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm); //���� �ݺ� ���
	else	//��� ���� ��ȣ�� ����
		mciSendCommand(dwID, MCI_PAUSE, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm);		//��� ����
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
	printf("\n\n\t              ���θ޴��� ������ esc");
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

void print_single1() { system("cls"); gotoxy(1, 5); printf("\n\n\t\t\t  <���̵� ����>\n\n\t\t         �� ���� ��� ��\n\n\t\t\t    ��� ���\n\n\t\t\t    �ϵ� ���"); }
void print_single2() { system("cls"); gotoxy(1, 5); printf("\n\n\t\t\t  <���̵� ����>\n\n\t\t            ���� ���\n\n\t\t\t �� ��� ��� ��\n\n\t\t\t    �ϵ� ���"); }
void print_single3() { system("cls"); gotoxy(1, 5); printf("\n\n\t\t\t  <���̵� ����>\n\n\t\t            ���� ���\n\n\t\t\t    ��� ���\n\n\t\t\t �� �ϵ� ��� ��"); }

void print_warnnig() {
	textcolor(4);
	printf("\n\n\n\t\t �ٽ��ϱ� | ���θ޴� | ��������\n\t\t    ���ý� �й�� ���ֵ˴ϴ�");
	textcolor(15);
}

void print_pause1() {
	system("cls");
	printf("\n\n\t\t\t   <�Ͻ�����>\n\n\n\t\t\t �� ����ϱ� ��\n\n\n\t\t\t    �ٽ��ϱ�\n\n\n\t\t\t    ���θ޴�\n\n\n\t\t\t    ��������");
}
void print_pause2() {
	system("cls");
	printf("\n\n\t\t\t   <�Ͻ�����>\n\n\n\t\t\t    ����ϱ� \n\n\n\t\t\t �� �ٽ��ϱ� ��\n\n\n\t\t\t    ���θ޴�\n\n\n\t\t\t    ��������");
}
void print_pause3() {
	system("cls");
	printf("\n\n\t\t\t   <�Ͻ�����>\n\n\n\t\t\t    ����ϱ� \n\n\n\t\t\t    �ٽ��ϱ�\n\n\n\t\t\t �� ���θ޴� ��\n\n\n\t\t\t    ��������");
}
void print_pause4() {
	system("cls");
	printf("\n\n\t\t\t   <�Ͻ�����>\n\n\n\t\t\t    ����ϱ� \n\n\n\t\t\t    �ٽ��ϱ�\n\n\n\t\t\t    ���θ޴�\n\n\n\t\t\t �� �������� ��");
}

void print_afvic1() {
	system("cls"); gotoxy(1, 5); printf("\n\n\n\t\t\t   <�޴�����>\n\n\t\t         �� �ٽ��ϱ� ��\n\n\t\t\t    ���θ޴�\n\n\t\t\t    ��������");
}
void print_afvic2() {
	system("cls"); gotoxy(1, 5); printf("\n\n\n\t\t\t   <�޴�����>\n\n\t\t            �ٽ��ϱ�\n\n\t\t\t �� ���θ޴� ��\n\n\t\t\t    ��������");
}
void print_afvic3() {
	system("cls"); gotoxy(1, 5); printf("\n\n\n\t\t\t   <�޴�����>\n\n\t\t            �ٽ��ϱ�\n\n\t\t\t    ���θ޴�\n\n\t\t\t �� �������� ��");
}