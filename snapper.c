#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

#define CAPTURE_CMD                "imagesnap"
#define RESAMPLE_CMD               "sips --resampleWidth 800"
#define CAPTURE_NUMBER_FILE        "/usr/local/bin/snapperd.last"

#define CAPTURE_DIRECTORY          "/usr/local/snapper/"

void capture(const char *filename)
{
	size_t buffer_length = strlen(CAPTURE_CMD) + strlen(filename) + 1;
	char *buffer = malloc(buffer_length + 1);

	sprintf(buffer, "%s %s", CAPTURE_CMD, filename);

	system(buffer);

	free(buffer);
	
	buffer_length = strlen(RESAMPLE_CMD) + strlen(filename) + 1;
	buffer = malloc(buffer_length + 1);

	sprintf(buffer, "%s %s", RESAMPLE_CMD, filename);

	system(buffer);

	free(buffer);
}

int main(int argc, char const *argv[])
{
	mkdir(CAPTURE_DIRECTORY, 0777);
	// reading num from file
	FILE *f = fopen(CAPTURE_NUMBER_FILE, "r+");
	printf("f is %p\n", f);
	int num = 0;
	if (f)
	{
		rewind(f);
		fscanf(f, "%d", &num);
	}
	else
	{
		f = fopen(CAPTURE_NUMBER_FILE, "w+");
		if (!f)
		{
			printf("Can\'t open file %s!\n", CAPTURE_NUMBER_FILE);
			exit(1);
		}
	}
	printf("num is %d\n", num);
	num++;
	rewind(f);
	// writing new num to file
	fprintf(f, "%d \n", num);
	fclose(f);

	char file[500];
	sprintf(file, "%ssnap_%010d.png", CAPTURE_DIRECTORY, num);
	printf("file: %s\n", file);

	capture(file);
	return 0;
}