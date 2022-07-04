#pragma once
#include "main.h"

void move_arrow_key(char chr, int* x, int* y, int x_b, int y_b);//방향키 입력 인식
void matrix_draw(char matrix_draw[SIZE + 1][SIZE + 1]);//바둑판 출력
void matrix_save(char matrix_draw[SIZE + 1][SIZE + 1]);
int draw_stone_error(int matrix_data[SIZE + 2][SIZE + 2], int x, int y);//중복돌 확인
void stone_Pronunciation(int matrix_data[SIZE + 2][SIZE + 2], int x, int y, int other);//가중치 계산
void display_stone(int matrix[SIZE + 2][SIZE + 2]);
int victroy(int matrix_data[SIZE + 2][SIZE + 2]);//승리조건
void set_stone(char matrix[SIZE + 1][SIZE + 1], int x_s, int y_s, int matrix_data[SIZE + 2][SIZE + 2]);//바둑돌 출력


void multi_mode();//멀티모드
void single_mode(player* p1);
void single_mode_Practice();//싱글모드
void single_mode_Normal();//싱글모드
void single_mode_Hard();//싱글모드


void AI(int matrix_data[SIZE + 2][SIZE + 2]);
int white4(int data[SIZE + 2][SIZE + 2], int x, int y);//백4
int black4(int data[SIZE + 2][SIZE + 2], int x, int y);//흑4
int white3(int data[SIZE + 2][SIZE + 2], int x, int y);//백3
int black3(int data[SIZE + 2][SIZE + 2], int x, int y);//흑3

int black2_Defance(int data[SIZE + 2][SIZE + 2], int x, int y);//흑2방어
int black3_Defance(int data[SIZE + 2][SIZE + 2], int x, int y);//흑3방어

int white2(int data[SIZE + 2][SIZE + 2], int x, int y);//백2
int	blocked_white3(int data[SIZE + 2][SIZE + 2], int x, int y);//막힌백3

int third_stone(int data[SIZE + 2][SIZE + 2], int x, int y, int other);//33금수1
int third_stone_2(int data[SIZE + 2][SIZE + 2], int x, int y, int data_direction[4]);//33금수2