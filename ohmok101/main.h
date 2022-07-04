#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <mmsystem.h>//ȿ����
#include<Digitalv.h>
#pragma comment(lib,"winmm.lib")//ȿ����

MCI_OPEN_PARMS openBgm;		//bgm ����ü
MCI_PLAY_PARMS playBgm;

int dwID;		//���� ���� �ҷ����� ��

#define SIZE 19

typedef struct rank {
    char name[20];
    float match_count;
    float wins;
    float lose;
    float draw;
    float winrate;

}player;

void rankin(int level, player p1);
void rankout();

//���θ޴�UI ���
void print_game1();
void print_game2();
void print_main1();
void print_main2();
void print_main3();
void print_main4();
void print_main5();

//���̵� ���� ���� �Լ�
void AI_Practice();
void AI_Normal();
void AI_Hard();

//���̵� ���ÿ� ���� ��
void Ch_single();
void print_single1();
void print_single2();
void print_single3();
void rankout();
void Game_start();
void How_To_Play();
void Options();
void get_usrname(char* usrname, player* p1);//�����̸� �Է�
void print_victory(int a, int b, char str[]);//�¸����


void CursorView();
void textcolor(int color_number);
void gotoxy(int x, int y);
void back_menu();