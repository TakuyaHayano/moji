#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<process.h>
int main(void)
{
	//�t�@�C�����J��
	const char* fileName = "data.txt";
	FILE* fp = fopen(fileName, "rb");
	assert(fp);

	//�t�@�C���T�C�Y���擾
	fseek(fp, 0, SEEK_END);
	int fileSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	//�t�@�C�����烁�����֓ǂݍ���
	char* fig = (char*)malloc(fileSize);
	fread(fig, sizeof(char), fileSize, fp);
	printf("%d\n", fileSize);

	fclose(fp);

	//�s���񐔂𐔂���
	int row = 0;    //�s
	int col = 0;    //��
	int cnt = 0;
	for (int i = 0; i < fileSize; i++) {
		cnt++;
		if (fig[i] == '\n') {
			if (row == 0) {
				col = cnt;
			}
			else if (col != cnt) {
				puts("�f�[�^�̗񐔂�������Ă��܂���B");
			}
			row++;
			cnt = 0;
		}
	}
	if (fileSize % col != 0) {
		puts("�Ō�̍s�����s���Ă��܂���B");
	}
	printf("row:%d\n", row);
	printf("col:%d\n", col);

	//�\������
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int idx = i * col + j;
			if (fig[idx] == 1) {
				printf("��");
			}
			else if (fig[idx] == 0) {
				printf("�@");
			}
		}
	}


	free(fig);

	system("pause > 0");
	return 0;
}