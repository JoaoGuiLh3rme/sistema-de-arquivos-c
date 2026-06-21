#include <stdio.h>
#include "directory.h"

int main()
{
    Directory *root = createDirectory("/");

    // Cria diretórios na raiz
    mkdirDirectory(root, "documentos");
    mkdirDirectory(root, "fotos");
    mkdirDirectory(root, "downloads");

    printf("=== Conteudo inicial da raiz ===\n");
    ls(root);

    printf("\n");

    // Remove fotos
    rm(root, "fotos");

    printf("\n=== Conteudo apos remover 'fotos' ===\n");
    ls(root);

    printf("\n");

    // Tenta remover um diretório inexistente
    rm(root, "musicas");

    printf("\n=== Conteudo final ===\n");
    ls(root);

    getchar();
    return 0;
}