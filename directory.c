#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "directory.h"

Directory *createDirectory(char *name)
{
    Directory *dir = malloc(sizeof(Directory));

    strcpy(dir->name, name);

    dir->parent = NULL;
    dir->firstChild = NULL;
    dir->nextSibling = NULL;

    return dir;
}

void mkdirDirectory(Directory *current, char *name)
{
    Directory *newDir = createDirectory(name);

    if(newDir == NULL)
        return;

    newDir->parent = current;

    if(current->firstChild == NULL)
    {
        current->firstChild = newDir;
    }
    else
    {
        Directory *temp = current->firstChild;

        while(temp->nextSibling != NULL)
        {
            temp = temp->nextSibling;
        }

        temp->nextSibling = newDir;
    }
}

void ls(Directory *current)
{
    Directory *temp = current->firstChild;

    while(temp != NULL)
    {
        printf("%s\n", temp->name);
        temp = temp->nextSibling;
    }
}

Directory *cd(Directory *current, char *name)
{
    // voltar para o diretório pai
    if(strcmp(name, "..") == 0)
    {
        if(current->parent != NULL)
            return current->parent;

        return current;
    }

    // procurar entre os filhos
    Directory *temp = current->firstChild;

    while(temp != NULL)
    {
        if(strcmp(temp->name, name) == 0)
        {
            return temp;
        }

        temp = temp->nextSibling;
    }

    printf("Diretorio '%s' nao encontrado.\n", name);

    return current;
}