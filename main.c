#include <stdio.h>
#include "directory.h"

int main()
{
    Directory *root = createDirectory("/");

    mkdirDirectory(root, "documentos");
    mkdirDirectory(root, "fotos");
    mkdirDirectory(root, "downloads");

    printf("Conteudo da raiz:\n\n");

    ls(root);

    return 0;
}