#include <iostream>
#include <string>
//+ The headers for the C++ Standard Library are the same as those for the C standard library
// but have no .h at the end and have a lower case "c" at the beginning
#include <cstring>
#include <cerrno>
#include <cstdlib>
#include <cstdio>
#include <cerrno>

// Standard Library namespace
using namespace std;

// read buffer size
const int maxString = 1024;

const size_t slen = 125;
struct s1 {
	uint8_t num;
	uint8_t len;
	char s[slen + 1];
};

int main(int argc, char **argv)
{
	// ----- FILE I/O -----
	puts("\n\nFILE I/O\n");
	const char * fileName = "test.file";
	const char * str = "This is a literal C-string.\n";

	// create/write the file
	// open specified file in a write ("w") mode
	// See more fopen() modes
	FILE * fileWrite = fopen(fileName, "w");
	for (int i = 0; i < 5; i++) {
		// buffer is not yet flushed
		fputs(str, fileWrite);
	}

	// flush the buffer and close
	fclose(fileWrite);
	printf("done.\n");

	// Read the file
	printf("reading file\n");
	char buffer[maxString];
	FILE * fileRead = fopen(fileName, "r");
	while (fgets(buffer, maxString, fileRead)) {
		fputs(buffer, stdout);
	}

	fclose(fileRead);

	printf("done.\n");

	// writebinary (serialize)
	printf("writing binary file\n");
	FILE * fileWriteBinary = fopen(fileName, "wb");

	struct s1 buf1;
	for (int i = 0; i < 5; i++) {
		buf1.num = i;
		buf1.len = strlen(str);
		if (buf1.len > slen)buf1.len = slen;
		// write first 'slen' characters from 'str' into 'buf1.s'
		strncpy(buf1.s, str, slen);
		if (buf1.len == slen)buf1.s[buf1.len] = 0; //make sure it's terminated
		fwrite(&buf1, sizeof(struct s1), 1, fileWriteBinary);
	}
	fclose(fileWriteBinary);

	// readbinary
	printf("reading binary file\n");
	FILE * fileReadBinary = fopen(fileName, "rb");
	struct s1 buf2;
	size_t rc;
	// deserialize
	while ((rc = fread(&buf2, sizeof(struct s1), 1, fileReadBinary))) {
		printf("a: %d, b: %d, s: %s\n", buf2.num, buf2.len, buf2.s);
	}
	fclose(fileReadBinary);

	remove(fileName); // delete the file


	// ----- FILE MANAGEMENT -----
	puts("\n\nFILE MANAGEMENT\n");

	// 1 - create new file
	const static char * fn1 = "file1";
	FILE * fh = fopen(fn1, "w");
	fclose(fh);
	puts("Done.\n");

	// 2 - rename the file
	const static char * fn2 = "file2";
	int code = rename(fn1, fn2);
	// returns 0 on success
	if (code == 0) {
		puts("File renamed successfully!");
	}
	else {
		puts("Error occured!");
	}

	// 3 - delete the file
	code = remove(fn2);
	if (code == 0) {
		puts("File deleted successfully!");
	}
	else {
		puts("Error occured!");
	}


	// ----- UNFORMATTED CHARACTER IO -----
	puts("\n\nUNFORMATTED CHARACTER I/O\n");

	// write to console (buffer) and puts a new line, adds new line and flushes the buffer
	puts("Hello, World!");
	// write to a specified file handle (name), which is console handle currently
	// doesn't add a new line but also flushes the buffer
	fputs("Hello, World!", stdout);

	// create the buffer
	const static int buffSize = 256;
	char buf[buffSize];
	fputs("Prompt: ", stdout);
	// flush the buffer causing the characters to be read
	fflush(stdout);
	fgets(buf, buffSize, stdout);
	fputs(buf, stdout);

	// ----- FORMATTED CHARACTER IO -----
	puts("\n\nFORMATTED CHARACTER I/O\n");

	int i = 47;
	long int li = 1234567890;
	const char * s = "This is a string.";
	printf("i is %d, li is %ld, s is \"%s\"\n", i, li, s);
	// printf is a version of fprintf, which writes to stdout (console output)
	fprintf(stdout, "i is %d, li is %ld, s is \"%s\"\n", i, li, s);
	FILE * fileHandle = fopen("file.txt", "w");
	fprintf(fileHandle, "i is %d, li is %ld, s is \"%s\"\n", i, li, s);
	fclose(fileHandle);

	const size_t maxlen = 128;
	char buf3[maxlen];
	snprintf(buf3, maxlen, "i is %d, li is %ld, s is \"%s\"\n", i, li, s);
	puts(buf3);


	// ----- STRING FUNCTIONS -----
	puts("\n\nSTRING FUNCTIONS\n");

	// C-strings are array of characters, terminated with a value of 0
	const char cString1[] = { 'S','t','r','i','n','g','0' };
	// exactly the same as
	const char cString2[] = "String"; // copy constructor
	puts(cString1);
	puts(cString2);
	const char * cString3 = "String"; // assignment
	puts(cString3);


	// ----- HANDLING SYSTEMS ERRORS -----
	puts("\n\nHANDLING SYSTEMS ERRORS\n");

	printf("errno is %d\n", errno);
	// will throw error, thus increasing errno
	remove("foo.bar");
	printf("errno is %d\n", errno);




	getchar();
	return 0;
}