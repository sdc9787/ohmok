#pragma once
#include "main.h"

void move_arrow_key(char chr, int* x, int* y, int x_b, int y_b);//����Ű �Է� �ν�
void matrix_draw(char matrix_draw[SIZE + 1][SIZE + 1]);//�ٵ��� ���
void matrix_save(char matrix_draw[SIZE + 1][SIZE + 1]);
int draw_stone_error(int matrix_data[SIZE + 2][SIZE + 2], int x, int y);//�ߺ��� Ȯ��
void stone_Pronunciation(int matrix_data[SIZE + 2][SIZE + 2], int x, int y, int other);//����ġ ���
void display_stone(int matrix[SIZE + 2][SIZE + 2]);
int victroy(int matrix_data[SIZE + 2][SIZE + 2]);//�¸�����
void set_stone(char matrix[SIZE + 1][SIZE + 1], int x_s, int y_s, int matrix_data[SIZE + 2][SIZE + 2]);//�ٵϵ� ���


void multi_mode();//��Ƽ���
void single_mode(player* p1);
void single_mode_Practice();//�̱۸��
void single_mode_Normal();//�̱۸��
void single_mode_Hard();//�̱۸��


void AI(int matrix_data[SIZE + 2][SIZE + 2]);
int white4(int data[SIZE + 2][SIZE + 2], int x, int y);//��4
int black4(int data[SIZE + 2][SIZE + 2], int x, int y);//��4
int white3(int data[SIZE + 2][SIZE + 2], int x, int y);//��3
int black3(int data[SIZE + 2][SIZE + 2], int x, int y);//��3

int black2_Defance(int data[SIZE + 2][SIZE + 2], int x, int y);//��2���
int black3_Defance(int data[SIZE + 2][SIZE + 2], int x, int y);//��3���

int white2(int data[SIZE + 2][SIZE + 2], int x, int y);//��2
int	blocked_white3(int data[SIZE + 2][SIZE + 2], int x, int y);//������3

int third_stone(int data[SIZE + 2][SIZE + 2], int x, int y, int other);//33�ݼ�1
int third_stone_2(int data[SIZE + 2][SIZE + 2], int x, int y, int data_direction[4]);//33�ݼ�2