#ifndef DIRECTORY_H
#define DIRECTORY_H

typedef struct File {
    char name[50];
    struct File *next;
} File;

typedef struct Directory {
    char name[50];

    struct Directory *parent;
    struct Directory *firstChild;
    struct Directory *nextSibling;

    File *files;

} Directory;


Directory *createDirectory(char *name);

Directory *cd(Directory *current, char *name);

void mkdirDirectory(Directory *current, char *name);

void ls(Directory *current);

void pwd(Directory *current);

void rm(Directory *current, char *name);
void freeDirectory(Directory *dir);

void touch(Directory *current, char *filename);

#endif