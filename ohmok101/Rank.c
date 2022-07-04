#include "game_engine.h"
#include "main.h"
#include "main_UI.h"
#include "Rank.h"


void rankin(int level, player p1) {
	FILE* fp = NULL;
	FILE* temp_fp = NULL;
	player p2 = { "GM",0,0,0,0,0 };

	char buffer[100] = { 0 };
	if (level == 0) {
		if ((fp = fopen("practice.txt", "r")) == NULL) {
			printf("practice.txt 파일을 열 수 없습니다.");
			return 1;
		}

		if ((temp_fp = fopen("temp.txt", "w+")) == NULL) {
			exit(1);
		}
	}
	else if (level == 1) {
		if ((fp = fopen("normal.txt", "r")) == NULL) {
			printf("normal.txt 파일을 열 수 없습니다.");
			return 1;
		}

		if ((temp_fp = fopen("temp.txt", "w+")) == NULL) {
			exit(1);
		}
	}
	else if (level == 2) {
		if ((fp = fopen("hard.txt", "r")) == NULL) {
			printf("hard.txt 파일을 열 수 없습니다.");
			return 1;
		}

		if ((temp_fp = fopen("temp.txt", "w+t")) == NULL) {
			exit(1);
		}
	}


	fscanf(fp, "%s %f %f %f %f %f", &p2.name, &p2.match_count, &p2.wins, &p2.lose, &p2.draw, &p2.winrate);
	fgetc(fp);
	int namecount = 0;
	while (!feof(fp)) {

		if (strcmp(p2.name, p1.name) == 0) {
			namecount++;
			float sum_match_count = (p1.match_count) + (p2.match_count);
			float sum_wins = p1.wins + p2.wins;
			float sum_lose = p1.lose + p2.lose;
			float sum_draws = p1.draw + p2.draw;
			float new_winrate = sum_wins / sum_match_count * 100;
			fprintf(temp_fp, "%s %f %f %f %f %f\n", p1.name, sum_match_count, sum_wins, sum_lose, sum_draws, new_winrate, 100);
		}
		else
			fprintf(temp_fp, "%s %f %f %f %f %f\n", p2.name, p2.match_count, p2.wins, p2.lose, p2.draw, p2.winrate, 100);
		fscanf(fp, "%s %f %f %f %f %f", &p2.name, &p2.match_count, &p2.wins, &p2.lose, &p2.draw, &p2.winrate);
		fgetc(fp);
	}
	if (namecount == 0) {
		p1.winrate = p1.wins / p1.match_count * 100;
		fprintf(temp_fp, "%s %f %f %f %f %f\n", p1.name, p1.match_count, p1.wins, p1.lose, p1.draw, p1.winrate);
	}
	namecount = 0;

	fclose(fp);
	fclose(temp_fp);

	if (level == 0) {
		if ((fp = fopen("practice.txt", "w+t")) == NULL) exit(1);
	}
	else if (level == 1) {
		if ((fp = fopen("normal.txt", "w+t")) == NULL) exit(1);
	}
	else if (level == 2) {
		if ((fp = fopen("hard.txt", "w+t")) == NULL) exit(1);
	}

	if ((temp_fp = fopen("temp.txt", "r+t")) == NULL) {
		printf("hard.txt 파일을 열 수 없습니다.");
		return 1;
	}
	while (fgets(buffer, 100, temp_fp) != NULL)
		fputs(buffer, fp);

	fclose(fp);
	fclose(temp_fp);
	remove("temp.txt");
}
void rankout() {
	char sound_check1 = sound_check();
	FILE* fp = { 0 };

	int level = 0;
	int key = NULL;
	goto ONE;
	print_mode1();

ONE:
	gotoxy(1, 4);
	print_mode1();
	key = _getch();
	if (key == 32) {
		level = 0;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) goto TWO;
		else goto ONE;
	}
	if (key == 27) {
		system("cls");
		firi();
	}
TWO:
	gotoxy(1, 4);
	print_mode2();
	if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC);
	key = _getch();
	if (key == 32) {
		level = 1;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 80) { if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto THREE; }
		else if (key == 72) { if (sound_check1 == '1') PlaySound(TEXT("Tick.wav"), NULL, SND_ASYNC); goto ONE; }
		else goto ONE;
	}
	if (key == 27) {
		system("cls");
		firi();
	}
THREE:
	gotoxy(1, 4);
	print_mode3();
	key = _getch();
	if (key == 32) {
		level = 2;
		goto EXIT;
	}
	if (key == 224) {
		key = _getch();
		if (key == 72) goto TWO;
		else goto THREE;
	}
	if (key == 27) {
		system("cls");
		firi();
	}

EXIT:
	if (level == 0) {
		if ((fp = fopen("practice.txt", "r")) == NULL) {
			printf("practice.txt 파일을 열 수 없습니다.");
			return 1;
		}
	}
	else if (level == 1) {
		if ((fp = fopen("normal.txt", "r")) == NULL) {
			printf("normal.txt 파일을 열 수 없습니다.");
			return 1;
		}
	}
	else if (level == 2) {
		if ((fp = fopen("hard.txt", "r")) == NULL) {
			printf("hard.txt 파일을 열 수 없습니다.");
			return 1;
		}
	}
	struct rank ranker[100] = { 0, };
	memset(&ranker, 0, sizeof(struct rank) * 100);
	struct rank temp;
	memset(&temp, 0, sizeof(struct rank));

	int i = 0;
	while (!feof(fp)) {
		fscanf(fp, "%s %f %f %f %f %f\n", ranker[i].name, &ranker[i].match_count, &ranker[i].wins,
			&ranker[i].lose, &ranker[i].draw, &ranker[i].winrate);
		i++;
	} //텍스트 파일에 있는 것들을 배열로 다 저장

	int j, k;
	for (j = 0; j < i; j++) {
		for (k = 0; k < (i - 1) - j; k++) {
			if (ranker[k].wins < ranker[k + 1].wins) {
				temp = ranker[k];
				ranker[k] = ranker[k + 1];
				ranker[k + 1] = temp;
			}
		}
	}

	fclose(fp);

RANK:
	system("cls");
	if (level == 0)
		printf("\n 게임 모드  :  연습 모드\n\n\n");
	else if (level == 1)
		printf("\n 게임 모드 : 노멀 모드\n\n\n");
	else if (level == 2)
		printf("\n 게임 모드  :  하드 모드\n\n\n");
	printf("      랭킹 |  이름  | 게임 수 | 승리 | 패배 | 무승부 | 승률 \n\n");
	for (int t = 0; t < 10; t++) {
		printf("       %2d     %-6s	%2d       %2d     %2d      %2d    %.1f %%\n",
			t + 1, ranker[t].name, (int)ranker[t].match_count, (int)ranker[t].wins, (int)ranker[t].lose, (int)ranker[t].draw, ranker[t].winrate);
	}

	key = _getch();
	if (key == 27) {
		rankout();
	}
	else goto RANK;
}
void print_mode1() {
	system("cls");
	printf("----------------------------------------------------------------\n");
	printf("      ■■■■■   ■■■■   ■■■     ■■ ■■    ■■\n");
	printf("      ■■   ■■ ■■  ■■  ■■■■   ■■ ■■   ■■ \n");
	printf("      ■■■■■  ■■■■■  ■■ ■■  ■■ ■■■■■\n");
	printf("      ■■   ■■ ■■  ■■  ■■  ■■ ■■ ■■   ■■\n");
	printf("      ■■   ■■ ■■  ■■  ■■   ■■■■ ■■    ■■\n");
	printf("----------------------------------------------------------------\n\n\n\n");
	printf("                      ▶ 연습 모드 랭크 ◀          \n\n");
	printf("                         노멀 모드 랭크                \n\n");
	printf("                         하드 모드 랭크             \n\n");
}
void print_mode2() {
	system("cls");
	printf("----------------------------------------------------------------\n");
	printf("      ■■■■■   ■■■■   ■■■     ■■ ■■    ■■\n");
	printf("      ■■   ■■ ■■  ■■  ■■■■   ■■ ■■   ■■ \n");
	printf("      ■■■■■  ■■■■■  ■■ ■■  ■■ ■■■■■\n");
	printf("      ■■   ■■ ■■  ■■  ■■  ■■ ■■ ■■   ■■\n");
	printf("      ■■   ■■ ■■  ■■  ■■   ■■■■ ■■    ■■\n");
	printf("----------------------------------------------------------------\n\n\n\n");

	printf("                         연습 모드 랭크           \n\n");
	printf("                      ▶ 노멀 모드 랭크 ◀               \n\n");
	printf("                         하드 모드 랭크             \n\n");
}
void print_mode3() {
	system("cls");
	printf("----------------------------------------------------------------\n");
	printf("      ■■■■■   ■■■■   ■■■     ■■ ■■    ■■\n");
	printf("      ■■   ■■ ■■  ■■  ■■■■   ■■ ■■   ■■ \n");
	printf("      ■■■■■  ■■■■■  ■■ ■■  ■■ ■■■■■\n");
	printf("      ■■   ■■ ■■  ■■  ■■  ■■ ■■ ■■   ■■\n");
	printf("      ■■   ■■ ■■  ■■  ■■   ■■■■ ■■    ■■\n");
	printf("----------------------------------------------------------------\n\n\n\n");

	printf("                         연습 모드 랭크           \n\n");
	printf("                         노멀 모드 랭크                \n\n");
	printf("                      ▶ 하드 모드 랭크 ◀            \n\n");
}
