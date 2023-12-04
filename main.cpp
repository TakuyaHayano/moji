#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<process.h>
int main(void)
{
	//ファイルを開く
	const char* fileName = "data.txt";
	FILE* fp = fopen(fileName, "rb");
	assert(fp);

	//ファイルサイズを取得
	fseek(fp, 0, SEEK_END);
	int fileSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	//ファイルからメモリへ読み込む
	char* fig = (char*)malloc(fileSize);
	fread(fig, sizeof(char), fileSize, fp);
	printf("%d\n", fileSize);

	fclose(fp);

	//行数列数を数える
	int row = 0;    //行
	int col = 0;    //列
	int cnt = 0;
	for (int i = 0; i < fileSize; i++) {
		cnt++;
		if (fig[i] == '\n') {
			if (row == 0) {
				col = cnt;
			}
			else if (col != cnt) {
				puts("データの列数がそろっていません。");
			}
			row++;
			cnt = 0;
		}
	}
	if (fileSize % col != 0) {
		puts("最後の行を改行していません。");
	}
	printf("row:%d\n", row);
	printf("col:%d\n", col);

	//表示する
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int idx = i * col + j;
			if (fig[idx] == 1) {
				printf("＊");
			}
			else if (fig[idx] == 0) {
				printf("　");
			}
		}
	}


	free(fig);

	system("pause > 0");
	return 0;
}