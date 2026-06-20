#include <stdio.h> 
#include "directory.h"

int main()
{
    Directory *root = createDirectory("/");

    mkdirDirectory(root, "documentos");
    mkdirDirectory(root, "fotos");

    Directory *current = root;

    printf("Conteudo da raiz:\n");
    ls(root);

    current = cd(current, "documentos");

    printf("\nDiretorio atual: %s\n", current->name);

    current = cd(current, "..");

    printf("Diretorio atual: %s\n", current->name);

    getchar();

    return 0;
}