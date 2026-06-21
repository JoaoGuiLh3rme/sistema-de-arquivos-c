#include <stdio.h>
#include "directory.h"


int main()
{
    Directory *root = createDirectory("/");

    mkdirDirectory(root, "documentos");
    mkdirDirectory(root, "fotos");

    touch(root, "README.md");
    touch(root, "main.c");
    touch(root, "relatorio.pdf");

    ls(root);

    return 0;
}