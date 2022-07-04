#include "game_engine.h"
#include "main.h"
#include "main_UI.h"
#include "Rank.h"
char* stone = "��";//��
char* b = "��";
char a = 0xa6;//Ȯ�� �ϼ��ڸ� ����ϱ����� ����
float matchcount = 0, winscount = 0, losecount = 0;
player p1 = { 0, };


void multi_mode() {
	char sound_check1 = sound_check();
	system("cls");
	char* stone = "��";//��
	char a = 0xa6;//Ȯ�� �ϼ��ڸ� ����ϱ����� ����
	int turn = 1;
	int x = 19, y = 10, other = 0;
	int x_s = 19, y_s = 10;
	char matrix[SIZE + 1][SIZE + 1] = { 0, };
	int matrix_data[SIZE + 2][SIZE + 2] = { 0 };//����ġ ����� ������
	char key;//Ű���尪
	int third_stone_check = 0;
	for (int i = 0; i < SIZE + 2; i++) {
		matrix_data[i][0] = 21;
		matrix_data[0][i] = 21;
		matrix_data[SIZE + 1][i] = 21;
		matrix_data[i][SIZE + 1] = 21;

	}
	clock_t start, end = 20;
	long cl = 60;
	start = clock();
	clock_t pause_start = 0, pause_end = 0;
again:
	
	textcolor(96);
	matrix_save(matrix);
	matrix_draw(matrix);
	display_stone(matrix_data);
	gotoxy(x, y);


	while (1) {
		textcolor(15);
		gotoxy(1, 5);
		printf("\n\t\t\t\t\t  ==================\n");
		printf("\t\t\t\t\t       Turn = %d\n", turn);
		if (turn % 2 == 1)printf("\t\t\t\t\t  ���� ���� : �浹\n");
		else printf("\t\t\t\t\t  ���� ���� : �鵹\n");
		printf("\t\t\t\t\t  ==================\n");
		textcolor(96);//������;
		if (_kbhit()) {
			key = _getch();
			if (key == 27) { pause_start = clock(); if (pause_multi_game() == 0) { pause_end = pause_end + clock() - pause_start; goto again; } }
			else if (key == 32) {//32 = SPACE
				if (draw_stone_error(matrix_data, (x + 1) / 2, y) == 0 && third_stone_check == 0) {
					if (other == 0) stone_Pronunciation(matrix_data, (x + 1) / 2, y, 1);//����ġ ����
					else if (other == 1) stone_Pronunciation(matrix_data, (x + 1) / 2, y, -1);//����ġ ����
					other = 1 - other;//������
					if (sound_check1 == '1') PlaySound(TEXT("Blop.wav"), NULL, SND_ASYNC);
					start = clock();
					turn++;
				}
				gotoxy(70, 30);
				if (victroy(matrix_data) == 10) { print_victory(1, 9, "�浹 �¸�"); After_victory(3, p1); }
				else if (victroy(matrix_data) == 20) { print_victory(1, 9, "�鵹 �¸�"); After_victory(3, p1); }
				cl = 60;
			}
			if (key >= 72) move_arrow_key(key, &x, &y, 37, 19);//Ű�� �ν� 37�� x�ִ� 19�� y�ִ�
			set_stone(matrix, x_s, y_s, matrix_data);
			gotoxy(x, y);
			x_s = x;
			y_s = y;
			if (matrix_data[(x + 1) / 2][y] > 9) textcolor(108);//�ٵϵ��� ���������� ������
			else if (other == 1) textcolor(111);//other�� 1�̸� ���
			if ((third_stone_check = third_stone(matrix_data, (x + 1) / 2, y, other)) == 1 && matrix_data[(x + 1) / 2][y] < 10) {
				printf("%s", b);
			}
			else printf("%s", stone);//�ٵϵ�
			textcolor(96);//������;
		}
		else {
			end = clock() - start - pause_end;
			long turn_time = cl - end / CLOCKS_PER_SEC;
			textcolor(15);//������;
			
			gotoxy(43, 2);
			printf("==================\n");
			gotoxy(43, 3);
			printf("     TIME : %2ld\n", turn_time);
			gotoxy(43, 4);
			printf("==================\n");
			if (turn_time == 0) {
				textcolor(96);//������;
				other = 1 - other;
				gotoxy(x, y);
				x_s = x;
				y_s = y;
				if (matrix_data[(x + 1) / 2][y] > 9) textcolor(108);//�ٵϵ��� ���������� ������
				else if (other == 1) textcolor(111);//other�� 1�̸� ���
				if ((third_stone_check = third_stone(matrix_data, (x + 1) / 2, y, other)) == 1 && matrix_data[(x + 1) / 2][y] < 10) {
					printf("%s", b);
				}
				else printf("%s", stone);//�ٵϵ�
				textcolor(96);//������;
				turn++;
				cl = 60;
				start = clock();
				end = clock() - start;
			}
		}
	}
}
void single_mode(player* p1) {
	char usrname[20];
	system("cls");
	printf("\n\n\n\n\n\t\t     �̸��� �Է��� �ּ���");
	printf("\n\n\n     (����,���� 6���� �̳�, Ư������,������� �������ּ���)");
	printf("\n\n\n\t            �г��� : ");
	
	
	scanf("%s", p1->name);
	if (6 < strlen(p1->name))
		single_mode(p1);
	system("cls");
	gotoxy(1, 7);
	printf("\n\n\t\t   %s�� �÷��̸� �����մϴ�.", p1->name);
	_getch();
	system("cls");

	matchcount = 0;
	winscount = 0;
	losecount = 0;
}
void single_mode_Practice() {
	matchcount++;
	char sound_check1 = sound_check();
	char* stone = "��";//��
	char a = 0xa6;//Ȯ�� �ϼ��ڸ� ����ϱ����� ����

	int x = 19, y = 10, other = 0;
	int x_s = 19, y_s = 10;
	char matrix[SIZE + 1][SIZE + 1] = { 0, };
	int matrix_data[SIZE + 2][SIZE + 2] = { 0 };//����ġ ����� ������
	int matrix_data_retrun[SIZE + 2][SIZE + 2] = { 0, };//0�� 1�� 
	char key;//Ű���尪
	int third_stone_check = 0;
	for (int i = 0; i < SIZE + 2; i++) {
		matrix_data[i][0] = 21;
		matrix_data[0][i] = 21;
		matrix_data[SIZE + 1][i] = 21;
		matrix_data[i][SIZE + 1] = 21;

	}
	clock_t start, end = 20;
	int turn = 1;
	long cl = 60;
	clock_t pause_start = 0, pause_end = 0;
	start = clock();
again:
	textcolor(96);
	matrix_save(matrix);
	matrix_draw(matrix);
	display_stone(matrix_data);
	gotoxy(x, y);
	printf("%s", stone);//�ٵϵ�

	int back_num = 0;

	while (1) {
		textcolor(15);
		gotoxy(1, 5);
		printf("\n\t\t\t\t\t  ==================\n");
		printf("\t\t\t\t\t       Turn = %d\n", turn);
		if (turn % 2 == 1)printf("\t\t\t\t\t  ���� ���� : �浹\n");
		else printf("\t\t\t\t\t  ���� ���� : �鵹\n");
		printf("\t\t\t\t\t  ==================\n");
		textcolor(96);//������;
		if (_kbhit()) {
			key = _getch();
			if (key == 27) { pause_start = clock(); if (pause_single_game(0) == 0) { pause_end = pause_end + clock() - pause_start; goto again; } }
			else if (key == 32) {//32 = SPACE
				for (int i = 1; i < SIZE + 1; i++) {
					for (int k = 1; k < SIZE + 1; k++) {
						matrix_data_retrun[k][i] = matrix_data[k][i];
					}
				}

				if (draw_stone_error(matrix_data, (x + 1) / 2, y) == 0 && third_stone_check == 0) {
					stone_Pronunciation(matrix_data, (x + 1) / 2, y, 1);//����ġ ����
					if (sound_check1 == '1') PlaySound(TEXT("Blop.wav"), NULL, SND_ASYNC);
					Sleep(800);
					AI(matrix_data);
					if (sound_check1 == '1') PlaySound(TEXT("Blop.wav"), NULL, SND_ASYNC);
					start = clock();
					turn += 2;
				}
				if (victroy(matrix_data) == 10) { print_victory(1, 9, "�浹 �¸�"); winscount++; After_victory(0, p1); }
				else if (victroy(matrix_data) == 20) { print_victory(1, 9, "�鵹 �¸�"); losecount++; After_victory(0, p1); }
				cl = 60;
				if (back_num < 2)back_num++;

				if (back_num == 2) {
					gotoxy(46, 17);
					textcolor(15);
					printf("������ Ȱ��ȭ");
					textcolor(96);
				}
			}

			else if (key == 8 && back_num == 2) {
				turn -= 2;
				for (int i = 1; i < SIZE + 1; i++) {
					for (int k = 1; k < SIZE + 1; k++) {
						matrix_data[k][i] = matrix_data_retrun[k][i];
					}
				}
				gotoxy(1, 1);
				matrix_draw(matrix);
				display_stone(matrix_data);
				cl = 60;
				start = clock();
				back_num = 0;
				gotoxy(46, 17);
				textcolor(15);
				printf("               ");
				textcolor(96);

			}

			else if (key >= 72) move_arrow_key(key, &x, &y, 37, 19);//Ű�� �ν� 37�� x�ִ� 19�� y�ִ�
			set_stone(matrix, x_s, y_s, matrix_data);
			gotoxy(x, y);
			x_s = x;
			y_s = y;
			if (matrix_data[(x + 1) / 2][y] > 9) textcolor(108);//�ٵϵ��� ���������� ������
			else if (other == 1) textcolor(111);//other�� 1�̸� ���
			if ((third_stone_check = third_stone(matrix_data, (x + 1) / 2, y, other)) == 1 && matrix_data[(x + 1) / 2][y] < 10) {
				printf("%s", b);
			}
			else printf("%s", stone);//�ٵϵ�
			textcolor(96);//������;
		}
		else {
			end = clock() - start - pause_end;
			long turn_time = cl - end / CLOCKS_PER_SEC;
			textcolor(15);//������;
			gotoxy(43, 2);
			printf("==================\n");
			gotoxy(43, 3);
			printf("     TIME : %2ld\n", turn_time);
			gotoxy(43, 4);
			printf("==================\n");
			if (turn_time == 0) {
				if (sound_check1 == '1') PlaySound(TEXT("Blop.wav"), NULL, SND_ASYNC);
				AI(matrix_data);
				textcolor(96);//������;
				other = 1 - other;
				gotoxy(x, y);
				x_s = x;
				y_s = y;
				if (matrix_data[(x + 1) / 2][y] > 9) textcolor(108);//�ٵϵ��� ���������� ������
				else if (other == 1) textcolor(111);//other�� 1�̸� ���
				if ((third_stone_check = third_stone(matrix_data, (x + 1) / 2, y, other)) == 1 && matrix_data[(x + 1) / 2][y] < 10) {
					printf("%s", b);
				}
				else printf("%s", stone);//�ٵϵ�
				textcolor(96);//������;
				turn += 2;
				cl = 60;
				start = clock();
				end = clock() - start;
			}
		}
	}
}
void single_mode_Normal() {
	matchcount++;
	char sound_check1 = sound_check();
	char* stone = "��";//��
	char a = 0xa6;//Ȯ�� �ϼ��ڸ� ����ϱ����� ����

	int x = 19, y = 10, other = 0;
	int x_s = 19, y_s = 10;
	char matrix[SIZE + 1][SIZE + 1] = { 0, };
	int matrix_data[SIZE + 2][SIZE + 2] = { 0 };//����ġ ����� ������
	char key;//Ű���尪
	int third_stone_check = 0;
	for (int i = 0; i < SIZE + 2; i++) {
		matrix_data[i][0] = 21;
		matrix_data[0][i] = 21;
		matrix_data[SIZE + 1][i] = 21;
		matrix_data[i][SIZE + 1] = 21;

	}
	clock_t start, end = 20;
	int turn = 1;
	long cl = 60;
	clock_t pause_start = 0, pause_end = 0;
	start = clock();
again:
	textcolor(96);
	matrix_save(matrix);
	matrix_draw(matrix);
	display_stone(matrix_data);


	gotoxy(x, y);
	printf("%s", stone);//�ٵϵ�

	while (1) {
		textcolor(15);
		gotoxy(1, 5);
		printf("\n\t\t\t\t\t  ==================\n");
		printf("\t\t\t\t\t       Turn = %d\n", turn);
		if (turn % 2 == 1)printf("\t\t\t\t\t  ���� ���� : �浹\n");
		else printf("\t\t\t\t\t  ���� ���� : �鵹\n");
		printf("\t\t\t\t\t  ==================\n");
		textcolor(96);//������;
		if (_kbhit()) {
			key = _getch();
			if (key == 27) { pause_start = clock(); if (pause_single_game(1) == 0) { pause_end = pause_end + clock() - pause_start; goto again; } }
			else if (key == 32) {//32 = SPACE
				if (draw_stone_error(matrix_data, (x + 1) / 2, y) == 0 && third_stone_check == 0) {
					stone_Pronunciation(matrix_data, (x + 1) / 2, y, 1);//����ġ ����
					if (sound_check1 == '1') PlaySound(TEXT("Blop.wav"), NULL, SND_ASYNC);
					Sleep(800);
					AI(matrix_data);
					if (sound_check1 == '1') PlaySound(TEXT("Blop.wav"), NULL, SND_ASYNC);
					start = clock();
					turn += 2;
				}
				gotoxy(70, 30);
				if (victroy(matrix_data) == 10) { print_victory(1, 9, "�浹 �¸�"); winscount++; After_victory(1, p1); }
				else if (victroy(matrix_data) == 20) { print_victory(1, 9, "�鵹 �¸�"); losecount++; After_victory(1, p1); }
				cl = 60;
			}
			if (key >= 72) move_arrow_key(key, &x, &y, 37, 19);//Ű�� �ν� 37�� x�ִ� 19�� y�ִ�
			set_stone(matrix, x_s, y_s, matrix_data);
			gotoxy(x, y);
			x_s = x;
			y_s = y;
			if (matrix_data[(x + 1) / 2][y] > 9) textcolor(108);//�ٵϵ��� ���������� ������
			else if (other == 1) textcolor(111);//other�� 1�̸� ���
			if ((third_stone_check = third_stone(matrix_data, (x + 1) / 2, y, other)) == 1 && matrix_data[(x + 1) / 2][y] < 10) {
				printf("%s", b);
			}
			else printf("%s", stone);//�ٵϵ�
			textcolor(96);//������;
		}
		else {
			end = clock() - start - pause_end;
			long turn_time = cl - end / CLOCKS_PER_SEC;
			textcolor(15);//������;
			gotoxy(43, 2);
			printf("==================\n");
			gotoxy(43, 3);
			printf("     TIME : %2ld\n", turn_time);
			gotoxy(43, 4);
			printf("==================\n");
			if (turn_time == 0) {
				if (sound_check1 == '1') PlaySound(TEXT("Blop.wav"), NULL, SND_ASYNC);
				AI(matrix_data);
				textcolor(96);//������;
				other = 1 - other;
				gotoxy(x, y);
				x_s = x;
				y_s = y;
				if (matrix_data[(x + 1) / 2][y] > 9) textcolor(108);//�ٵϵ��� ���������� ������
				else if (other == 1) textcolor(111);//other�� 1�̸� ���
				if ((third_stone_check = third_stone(matrix_data, (x + 1) / 2, y, other)) == 1 && matrix_data[(x + 1) / 2][y] < 10) {
					printf("%s", b);
				}
				else printf("%s", stone);//�ٵϵ�
				textcolor(96);//������;
				turn += 2;
				cl = 60;
				start = clock();
				end = clock() - start;
			}
		}
	}
}
void single_mode_Hard() {
	matchcount++;
	char sound_check1 = sound_check();
	char* stone = "��";//��
	char a = 0xa6;//Ȯ�� �ϼ��ڸ� ����ϱ����� ����

	int x = 19, y = 10, other = 0;
	int x_s = 19, y_s = 10;
	char matrix[SIZE + 1][SIZE + 1] = { 0, };
	int matrix_data[SIZE + 2][SIZE + 2] = { 0 };//����ġ ����� ������
	char key;//Ű���尪
	int third_stone_check = 0;
	for (int i = 0; i < SIZE + 2; i++) {
		matrix_data[i][0] = 21;
		matrix_data[0][i] = 21;
		matrix_data[SIZE + 1][i] = 21;
		matrix_data[i][SIZE + 1] = 21;

	}
	clock_t start, end = 20;
	int turn = 1;
	long cl = 20;
	clock_t pause_start = 0, pause_end = 0;
	start = clock();
again:
	textcolor(96);
	matrix_save(matrix);
	matrix_draw(matrix);
	display_stone(matrix_data);
	gotoxy(x, y);
	printf("%s", stone);//�ٵϵ�

	while (1) {
		textcolor(15);
		gotoxy(1, 5);
		printf("\n\t\t\t\t\t  ==================\n");
		printf("\t\t\t\t\t       Turn = %d\n", turn);
		if (turn % 2 == 1)printf("\t\t\t\t\t  ���� ���� : �浹\n");
		else printf("\t\t\t\t\t  ���� ���� : �鵹\n");
		printf("\t\t\t\t\t  ==================\n");
		textcolor(96);//������;
		if (_kbhit()) {
			key = _getch();
			if (key == 27) { pause_start = clock(); if (pause_single_game(2) == 0) { pause_end = pause_end + clock() - pause_start; goto again; } }
			else if (key == 32) {//32 = SPACE
				if (draw_stone_error(matrix_data, (x + 1) / 2, y) == 0 && third_stone_check == 0) {
					stone_Pronunciation(matrix_data, (x + 1) / 2, y, 1);//����ġ ����
					black2_Defance(matrix_data, (x + 1) / 2, y);
					black3_Defance(matrix_data, (x + 1) / 2, y);
					if (sound_check1 == '1') PlaySound(TEXT("Blop.wav"), NULL, SND_ASYNC);
					Sleep(800);
					AI(matrix_data);
					if (sound_check1 == '1') PlaySound(TEXT("Blop.wav"), NULL, SND_ASYNC);
					start = clock();
					turn += 2;
				}
				gotoxy(70, 30);
				if (victroy(matrix_data) == 10) { print_victory(1, 9, "�浹 �¸�"); winscount++; After_victory(2, p1); }
				else if (victroy(matrix_data) == 20) { print_victory(1, 9, "�鵹 �¸�"); losecount++;  After_victory(2, p1); }
				cl = 20;
				black3_Defance(matrix_data, (x + 1) / 2, y);
			}
			if (key >= 72) move_arrow_key(key, &x, &y, 37, 19);//Ű�� �ν� 37�� x�ִ� 19�� y�ִ�
			set_stone(matrix, x_s, y_s, matrix_data);
			gotoxy(x, y);
			x_s = x;
			y_s = y;
			if (matrix_data[(x + 1) / 2][y] > 9) textcolor(108);//�ٵϵ��� ���������� ������
			else if (other == 1) textcolor(111);//other�� 1�̸� ���
			if ((third_stone_check = third_stone(matrix_data, (x + 1) / 2, y, other)) == 1 && matrix_data[(x + 1) / 2][y] < 10) {
				printf("%s", b);
			}
			else printf("%s", stone);//�ٵϵ�
			textcolor(96);//������;
		}
		else {
			end = clock() - start - pause_end;
			long turn_time = cl - end / CLOCKS_PER_SEC;
			textcolor(15);//������;
			gotoxy(43, 2);
			printf("==================\n");
			gotoxy(43, 3);
			printf("     TIME : %2ld\n", turn_time);
			gotoxy(43, 4);
			printf("==================\n");
			if (turn_time == 0) {
				if (sound_check1 == '1') PlaySound(TEXT("Blop.wav"), NULL, SND_ASYNC);
				AI(matrix_data);
				textcolor(96);//������;
				other = 1 - other;
				gotoxy(x, y);
				x_s = x;
				y_s = y;
				if (matrix_data[(x + 1) / 2][y] > 9) textcolor(108);//�ٵϵ��� ���������� ������
				else if (other == 1) textcolor(111);//other�� 1�̸� ���
				if ((third_stone_check = third_stone(matrix_data, (x + 1) / 2, y, other)) == 1 && matrix_data[(x + 1) / 2][y] < 10) {
					printf("%s", b);
				}
				else printf("%s", stone);//�ٵϵ�
				textcolor(96);//������;
				turn += 2;
				cl = 20;
				start = clock();
				end = clock() - start;
			}
		}
	}
}


void After_victory(int input, player p1) {
	textcolor(15);
	system("cls");
	char sound_check1 = sound_check();
	int level = 0;
	int key = NULL;
	print_afvic1();
ONE:
	gotoxy(5, 5);
	print_afvic1();
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
	else goto ONE;

TWO:
	gotoxy(5, 5);
	print_afvic2();
	if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC);
	key = _getch();
	if (key == 32) {
		level = 2;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) {if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto THREE; }
		else if (key == 72) { if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto ONE; }
		else goto TWO;
	}
	else goto TWO;
THREE:
	gotoxy(5, 5);
	print_afvic3();
	key = _getch();
	if (key == 32) {
		level = 3;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) goto THREE;
		else if (key == 72) goto TWO;
		else goto THREE;
	}
	else goto THREE;
EXIT: {
	system("cls");
	switch (level) {
	case 1:
		if (input == 0) single_mode_Practice();
		if (input == 1) single_mode_Normal();
		if (input == 2) single_mode_Hard();
		if (input == 3) multi_mode();
	case 2:
		if (input != 3) {
			p1.match_count = matchcount;
			p1.wins = winscount;
			p1.lose = losecount;
			p1.draw = matchcount - winscount - losecount;
			p1.winrate = p1.wins / p1.match_count * 100;
			rankin(input, p1);
		}
		firi();
	case 3: 
		if (input != 3) {
			p1.match_count = matchcount;
			p1.wins = winscount;
			p1.lose = losecount;
			p1.draw = matchcount - winscount - losecount;
			p1.winrate = p1.wins / p1.match_count * 100;
			rankin(input, p1);
		}
		exit(1);
	}

	}


}
void Ch_single() {
	char sound_check1 = sound_check();
	int level = 0;
	int key = NULL;
	system("cls");
	print_single1();

ONE:
	gotoxy(1, 4);
	print_single1();
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
	if (key == 27) Game_start();
TWO:
	gotoxy(1, 4);
	print_single2();
	if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC);
	key = _getch();
	if (key == 32) {
		level = 2;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) {
			if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto THREE;
		}
		else if (key == 72) {
			if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto ONE;
		}
		else goto ONE;
	}
	if (key == 27) Game_start();
THREE:
	gotoxy(1, 4);
	print_single3();
	key = _getch();
	if (key == 32) {
		level = 3;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) goto THREE;
		else if (key == 72) goto TWO;
		else goto THREE;
	}
	if (key == 27) Game_start();
EXIT: {
	system("cls");
	single_mode(&p1);
	switch (level) {
	case 1: AI_Practice();
	case 2: AI_Normal();
	case 3: AI_Hard();
	}

	}
}

int pause_multi_game() {
	textcolor(15);
	system("cls");
	char sound_check1 = sound_check();
	int level = 0;
	int key = NULL;
	print_pause1();
ONE:
	gotoxy(5, 5);
	print_pause1();
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
	if (key == 27) {
		system("cls");
		return 0;
	}

TWO:
	gotoxy(5, 5);
	print_pause2();
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
		else goto TWO;
	}
	if (key == 27) {
		system("cls");
		return 0;
	}
THREE:
	gotoxy(5, 5);
	print_pause3();
	if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC);
	key = _getch();
	if (key == 32) {
		level = 3;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) {
			if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto FOUR;
		}
		else if (key == 72) goto TWO;
		else goto THREE;
	}
	if (key == 27) {
		system("cls");
		return 0;
	}
FOUR:
	gotoxy(5, 5);
	print_pause4();
	key = _getch();
	if (key == 32) {
		level = 4;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) goto FOUR;
		else if (key == 72) goto THREE;
		else goto FOUR;
	}
	if (key == 27) {
		system("cls");
		return 0;
	}
EXIT: {
	system("cls");
	switch (level) {
	case 1: return 0;
	case 2: multi_mode();
	case 3: firi();
	case 4: exit(1);
	}

	}


}
int pause_single_game(int input) {
	textcolor(15);
	system("cls");
	char sound_check1 = sound_check();
	int level = 0;
	int key = NULL;
	print_pause1();
	print_warnnig();
ONE:
	gotoxy(5, 5);
	print_pause1();
	print_warnnig();
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
	if (key == 27) {
		system("cls");
		return 0;
	}

TWO:
	gotoxy(5, 5);
	print_pause2();
	if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC);
	print_warnnig();
	key = _getch();
	if (key == 32) {
		level = 2;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) goto THREE;
		else if (key == 72) {
			if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto ONE;
		}
		else goto TWO;
	}
	if (key == 27) {
		system("cls");
		return 0;
	}
THREE:
	gotoxy(5, 5);
	print_pause3();
	if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC);
	print_warnnig();
	key = _getch();
	if (key == 32) {
		level = 3;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) { if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto FOUR; }
		else if (key == 72) goto TWO;
		else goto THREE;
	}
	if (key == 27) {
		system("cls");
		return 0;
	}
FOUR:
	gotoxy(5, 5);
	print_pause4();
	print_warnnig();
	key = _getch();
	if (key == 32) {
		level = 4;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) goto FOUR;
		else if (key == 72) goto THREE;
		else goto FOUR;
	}
	if (key == 27) {
		system("cls");
		return 0;
	}
EXIT: {
	system("cls");
	switch (level) {
	case 1: return 0;
	case 2:
		losecount++;
		if (input == 0) single_mode_Practice();
		if (input == 1) single_mode_Normal();
		if (input == 2) single_mode_Hard();
	case 3:
		losecount++;
		p1.match_count = matchcount;
		p1.wins = winscount;
		p1.lose = losecount;
		p1.draw = matchcount - winscount - losecount;
		rankin(input, p1);
		firi();
	case 4:
		losecount++;
		p1.match_count = matchcount;
		p1.wins = winscount;
		p1.lose = losecount;
		p1.draw = matchcount - winscount - losecount;
		rankin(input, p1);
		exit(1);
	}

	}


}

void matrix_draw(char matrix[SIZE + 1][SIZE + 1]) {//�ٵ��� ���
	for (int i = 1; i <= SIZE; i++) {
		for (int k = 1; k <= SIZE; k++) printf("%c%c ", a, matrix[k][i]);
		printf("\n");
	}
}
void matrix_save(char matrix[SIZE + 1][SIZE + 1]) {//�ٵ��� ����
	int i, j;
	char b[12];//Ư����������
	for (i = 1; i < 12; i++) b[i] = 0xa0 + i;//b[]�� Ư������ �Է�

	//��ܺκ�
	matrix[1][1] = b[3];//b[3]="��"
	for (i = 2; i < SIZE; i++)matrix[i][1] = b[8];//b[8]="��"
	matrix[SIZE][1] = b[4];//b[4]="��"

	//�߰��κ�
	for (i = 2; i <= SIZE - 1; i++) {
		matrix[1][i] = b[7];//b[7]="��"
		for (j = 2; j < SIZE; j++) matrix[j][i] = b[11];//b[11]="��"
		matrix[SIZE][i] = b[9];//b[9]="��"
	}

	//�ϴܺκ�
	matrix[1][SIZE] = b[6];//b[6]="��"
	for (i = 2; i < SIZE; i++) matrix[i][SIZE] = b[10];//b[10]="��"
	matrix[SIZE][SIZE] = b[5];//b[5]="��"
}
void move_arrow_key(char key, int* x1, int* y1, int x_b, int y_b) {//����Ű �Է� �ν�
	switch (key) {
	case 72:
		*y1 = *y1 - 1; //���� ������ ȭ��ǥ Ű �Է�
		if (*y1 < 1) *y1 = 1;//�ٵϵ� ��Ż ����
		break;
	case 75://2����Ʈ�̱⶧���� 2ĭ�̵�
		*x1 = *x1 - 2; //���� ������ ȭ��ǥ Ű �Է�
		if (*x1 < 1) *x1 = 1;//�ٵϵ� ��Ż ����            
		break;
	case 77://2����Ʈ�̱⶧���� 2ĭ�̵�
		*x1 = *x1 + 2; //������ ������ ȭ��ǥ Ű �Է�
		if (*x1 > x_b) *x1 = x_b;//�ٵϵ� ��Ż ����
		break;
	case 80:
		*y1 = *y1 + 1; //�Ʒ��� ������ ȭ��ǥ Ű �Է�
		if (*y1 > y_b) *y1 = y_b;//�ٵϵ� ��Ż ����
		break;
	default:
		return;
	}
}
void set_stone(char matrix[SIZE + 1][SIZE + 1], int x_s, int y_s, int matrix_data[SIZE + 2][SIZE + 2]) {//�ٵϵ� ���
	gotoxy(x_s, y_s);
	printf("%c%c ", a, matrix[(x_s + 1) / 2][y_s]);

	if (matrix_data[(x_s + 1) / 2][y_s] == 10) {
		gotoxy(x_s, y_s);
		printf("%s", stone);//�浹
	}
	else if (matrix_data[(x_s + 1) / 2][y_s] == 20) {
		gotoxy(x_s, y_s);
		textcolor(111);
		printf("%s", stone);//�鵹
		textcolor(96);
	}
}
void display_stone(int matrix[SIZE + 2][SIZE + 2]) {//��ü�� ��� -> �Ͻ������� �ٽ������ ���� �Լ�
	int x, y;//��ǥ

	for (y = 1; y < 20; y++) {
		for (x = 1; x < 20; x++) {
			if (matrix[x][y] == 10) {
				gotoxy(x * 2 - 1, y);
				printf("%s", stone);//�浹
			}
			else if (matrix[x][y] == 20) {
				gotoxy(x * 2 - 1, y);
				textcolor(111);
				printf("%s", stone);//�鵹
				textcolor(96);
			}
		}
	}
}
int draw_stone_error(int matrix_data[SIZE + 2][SIZE + 2], int x, int y) {//�ߺ��� ����
	if (matrix_data[x][y] >= 10) return 1;
	return 0;
}
void stone_Pronunciation(int matrix_data[SIZE + 2][SIZE + 2], int x, int y, int other) {//����ġ ���
	if (other == 1) matrix_data[x][y] = 10;//�浹
	else if (other == -1) matrix_data[x][y] = 20;//�鵹
	for (int i = y - 1; i < y + 2; i++) {
		for (int k = x - 1; k < x + 2; k++) {
			if (matrix_data[k][i] < 10) matrix_data[k][i] = matrix_data[k][i] + other;
		}
	}
	gotoxy(x * 2 - 1, y);
	if (other == -1) textcolor(111);//other�� 1�̸� ���
	printf("%s", stone);//�ٵϵ�
	textcolor(96);//������


}
int victroy(int matrix_data[SIZE + 2][SIZE + 2]) {

	int other = 0;
	int count = 0;
	for (int i = 1; i <= SIZE; i++) {//����
		for (int k = 1; k <= SIZE; k++) {//����
			if (matrix_data[k][i] > 9) {
				count = 0;
				other = matrix_data[k][i];

				//������ ��
				for (int j = 0; j < 5; j++) if (matrix_data[k + j][i] == other) count++;
				if (matrix_data[k + 5][i] == other) count--;
				if (matrix_data[k - 1][i] == other) count--;
				if (count == 5) return other;


				//������ �Ʒ� ��
				count = 0;
				for (int j = 0; j < 5; j++) if (matrix_data[k + j][i + j] == other) count++;
				if (matrix_data[k + 5][i + 5] == other) count--;
				if (matrix_data[k - 1][i - 1] == other) count--;
				if (count == 5) return other;


				//�Ʒ� ��
				count = 0;
				for (int j = 0; j < 5; j++) if (matrix_data[k][i + j] == other) count++;
				if (matrix_data[k][i + 5] == other) count--;
				if (matrix_data[k][i - 1] == other) count--;
				if (count == 5) return other;


				//���� �Ʒ� ��
				count = 0;
				for (int j = 0; j < 5; j++) if (matrix_data[k - j][i + j] == other) count++;
				if (matrix_data[k - 5][i + 5] == other) count--;
				if (matrix_data[k + 1][i - 1] == other) count--;
				if (count == 5) return other;

			}

		}
	}
	return 0;
}


void print_victory(int a, int b, char str[]) {
	textcolor(15);
	gotoxy(a, b);
	printf("\n\n\t\t\t\t\t  �� �� �� �� �� �� �� �� �� \n");
	printf("\t\t\t\t\t  ��               �� \n");
	printf("\t\t\t\t\t  ��    %s  �� \n", str);
	printf("\t\t\t\t\t  ��               �� \n");
	printf("\t\t\t\t\t  �� �� �� �� �� �� �� �� �� \n");
	_getch();
}



void AI(int matrix_data[SIZE + 2][SIZE + 2]) {
	int other = 0;
	int check = 0;
	int random = 0;
	int Pc_data = 0;
	int Pc_count = 0;
	int Pc_xy[400][2] = { 0, };
	srand(time(0));

	//��4
	if (check == 0) {
		for (int i = 1; i <= SIZE; i++) {//����
			for (int k = 1; k <= SIZE; k++) {//����
				if (matrix_data[k][i] > 9) {
					other = matrix_data[k][i];
					if (other == 20 && check == 0) {
						check = white4(matrix_data, k, i);
					}
				}
			}
		}
	}

	//����4
	if (check == 0) {
		for (int i = 1; i <= SIZE; i++) {//����
			for (int k = 1; k <= SIZE; k++) {//����
				if (matrix_data[k][i] > 9) {
					other = matrix_data[k][i];
					if (other == 10 && check == 0) {
						check = black4(matrix_data, k, i);
					}
				}
			}
		}
	}

	//�� 3
	if (check == 0) {
		for (int i = 1; i <= SIZE; i++) {//����
			for (int k = 1; k <= SIZE; k++) {//����
				if (matrix_data[k][i] > 9) {
					other = matrix_data[k][i];
					if (other == 20 && check == 0) {
						check = white3(matrix_data, k, i);
					}
				}
			}
		}
	}
	//�� 3
	if (check == 0) {
		for (int i = 1; i <= SIZE; i++) {//����
			for (int k = 1; k <= SIZE; k++) {//����
				if (matrix_data[k][i] > 9) {
					other = matrix_data[k][i];
					if (other == 10 && check == 0) {
						check = black3(matrix_data, k, i);
					}
				}
			}
		}
	}

	//���� 3
	if (check == 0) {
		for (int i = 1; i <= SIZE; i++) {//����
			for (int k = 1; k <= SIZE; k++) {//����
				if (matrix_data[k][i] > 9) {
					other = matrix_data[k][i];
					if (other == 20 && check == 0) {
						check = blocked_white3(matrix_data, k, i);
					}
				}
			}
		}
	}

	//��2
	if (check == 0) {
		for (int i = 1; i <= SIZE; i++) {//����
			for (int k = 1; k <= SIZE; k++) {//����
				if (matrix_data[k][i] > 9) {
					other = matrix_data[k][i];
					if (other == 20 && check == 0) {
						check = white2(matrix_data, k, i);
					}
				}
			}
		}
	}

	//�������� ����ġ ���
	if (check == 0) {
		for (int i = 1; i <= SIZE; i++) {
			for (int k = 1; k <= SIZE; k++) {
				if (matrix_data[k][i] < 9 && matrix_data[k][i] >= 0) {
					if (matrix_data[k][i] > Pc_data) {
						Pc_data = matrix_data[k][i];
						Pc_count = 0;
					}
					if (matrix_data[k][i] == Pc_data) {
						Pc_count++;
						Pc_xy[Pc_count][0] = k;
						Pc_xy[Pc_count][1] = i;
					}
				}
			}
		}

		random = rand() % Pc_count + 1;
		stone_Pronunciation(matrix_data, Pc_xy[random][0], Pc_xy[random][1], -1);

	}

}

int white4(int data[SIZE + 2][SIZE + 2], int x, int y) {//�� 20 �� 10
	//nx1111xn
	if (data[x - 2][y] < 20 && data[x - 1][y] < 10 && data[x][y] > 19 && data[x + 1][y] > 19 && data[x + 2][y] > 19 && data[x + 3][y] > 19 && data[x + 4][y] < 10 && data[x + 5][y] < 20)//��
		stone_Pronunciation(data, x + 4, y, -1);//����ġ ����
	else if (data[x - 2][y - 2] < 20 && data[x - 1][y - 1] < 10 && data[x][y] > 19 && data[x + 1][y + 1] > 19 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] > 19 && data[x + 4][y + 4] < 10 && data[x + 5][y + 5] < 20)//��
		stone_Pronunciation(data, x + 4, y + 4, -1);//����ġ ����
	else if (data[x][y - 2] < 20 && data[x][y - 1] < 10 && data[x][y] > 19 && data[x][y + 1] > 19 && data[x][y + 2] > 19 && data[x][y + 3] > 19 && data[x][y + 4] < 10 && data[x][y + 5] < 20)//��
		stone_Pronunciation(data, x, y + 4, -1);//����ġ ����
	else if (data[x + 2][y - 2] < 20 && data[x + 1][y - 1] < 10 && data[x][y] > 19 && data[x - 1][y + 1] > 19 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] > 19 && data[x - 4][y + 4] < 10 && data[x - 5][y + 5] < 20)//��
		stone_Pronunciation(data, x - 4, y + 4, -1);//����ġ ����

	//nx11110n
	else if (data[x - 2][y] < 20 && data[x - 1][y] < 10 && data[x][y] > 19 && data[x + 1][y] > 19 && data[x + 2][y] > 19 && data[x + 3][y] > 19 && data[x + 4][y] == 10 && data[x + 5][y] < 20)//��
		stone_Pronunciation(data, x - 1, y, -1);//����ġ ����
	else if (data[x - 2][y - 2] < 20 && data[x - 1][y - 1] < 10 && data[x][y] > 19 && data[x + 1][y + 1] > 19 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] > 19 && data[x + 4][y + 4] == 10 && data[x + 5][y + 5] < 20)//��
		stone_Pronunciation(data, x - 1, y - 1, -1);//����ġ ����
	else if (data[x][y - 2] < 20 && data[x][y - 1] < 10 && data[x][y] > 19 && data[x][y + 1] > 19 && data[x][y + 2] > 19 && data[x][y + 3] > 19 && data[x][y + 4] == 10 && data[x][y + 5] < 20)//��
		stone_Pronunciation(data, x, y - 1, -1);//����ġ ����
	else if (data[x + 2][y - 2] < 20 && data[x + 1][y - 1] < 10 && data[x][y] > 19 && data[x - 1][y + 1] > 19 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] > 19 && data[x - 4][y + 4] == 10 && data[x - 5][y + 5] < 20)//��
		stone_Pronunciation(data, x + 1, y - 1, -1);//����ġ ����

	//n01111xn
	else if (data[x - 2][y] < 20 && data[x - 1][y] == 10 && data[x][y] > 19 && data[x + 1][y] > 19 && data[x + 2][y] > 19 && data[x + 3][y] > 19 && data[x + 4][y] < 10 && data[x + 5][y] < 20)//��
		stone_Pronunciation(data, x + 4, y, -1);//����ġ ����
	else if (data[x - 2][y - 2] < 20 && data[x - 1][y - 1] == 10 && data[x][y] > 19 && data[x + 1][y + 1] > 19 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] > 19 && data[x + 4][y + 4] < 10 && data[x + 5][y + 5] < 20)//��
		stone_Pronunciation(data, x + 4, y + 4, -1);//����ġ ����
	else if (data[x][y - 2] < 20 && data[x][y - 1] == 10 && data[x][y] > 19 && data[x][y + 1] > 19 && data[x][y + 2] > 19 && data[x][y + 3] > 19 && data[x][y + 4] < 10 && data[x][y + 5] < 20)//��
		stone_Pronunciation(data, x, y + 4, -1);//����ġ ����
	else if (data[x + 2][y - 2] < 20 && data[x + 1][y - 1] == 10 && data[x][y] > 19 && data[x - 1][y + 1] > 19 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] > 19 && data[x - 4][y + 4] < 10 && data[x - 5][y + 5] < 20)//��
		stone_Pronunciation(data, x - 4, y + 4, -1);//����ġ ����

	//1x1111xn
	else if (data[x - 2][y] > 19 && data[x - 1][y] < 9 && data[x][y] > 19 && data[x + 1][y] > 19 && data[x + 2][y] > 19 && data[x + 3][y] > 19 && data[x + 4][y] < 10 && data[x + 5][y] < 20)//��
		stone_Pronunciation(data, x + 4, y, -1);//����ġ ����
	else if (data[x - 2][y - 2] > 19 && data[x - 1][y - 1] < 9 && data[x][y] > 19 && data[x + 1][y + 1] > 19 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] > 19 && data[x + 4][y + 4] < 10 && data[x + 5][y + 5] < 20)//��
		stone_Pronunciation(data, x + 4, y + 4, -1);//����ġ ����
	else if (data[x][y - 2] > 19 && data[x][y - 1] < 9 && data[x][y] > 19 && data[x][y + 1] > 19 && data[x][y + 2] > 19 && data[x][y + 3] > 19 && data[x][y + 4] < 10 && data[x][y + 5] < 20)//��
		stone_Pronunciation(data, x, y + 4, -1);//����ġ ����
	else if (data[x + 2][y - 2] > 19 && data[x + 1][y - 1] < 9 && data[x][y] > 19 && data[x - 1][y + 1] > 19 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] > 19 && data[x - 4][y + 4] < 10 && data[x - 5][y + 5] < 20)//��
		stone_Pronunciation(data, x - 4, y + 4, -1);//����ġ ����

	//nx1111x1
	else if (data[x - 2][y] < 20 && data[x - 1][y] < 10 && data[x][y] > 19 && data[x + 1][y] > 19 && data[x + 2][y] > 19 && data[x + 3][y] > 19 && data[x + 4][y] < 10 && data[x + 5][y] > 19)//��
		stone_Pronunciation(data, x - 1, y, -1);//����ġ ����
	else if (data[x - 2][y - 2] < 20 && data[x - 1][y - 1] < 10 && data[x][y] > 19 && data[x + 1][y + 1] > 19 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] > 19 && data[x + 4][y + 4] < 10 && data[x + 5][y + 5] > 19)//��
		stone_Pronunciation(data, x - 1, y - 1, -1);//����ġ ����
	else if (data[x][y - 2] < 20 && data[x][y - 1] < 10 && data[x][y] > 19 && data[x][y + 1] > 19 && data[x][y + 2] > 19 && data[x][y + 3] > 19 && data[x][y + 4] < 10 && data[x][y + 5] > 19)//��
		stone_Pronunciation(data, x, y - 1, -1);//����ġ ����
	else if (data[x + 2][y - 2] < 20 && data[x + 1][y - 1] < 10 && data[x][y] > 19 && data[x - 1][y + 1] > 19 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] > 19 && data[x - 4][y + 4] < 10 && data[x - 5][y + 5] > 19)//��
		stone_Pronunciation(data, x + 1, y - 1, -1);//����ġ ����

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//n111x1n
	else if (data[x - 1][y] < 20 && data[x][y] > 19 && data[x + 1][y] > 19 && data[x + 2][y] > 19 && data[x + 3][y] < 9 && data[x + 4][y] > 19 && data[x + 5][y] < 20)//��
		stone_Pronunciation(data, x + 3, y, -1);//����ġ ����
	else if (data[x - 1][y - 1] < 20 && data[x][y] > 19 && data[x + 1][y + 1] > 19 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] > 19 && data[x + 5][y + 5] < 20)//��
		stone_Pronunciation(data, x + 3, y + 3, -1);//����ġ ����
	else if (data[x][y - 1] < 20 && data[x][y] > 19 && data[x][y + 1] > 19 && data[x][y + 2] > 19 && data[x][y + 3] < 9 && data[x][y + 4] > 19 && data[x][y + 5] < 20)//��
		stone_Pronunciation(data, x, y + 3, -1);//����ġ ����
	else if (data[x + 1][y - 1] < 20 && data[x][y] > 19 && data[x - 1][y + 1] > 19 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] > 19 && data[x - 5][y + 5] < 20)//��
		stone_Pronunciation(data, x - 3, y + 3, -1);//����ġ ����

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//n11x11n
	else if (data[x - 1][y] < 20 && data[x][y] > 19 && data[x + 1][y] > 19 && data[x + 2][y] < 9 && data[x + 3][y] > 19 && data[x + 4][y] > 19 && data[x + 5][y] < 20)//��
		stone_Pronunciation(data, x + 2, y, -1);//����ġ ����
	else if (data[x - 1][y - 1] < 20 && data[x][y] > 19 && data[x + 1][y + 1] > 19 && data[x + 2][y + 2] < 9 && data[x + 3][y + 3] > 19 && data[x + 4][y + 4] > 19 && data[x + 5][y + 5] < 20)//��
		stone_Pronunciation(data, x + 2, y + 2, -1);//����ġ ����
	else if (data[x][y - 1] < 20 && data[x][y] > 19 && data[x][y + 1] > 19 && data[x][y + 2] < 9 && data[x][y + 3] > 19 && data[x][y + 4] > 19 && data[x][y + 5] < 20)//��
		stone_Pronunciation(data, x, y + 2, -1);//����ġ ����
	else if (data[x + 1][y - 1] < 20 && data[x][y] > 19 && data[x - 1][y + 1] > 19 && data[x - 2][y + 2] < 9 && data[x - 3][y + 3] > 19 && data[x - 4][y + 4] > 19 && data[x - 5][y + 5] < 20)//��
		stone_Pronunciation(data, x - 2, y + 2, -1);//����ġ ����


////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//n1x111n
	else if (data[x - 1][y] < 20 && data[x][y] > 19 && data[x + 1][y] < 9 && data[x + 2][y] > 19 && data[x + 3][y] > 19 && data[x + 4][y] > 19 && data[x + 5][y] < 20)//��
		stone_Pronunciation(data, x + 1, y, -1);//����ġ ����
	else if (data[x - 1][y - 1] < 20 && data[x][y] > 19 && data[x + 1][y + 1] < 9 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] > 19 && data[x + 4][y + 4] > 19 && data[x + 5][y + 5] < 20)//��
		stone_Pronunciation(data, x + 1, y + 1, -1);//����ġ ����
	else if (data[x][y - 1] < 20 && data[x][y] > 19 && data[x][y + 1] < 9 && data[x][y + 2] > 19 && data[x][y + 3] > 19 && data[x][y + 4] > 19 && data[x][y + 5] < 20)//��
		stone_Pronunciation(data, x, y + 1, -1);//����ġ ����
	else if (data[x + 1][y - 1] < 20 && data[x][y] > 19 && data[x - 1][y + 1] < 9 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] > 19 && data[x - 4][y + 4] > 19 && data[x - 5][y + 5] < 20)//��
		stone_Pronunciation(data, x - 1, y + 1, -1);//����ġ ����

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	else return 0;
	return 1;
}
int black4(int data[SIZE + 2][SIZE + 2], int x, int y) {
	//0x0000x
	if (data[x - 2][y] == 10 && data[x - 1][y] < 10 && data[x][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] == 10 && data[x + 3][y] == 10 && data[x + 4][y] < 10)//��
		stone_Pronunciation(data, x + 4, y, -1);//����ġ ����
	else if (data[x - 2][y - 2] == 10 && data[x - 1][y - 1] < 10 && data[x][y] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] == 10 && data[x + 4][y + 4] < 10)//��
		stone_Pronunciation(data, x + 4, y + 4, -1);//����ġ ����
	else if (data[x][y - 2] == 10 && data[x][y - 1] < 10 && data[x][y] == 10 && data[x][y + 1] == 10 && data[x][y + 2] == 10 && data[x][y + 3] == 10 && data[x][y + 4] < 10)//��
		stone_Pronunciation(data, x, y + 4, -1);//����ġ ����
	else if (data[x + 2][y - 2] == 10 && data[x + 1][y - 1] < 10 && data[x][y] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] == 10 && data[x - 4][y + 4] < 10)//��
		stone_Pronunciation(data, x - 4, y + 4, -1);//����ġ ����

	//x0000x0
	else if (data[x - 1][y] < 10 && data[x][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] == 10 && data[x + 3][y] == 10 && data[x + 4][y] < 10 && data[x + 5][y] == 10)//��
		stone_Pronunciation(data, x - 1, y, -1);//����ġ ����
	else if (data[x - 1][y - 1] < 10 && data[x][y] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] == 10 && data[x + 4][y + 4] < 10 && data[x + 5][y + 5] == 10)//��
		stone_Pronunciation(data, x - 1, y - 1, -1);//����ġ ����
	else if (data[x][y - 1] < 10 && data[x][y] == 10 && data[x][y + 1] == 10 && data[x][y + 2] == 10 && data[x][y + 3] == 10 && data[x][y + 4] < 10 && data[x][y + 5] == 10)//��
		stone_Pronunciation(data, x, y - 1, -1);//����ġ ����
	else if (data[x + 1][y - 1] < 10 && data[x][y] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] == 10 && data[x - 4][y + 4] < 10 && data[x - 5][y + 5] == 10)//��
		stone_Pronunciation(data, x + 1, y - 1, -1);//����ġ ����

	//nx00001
	else if (data[x - 2][y] != 10 && data[x - 1][y] < 9 && data[x][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] == 10 && data[x + 3][y] == 10 && data[x + 4][y] > 19)//��
		stone_Pronunciation(data, x - 1, y, -1);//����ġ ����
	else if (data[x - 2][y - 2] != 10 && data[x - 1][y - 1] < 9 && data[x][y] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] == 10 && data[x + 4][y + 4] > 19)//��
		stone_Pronunciation(data, x - 1, y - 1, -1);//����ġ ����
	else if (data[x][y - 2] != 10 && data[x][y - 1] < 9 && data[x][y] == 10 && data[x][y + 1] == 10 && data[x][y + 2] == 10 && data[x][y + 3] == 10 && data[x][y + 4] > 19)//��
		stone_Pronunciation(data, x, y - 1, -1);//����ġ ����
	else if (data[x + 2][y - 2] != 10 && data[x + 1][y - 1] < 9 && data[x][y] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] == 10 && data[x - 4][y + 4] > 19)//��
		stone_Pronunciation(data, x + 1, y - 1, -1);//����ġ ����

	//10000xn
	else if (data[x - 1][y] > 19 && data[x][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] == 10 && data[x + 3][y] == 10 && data[x + 4][y] < 9 && data[x + 5][y] != 10)//��
		stone_Pronunciation(data, x + 4, y, -1);//����ġ ����
	else if (data[x - 1][y - 1] > 19 && data[x][y] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] == 10 && data[x + 4][y + 4] < 9 && data[x + 5][y + 5] != 10)//��
		stone_Pronunciation(data, x + 4, y + 4, -1);//����ġ ����
	else if (data[x][y - 1] > 19 && data[x][y] == 10 && data[x][y + 1] == 10 && data[x][y + 2] == 10 && data[x][y + 3] == 10 && data[x][y + 4] < 9 && data[x][y + 5] != 10)//��
		stone_Pronunciation(data, x, y + 4, -1);//����ġ ����
	else if (data[x + 1][y - 1] > 19 && data[x][y] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] == 10 && data[x - 4][y + 4] < 9 && data[x - 5][y + 5] != 10)//��
		stone_Pronunciation(data, x - 4, y + 4, -1);//����ġ ����

/////////////////////////////////////////////////////////////////////////////////////////////////////

	//n000x0n
	else if (data[x - 1][y] != 10 && data[x][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] == 10 && data[x + 3][y] < 9 && data[x + 4][y] == 10 && data[x + 5][y] != 10)//��
		stone_Pronunciation(data, x + 3, y, -1);//����ġ ����
	else if (data[x - 1][y - 1] != 10 && data[x][y] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] == 10 && data[x + 5][y + 5] != 10)//��
		stone_Pronunciation(data, x + 3, y + 3, -1);//����ġ ����
	else if (data[x][y - 1] != 10 && data[x][y] == 10 && data[x][y + 1] == 10 && data[x][y + 2] == 10 && data[x][y + 3] < 9 && data[x][y + 4] == 10 && data[x][y + 5] != 10)//��
		stone_Pronunciation(data, x, y + 3, -1);//����ġ ����
	else if (data[x + 1][y - 1] != 10 && data[x][y] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] == 10 && data[x - 5][y + 5] != 10)//��
		stone_Pronunciation(data, x - 3, y + 3, -1);//����ġ ����

/////////////////////////////////////////////////////////////////////////////////////////////////////

	//n00x00n
	else if (data[x - 1][y] != 10 && data[x][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] < 9 && data[x + 3][y] == 10 && data[x + 4][y] == 10 && data[x + 5][y] != 10)//��
		stone_Pronunciation(data, x + 2, y, -1);//����ġ ����
	else if (data[x - 1][y - 1] != 10 && data[x][y] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] < 9 && data[x + 3][y + 3] == 10 && data[x + 4][y + 4] == 10 && data[x + 5][y + 5] != 10)//��
		stone_Pronunciation(data, x + 2, y + 2, -1);//����ġ ����
	else if (data[x][y - 1] != 10 && data[x][y] == 10 && data[x][y + 1] == 10 && data[x][y + 2] < 9 && data[x][y + 3] == 10 && data[x][y + 4] == 10 && data[x][y + 5] != 10)//��
		stone_Pronunciation(data, x, y + 2, -1);//����ġ ����
	else if (data[x + 1][y - 1] != 10 && data[x][y] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] < 9 && data[x - 3][y + 3] == 10 && data[x - 4][y + 4] == 10 && data[x - 5][y + 5] != 10)//��
		stone_Pronunciation(data, x - 2, y + 2, -1);//����ġ ����

/////////////////////////////////////////////////////////////////////////////////////////////////////

	//n0x000n
	else if (data[x - 1][y] != 10 && data[x][y] == 10 && data[x + 1][y] < 9 && data[x + 2][y] == 10 && data[x + 3][y] == 10 && data[x + 4][y] == 10 && data[x + 5][y] != 10)//��
		stone_Pronunciation(data, x + 1, y, -1);//����ġ ����
	else if (data[x - 1][y - 1] != 10 && data[x][y] == 10 && data[x + 1][y + 1] < 9 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] == 10 && data[x + 4][y + 4] == 10 && data[x + 5][y + 5] != 10)//��
		stone_Pronunciation(data, x + 1, y + 1, -1);//����ġ ����
	else if (data[x][y - 1] != 10 && data[x][y] == 10 && data[x][y + 1] < 9 && data[x][y + 2] == 10 && data[x][y + 3] == 10 && data[x][y + 4] == 10 && data[x][y + 5] != 10)//��
		stone_Pronunciation(data, x, y + 1, -1);//����ġ ����
	else if (data[x + 1][y - 1] != 10 && data[x][y] == 10 && data[x - 1][y + 1] < 9 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] == 10 && data[x - 4][y + 4] == 10 && data[x - 5][y + 5] != 10)//��
		stone_Pronunciation(data, x - 1, y + 1, -1);//����ġ ����



	else return 0;

	return 1;
}
int white3(int data[SIZE + 2][SIZE + 2], int x, int y) {
	//xx111xx
	if (data[x - 2][y] < 9 && data[x - 1][y] < 9 && data[x][y] > 19 && data[x + 1][y] > 19 && data[x + 2][y] > 19 && data[x + 3][y] < 9 && data[x + 4][y] < 9) {//��
		if (data[x - 1][y] > data[x + 3][y]) stone_Pronunciation(data, x - 1, y, -1);//����ġ ����
		else stone_Pronunciation(data, x + 3, y, -1);//����ġ ����
	}
	else if (data[x - 2][y - 2] < 9 && data[x - 1][y - 1] < 9 && data[x][y] > 19 && data[x + 1][y + 1] > 19 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] < 9) {//��
		if (data[x - 1][y - 1] > data[x + 3][y + 3]) stone_Pronunciation(data, x - 1, y - 1, -1);//����ġ ����
		else stone_Pronunciation(data, x + 3, y + 3, -1);//����ġ ����
	}
	else if (data[x][y - 2] < 9 && data[x][y - 1] < 9 && data[x][y] > 19 && data[x][y + 1] > 19 && data[x][y + 2] > 19 && data[x][y + 3] < 9 && data[x][y + 4] < 9) {//��
		if (data[x][y - 1] > data[x][y + 3]) stone_Pronunciation(data, x, y - 1, -1);//����ġ ����
		else stone_Pronunciation(data, x, y + 3, -1);//����ġ ����
	}
	else if (data[x + 2][y - 2] < 9 && data[x + 1][y - 1] < 9 && data[x][y] > 19 && data[x - 1][y + 1] > 19 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] < 9) {//��
		if (data[x + 1][y - 1] > data[x - 3][y + 3]) stone_Pronunciation(data, x + 1, y - 1, -1);//����ġ ����
		else stone_Pronunciation(data, x - 3, y + 3, -1);//����ġ ����
	}

	//0x111xx
	else if (data[x - 2][y] == 10 && data[x - 1][y] < 9 && data[x][y] > 19 && data[x + 1][y] > 19 && data[x + 2][y] > 19 && data[x + 3][y] < 9 && data[x + 4][y] < 9)//��
		stone_Pronunciation(data, x + 3, y, -1);//����ġ ����
	else if (data[x - 2][y - 2] == 10 && data[x - 1][y - 1] < 9 && data[x][y] > 19 && data[x + 1][y + 1] > 19 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] < 9)//��
		stone_Pronunciation(data, x + 3, y + 3, -1);//����ġ ����
	else if (data[x][y - 2] == 10 && data[x][y - 1] < 9 && data[x][y] > 19 && data[x][y + 1] > 19 && data[x][y + 2] > 19 && data[x][y + 3] < 9 && data[x][y + 4] < 9)//��
		stone_Pronunciation(data, x, y + 3, -1);//����ġ ����
	else if (data[x + 2][y - 2] == 10 && data[x + 1][y - 1] < 9 && data[x][y] > 19 && data[x - 1][y + 1] > 19 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] < 9)//��
		stone_Pronunciation(data, x - 3, y + 3, -1);//����ġ ����

	//xx111x0
	else if (data[x - 2][y] < 9 && data[x - 1][y] < 9 && data[x][y] > 19 && data[x + 1][y] > 19 && data[x + 2][y] > 19 && data[x + 3][y] < 9 && data[x + 4][y] == 10)//��
		stone_Pronunciation(data, x - 1, y, -1);//����ġ ����
	else if (data[x - 2][y - 2] < 9 && data[x - 1][y - 1] < 9 && data[x][y] > 19 && data[x + 1][y + 1] > 19 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] == 10)//��
		stone_Pronunciation(data, x - 1, y - 1, -1);//����ġ ����
	else if (data[x][y - 2] < 9 && data[x][y - 1] < 9 && data[x][y] > 19 && data[x][y + 1] > 19 && data[x][y + 2] > 19 && data[x][y + 3] < 9 && data[x][y + 4] == 10)//��
		stone_Pronunciation(data, x, y - 1, -1);//����ġ ����
	else if (data[x + 2][y - 2] < 9 && data[x + 1][y - 1] < 9 && data[x][y] > 19 && data[x - 1][y + 1] > 19 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] == 10)//��
		stone_Pronunciation(data, x + 1, y - 1, -1);//����ġ ����


////////////////////////////////////////////////////////////////////////////////////


	//x11x1x
	else if (data[x - 1][y] < 9 && data[x][y] > 19 && data[x + 1][y] > 19 && data[x + 2][y] < 9 && data[x + 3][y] > 19 && data[x + 4][y] < 9)//��
		stone_Pronunciation(data, x + 2, y, -1);//����ġ ����
	else if (data[x - 1][y - 1] < 9 && data[x][y] > 19 && data[x + 1][y + 1] > 19 && data[x + 2][y + 2] < 9 && data[x + 3][y + 3] > 19 && data[x + 4][y + 4] < 9)//��
		stone_Pronunciation(data, x + 2, y + 2, -1);//����ġ ����
	else if (data[x][y - 1] < 9 && data[x][y] > 19 && data[x][y + 1] > 19 && data[x][y + 2] < 9 && data[x][y + 3] > 19 && data[x][y + 4] < 9)//��
		stone_Pronunciation(data, x, y + 2, -1);//����ġ ����
	else if (data[x + 1][y - 1] < 9 && data[x][y] > 19 && data[x - 1][y + 1] > 19 && data[x - 2][y + 2] < 9 && data[x - 3][y + 3] > 19 && data[x - 4][y + 4] < 9)//��
		stone_Pronunciation(data, x - 2, y + 2, -1);//����ġ ����

	//x1x11x
	else if (data[x - 1][y] < 9 && data[x][y] > 19 && data[x + 1][y] < 9 && data[x + 2][y] > 19 && data[x + 3][y] > 19 && data[x + 4][y] < 9)//��
		stone_Pronunciation(data, x + 1, y, -1);//����ġ ����
	else if (data[x - 1][y - 1] < 9 && data[x][y] > 19 && data[x + 1][y + 1] < 9 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] > 19 && data[x + 4][y + 4] < 9)//��
		stone_Pronunciation(data, x + 1, y + 1, -1);//����ġ ����
	else if (data[x][y - 1] < 9 && data[x][y] > 19 && data[x][y + 1] < 9 && data[x][y + 2] > 19 && data[x][y + 3] > 19 && data[x][y + 4] < 9)//��
		stone_Pronunciation(data, x, y + 1, -1);//����ġ ����
	else if (data[x + 1][y - 1] < 9 && data[x][y] > 19 && data[x - 1][y + 1] < 9 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] > 19 && data[x - 4][y + 4] < 9)//��
		stone_Pronunciation(data, x - 1, y + 1, -1);//����ġ ����

	else return 0;
	return 1;
}
int black3(int data[SIZE + 2][SIZE + 2], int x, int y) {
	//xx000xx
	if (data[x - 2][y] < 9 && data[x - 1][y] < 9 && data[x][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] == 10 && data[x + 3][y] < 9 && data[x + 4][y] < 9) {//��
		if (data[x - 1][y] > data[x + 3][y]) stone_Pronunciation(data, x - 1, y, -1);//����ġ ����
		else stone_Pronunciation(data, x + 3, y, -1);//����ġ ����
	}
	else if (data[x - 2][y - 2] < 9 && data[x - 1][y - 1] < 9 && data[x][y] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] < 9) {//��
		if (data[x - 1][y - 1] > data[x + 3][y + 3]) stone_Pronunciation(data, x - 1, y - 1, -1);//����ġ ����
		else stone_Pronunciation(data, x + 3, y + 3, -1);//����ġ ����
	}
	else if (data[x][y - 2] < 9 && data[x][y - 1] < 9 && data[x][y] == 10 && data[x][y + 1] == 10 && data[x][y + 2] == 10 && data[x][y + 3] < 9 && data[x][y + 4] < 9) {//��
		if (data[x][y - 1] > data[x][y + 3]) stone_Pronunciation(data, x, y - 1, -1);//����ġ ����
		else stone_Pronunciation(data, x, y + 3, -1);//����ġ ����
	}
	else if (data[x + 2][y - 2] < 9 && data[x + 1][y - 1] < 9 && data[x][y] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] < 9) {//��
		if (data[x + 1][y - 1] > data[x - 3][y + 3]) stone_Pronunciation(data, x + 1, y - 1, -1);//����ġ ����
		else stone_Pronunciation(data, x - 3, y + 3, -1);//����ġ ����
	}

	//1x000xx
	else if (data[x - 2][y] > 19 && data[x - 1][y] < 9 && data[x][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] == 10 && data[x + 3][y] < 9 && data[x + 4][y] < 9)//��
		stone_Pronunciation(data, x + 3, y, -1);//����ġ ����
	else if (data[x - 2][y - 2] > 19 && data[x - 1][y - 1] < 9 && data[x][y] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] < 9)//��
		stone_Pronunciation(data, x + 3, y + 3, -1);//����ġ ����
	else if (data[x][y - 2] > 19 && data[x][y - 1] < 9 && data[x][y] == 10 && data[x][y + 1] == 10 && data[x][y + 2] == 10 && data[x][y + 3] < 9 && data[x][y + 4] < 9)//��
		stone_Pronunciation(data, x, y + 3, -1);//����ġ ����
	else if (data[x + 2][y - 2] > 19 && data[x + 1][y - 1] < 9 && data[x][y] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] < 9)//��
		stone_Pronunciation(data, x - 3, y + 3, -1);//����ġ ����

	//xx000x1
	else if (data[x - 2][y] < 9 && data[x - 1][y] < 9 && data[x][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] == 10 && data[x + 3][y] < 9 && data[x + 4][y] > 19)//��
		stone_Pronunciation(data, x - 1, y, -1);//����ġ ����
	else if (data[x - 2][y - 2] < 9 && data[x - 1][y - 1] < 9 && data[x][y] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] > 19)//��
		stone_Pronunciation(data, x - 1, y - 1, -1);//����ġ ����
	else if (data[x][y - 2] < 9 && data[x][y - 1] < 9 && data[x][y] == 10 && data[x][y + 1] == 10 && data[x][y + 2] == 10 && data[x][y + 3] < 9 && data[x][y + 4] > 19)//��
		stone_Pronunciation(data, x, y - 1, -1);//����ġ ����
	else if (data[x + 2][y - 2] < 9 && data[x + 1][y - 1] < 9 && data[x][y] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] > 19)//��
		stone_Pronunciation(data, x + 1, y - 1, -1);//����ġ ����

////////////////////////////////////////////////////////////////////////////////////////

	//x00x0x
	else if (data[x - 1][y] < 9 && data[x][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] < 9 && data[x + 3][y] == 10 && data[x + 4][y] < 9)//��
		stone_Pronunciation(data, x + 2, y, -1);//����ġ ����
	else if (data[x - 1][y - 1] < 9 && data[x][y] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] < 9 && data[x + 3][y + 3] == 10 && data[x + 4][y + 4] < 9)//��
		stone_Pronunciation(data, x + 2, y + 2, -1);//����ġ ����
	else if (data[x][y - 1] < 9 && data[x][y] == 10 && data[x][y + 1] == 10 && data[x][y + 2] < 9 && data[x][y + 3] == 10 && data[x][y + 4] < 9)//��
		stone_Pronunciation(data, x, y + 2, -1);//����ġ ����
	else if (data[x + 1][y - 1] < 9 && data[x][y] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] < 9 && data[x - 3][y + 3] == 10 && data[x - 4][y + 4] < 9)//��
		stone_Pronunciation(data, x - 2, y + 2, -1);//����ġ ����

////////////////////////////////////////////////////////////////////////////////////////
// 
	//x0x00x
	else if (data[x - 1][y] < 9 && data[x][y] == 10 && data[x + 1][y] < 9 && data[x + 2][y] == 10 && data[x + 3][y] == 10 && data[x + 4][y] < 9)//��
		stone_Pronunciation(data, x + 1, y, -1);//����ġ ����
	else if (data[x - 1][y - 1] < 9 && data[x][y] == 10 && data[x + 1][y + 1] < 9 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] == 10 && data[x + 4][y + 4] < 9)//��
		stone_Pronunciation(data, x + 1, y + 1, -1);//����ġ ����
	else if (data[x][y - 1] < 9 && data[x][y] == 10 && data[x][y + 1] < 9 && data[x][y + 2] == 10 && data[x][y + 3] == 10 && data[x][y + 4] < 9)//��
		stone_Pronunciation(data, x, y + 1, -1);//����ġ ����
	else if (data[x + 1][y - 1] < 9 && data[x][y] == 10 && data[x - 1][y + 1] < 9 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] == 10 && data[x - 4][y + 4] < 9)//��
		stone_Pronunciation(data, x - 1, y + 1, -1);//����ġ ����



	else return 0;
	return 1;
}

int black2_Defance(int data[SIZE + 2][SIZE + 2], int x, int y) {
	//  1
	//xx00xx
	if (data[x - 2][y] < 9 && data[x - 1][y] < 9 && data[x][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] < 9 && data[x + 3][y] < 9) {//��
		data[x - 1][y] += 1;
		data[x + 3][y] += 1;
	}
	else if (data[x - 2][y - 2] < 9 && data[x - 1][y - 1] < 9 && data[x][y] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] < 9 && data[x + 3][y + 3] < 9) {//��
		data[x - 1][y - 1] += 1;
		data[x + 3][y + 3] += 1;
	}
	else if (data[x][y - 2] < 9 && data[x][y - 1] < 9 && data[x][y] == 10 && data[x][y + 1] == 10 && data[x][y + 2] < 9 && data[x][y + 3] < 9) {//��
		data[x][y - 1] += 1;
		data[x][y + 3] += 1;
	}
	else if (data[x + 2][y - 2] < 9 && data[x + 1][y - 1] < 9 && data[x][y] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] < 9 && data[x - 3][y + 3] < 9) {//��
		data[x + 1][y - 1] += 1;
		data[x - 3][y + 3] += 1;
	}
	else if (data[x + 2][y] < 9 && data[x + 1][y] < 9 && data[x][y] == 10 && data[x - 1][y] == 10 && data[x - 2][y] < 9 && data[x - 3][y] < 9) {//��
		data[x + 1][y + 1] += 1;
		data[x - 3][y - 3] += 1;
	}
	else if (data[x + 2][y + 2] < 9 && data[x + 1][y + 1] < 9 && data[x][y] == 10 && data[x - 1][y - 1] == 10 && data[x - 2][y - 2] < 9 && data[x - 3][y - 3] < 9) {//��
		data[x + 1][y + 1] += 1;
		data[x - 3][y - 3] += 1;
	}
	else if (data[x][y + 2] < 9 && data[x][y + 1] < 9 && data[x][y] == 10 && data[x][y - 1] == 10 && data[x][y - 2] < 9 && data[x][y - 3] < 9) {//��
		data[x][y + 1] += 1;
		data[x][y - 3] += 1;
	}
	else if (data[x - 2][y + 2] < 9 && data[x - 1][y + 1] < 9 && data[x][y] == 10 && data[x + 1][y - 1] == 10 && data[x + 2][y - 2] < 9 && data[x + 3][y - 3] < 9) {//��
		data[x - 1][y + 1] += 1;
		data[x + 3][y - 3] += 1;
	}

	//   1
	//xx00xx
	if (data[x - 3][y] < 9 && data[x - 2][y] < 9 && data[x - 1][y] == 10 && data[x][y] == 10 && data[x + 1][y] < 9 && data[x + 2][y] < 9) {//��
		data[x - 2][y] += 1;
		data[x + 2][y] += 1;
	}
	else if (data[x - 3][y - 2] < 9 && data[x - 2][y - 2] < 9 && data[x - 1][y - 1] == 10 && data[x][y] == 10 && data[x + 1][y + 1] < 9 && data[x + 2][y + 2] < 9) {//��
		data[x - 2][y - 2] += 1;
		data[x + 2][y + 2] += 1;
	}
	else if (data[x][y - 3] < 9 && data[x][y - 2] < 9 && data[x][y - 1] == 10 && data[x][y] == 10 && data[x][y + 1] < 9 && data[x][y + 2] < 9) {//��
		data[x][y - 2] += 1;
		data[x][y + 2] += 1;
	}
	else if (data[x + 3][y - 3] < 9 && data[x + 2][y - 2] < 9 && data[x + 1][y - 1] == 10 && data[x][y] == 10 && data[x - 1][y + 1] < 9 && data[x - 2][y + 2] < 9) {//��
		data[x + 2][y - 2] += 1;
		data[x - 2][y + 2] += 1;
	}
	else if (data[x + 3][y] < 9 && data[x + 2][y] < 9 && data[x + 1][y] == 10 && data[x][y] == 10 && data[x - 1][y] < 9 && data[x - 2][y] < 9) {//��
		data[x + 2][y + 2] += 1;
		data[x - 2][y - 2] += 1;
	}
	else if (data[x + 3][y - 3] < 9 && data[x + 2][y + 2] < 9 && data[x + 1][y + 1] == 10 && data[x][y] == 10 && data[x - 1][y - 1] < 9 && data[x - 2][y - 2] < 9) {//��
		data[x + 2][y + 2] += 1;
		data[x - 2][y - 2] += 1;
	}
	else if (data[x][y + 3] < 9 && data[x][y + 2] < 9 && data[x][y + 1] == 10 && data[x][y] == 10 && data[x][y - 1] < 9 && data[x][y - 2] < 9) {//��
		data[x][y + 2] += 1;
		data[x][y - 2] += 1;
	}
	else if (data[x - 3][y + 3] < 9 && data[x - 2][y + 2] < 9 && data[x - 1][y + 1] == 10 && data[x][y] == 10 && data[x + 1][y - 1] < 9 && data[x + 2][y - 2] < 9) {//��
		data[x - 2][y + 2] += 1;
		data[x + 2][y - 2] += 1;
	}

	else return 0;
	return 1;

}
int black3_Defance(int data[SIZE + 2][SIZE + 2], int x, int y) {
	//  1
	//xx000xx
	if (data[x - 2][y] < 9 && data[x - 1][y] < 9 && data[x][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] == 10 && data[x + 3][y] < 9 && data[x + 4][y] < 9) {//��
		data[x - 1][y] += 1;
		data[x + 3][y] += 1;
	}
	else if (data[x - 2][y - 2] < 9 && data[x - 1][y - 1] < 9 && data[x][y] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] < 9) {//��
		data[x - 1][y - 1] += 1;
		data[x + 3][y + 3] += 1;
	}
	else if (data[x][y - 2] < 9 && data[x][y - 1] < 9 && data[x][y] == 10 && data[x][y + 1] == 10 && data[x][y + 2] == 10 && data[x][y + 3] < 9 && data[x][y + 4] < 9) {//��
		data[x][y - 1] += 1;
		data[x][y + 3] += 1;
	}
	else if (data[x + 2][y - 2] < 9 && data[x + 1][y - 1] < 9 && data[x][y] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] < 9) {//��
		data[x + 1][y - 1] += 1;
		data[x - 3][y + 3] += 1;
	}
	else if (data[x + 2][y] < 9 && data[x + 1][y] < 9 && data[x][y] == 10 && data[x - 1][y] == 10 && data[x - 2][y] == 10 && data[x - 3][y] < 9 && data[x - 4][y] < 9) {//��
		data[x + 1][y + 1] += 1;
		data[x - 3][y - 3] += 1;
	}
	else if (data[x + 2][y + 2] < 9 && data[x + 1][y + 1] < 9 && data[x][y] == 10 && data[x - 1][y - 1] == 10 && data[x - 2][y - 2] == 10 && data[x - 3][y - 3] < 9 && data[x - 4][y - 4] < 9) {//��
		data[x + 1][y + 1] += 1;
		data[x - 3][y - 3] += 1;
	}
	else if (data[x][y + 2] < 9 && data[x][y + 1] < 9 && data[x][y] == 10 && data[x][y - 1] == 10 && data[x][y - 2] == 10 && data[x][y - 3] < 9 && data[x][y - 4] < 9) {//��
		data[x][y + 1] += 1;
		data[x][y - 3] += 1;
	}
	else if (data[x - 2][y + 2] < 9 && data[x - 1][y + 1] < 9 && data[x][y] == 10 && data[x + 1][y - 1] == 10 && data[x + 2][y - 2] == 10 && data[x + 3][y - 3] < 9 && data[x + 4][y - 4] < 9) {//��
		data[x - 1][y + 1] += 1;
		data[x + 3][y - 3] += 1;
	}

	//   1
	//xx000xx
	if (data[x - 3][y] < 9 && data[x - 2][y] < 9 && data[x - 1][y] == 10 && data[x][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] < 9 && data[x + 3][y] < 9) {//��
		data[x - 2][y] += 1;
		data[x + 2][y] += 1;
	}
	else if (data[x - 3][y - 2] < 9 && data[x - 2][y - 2] < 9 && data[x - 1][y - 1] == 10 && data[x][y] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] < 9 && data[x + 3][y + 3] < 9) {//��
		data[x - 2][y - 2] += 1;
		data[x + 2][y + 2] += 1;
	}
	else if (data[x][y - 3] < 9 && data[x][y - 2] < 9 && data[x][y - 1] == 10 && data[x][y] == 10 && data[x][y + 1] == 10 && data[x][y + 2] < 9 && data[x][y + 3] < 9) {//��
		data[x][y - 2] += 1;
		data[x][y + 2] += 1;
	}
	else if (data[x + 3][y - 3] < 9 && data[x + 2][y - 2] < 9 && data[x + 1][y - 1] == 10 && data[x][y] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] < 9 && data[x - 3][y + 3] < 9) {//��
		data[x + 2][y - 2] += 1;
		data[x - 2][y + 2] += 1;
	}
	else if (data[x + 3][y] < 9 && data[x + 2][y] < 9 && data[x + 1][y] == 10 && data[x][y] == 10 && data[x - 1][y] == 10 && data[x - 2][y] < 9 && data[x - 3][y] < 9) {//��
		data[x + 2][y + 2] += 1;
		data[x - 2][y - 2] += 1;
	}
	else if (data[x + 3][y - 3] < 9 && data[x + 2][y + 2] < 9 && data[x + 1][y + 1] == 10 && data[x][y] == 10 && data[x - 1][y - 1] == 10 && data[x - 2][y - 2] < 9 && data[x - 3][y - 3] < 9) {//��
		data[x + 2][y + 2] += 1;
		data[x - 2][y - 2] += 1;
	}
	else if (data[x][y + 3] < 9 && data[x][y + 2] < 9 && data[x][y + 1] == 10 && data[x][y] == 10 && data[x][y - 1] == 10 && data[x][y - 2] < 9 && data[x][y - 3] < 9) {//��
		data[x][y + 2] += 1;
		data[x][y - 2] += 1;
	}
	else if (data[x - 3][y + 3] < 9 && data[x - 2][y + 2] < 9 && data[x - 1][y + 1] == 10 && data[x][y] == 10 && data[x + 1][y - 1] == 10 && data[x + 2][y - 2] < 9 && data[x + 3][y - 3] < 9) {//��
		data[x - 2][y + 2] += 1;
		data[x + 2][y - 2] += 1;
	}

	else return 0;
	return 1;

}

int white2(int data[SIZE + 2][SIZE + 2], int x, int y) {
	//nx11xx
	if (data[x - 2][y] != 20 && data[x - 1][y] < 9 && data[x][y] > 19 && data[x + 1][y] > 19 && data[x + 2][y] < 9 && data[x + 3][y] < 9)//��
		stone_Pronunciation(data, x + 2, y, -1);
	else if (data[x - 2][y - 2] != 20 && data[x - 1][y - 1] < 9 && data[x][y] > 19 && data[x + 1][y + 1] > 19 && data[x + 2][y + 2] < 9 && data[x + 3][y + 3] < 9)//��
		stone_Pronunciation(data, x + 2, y + 2, -1);
	else if (data[x][y - 2] != 20 && data[x][y - 1] < 9 && data[x][y] > 19 && data[x][y + 1] > 19 && data[x][y + 2] < 9 && data[x][y + 3] < 9)//��
		stone_Pronunciation(data, x, y + 2, -1);
	else if (data[x + 2][y - 2] != 20 && data[x + 1][y - 1] < 9 && data[x][y] > 19 && data[x - 1][y + 1] > 19 && data[x - 2][y + 2] < 9 && data[x - 3][y + 3] < 9)//��
		stone_Pronunciation(data, x - 2, y + 2, -1);

	//------------------------------------------------------------------------------------------------------------------------------------------------------

	//xx11xn
	else if (data[x - 2][y] < 9 && data[x - 1][y] < 9 && data[x][y] > 19 && data[x + 1][y] > 19 && data[x + 2][y] < 9 && data[x + 3][y] != 20)//��
		stone_Pronunciation(data, x - 1, y, -1);
	else if (data[x - 2][y - 2] < 9 && data[x - 1][y - 1] < 9 && data[x][y] > 19 && data[x + 1][y + 1] > 19 && data[x + 2][y + 2] < 9 && data[x + 3][y + 3] != 20)//��
		stone_Pronunciation(data, x - 1, y - 1, -1);
	else if (data[x][y - 2] < 9 && data[x][y - 1] < 9 && data[x][y] > 19 && data[x][y + 1] > 19 && data[x][y + 2] < 9 && data[x][y + 3] != 20)//��
		stone_Pronunciation(data, x, y - 1, -1);
	else if (data[x + 2][y - 2] < 9 && data[x + 1][y - 1] < 9 && data[x][y] > 19 && data[x - 1][y + 1] > 19 && data[x - 2][y + 2] < 9 && data[x - 3][y + 3] != 20)//��
		stone_Pronunciation(data, x + 1, y - 1, -1);

	//--------------------------------------------------------------------------------------------------------------------------------------------

	//nx1x1xn
	else if (data[x - 2][y] != 20 && data[x - 1][y] < 9 && data[x][y] > 19 && data[x + 1][y] < 9 && data[x + 2][y] > 19 && data[x + 3][y] < 9 && data[x + 4][y] != 20)//��
		stone_Pronunciation(data, x + 1, y, -1);
	else if (data[x - 2][y - 2] != 20 && data[x - 1][y - 1] < 9 && data[x][y] > 19 && data[x + 1][y + 1] < 9 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] != 20)//��
		stone_Pronunciation(data, x + 1, y + 1, -1);
	else if (data[x][y - 2] != 20 && data[x][y - 1] < 9 && data[x][y] > 19 && data[x][y + 1] < 9 && data[x][y + 2] > 19 && data[x][y + 3] < 9 && data[x][y + 4] != 20)//��
		stone_Pronunciation(data, x, y + 2, -1);
	else if (data[x + 2][y - 2] != 20 && data[x + 1][y - 1] < 9 && data[x][y] > 19 && data[x - 1][y + 1] < 9 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] != 20)//��
		stone_Pronunciation(data, x - 2, y + 2, -1);

	//xx1x1xx
	else if (data[x - 2][y] < 9 && data[x - 1][y] < 9 && data[x][y] > 19 && data[x + 1][y] < 9 && data[x + 2][y] > 19 && data[x + 3][y] < 9 && data[x + 4][y] != 20)//��
		stone_Pronunciation(data, x + 1, y, -1);
	else if (data[x - 2][y - 2] < 9 && data[x - 1][y - 1] < 9 && data[x][y] > 19 && data[x + 1][y + 1] < 9 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] != 20)//��
		stone_Pronunciation(data, x + 1, y + 1, -1);
	else if (data[x][y - 2] < 9 && data[x][y - 1] < 9 && data[x][y] > 19 && data[x][y + 1] < 9 && data[x][y + 2] > 19 && data[x][y + 3] < 9 && data[x][y + 4] != 20)//��
		stone_Pronunciation(data, x, y + 2, -1);
	else if (data[x + 2][y - 2] < 9 && data[x + 1][y - 1] < 9 && data[x][y] > 19 && data[x - 1][y + 1] < 9 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] != 20)//��
		stone_Pronunciation(data, x - 2, y + 2, -1);


	//nx1x1x1n
	else if (data[x - 2][y] != 20 && data[x - 1][y] < 9 && data[x][y] > 19 && data[x + 1][y] < 9 && data[x + 2][y] > 19 && data[x + 3][y] < 9 && data[x + 4][y] > 19 && data[x + 5][y] != 20)//��
		stone_Pronunciation(data, x + 1, y, -1);
	else if (data[x - 2][y - 2] != 20 && data[x - 1][y - 1] < 9 && data[x][y] > 19 && data[x + 1][y + 1] < 9 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] > 19 && data[x + 5][y + 5] != 20)//��
		stone_Pronunciation(data, x + 1, y + 1, -1);
	else if (data[x][y - 2] != 20 && data[x][y - 1] < 9 && data[x][y] > 19 && data[x][y + 1] < 9 && data[x][y + 2] > 19 && data[x][y + 3] < 9 && data[x][y + 4] > 19 && data[x][y + 5] != 20)//��
		stone_Pronunciation(data, x, y + 1, -1);
	else if (data[x + 2][y - 2] != 20 && data[x + 1][y - 1] < 9 && data[x][y] > 19 && data[x - 1][y + 1] < 9 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] > 19 && data[x - 5][y + 5] != 20)//��
		stone_Pronunciation(data, x - 1, y + 1, -1);

	//n1x1x1xn
	else if (data[x - 1][y] != 20 && data[x][y] > 19 && data[x + 1][y] < 9 && data[x + 2][y] > 19 && data[x + 3][y] < 9 && data[x + 4][y] > 19 && data[x + 5][y] < 9 && data[x + 6][y] != 20)//��
		stone_Pronunciation(data, x + 1, y, -1);
	else if (data[x - 1][y - 1] != 20 && data[x][y] > 19 && data[x + 1][y + 1] < 9 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] > 19 && data[x + 5][y + 5] < 9 && data[x + 6][y + 6] != 20)//��
		stone_Pronunciation(data, x + 1, y + 1, -1);
	else if (data[x][y - 1] != 20 && data[x][y] > 19 && data[x][y + 1] < 9 && data[x][y + 2] > 19 && data[x][y + 3] < 9 && data[x][y + 4] > 19 && data[x][y + 5] < 9 && data[x][y + 6] != 20)//��
		stone_Pronunciation(data, x, y + 1, -1);
	else if (data[x + 1][y - 1] != 20 && data[x][y] > 19 && data[x - 1][y + 1] < 9 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] > 19 && data[x - 5][y + 5] < 9 && data[x - 6][y + 6] != 20)//��
		stone_Pronunciation(data, x - 1, y + 1, -1);

	else return 0;
	return 1;

}
int	blocked_white3(int data[SIZE + 2][SIZE + 2], int x, int y) {
	//0111xxn
	if (data[x - 1][y] == 10 && data[x][y] > 19 && data[x + 1][y] > 19 && data[x + 2][y] > 19 && data[x + 3][y] < 9 && data[x + 4][y] < 9 && data[x + 5][y] != 20) //��
		stone_Pronunciation(data, x + 3, y, -1);//����ġ ����
	else if (data[x - 1][y - 1] == 10 && data[x][y] > 19 && data[x + 1][y + 1] > 19 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] < 9 && data[x + 5][y + 5] != 20) //��
		stone_Pronunciation(data, x + 3, y + 3, -1);//����ġ ����
	else if (data[x][y - 1] < 9 && data[x][y] > 19 && data[x][y + 1] > 19 && data[x][y + 2] > 19 && data[x][y + 3] < 9 && data[x][y + 4] < 9 && data[x][y + 5] != 20) //��
		stone_Pronunciation(data, x, y + 3, -1);//����ġ ����
	else if (data[x + 1][y - 1] < 9 && data[x][y] > 19 && data[x - 1][y + 1] > 19 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] < 9 && data[x - 5][y + 5] != 20) //��
		stone_Pronunciation(data, x - 3, y + 3, -1);//����ġ ����

	//nxx1110
	else if (data[x - 3][y] != 20 && data[x - 2][y] < 9 && data[x - 1][y] < 9 && data[x][y] > 19 && data[x + 1][y] > 19 && data[x + 2][y] > 19 && data[x + 3][y] == 10)//��
		stone_Pronunciation(data, x - 1, y, -1);//����ġ ����
	else if (data[x - 3][y - 3] != 20 && data[x - 2][y - 2] < 9 && data[x - 1][y - 1] < 9 && data[x][y] > 19 && data[x + 1][y + 1] > 19 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] == 10)//��
		stone_Pronunciation(data, x - 1, y - 1, -1);//����ġ ����
	else if (data[x][y - 3] != 20 && data[x][y - 2] < 9 && data[x][y - 1] < 9 && data[x][y] > 19 && data[x][y + 1] > 19 && data[x][y + 2] > 19 && data[x][y + 3] == 10)//��
		stone_Pronunciation(data, x, y - 1, -1);//����ġ ����
	else if (data[x + 3][y - 3] != 20 && data[x + 2][y - 2] < 9 && data[x + 1][y - 1] < 9 && data[x][y] > 19 && data[x - 1][y + 1] > 19 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] == 10)//��
		stone_Pronunciation(data, x + 1, y - 1, -1);//����ġ ����


////////////////////////////////////////////////////////////////////////////////////


	//011x1xn
	else if (data[x - 1][y] == 10 && data[x][y] > 19 && data[x + 1][y] > 19 && data[x + 2][y] < 9 && data[x + 3][y] > 19 && data[x + 4][y] < 9 && data[x + 5][y] != 20)//��
		stone_Pronunciation(data, x + 2, y, -1);//����ġ ����
	else if (data[x - 1][y - 1] == 10 && data[x][y] > 19 && data[x + 1][y + 1] > 19 && data[x + 2][y + 2] < 9 && data[x + 3][y + 3] > 19 && data[x + 4][y + 4] < 9 && data[x + 5][y + 5] != 20)//��
		stone_Pronunciation(data, x + 2, y + 2, -1);//����ġ ����
	else if (data[x][y - 1] == 10 && data[x][y] > 19 && data[x][y + 1] > 19 && data[x][y + 2] < 9 && data[x][y + 3] > 19 && data[x][y + 4] < 9 && data[x][y + 5] != 20)//��
		stone_Pronunciation(data, x, y + 2, -1);//����ġ ����
	else if (data[x + 1][y - 1] == 10 && data[x][y] > 19 && data[x - 1][y + 1] > 19 && data[x - 2][y + 2] < 9 && data[x - 3][y + 3] > 19 && data[x - 4][y + 4] < 9 && data[x - 5][y + 5] != 20)//��
		stone_Pronunciation(data, x - 2, y + 2, -1);//����ġ ����

	//01x11xn
	else if (data[x - 1][y] == 10 && data[x][y] > 19 && data[x + 1][y] < 9 && data[x + 2][y] > 19 && data[x + 3][y] > 19 && data[x + 4][y] < 9 && data[x + 5][y] != 20)//��
		stone_Pronunciation(data, x + 1, y, -1);//����ġ ����
	else if (data[x - 1][y - 1] == 10 && data[x][y] > 19 && data[x + 1][y + 1] < 9 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] > 19 && data[x + 4][y + 4] < 9 && data[x + 5][y + 5] != 20)//��
		stone_Pronunciation(data, x + 1, y + 1, -1);//����ġ ����
	else if (data[x][y - 1] == 10 && data[x][y] > 19 && data[x][y + 1] < 9 && data[x][y + 2] > 19 && data[x][y + 3] > 19 && data[x][y + 4] < 9 && data[x][y + 5] != 20)//��
		stone_Pronunciation(data, x, y + 1, -1);//����ġ ����
	else if (data[x + 1][y - 1] == 10 && data[x][y] > 19 && data[x - 1][y + 1] < 9 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] > 19 && data[x - 4][y + 4] < 9 && data[x - 5][y + 5] != 20)//��
		stone_Pronunciation(data, x - 1, y + 1, -1);//����ġ ����

	//nx11x10
	else if (data[x - 2][y + 5] != 20 && data[x - 1][y] < 9 && data[x][y] > 19 && data[x + 1][y] > 19 && data[x + 2][y] < 9 && data[x + 3][y] > 19 && data[x + 4][y] == 10)//��
		stone_Pronunciation(data, x + 2, y, -1);//����ġ ����
	else if (data[x - 2][y - 2] != 20 && data[x - 1][y - 1] < 9 && data[x][y] > 19 && data[x + 1][y + 1] > 19 && data[x + 2][y + 2] < 9 && data[x + 3][y + 3] > 19 && data[x + 4][y + 4] == 10)//��
		stone_Pronunciation(data, x + 2, y + 2, -1);//����ġ ����
	else if (data[x][y - 2] != 20 && data[x][y - 1] < 9 && data[x][y] > 19 && data[x][y + 1] > 19 && data[x][y + 2] < 9 && data[x][y + 3] > 19 && data[x][y + 4] == 10)//��
		stone_Pronunciation(data, x, y + 2, -1);//����ġ ����
	else if (data[x + 2][y - 2] != 20 && data[x + 1][y - 1] < 9 && data[x][y] > 19 && data[x - 1][y + 1] > 19 && data[x - 2][y + 2] < 9 && data[x - 3][y + 3] > 19 && data[x - 4][y + 4] == 10)//��
		stone_Pronunciation(data, x - 2, y + 2, -1);//����ġ ����

	//nx1x110
	else if (data[x - 2][y] != 20 && data[x - 1][y] < 9 && data[x][y] > 19 && data[x + 1][y] < 9 && data[x + 2][y] > 19 && data[x + 3][y] > 19 && data[x + 4][y] == 10)//��
		stone_Pronunciation(data, x + 1, y, -1);//����ġ ����
	else if (data[x - 2][y - 2] != 20 && data[x - 1][y - 1] < 9 && data[x][y] > 19 && data[x + 1][y + 1] < 9 && data[x + 2][y + 2] > 19 && data[x + 3][y + 3] > 19 && data[x + 4][y + 4] == 10)//��
		stone_Pronunciation(data, x + 1, y + 1, -1);//����ġ ����
	else if (data[x][y - 2] != 20 && data[x][y - 1] < 9 && data[x][y] > 19 && data[x][y + 1] < 9 && data[x][y + 2] > 19 && data[x][y + 3] > 19 && data[x][y + 4] == 10)//��
		stone_Pronunciation(data, x, y + 1, -1);//����ġ ����
	else if (data[x + 2][y - 2] != 20 && data[x + 1][y - 1] < 9 && data[x][y] > 19 && data[x - 1][y + 1] < 9 && data[x - 2][y + 2] > 19 && data[x - 3][y + 3] > 19 && data[x - 4][y + 4] == 10)//��
		stone_Pronunciation(data, x - 1, y + 1, -1);//����ġ ����

	else return 0;
	return 1;
}

int third_stone(int data[SIZE + 2][SIZE + 2], int x, int y, int other) {
	int save_data[3][2] = { 0, };
	int data_direction[4] = { 0, };
	int cnt = 0;
	//  1
	//xx000xx
	if (other == 0) {
		if (data[x - 2][y] < 9 && data[x - 1][y] < 9 && data[x + 1][y] == 10 && data[x + 2][y] == 10 && data[x + 3][y] < 9 && data[x + 4][y] < 9) {//������
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 1;
			save_data[1][1] = y;
			save_data[2][0] = x + 2;
			save_data[2][1] = y;
			cnt++;
			data_direction[0] = 1;
		}

		else if (data[x - 2][y - 2] < 9 && data[x - 1][y - 1] < 9 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] < 9) {//������ �Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 1;
			save_data[1][1] = y + 1;
			save_data[2][0] = x + 2;
			save_data[2][1] = y + 2;
			cnt++;
			data_direction[1] = 1;
		}

		else if (data[x][y - 2] < 9 && data[x][y - 1] < 9 && data[x][y + 1] == 10 && data[x][y + 2] == 10 && data[x][y + 3] < 9 && data[x][y + 4] < 9) {//�Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x;
			save_data[1][1] = y + 1;
			save_data[2][0] = x;
			save_data[2][1] = y + 2;
			cnt++;
			data_direction[2] = 1;
		}

		else if (data[x + 2][y - 2] < 9 && data[x + 1][y - 1] < 9 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] < 9) {//���� �Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y + 1;
			save_data[2][0] = x - 2;
			save_data[2][1] = y + 2;
			cnt++;
			data_direction[3] = 1;
		}

		else if (data[x + 2][y] < 9 && data[x + 1][y] < 9 && data[x - 1][y] == 10 && data[x - 2][y] == 10 && data[x - 3][y] < 9 && data[x - 4][y] < 9) {//����
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y;
			save_data[2][0] = x - 2;
			save_data[2][1] = y;
			cnt++;
			data_direction[0] = 1;
		}

		else if (data[x + 2][y + 2] < 9 && data[x + 1][y + 1] < 9 && data[x - 1][y - 1] == 10 && data[x - 2][y - 2] == 10 && data[x - 3][y - 3] < 9 && data[x - 4][y - 4] < 9) {//���� ��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y - 1;
			save_data[2][0] = x - 2;
			save_data[2][1] = y - 2;
			cnt++;
			data_direction[1] = 1;
		}

		else if (data[x][y + 2] < 9 && data[x][y + 1] < 9 && data[x][y - 1] == 10 && data[x][y - 2] == 10 && data[x][y - 3] < 9 && data[x][y - 4] < 9) {//��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x;
			save_data[1][1] = y - 1;
			save_data[2][0] = x;
			save_data[2][1] = y - 2;
			cnt++;
			data_direction[2] = 1;
		}

		else if (data[x - 2][y + 2] < 9 && data[x - 1][y + 1] < 9 && data[x + 1][y - 1] == 10 && data[x + 2][y - 2] == 10 && data[x + 3][y - 3] < 9 && data[x + 4][y - 4] < 9) {//������ ��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 1;
			save_data[1][1] = y - 1;
			save_data[2][0] = x + 2;
			save_data[2][1] = y - 2;
			cnt++;
			data_direction[3] = 1;
		}

		//  1
		//1x000xx
		else if (data[x - 2][y] == 20 && data[x - 1][y] < 9 && data[x + 1][y] == 10 && data[x + 2][y] == 10 && data[x + 3][y] < 9 && data[x + 4][y] < 9) {//������
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 1;
			save_data[1][1] = y;
			save_data[2][0] = x + 2;
			save_data[2][1] = y;
			cnt++;
			data_direction[0] = 1;
		}

		else if (data[x - 2][y - 2] == 20 && data[x - 1][y - 1] < 9 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] < 9) {//������ �Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 1;
			save_data[1][1] = y + 1;
			save_data[2][0] = x + 2;
			save_data[2][1] = y + 2;
			cnt++;
			data_direction[1] = 1;
		}

		else if (data[x][y - 2] == 20 && data[x][y - 1] < 9 && data[x][y + 1] == 10 && data[x][y + 2] == 10 && data[x][y + 3] < 9 && data[x][y + 4] < 9) {//�Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x;
			save_data[1][1] = y + 1;
			save_data[2][0] = x;
			save_data[2][1] = y + 2;
			cnt++;
			data_direction[2] = 1;
		}

		else if (data[x + 2][y - 2] == 20 && data[x + 1][y - 1] < 9 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] < 9) {//���� �Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y + 1;
			save_data[2][0] = x - 2;
			save_data[2][1] = y + 2;
			cnt++;
			data_direction[3] = 1;
		}

		else if (data[x + 2][y] == 20 && data[x + 1][y] < 9 && data[x - 1][y] == 10 && data[x - 2][y] == 10 && data[x - 3][y] < 9 && data[x - 4][y] < 9) {//����
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y;
			save_data[2][0] = x - 2;
			save_data[2][1] = y;
			cnt++;
			data_direction[0] = 1;
		}

		else if (data[x + 2][y + 2] == 20 && data[x + 1][y + 1] < 9 && data[x - 1][y - 1] == 10 && data[x - 2][y - 2] == 10 && data[x - 3][y - 3] < 9 && data[x - 4][y - 4] < 9) {//���� ��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y - 1;
			save_data[2][0] = x - 2;
			save_data[2][1] = y - 2;
			cnt++;
			data_direction[1] = 1;
		}

		else if (data[x][y + 2] == 20 && data[x][y + 1] < 9 && data[x][y - 1] == 10 && data[x][y - 2] == 10 && data[x][y - 3] < 9 && data[x][y - 4] < 9) {//��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x;
			save_data[1][1] = y - 1;
			save_data[2][0] = x;
			save_data[2][1] = y - 2;
			cnt++;
			data_direction[2] = 1;
		}

		else if (data[x - 2][y + 2] == 20 && data[x - 1][y + 1] < 9 && data[x + 1][y - 1] == 10 && data[x + 2][y - 2] == 10 && data[x + 3][y - 3] < 9 && data[x + 4][y - 4] < 9) {//������ ��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 1;
			save_data[1][1] = y - 1;
			save_data[2][0] = x + 2;
			save_data[2][1] = y - 2;
			cnt++;
			data_direction[3] = 1;
		}

		//  1
		//xx000x1
		else if (data[x - 2][y] < 9 && data[x - 1][y] < 9 && data[x + 1][y] == 10 && data[x + 2][y] == 10 && data[x + 3][y] < 9 && data[x + 4][y] == 20) {//������
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 1;
			save_data[1][1] = y;
			save_data[2][0] = x + 2;
			save_data[2][1] = y;
			cnt++;
			data_direction[0] = 1;
		}

		else if (data[x - 2][y - 2] < 9 && data[x - 1][y - 1] < 9 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] == 20) {//������ �Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 1;
			save_data[1][1] = y + 1;
			save_data[2][0] = x + 2;
			save_data[2][1] = y + 2;
			cnt++;
			data_direction[1] = 1;
		}

		else if (data[x][y - 2] < 9 && data[x][y - 1] < 9 && data[x][y + 1] == 10 && data[x][y + 2] == 10 && data[x][y + 3] < 9 && data[x][y + 4] == 20) {//�Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x;
			save_data[1][1] = y + 1;
			save_data[2][0] = x;
			save_data[2][1] = y + 2;
			cnt++;
			data_direction[2] = 1;
		}

		else if (data[x + 2][y - 2] < 9 && data[x + 1][y - 1] < 9 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] == 20) {//���� �Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y + 1;
			save_data[2][0] = x - 2;
			save_data[2][1] = y + 2;
			cnt++;
			data_direction[3] = 1;
		}

		else if (data[x + 2][y] < 9 && data[x + 1][y] < 9 && data[x - 1][y] == 10 && data[x - 2][y] == 10 && data[x - 3][y] < 9 && data[x - 4][y] == 20) {//����
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y;
			save_data[2][0] = x - 2;
			save_data[2][1] = y;
			cnt++;
			data_direction[0] = 1;
		}

		else if (data[x + 2][y + 2] < 9 && data[x + 1][y + 1] < 9 && data[x - 1][y - 1] == 10 && data[x - 2][y - 2] == 10 && data[x - 3][y - 3] < 9 && data[x - 4][y - 4] == 20) {//���� ��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y - 1;
			save_data[2][0] = x - 2;
			save_data[2][1] = y - 2;
			cnt++;
			data_direction[1] = 1;
		}

		else if (data[x][y + 2] < 9 && data[x][y + 1] < 9 && data[x][y - 1] == 10 && data[x][y - 2] == 10 && data[x][y - 3] < 9 && data[x][y - 4] == 20) {//��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x;
			save_data[1][1] = y - 1;
			save_data[2][0] = x;
			save_data[2][1] = y - 2;
			cnt++;
			data_direction[2] = 1;
		}

		else if (data[x - 2][y + 2] < 9 && data[x - 1][y + 1] < 9 && data[x + 1][y - 1] == 10 && data[x + 2][y - 2] == 10 && data[x + 3][y - 3] < 9 && data[x + 4][y - 4] == 20) {//������ ��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 1;
			save_data[1][1] = y - 1;
			save_data[2][0] = x + 2;
			save_data[2][1] = y - 2;
			cnt++;
			data_direction[3] = 1;
		}


		//   1
		//xx000xx
		else if (data[x - 3][y] < 9 && data[x - 2][y] < 9 && data[x - 1][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] < 9 && data[x + 3][y] < 9) {//������
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y;
			save_data[2][0] = x + 1;
			save_data[2][1] = y;
			cnt++;
			data_direction[0] = 1;
		}

		else if (data[x - 3][y - 3] < 9 && data[x - 2][y - 2] < 9 && data[x - 1][y - 1] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] < 9 && data[x + 3][y + 3] < 9) {//������ �Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y - 1;
			save_data[2][0] = x + 1;
			save_data[2][1] = y + 1;
			cnt++;
			data_direction[1] = 1;
		}

		else if (data[x][y - 3] < 9 && data[x][y - 2] < 9 && data[x][y - 1] == 10 && data[x][y + 1] == 10 && data[x][y + 2] < 9 && data[x][y + 3] < 9) {//�Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x;
			save_data[1][1] = y - 1;
			save_data[2][0] = x;
			save_data[2][1] = y + 1;
			cnt++;
			data_direction[2] = 1;
		}

		else if (data[x + 3][y - 3] < 9 && data[x + 2][y - 2] < 9 && data[x + 1][y - 1] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] < 9 && data[x - 3][y + 3] < 9) {//���� �Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 1;
			save_data[1][1] = y - 1;
			save_data[2][0] = x - 1;
			save_data[2][1] = y + 1;
			cnt++;
			data_direction[3] = 1;
		}

		else if (data[x + 3][y] < 9 && data[x + 2][y] < 9 && data[x + 1][y] == 10 && data[x - 1][y] == 10 && data[x - 2][y] < 9 && data[x - 3][y] < 9) {//����
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 1;
			save_data[1][1] = y;
			save_data[2][0] = x - 1;
			save_data[2][1] = y;
			cnt++;
			data_direction[0] = 1;
		}

		else if (data[x + 3][y + 3] < 9 && data[x + 2][y + 2] < 9 && data[x + 1][y + 1] == 10 && data[x - 1][y - 1] == 10 && data[x - 2][y - 2] < 9 && data[x - 3][y - 3] < 9) {//���� ��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y - 1;
			save_data[2][0] = x + 1;
			save_data[2][1] = y + 1;
			cnt++;
			data_direction[1] = 1;
		}

		else if (data[x][y + 3] < 9 && data[x][y + 2] < 9 && data[x][y + 1] == 10 && data[x][y - 1] == 10 && data[x][y - 2] < 9 && data[x][y - 3] < 9) {//��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x;
			save_data[1][1] = y + 1;
			save_data[2][0] = x;
			save_data[2][1] = y - 1;
			cnt++;
			data_direction[2] = 1;
		}

		else if (data[x - 3][y + 3] < 9 && data[x - 2][y + 2] < 9 && data[x - 1][y + 1] == 10 && data[x + 1][y - 1] == 10 && data[x + 2][y - 2] < 9 && data[x + 3][y - 3] < 9) {//������ ��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y + 1;
			save_data[2][0] = x + 1;
			save_data[2][1] = y - 1;
			cnt++;
			data_direction[3] = 1;
		}

		//   1
		//1x000xx
		else if (data[x - 3][y] == 20 && data[x - 2][y] < 9 && data[x - 1][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] < 9 && data[x + 3][y] < 9) {//������
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y;
			save_data[2][0] = x + 1;
			save_data[2][1] = y;
			cnt++;
			data_direction[0] = 1;
		}

		else if (data[x - 3][y - 3] == 20 && data[x - 2][y - 2] < 9 && data[x - 1][y - 1] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] < 9 && data[x + 3][y + 3] < 9) {//������ �Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y - 1;
			save_data[2][0] = x + 1;
			save_data[2][1] = y + 1;
			cnt++;
			data_direction[1] = 1;
		}

		else if (data[x][y - 3] == 20 && data[x][y - 2] < 9 && data[x][y - 1] == 10 && data[x][y + 1] == 10 && data[x][y + 2] < 9 && data[x][y + 3] < 9) {//�Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x;
			save_data[1][1] = y - 1;
			save_data[2][0] = x;
			save_data[2][1] = y + 1;
			cnt++;
			data_direction[2] = 1;
		}

		else if (data[x + 3][y - 3] == 20 && data[x + 2][y - 2] < 9 && data[x + 1][y - 1] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] < 9 && data[x - 3][y + 3] < 9) {//���� �Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 1;
			save_data[1][1] = y - 1;
			save_data[2][0] = x - 1;
			save_data[2][1] = y + 1;
			cnt++;
			data_direction[3] = 1;
		}

		else if (data[x + 3][y] == 20 && data[x + 2][y] < 9 && data[x + 1][y] == 10 && data[x - 1][y] == 10 && data[x - 2][y] < 9 && data[x - 3][y] < 9) {//����
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 1;
			save_data[1][1] = y;
			save_data[2][0] = x - 1;
			save_data[2][1] = y;
			cnt++;
			data_direction[0] = 1;
		}

		else if (data[x + 3][y + 3] == 20 && data[x + 2][y + 2] < 9 && data[x + 1][y + 1] == 10 && data[x - 1][y - 1] == 10 && data[x - 2][y - 2] < 9 && data[x - 3][y - 3] < 9) {//���� ��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y - 1;
			save_data[2][0] = x + 1;
			save_data[2][1] = y + 1;
			cnt++;
			data_direction[1] = 1;
		}

		else if (data[x][y + 3] == 20 && data[x][y + 2] < 9 && data[x][y + 1] == 10 && data[x][y - 1] == 10 && data[x][y - 2] < 9 && data[x][y - 3] < 9) {//��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x;
			save_data[1][1] = y + 1;
			save_data[2][0] = x;
			save_data[2][1] = y - 1;
			cnt++;
			data_direction[2] = 1;
		}

		else if (data[x - 3][y + 3] == 20 && data[x - 2][y + 2] < 9 && data[x - 1][y + 1] == 10 && data[x + 1][y - 1] == 10 && data[x + 2][y - 2] < 9 && data[x + 3][y - 3] < 9) {//������ ��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y + 1;
			save_data[2][0] = x + 1;
			save_data[2][1] = y - 1;
			cnt++;
			data_direction[3] = 1;
		}

		//   1
		//xx000x1
		else if (data[x - 3][y] < 9 && data[x - 2][y] < 9 && data[x - 1][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] < 9 && data[x + 3][y] == 20) {//������
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y;
			save_data[2][0] = x + 1;
			save_data[2][1] = y;
			cnt++;
			data_direction[0] = 1;
		}

		else if (data[x - 3][y - 3] < 9 && data[x - 2][y - 2] < 9 && data[x - 1][y - 1] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] < 9 && data[x + 3][y + 3] == 20) {//������ �Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y - 1;
			save_data[2][0] = x + 1;
			save_data[2][1] = y + 1;
			cnt++;
			data_direction[1] = 1;
		}

		else if (data[x][y - 3] < 9 && data[x][y - 2] < 9 && data[x][y - 1] == 10 && data[x][y + 1] == 10 && data[x][y + 2] < 9 && data[x][y + 3] == 20) {//�Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x;
			save_data[1][1] = y - 1;
			save_data[2][0] = x;
			save_data[2][1] = y + 1;
			cnt++;
			data_direction[2] = 1;
		}

		else if (data[x + 3][y - 3] < 9 && data[x + 2][y - 2] < 9 && data[x + 1][y - 1] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] < 9 && data[x - 3][y + 3] == 20) {//���� �Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 1;
			save_data[1][1] = y - 1;
			save_data[2][0] = x - 1;
			save_data[2][1] = y + 1;
			cnt++;
			data_direction[3] = 1;
		}

		else if (data[x + 3][y] < 9 && data[x + 2][y] < 9 && data[x + 1][y] == 10 && data[x - 1][y] == 10 && data[x - 2][y] < 9 && data[x - 3][y] == 20) {//����
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 1;
			save_data[1][1] = y;
			save_data[2][0] = x - 1;
			save_data[2][1] = y;
			cnt++;
			data_direction[0] = 1;
		}

		else if (data[x + 3][y + 3] < 9 && data[x + 2][y + 2] < 9 && data[x + 1][y + 1] == 10 && data[x - 1][y - 1] == 10 && data[x - 2][y - 2] < 9 && data[x - 3][y - 3] == 20) {//���� ��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y - 1;
			save_data[2][0] = x + 1;
			save_data[2][1] = y + 1;
			cnt++;
			data_direction[1] = 1;
		}

		else if (data[x][y + 3] < 9 && data[x][y + 2] < 9 && data[x][y + 1] == 10 && data[x][y - 1] == 10 && data[x][y - 2] < 9 && data[x][y - 3] == 20) {//��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x;
			save_data[1][1] = y + 1;
			save_data[2][0] = x;
			save_data[2][1] = y - 1;
			cnt++;
			data_direction[2] = 1;
		}

		else if (data[x - 3][y + 3] < 9 && data[x - 2][y + 2] < 9 && data[x - 1][y + 1] == 10 && data[x + 1][y - 1] == 10 && data[x + 2][y - 2] < 9 && data[x + 3][y - 3] == 20) {//������ ��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y + 1;
			save_data[2][0] = x + 1;
			save_data[2][1] = y - 1;
			cnt++;
			data_direction[3] = 1;
		}
		// 1
		//x0x00x
		else if (data[x - 1][y] < 9 && data[x + 1][y] < 9 && data[x + 2][y] == 10 && data[x + 3][y] == 10 && data[x + 4][y] < 9) {//������
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 2;
			save_data[1][1] = y;
			save_data[2][0] = x + 3;
			save_data[2][1] = y;
			cnt++;
			data_direction[0] = 1;
		}

		else if (data[x - 1][y - 1] < 9 && data[x + 1][y + 1] < 9 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] == 10 && data[x + 4][y + 4] < 9) {//������ �Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 2;
			save_data[1][1] = y + 2;
			save_data[2][0] = x + 3;
			save_data[2][1] = y + 3;
			cnt++;
			data_direction[1] = 1;
		}

		else if (data[x][y - 1] < 9 && data[x][y + 1] < 9 && data[x][y + 2] == 10 && data[x][y + 3] == 10 && data[x][y + 4] < 9) {//�Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x;
			save_data[1][1] = y + 2;
			save_data[2][0] = x;
			save_data[2][1] = y + 3;
			cnt++;
			data_direction[2] = 1;
		}

		else if (data[x + 1][y - 1] < 9 && data[x - 1][y + 1] < 9 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] == 10 && data[x - 4][y + 4] < 9) {//���� �Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 2;
			save_data[1][1] = y + 2;
			save_data[2][0] = x - 3;
			save_data[2][1] = y + 3;
			cnt++;
			data_direction[3] = 1;
		}

		else if (data[x + 1][y] < 9 && data[x - 1][y] < 9 && data[x - 2][y] == 10 && data[x - 3][y] == 10 && data[x - 4][y] < 9) {//����
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 2;
			save_data[1][1] = y;
			save_data[2][0] = x - 3;
			save_data[2][1] = y;
			cnt++;
			data_direction[0] = 1;
		}

		else if (data[x + 1][y + 1] < 9 && data[x - 1][y - 1] < 9 && data[x - 2][y - 2] == 10 && data[x - 3][y - 3] == 10 && data[x - 4][y - 4] < 9) {//���� ��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 2;
			save_data[1][1] = y - 2;
			save_data[2][0] = x - 3;
			save_data[2][1] = y - 3;
			cnt++;
			data_direction[1] = 1;
		}

		else if (data[x][y + 1] < 9 && data[x][y - 1] < 9 && data[x][y - 2] == 10 && data[x][y - 3] == 10 && data[x][y - 4] < 9) {//��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x;
			save_data[1][1] = y - 2;
			save_data[2][0] = x;
			save_data[2][1] = y - 3;
			cnt++;
			data_direction[2] = 1;
		}

		else if (data[x - 1][y + 1] < 9 && data[x + 1][y - 1] < 9 && data[x + 2][y - 2] == 10 && data[x + 3][y - 3] == 10 && data[x + 4][y - 4] < 9) {//������ ��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 2;
			save_data[1][1] = y - 2;
			save_data[2][0] = x + 3;
			save_data[2][1] = y - 3;
			cnt++;
			data_direction[3] = 1;
		}

		// 1
		//x00x0x
		else if (data[x - 1][y] < 9 && data[x + 1][y] == 10 && data[x + 2][y] < 9 && data[x + 3][y] == 10 && data[x + 4][y] < 9) {//������
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 1;
			save_data[1][1] = y;
			save_data[2][0] = x + 3;
			save_data[2][1] = y;
			cnt++;
			data_direction[0] = 1;
		}

		else if (data[x - 1][y - 1] < 9 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] < 9 && data[x + 3][y + 3] == 10 && data[x + 4][y + 4] < 9) {//������ �Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 1;
			save_data[1][1] = y + 1;
			save_data[2][0] = x + 3;
			save_data[2][1] = y + 3;
			cnt++;
			data_direction[1] = 1;
		}

		else if (data[x][y - 1] < 9 && data[x][y + 1] == 10 && data[x][y + 2] < 9 && data[x][y + 3] == 10 && data[x][y + 4] < 9) {//�Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x;
			save_data[1][1] = y + 1;
			save_data[2][0] = x;
			save_data[2][1] = y + 3;
			cnt++;
			data_direction[2] = 1;
		}

		else if (data[x + 1][y - 1] < 9 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] < 9 && data[x - 3][y + 3] == 10 && data[x - 4][y + 4] < 9) {//���� �Ʒ�
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y + 1;
			save_data[2][0] = x - 3;
			save_data[2][1] = y + 3;
			cnt++;
			data_direction[3] = 1;
		}

		else if (data[x + 1][y] < 9 && data[x - 1][y] == 10 && data[x - 2][y] < 9 && data[x - 3][y] == 10 && data[x - 4][y] < 9) {//����
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y;
			save_data[2][0] = x - 3;
			save_data[2][1] = y;
			cnt++;
			data_direction[0] = 1;
		}

		else if (data[x + 1][y + 1] < 9 && data[x - 1][y - 1] == 10 && data[x - 2][y - 2] < 9 && data[x - 3][y - 3] == 10 && data[x - 4][y - 4] < 9) {//���� ��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x - 1;
			save_data[1][1] = y - 1;
			save_data[2][0] = x - 3;
			save_data[2][1] = y - 3;
			cnt++;
			data_direction[1] = 1;
		}

		else if (data[x][y + 1] < 9 && data[x][y - 1] == 10 && data[x][y - 2] < 9 && data[x][y - 3] == 10 && data[x][y - 4] < 9) {//��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x;
			save_data[1][1] = y - 1;
			save_data[2][0] = x;
			save_data[2][1] = y - 3;
			cnt++;
			data_direction[2] = 1;
		}

		else if (data[x - 1][y + 1] < 9 && data[x + 1][y - 1] == 10 && data[x + 2][y - 2] < 9 && data[x + 3][y - 3] == 10 && data[x + 4][y - 4] < 9) {//������ ��
			save_data[0][0] = x;
			save_data[0][1] = y;
			save_data[1][0] = x + 1;
			save_data[1][1] = y - 1;
			save_data[2][0] = x + 3;
			save_data[2][1] = y - 3;
			cnt++;
			data_direction[3] = 1;
		}

		if (cnt == 1) {
			for (int i = 0; i < 3; i++) {
				if (third_stone_2(data, save_data[i][0], save_data[i][1], data_direction) == 1)
					return 1;
			}
		}
	}
	return 0;
}
int third_stone_2(int data[SIZE + 2][SIZE + 2], int x, int y, int data_direction[4]) {
	int cnt = 0;
	//  1
	//xx000xx
	if (data_direction[0] == 0 && data[x - 2][y] < 9 && data[x - 1][y] < 9 && data[x + 1][y] == 10 && data[x + 2][y] == 10 && data[x + 3][y] < 9 && data[x + 4][y] < 9)//������
		cnt++;


	else if (data_direction[1] == 0 && data[x - 2][y - 2] < 9 && data[x - 1][y - 1] < 9 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] < 9) //������ �Ʒ�
		cnt++;

	else if (data_direction[2] == 0 && data[x][y - 2] < 9 && data[x][y - 1] < 9 && data[x][y + 1] == 10 && data[x][y + 2] == 10 && data[x][y + 3] < 9 && data[x][y + 4] < 9) //�Ʒ�
		cnt++;

	else if (data_direction[3] == 0 && data[x + 2][y - 2] < 9 && data[x + 1][y - 1] < 9 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] < 9) //���� �Ʒ�
		cnt++;

	else if (data_direction[0] == 0 && data[x + 2][y] < 9 && data[x + 1][y] < 9 && data[x - 1][y] == 10 && data[x - 2][y] == 10 && data[x - 3][y] < 9 && data[x - 4][y] < 9) //����
		cnt++;

	else if (data_direction[1] == 0 && data[x + 2][y + 2] < 9 && data[x + 1][y + 1] < 9 && data[x - 1][y - 1] == 10 && data[x - 2][y - 2] == 10 && data[x - 3][y - 3] < 9 && data[x - 4][y - 4] < 9) //���� ��
		cnt++;

	else if (data_direction[2] == 0 && data[x][y + 2] < 9 && data[x][y + 1] < 9 && data[x][y - 1] == 10 && data[x][y - 2] == 10 && data[x][y - 3] < 9 && data[x][y - 4] < 9) //��
		cnt++;

	else if (data_direction[3] == 0 && data[x - 2][y + 2] < 9 && data[x - 1][y + 1] < 9 && data[x + 1][y - 1] == 10 && data[x + 2][y - 2] == 10 && data[x + 3][y - 3] < 9 && data[x + 4][y - 4] < 9) //������ ��
		cnt++;

	//  1
	//1x000xx
	else if (data_direction[0] == 0 && data[x - 2][y] == 20 && data[x - 1][y] < 9 && data[x + 1][y] == 10 && data[x + 2][y] == 10 && data[x + 3][y] < 9 && data[x + 4][y] < 9) //������
		cnt++;

	else if (data_direction[1] == 0 && data[x - 2][y - 2] == 20 && data[x - 1][y - 1] < 9 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] < 9) //������ �Ʒ�
		cnt++;

	else if (data_direction[2] == 0 && data[x][y - 2] == 20 && data[x][y - 1] < 9 && data[x][y + 1] == 10 && data[x][y + 2] == 10 && data[x][y + 3] < 9 && data[x][y + 4] < 9) //�Ʒ�
		cnt++;

	else if (data_direction[3] == 0 && data[x + 2][y - 2] == 20 && data[x + 1][y - 1] < 9 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] < 9) //���� �Ʒ�
		cnt++;

	else if (data_direction[0] == 0 && data[x + 2][y] == 20 && data[x + 1][y] < 9 && data[x - 1][y] == 10 && data[x - 2][y] == 10 && data[x - 3][y] < 9 && data[x - 4][y] < 9) //����
		cnt++;

	else if (data_direction[1] == 0 && data[x + 2][y + 2] == 20 && data[x + 1][y + 1] < 9 && data[x - 1][y - 1] == 10 && data[x - 2][y - 2] == 10 && data[x - 3][y - 3] < 9 && data[x - 4][y - 4] < 9) //���� ��
		cnt++;

	else if (data_direction[2] == 0 && data[x][y + 2] == 20 && data[x][y + 1] < 9 && data[x][y - 1] == 10 && data[x][y - 2] == 10 && data[x][y - 3] < 9 && data[x][y - 4] < 9) //��
		cnt++;

	else if (data_direction[3] == 0 && data[x - 2][y + 2] == 20 && data[x - 1][y + 1] < 9 && data[x + 1][y - 1] == 10 && data[x + 2][y - 2] == 10 && data[x + 3][y - 3] < 9 && data[x + 4][y - 4] < 9) //������ ��
		cnt++;

	//  1
	//xx000x1
	else if (data_direction[0] == 0 && data[x - 2][y] < 9 && data[x - 1][y] < 9 && data[x + 1][y] == 10 && data[x + 2][y] == 10 && data[x + 3][y] < 9 && data[x + 4][y] == 20) //������
		cnt++;

	else if (data_direction[1] == 0 && data[x - 2][y - 2] < 9 && data[x - 1][y - 1] < 9 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] < 9 && data[x + 4][y + 4] == 20) //������ �Ʒ�
		cnt++;

	else if (data_direction[2] == 0 && data[x][y - 2] < 9 && data[x][y - 1] < 9 && data[x][y + 1] == 10 && data[x][y + 2] == 10 && data[x][y + 3] < 9 && data[x][y + 4] == 20) //�Ʒ�
		cnt++;

	else if (data_direction[3] == 0 && data[x + 2][y - 2] < 9 && data[x + 1][y - 1] < 9 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] < 9 && data[x - 4][y + 4] == 20) //���� �Ʒ�
		cnt++;

	else if (data_direction[0] == 0 && data[x + 2][y] < 9 && data[x + 1][y] < 9 && data[x - 1][y] == 10 && data[x - 2][y] == 10 && data[x - 3][y] < 9 && data[x - 4][y] == 20) //����
		cnt++;

	else if (data_direction[1] == 0 && data[x + 2][y + 2] < 9 && data[x + 1][y + 1] < 9 && data[x - 1][y - 1] == 10 && data[x - 2][y - 2] == 10 && data[x - 3][y - 3] < 9 && data[x - 4][y - 4] == 20) //���� ��
		cnt++;

	else if (data_direction[2] == 0 && data[x][y + 2] < 9 && data[x][y + 1] < 9 && data[x][y - 1] == 10 && data[x][y - 2] == 10 && data[x][y - 3] < 9 && data[x][y - 4] == 20) //��
		cnt++;

	else if (data_direction[3] == 0 && data[x - 2][y + 2] < 9 && data[x - 1][y + 1] < 9 && data[x + 1][y - 1] == 10 && data[x + 2][y - 2] == 10 && data[x + 3][y - 3] < 9 && data[x + 4][y - 4] == 20) //������ ��
		cnt++;


	//   1
	//xx000xx
	else if (data_direction[0] == 0 && data[x - 3][y] < 9 && data[x - 2][y] < 9 && data[x - 1][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] < 9 && data[x + 3][y] < 9) //������
		cnt++;

	else if (data_direction[1] == 0 && data[x - 3][y - 3] < 9 && data[x - 2][y - 2] < 9 && data[x - 1][y - 1] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] < 9 && data[x + 3][y + 3] < 9) //������ �Ʒ�
		cnt++;

	else if (data_direction[2] == 0 && data[x][y - 3] < 9 && data[x][y - 2] < 9 && data[x][y - 1] == 10 && data[x][y + 1] == 10 && data[x][y + 2] < 9 && data[x][y + 3] < 9) //�Ʒ�
		cnt++;

	else if (data_direction[3] == 0 && data[x + 3][y - 3] < 9 && data[x + 2][y - 2] < 9 && data[x + 1][y - 1] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] < 9 && data[x - 3][y + 3] < 9) //���� �Ʒ�
		cnt++;

	else if (data_direction[0] == 0 && data[x + 3][y] < 9 && data[x + 2][y] < 9 && data[x + 1][y] == 10 && data[x - 1][y] == 10 && data[x - 2][y] < 9 && data[x - 3][y] < 9) //����
		cnt++;

	else if (data_direction[1] == 0 && data[x + 3][y + 3] < 9 && data[x + 2][y + 2] < 9 && data[x + 1][y + 1] == 10 && data[x - 1][y - 1] == 10 && data[x - 2][y - 2] < 9 && data[x - 3][y - 3] < 9) //���� ��
		cnt++;

	else if (data_direction[2] == 0 && data[x][y + 3] < 9 && data[x][y + 2] < 9 && data[x][y + 1] == 10 && data[x][y - 1] == 10 && data[x][y - 2] < 9 && data[x][y - 3] < 9) //��
		cnt++;

	else if (data_direction[3] == 0 && data[x - 3][y + 3] < 9 && data[x - 2][y + 2] < 9 && data[x - 1][y + 1] == 10 && data[x + 1][y - 1] == 10 && data[x + 2][y - 2] < 9 && data[x + 3][y - 3] < 9) //������ ��
		cnt++;

	//   1
	//1x000xx
	else if (data_direction[0] == 0 && data[x - 3][y] == 20 && data[x - 2][y] < 9 && data[x - 1][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] < 9 && data[x + 3][y] < 9) //������
		cnt++;

	else if (data_direction[1] == 0 && data[x - 3][y - 3] == 20 && data[x - 2][y - 2] < 9 && data[x - 1][y - 1] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] < 9 && data[x + 3][y + 3] < 9) //������ �Ʒ�
		cnt++;

	else if (data_direction[2] == 0 && data[x][y - 3] == 20 && data[x][y - 2] < 9 && data[x][y - 1] == 10 && data[x][y + 1] == 10 && data[x][y + 2] < 9 && data[x][y + 3] < 9) //�Ʒ�
		cnt++;

	else if (data_direction[3] == 0 && data[x + 3][y - 3] == 20 && data[x + 2][y - 2] < 9 && data[x + 1][y - 1] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] < 9 && data[x - 3][y + 3] < 9) //���� �Ʒ�
		cnt++;

	else if (data_direction[0] == 0 && data[x + 3][y] == 20 && data[x + 2][y] < 9 && data[x + 1][y] == 10 && data[x - 1][y] == 10 && data[x - 2][y] < 9 && data[x - 3][y] < 9) //����
		cnt++;

	else if (data_direction[1] == 0 && data[x + 3][y + 3] == 20 && data[x + 2][y + 2] < 9 && data[x + 1][y + 1] == 10 && data[x - 1][y - 1] == 10 && data[x - 2][y - 2] < 9 && data[x - 3][y - 3] < 9) //���� ��
		cnt++;

	else if (data_direction[2] == 0 && data[x][y + 3] == 20 && data[x][y + 2] < 9 && data[x][y + 1] == 10 && data[x][y - 1] == 10 && data[x][y - 2] < 9 && data[x][y - 3] < 9) //��
		cnt++;

	else if (data_direction[3] == 0 && data[x - 3][y + 3] == 20 && data[x - 2][y + 2] < 9 && data[x - 1][y + 1] == 10 && data[x + 1][y - 1] == 10 && data[x + 2][y - 2] < 9 && data[x + 3][y - 3] < 9) //������ ��
		cnt++;

	//   1
	//xx000x1
	else if (data_direction[0] == 0 && data[x - 3][y] < 9 && data[x - 2][y] < 9 && data[x - 1][y] == 10 && data[x + 1][y] == 10 && data[x + 2][y] < 9 && data[x + 3][y] == 20) //������
		cnt++;

	else if (data_direction[1] == 0 && data[x - 3][y - 3] < 9 && data[x - 2][y - 2] < 9 && data[x - 1][y - 1] == 10 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] < 9 && data[x + 3][y + 3] == 20) //������ �Ʒ�
		cnt++;

	else if (data_direction[2] == 0 && data[x][y - 3] < 9 && data[x][y - 2] < 9 && data[x][y - 1] == 10 && data[x][y + 1] == 10 && data[x][y + 2] < 9 && data[x][y + 3] == 20) //�Ʒ�
		cnt++;

	else if (data_direction[3] == 0 && data[x + 3][y - 3] < 9 && data[x + 2][y - 2] < 9 && data[x + 1][y - 1] == 10 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] < 9 && data[x - 3][y + 3] == 20) //���� �Ʒ�
		cnt++;

	else if (data_direction[0] == 0 && data[x + 3][y] < 9 && data[x + 2][y] < 9 && data[x + 1][y] == 10 && data[x - 1][y] == 10 && data[x - 2][y] < 9 && data[x - 3][y] == 20) //����
		cnt++;

	else if (data_direction[1] == 0 && data[x + 3][y + 3] < 9 && data[x + 2][y + 2] < 9 && data[x + 1][y + 1] == 10 && data[x - 1][y - 1] == 10 && data[x - 2][y - 2] < 9 && data[x - 3][y - 3] == 20) //���� ��
		cnt++;

	else if (data_direction[2] == 0 && data[x][y + 3] < 9 && data[x][y + 2] < 9 && data[x][y + 1] == 10 && data[x][y - 1] == 10 && data[x][y - 2] < 9 && data[x][y - 3] == 20) //��
		cnt++;

	else if (data_direction[3] == 0 && data[x - 3][y + 3] < 9 && data[x - 2][y + 2] < 9 && data[x - 1][y + 1] == 10 && data[x + 1][y - 1] == 10 && data[x + 2][y - 2] < 9 && data[x + 3][y - 3] == 20) //������ ��
		cnt++;

	// 1
	//x0x00x
	else if (data_direction[0] == 0 && data[x - 1][y] < 9 && data[x + 1][y] < 9 && data[x + 2][y] == 10 && data[x + 3][y] == 10 && data[x + 4][y] < 9) //������
		cnt++;

	else if (data_direction[1] == 0 && data[x - 1][y - 1] < 9 && data[x + 1][y + 1] < 9 && data[x + 2][y + 2] == 10 && data[x + 3][y + 3] == 10 && data[x + 4][y + 4] < 9) //������ �Ʒ�
		cnt++;

	else if (data_direction[2] == 0 && data[x][y - 1] < 9 && data[x][y + 1] < 9 && data[x][y + 2] == 10 && data[x][y + 3] == 10 && data[x][y + 4] < 9) //�Ʒ�
		cnt++;

	else if (data_direction[3] == 0 && data[x + 1][y - 1] < 9 && data[x - 1][y + 1] < 9 && data[x - 2][y + 2] == 10 && data[x - 3][y + 3] == 10 && data[x - 4][y + 4] < 9) //���� �Ʒ�
		cnt++;

	else if (data_direction[0] == 0 && data[x + 1][y] < 9 && data[x - 1][y] < 9 && data[x - 2][y] == 10 && data[x - 3][y] == 10 && data[x - 4][y] < 9) //����
		cnt++;


	else if (data_direction[1] == 0 && data[x + 1][y + 1] < 9 && data[x - 1][y - 1] < 9 && data[x - 2][y - 2] == 10 && data[x - 3][y - 3] == 10 && data[x - 4][y - 4] < 9) //���� ��
		cnt++;

	else if (data_direction[2] == 0 && data[x][y + 1] < 9 && data[x][y - 1] < 9 && data[x][y - 2] == 10 && data[x][y - 3] == 10 && data[x][y - 4] < 9) //��
		cnt++;

	else if (data_direction[3] == 0 && data[x - 1][y + 1] < 9 && data[x + 1][y - 1] < 9 && data[x + 2][y - 2] == 10 && data[x + 3][y - 3] == 10 && data[x + 4][y - 4] < 9) //������ ��
		cnt++;


	// 1
	//x00x0x
	else if (data_direction[0] == 0 && data[x - 1][y] < 9 && data[x + 1][y] == 10 && data[x + 2][y] < 9 && data[x + 3][y] == 10 && data[x + 4][y] < 9) //������
		cnt++;

	else if (data_direction[1] == 0 && data[x - 1][y - 1] < 9 && data[x + 1][y + 1] == 10 && data[x + 2][y + 2] < 9 && data[x + 3][y + 3] == 10 && data[x + 4][y + 4] < 9) //������ �Ʒ�
		cnt++;

	else if (data_direction[2] == 0 && data[x][y - 1] < 9 && data[x][y + 1] == 10 && data[x][y + 2] < 9 && data[x][y + 3] == 10 && data[x][y + 4] < 9) //�Ʒ�
		cnt++;

	else if (data_direction[3] == 0 && data[x + 1][y - 1] < 9 && data[x - 1][y + 1] == 10 && data[x - 2][y + 2] < 9 && data[x - 3][y + 3] == 10 && data[x - 4][y + 4] < 9) //���� �Ʒ�
		cnt++;

	else if (data_direction[0] == 0 && data[x + 1][y] < 9 && data[x - 1][y] == 10 && data[x - 2][y] < 9 && data[x - 3][y] == 10 && data[x - 4][y] < 9) //����
		cnt++;


	else if (data_direction[1] == 0 && data[x + 1][y + 1] < 9 && data[x - 1][y - 1] == 10 && data[x - 2][y - 2] < 9 && data[x - 3][y - 3] == 10 && data[x - 4][y - 4] < 9) //���� ��
		cnt++;

	else if (data_direction[2] == 0 && data[x][y + 1] < 9 && data[x][y - 1] == 10 && data[x][y - 2] < 9 && data[x][y - 3] == 10 && data[x][y - 4] < 9) //��
		cnt++;

	else if (data_direction[3] == 0 && data[x - 1][y + 1] < 9 && data[x + 1][y - 1] == 10 && data[x + 2][y - 2] < 9 && data[x + 3][y - 3] == 10 && data[x + 4][y - 4] < 9) //������ ��
		cnt++;

	if (cnt == 1) {
		return 1;
	}
	return 0;
}