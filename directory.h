#ifndef DIRECTORY_H
#define DIRECTORY_H

typedef struct Directory {
    char name[50];

    struct Directory *parent;
    struct Directory *firstChild;
    struct Directory *nextSibling;

} Directory;

Directory *createDirectory(char *name);

Directory *createDirectory(char *name);

void mkdirDirectory(Directory *current, char *name);
void ls(Directory *current);

#endif