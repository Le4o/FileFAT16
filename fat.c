#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define CABECAS 2
#define TRILHAS 80
#define SETORES_POR_TRILHA 18
#define BYTES_POR_SETOR 512

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

int main(int argc, char *argv[]){
  
  int n, c;
  
  /*  Imprime todos os argumentos recebidos pela main
  short x;
  for (x=0; x < argc; x++){
    printf("argv[%d] - %s\n", i, argv[i]);
  }
  */
  
  int fd;
  fd = open(argv[1], O_RDWR | O_CREAT');
  //O_RDWR, flag para abrir arquivo em leitura e escrita

  c = 0;
  //Preenchendo o arquivo todo com 0
  short x;
  for (x=0; x < CABECAS * TRILHAS * SETORES_POR_TRILHA * BYTES_POR_SETOR; x++){
    n = write(fd, &c, sizeof(char));
  }
  
  BOOT.salto = {0xEB, 0x1C, 0x90};
  BOOT.nome_oem = "FAT12    ";
  BOOT.bytes_por_setor = {0x00, 0x02};
  BOOT.setores_por_cluster = {0x01};
  BOOT.setores_reservados = {0x01, 0x00};
  BOOT.copias_da_fat = {0x02};
  BOOT.entradas_diretorio_raiz = {0xE0, 0x00};
  BOOT.numero_de_setores = {0x40, 0x08};
  BOOT.descritor_de_midia = {0xF0};
  BOOT.setores_por_copia_da_fat = {0x09, 0x00};
  BOOT.setores_por_trilha = {0x12, 0x00};
  BOOT.numero_de_cabecas = {0x02, 0x00};
  BOOT.setores_ocultos = {0x00, 0x00};
  BOOT.codigo_de_boot = {0xEB, 0xFE, 0x90};
  BOOT.assinatura_de_boot = {0x55, 0xAA}; 
            
  n = write(fd, &BOOT, sizeof(BOOT));
  fd = close(fd);
  
  return 0;
}
