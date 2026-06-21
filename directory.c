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
    dir->files = NULL;

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
    Directory *dir = current->firstChild;

    while(dir != NULL)
    {
        printf("[DIR] %s\n", dir->name);
        dir = dir->nextSibling;
    }

    File *file = current->files;

    while(file != NULL)
    {
        printf("[FILE] %s\n", file->name);
        file = file->next;
    }
}

Directory *cd(Directory *current, char *name)
{
    if(strcmp(name, "..") == 0)
    {
        if(current->parent != NULL)
            return current->parent;

        return current;
    }

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

void pwd(Directory *current)
{
    if (current == NULL)
        return;

    if (current->parent == NULL)
    {
        printf("/\n");
        return;
    }

    char caminho[500] = "";
    char temp[500];

    Directory *dir = current;

    while (dir != NULL && dir->parent != NULL)
    {
        strcpy(temp, "/");
        strcat(temp, dir->name);
        strcat(temp, caminho);
        strcpy(caminho, temp);

        dir = dir->parent;
    }

    printf("%s\n", caminho);
}

void freeDirectory(Directory *dir)
{
    if (dir == NULL)
        return;

    Directory *child = dir->firstChild;

    while (child != NULL)
    {
        Directory *next = child->nextSibling;
        freeDirectory(child);
        child = next;
    }

    free(dir);
}

void rm(Directory *current, char *name)
{
    if (current == NULL || current->firstChild == NULL)
    {
        printf("Diretorio '%s' nao encontrado.\n", name);
        return;
    }

    Directory *temp = current->firstChild;
    Directory *anterior = NULL;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            if (anterior == NULL)
            {
                current->firstChild = temp->nextSibling;
            }
            else
            {
                anterior->nextSibling = temp->nextSibling;
            }

            freeDirectory(temp);

            printf("Diretorio '%s' removido.\n", name);
            return;
        }

        anterior = temp;
        temp = temp->nextSibling;
    }

    printf("Diretorio '%s' nao encontrado.\n", name);
}

void touch(Directory *current, char *filename)
{
    File *newFile = malloc(sizeof(File));

    if(newFile == NULL)
        return;

    strcpy(newFile->name, filename);
    newFile->next = NULL;

    if(current->files == NULL)
    {
        current->files = newFile;
    }
    else
    {
        File *temp = current->files;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newFile;
    }
}