#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char * argv[])
{
    void showHelp(void);
    void fileMissingError(void);
    void optionInvalidError(char const *);
    int isFileExist(char const * );
    void encryptFile(const char *);
    void decryptFile(const char *);
    int i, rCode=0;
    switch(argc){
        case 1:
            showHelp();
            return 0;
        case 2:
            if(
                !strcmp(argv[1], "help") || 
                !strcmp(argv[1], "h") ||
                !strcmp(argv[1], "--help") ||
                !strcmp(argv[1], "-h") ||
                !strcmp(argv[1], "-help")
            ){
                showHelp();
                return 0;
            }
            else if(
                !strcmp(argv[1], "encrypt") ||
                !strcmp(argv[1], "--encrypt") ||
                !strcmp(argv[1], "-encrypt") ||
                !strcmp(argv[1], "-e") ||
                !strcmp(argv[1], "e") ||
                !strcmp(argv[1], "dncrypt") ||
                !strcmp(argv[1], "-decrypt") ||
                !strcmp(argv[1], "--dncrypt") ||
                !strcmp(argv[1], "-d") ||
                !strcmp(argv[1], "d") 
            ){
                fileMissingError();
                return 1;
            }
            else{
                optionInvalidError(argv[1]);
                return 1;
            }
    }
    if(
        !strcmp(argv[1], "encrypt") ||
        !strcmp(argv[1], "-encrypt") ||
        !strcmp(argv[1], "--encrypt") ||
        !strcmp(argv[1], "-e") ||
        !strcmp(argv[1], "e")
    ){
        for(i=2; i<argc; i++)
        {
            if(isFileExist(argv[i]))
            {
                encryptFile(argv[i]);
                printf("encrypt '%s' ok!\n\n", argv[i]);
                rCode = 0;
            }
            else 
            {
                printf("No such file, encrypt '%s' fail!\n", argv[i]);
                rCode = 1;
            }
        }
        return rCode;
    }

    if(
        !strcmp(argv[1], "dncrypt") ||
        !strcmp(argv[1], "-dncrypt") ||
        !strcmp(argv[1], "--dncrypt") ||
        !strcmp(argv[1], "-d") ||
        !strcmp(argv[1], "d")
    ){
        for(i=2; i<argc; i++)
        {
            if(isFileExist(argv[2]))
            {
                decryptFile(argv[2]);
                printf("\n\n-----------------------------\ndecrypt '%s' ok!\n\n", argv[2]);
                rCode = 0;
            }
            else   
            {
                printf("'No such file, decrypt '%s' fail!\n", argv[2]);
                rCode = 1;
            }
        }
        return rCode;
    }
    
    return 0;
}

void showHelp(void)
{
    fputs(
    "\
Usage: ash [OPTION]... [FILE]...\n\
help\tshow help, same as '--help' or '-h' or 'h'\n\
encrypt\tencrypt ascii file, same as '--encrypt' or 'e' or '-e'\n\
decrypt\tdecrypt ascii file, same as '--decrypt' or 'd' or '-d'\n\
", stdout);
}

void fileMissingError(void)
{
    fputs("\
Give at least one file\n\
Try 'ash --help' for more information.\n\
", stderr);
}

void optionInvalidError(char const *  fp)
{
    while(*fp=='-') fp++;
    fprintf(stderr, "\
ash: invalid option -- '%s'\n\
Try 'ash --help' for more information.\n\
", fp);
}

int isFileExist(char const * pFilename)
{
    if(!access(pFilename, F_OK))
        return 1;
    else
        return 0;
}

void encryptFile(const char * pFilename)
{
    FILE * src, * des;
    int fileNameLen;
    char ch, index;
    char * temp;
    char * desName;
    src = fopen(pFilename, "rb");
    fileNameLen = strlen(pFilename);
    desName = (char *)calloc(fileNameLen+5, sizeof(char));
    memcpy(desName, pFilename, fileNameLen);
    strcpy(&desName[fileNameLen], ".pwz");
    des = fopen(desName, "wb");
    free(desName);

    temp = (char *)malloc(sizeof(char)*2);
    while (fread(&ch, 1, 1, src))
    {
        index = ch*'p'-'w';
        ch = ch-'z'+'p'+'w';
        temp[0] = ch;
        temp[1] = index;
        fwrite(temp, 2, 1, des);
    }
    free(temp);
    fclose(src);
    fclose(des);
}

void decryptFile(const char * pFilename)
{
    FILE * src;
    int i;
    char ch;
    src = fopen(pFilename, "rb");
    for(i=1; ; i++)
    {
        if(fread(&ch, 1, 1, src))
        {
            if(i%2==1)
            {
                ch = ch-'w'-'p'+'z';
                fputc(ch, stdout);
            }
        }
        else    
            break;
    }
    fclose(src);
}