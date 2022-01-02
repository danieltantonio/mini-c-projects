#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char fileName[50];
	char fileContent[250];
	char opt;

	FILE *txtFile;
	char *newLine;

	printf("File to open/make: ");
	fgets(fileName, sizeof fileName, stdin);

	newLine = strrchr(fileName, '\n');

	if(newLine != NULL) {
		// If new line exists at the end of the file name remove it
		*newLine = '\0';
	}
	
	txtFile = fopen(fileName, "r");

	if(!txtFile) {
		printf("No file exists, creating new file...");
		txtFile = fopen(fileName, "w");
		printf("File \"%s\" has been created. Will now write to this file.\n", fileName);
	} else {
		printf("\"%s\" already exists.\nAre you sure you want to overwrite this file? y(yes)\\n(no): ", fileName);
		opt = getchar();

		switch(opt) {
			case 'y':
				printf("You said yes\n");
				txtFile = fopen(fileName, "w");
				break;
			case 'Y':
				printf("You said Yes\n");
				txtFile = fopen(fileName, "w");
				break;
			case 'n':
				printf("You said no\n");
				fclose(txtFile);
				exit(0);
			case 'N':
				printf("You said No\n");
				fclose(txtFile);
				exit(0);
			default:
				printf("You didn't say yes or no, will now exit. Goodbye...\n");
				fclose(txtFile);
				exit(1);
		}
	}

	printf("Write into file:\n");
	fgets(fileContent, sizeof fileContent, stdin);
	fputs(fileContent, txtFile);
	printf("Written to file %s, will now exit. Goodbye...\n", fileName);

	fclose(txtFile);

	return 0;
}
