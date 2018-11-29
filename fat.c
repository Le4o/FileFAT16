#include<stdio.h>
#include<stdlib.h>

struct{
  unsigned char salto[3];
  unsigned char nome_oem[8];
  unsigned char bytes_por_setor[2];
  unsigned char setores_por_cluster[1];
  unsigned char setores_reservados[2];
  unsigned char copias_da_fat[1];
  unsigned char entradas_diretorio_raiz[2];
  unsigned char numero_de_setores[2];
  unsigned char descritor_de_midia[1];
  unsigned char setores_por_copia_da_fat[2];
  unsigned char setores_por_trilha[2];
  unsigned char numero_de_cabecas[2];
  unsigned char setores_ocultos[2];
  unsigned char codigo_de_boot[400];
  unsigned char assinatura_de_boot[2]; 
  
} BOOT;

int main(void){

  return 0;
}
