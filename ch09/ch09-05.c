#include <stdio.h>
int main()
{
	char sentence[100] = "";
	char word[20];

	do {
		printf("�ܾ�? ");
		scanf("%s", word);
		strcat(sentence, word);
		strcat(sentence, " ");
	} while (strcmp(word, ".") != 0);

	printf("%s\n", sentence);

	return 0;
}