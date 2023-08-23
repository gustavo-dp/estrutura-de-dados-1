#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 20

#define OI "NomeRG100M.txt"


typedef struct{
    char nome[TAM];
    int rg;
} No;
typedef struct no{
    char name[TAM];
    int rge;
    struct no *proximo;
} Noe;
void salvar_lista(Noe** lista);
void salvar_lista1(No *vet, int *cont);
//lista simples ------------------------------
void inserir_Novo_Inicio(No *vet, int *cont);
void inserir_Novo_Final(No *vet, int *cont);
void inserir_Novo_N(No *vet, int *cont);
void retirar_No_Inicio(No *vet, int *cont);
void retirar_No_Fim(No *vet, int *cont);
void retirar_No_N(No *vet, int *cont);
void procura_No(No *vet, int *cont);
void imprime_Lista_Sequencial(No *vet, int *cont);
//--------------------------------lista encadeada
void aloca_Lista_Encadeada(FILE *arquivo, Noe **lista, Noe **ultimo);
Noe* criar_no(char* nome, int rg);
void imprime_Lista(Noe **lista);
void inserir_Inicio_Encadeado(Noe **lista);
void inserir_Fim_Encadeado(Noe **ultimo);
void inserir_Qualquer_Posicao(Noe**lista);
void retira_Inicio_Encadeado(Noe **lista);
void retira_Fim_Encadeado(Noe **lista);
void retira_Qualquer_Encadeado(Noe **lista);
void procura_No_Encadeado(Noe **lista);
void salvar_Lista_Encadeada(Noe **lista);
int main(){

	int menu, tam = 13000000;



	   clock_t begin = clock();
       FILE *arquivo;
       arquivo = fopen(OI, "r");
       int cont=0,i;
       if (arquivo == NULL)
        {
           printf("erro");
           return 1;

        }

       char str[100];
       while(fgets(str,100,arquivo)!= NULL)
        {
          cont ++;

        }
       rewind(arquivo);
       No *vet;
       vet = (No*)malloc(tam*sizeof(No));
       cont=0;
       while (fgets(str, 100, arquivo) != NULL)
        {
       char *nome_temp = strtok(str, ",");
       int rg_temp = atoi(strtok(NULL, "\n"));
       strcpy(vet[cont].nome, nome_temp);
       vet[cont].rg = rg_temp;
       cont++;

        }


      int opcao;
      int op=0, op1=0;
      printf("gostaria de usar lista simples ou lista encadeada?");
      scanf(" %d", &opcao);
      if(opcao==1)
      {

          while(op1!=8){

      int op;
      printf("\ndigite 1 para inserir um no no comeco\n 2 para inserir no final\n 3 para inserir em qualquer posicao\n 4 para retirar um no do comeco\n 5 para retirar um no do final\n 6 para retirar de qualquer posicao\n 7 para procurar um no\ndigite 8 para sair do programa\n9 para imprimir a lista");
      scanf(" %d", &op1);

      switch(op1){
         case 1:
          inserir_Novo_Inicio(vet, &cont);
         break;
      case 2:
          inserir_Novo_Final(vet, &cont);
         break;
      case 3:
          inserir_Novo_N(vet, &cont);
         break;
      case 4:
          retirar_No_Inicio(vet, &cont);
          break;
      case 5:
          retirar_No_Fim(vet, &cont);
         break;
      case 6:
          retirar_No_N(vet, &cont);
         break;
      case 7:
          procura_No(vet,&cont);
          break;
      case 8:
          break;
      case 9:
          imprime_Lista_Sequencial(vet, &cont);
          break;
          }


      }
      }else if(opcao==2)
      {

          Noe* lista = NULL;
          Noe* ultimo= NULL;
          aloca_Lista_Encadeada(arquivo, &lista, &ultimo);
          //imprime_Lista(&lista);

          while(op!=8){

              printf("\nDigite 1: para inserir no inicio: \nDigite 2: para inserir no final:\nDigite 3: para inserir em qualquer:\nDigite 4: para retirar do inicio:\nDigite 5: para retirar do fim\nDigite 6: para retirar em qualquer posicao\nDigite 7: para procurar um no\nDigite 8: para sair do programa\nDigite 9: para imprimir a lista\nDigite 10: para salvar a lista");
              scanf(" %d", &op);

            switch(op){
              case 1:
                 inserir_Inicio_Encadeado(&lista);
                 break;
              case 2:
                 inserir_Fim_Encadeado(&ultimo);
                 break;
              case 3:
                 inserir_Qualquer_Posicao(&lista);
                 break;
              case 4:
                 retira_Inicio_Encadeado(&lista);
                 break;
              case 5:
                 retira_Fim_Encadeado(&lista);
                 break;
              case 6:
                 retira_Qualquer_Encadeado(&lista);
                 break;
              case 7:
                 procura_No_Encadeado(&lista);
                 break;
              case 8:
                 break;
              case 9:
                 imprime_Lista(&lista);
                 break;
              case 10:
                 salvar_Lista_Encadeada(&lista);
                 break;
            }


          }
      }
return 0;

}
void inserir_Novo_Inicio(No *vet, int *cont)
{
   double time_spent = 0.0;
   clock_t begin = clock();
   char nome_temp[TAM];
   int rg_temp, i, Cn=0, Mn=0;
   printf("digite o nome");
   scanf("%s", nome_temp);
   printf("digite o rg");
   scanf(" %d", &rg_temp);

   for(i=*cont;i>0;i--)
   {
       strcpy(vet[i].nome,vet[i-1].nome);
       vet[i].rg=vet[i-1].rg;
       Cn++;
       Mn++;
   }
       (*cont)++;
       i=0;
       strcpy(vet[i].nome,nome_temp);
       vet[i].rg = rg_temp;
       Mn++;
       printf("\nNumero de comparacoes: %d", Cn);
       printf("\nNumero de movimentacoes: %d", Mn);
       clock_t end = clock();
       time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
       printf("\nTempo de execucao:%f segundos\n", time_spent);
}
void inserir_Novo_Final(No *vet, int *cont)
{
    double time_spent = 0.0;
    clock_t begin = clock();

   char nome_temp[TAM];
   int rg_temp, i, Mn=0;
   printf("digite o nome");
   scanf("%s", nome_temp);
   printf("digite o rg");
   scanf(" %d", &rg_temp);
   strcpy(vet[*cont].nome,nome_temp);
   vet[*cont].rg = rg_temp;
   (*cont)++;
   Mn++;
   printf("Numero de comparacoes: 0");
   printf("Numero de Movimentacoes: %d", Mn);
   clock_t end = clock();
   time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
   printf("\nTempo de execucao:%f segundos\n", time_spent);
}
void inserir_Novo_N(No *vet, int *cont)
{
    double time_spent = 0.0;
    clock_t begin = clock();
   int Cn=0,Mn=0;
   char nome_temp[TAM];
   int rg_temp, i, posi;
   printf("digite o nome");
   scanf("%s", nome_temp);
   printf("digite o rg");
   scanf(" %d", &rg_temp);
   printf("digite a posição a ser inserida");
   scanf(" %d", &posi);

   for(i=*cont;i>=posi-1;i--)
    {
      strcpy(vet[i].nome,vet[i-1].nome);
      vet[i].rg=vet[i-1].rg;
      Cn++;
      Mn++;
    }
     (*cont)++;
      strcpy(vet[posi-1].nome,nome_temp);
      vet[posi-1].rg = rg_temp;
      Mn++;
      printf("Numero de comparacoes: %d", Cn);
      printf("Numero de Movimentacoes: %d", Mn);
      clock_t end = clock();
      time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
      printf("\nTempo de execucao:%f segundos\n", time_spent);
}
void retirar_No_Inicio(No *vet, int *cont)
{
      double time_spent = 0.0;
      clock_t begin = clock();
      int i, Cn=0,Mn=0;
      for(i=0;i<*cont;i++)
      {
          strcpy(vet[i].nome,vet[i+1].nome);
          vet[i].rg=vet[i+1].rg;
          Cn++;
          Mn++;
      }
      (*cont)--;
      printf("Numero de comparacoes: %d", Cn);
      printf("Numero de Movimentacoes: %d", Mn);
      clock_t end = clock();
      time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
      printf("\nTempo de execucao:%f segundos\n", time_spent);
}
void retirar_No_Fim(No *vet, int *cont)
{
          double time_spent = 0.0;
          clock_t begin = clock();
          int i,Mn=0;
          strcpy(vet[*cont-1].nome,vet[*cont].nome);
          vet[*cont-1].rg=vet[*cont].rg;
          (*cont)--;
          Mn++;
          printf("Numero de comparacoes: 0");
          printf("Numero de Movimentacoes: %d", Mn);
          clock_t end = clock();
          time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
          printf("\nTempo de execucao:%f segundos\n", time_spent);
}
void retirar_No_N(No *vet, int *cont)
{
    double time_spent = 0.0;
    clock_t begin = clock();
    int posi, i, Cn=0,Mn=0;
    printf(" digite a posicao a ser retirada");
    scanf(" %d", &posi);

    for(i=posi-1;i<*cont;i++)
    {
        strcpy(vet[i].nome,vet[i+1].nome);
        vet[i].rg=vet[i+1].rg;
        Cn++;
        Mn++;
    }
    (*cont)--;
    printf("Numero de comparacoes: %d", Cn);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    printf("\nTempo de execucao:%f segundos\n", time_spent);
}
void procura_No(No *vet, int *cont)
{
    double time_spent = 0.0;
    clock_t begin = clock();
    int rg, i, Cn=0,Mn=0;
    printf("Digite o RG: ");
    scanf("%d", &rg);
    for(i=0; i < *cont; i++)
    {
        if(rg == vet[i].rg)
        {
            printf("Nome: %s - RG: %d\n", vet[i].nome, vet[i].rg);
            printf("Posicao: %d\n", i);
            break;
            Cn++;
        }
        Cn++;
        Mn++;
    }
    (*cont)--;
    printf("Numero de comparacoes: %d", Cn);
    printf("Numero de Movimentacoes: %d", Mn);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    printf("\nTempo de execucao:%f segundos\n", time_spent);
}
void imprime_Lista_Sequencial(No *vet, int *cont)
{
for(int i = 0; i < *cont; i++)
        {
           printf("Nome: %s - RG: %d\n", vet[i].nome, vet[i].rg);
        }
}
//-------------------------------------------------
void aloca_Lista_Encadeada(FILE *arquivo, Noe **lista, Noe **ultimo){
            rewind(arquivo);
            char str[50];
            int cont = 0;


            while (fgets(str,50, arquivo) != NULL) {
            char* nome_temp = strtok(str, ",");
            int rg_temp = atoi(strtok(NULL, "\n"));
            Noe* novo = criar_no(nome_temp, rg_temp);
            if((*lista)==NULL)
             {
                 (*lista) = novo;
                 (*ultimo) = novo;
             }
            else
             {
                 (*ultimo)->proximo=novo;
                 (*ultimo) = novo;
             }
             cont++;
            }


}
Noe* criar_no(char* nome, int rg){
    Noe(* novo) = (Noe*)malloc(sizeof(Noe));
    if (novo == NULL) {
        printf("Erro ao alocar memoria\n");// testa a memoria alocada
        exit(1);
    }
    strcpy(novo->name, nome);              // atribui o nome para o no novo usando atrcpy
    novo->rge = rg;                        // atribui o rg para o campo rg do no novo
    novo->proximo = NULL;                  // faz isso para que garanta que ele sempre seja o ultimo no



}
void imprime_Lista(Noe **lista){
     double time_spent = 0.0;
     clock_t begin = clock();
     Noe (* aux) = (*lista);
     while(aux!=NULL)
     {
        printf("Nome : %s  Rg : %d\n", aux->name,aux->rge);
        aux= aux->proximo;

     }

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    printf("\nTempo de execucao:%f segundos\n", time_spent);
}
void inserir_Inicio_Encadeado(Noe (**lista)){
       double time_spent = 0.0;
       clock_t begin = clock();
       char nome_temp[TAM];
       int rg_temp;
       int Cn=0,Mn=0;
       Noe *novo;
       printf("Digite o nome: ");
       getchar();
       fgets(nome_temp, TAM, stdin);
       nome_temp[strcspn(nome_temp, "\n")] = '\0';

       printf("Digite o RG: ");
       scanf("%d", &rg_temp);

       novo = criar_no(nome_temp,rg_temp);
       novo->proximo=(*lista);
       (*lista)=novo;
       Mn=Mn+2;
       printf("Numero de movimentacoes: %d\n", Mn);
       printf("Numero de comparacoes: 0\n");
       clock_t end = clock();
       time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
       printf("\nTempo de execucao:%f segundos\n", time_spent);

}
void inserir_Fim_Encadeado(Noe **ultimo){
       double time_spent = 0.0;
       clock_t begin = clock();
       char nome_temp[TAM];
       int rg_temp;
       int Cn=0,Mn=0;
       Noe *novo;
       printf("Digite o nome: ");
       getchar();
       fgets(nome_temp, TAM, stdin);
       nome_temp[strcspn(nome_temp, "\n")] = '\0';

       printf("Digite o RG: ");
       scanf("%d", &rg_temp);

       novo = criar_no(nome_temp,rg_temp);

       (*ultimo)->proximo=novo;
        *ultimo = novo;
       Mn=Mn+2;
       printf("Numero de movimentacoes: %d\n", Mn);
       printf("Numero de comparacoes: 0\n");
       clock_t end = clock();
       time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
       printf("\nTempo de execucao:%f segundos\n", time_spent);

}
void inserir_Qualquer_Posicao(Noe**lista){
       double time_spent = 0.0;
       clock_t begin = clock();
       int posi, i , j;
       char nome_temp[TAM];
       int rg_temp;
       int Cn=0,Mn=0;
       printf(" digite a posição a ser inserida");
       scanf(" %d", &posi);

       Noe *novo;
       printf("Digite o nome: ");
       getchar();
       fgets(nome_temp, TAM, stdin);
       nome_temp[strcspn(nome_temp, "\n")] = '\0';

       printf("Digite o RG: ");
       scanf("%d", &rg_temp);

       novo = criar_no(nome_temp,rg_temp);
       Noe *atual = *lista;
       Noe *anterior = *lista;
       for(i=0;i<posi-1;i++)
       {
           Cn++;
           atual=atual->proximo;
           for(j=0;j<i;j++)
           {
               Cn++;
               anterior=anterior->proximo;
           }
       }
       //anterior->proximo=novo;
       novo->proximo=anterior->proximo;
       anterior->proximo=novo;
       Mn=Mn+2;
       printf("Numero de comparacoes: %d\n", Cn);
       printf("Numero de movimentacoes: %d\n", Mn);
       clock_t end = clock();
       time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
       printf("\nTempo de execucao:%f segundos\n", time_spent);

}
void retira_Inicio_Encadeado(Noe **lista){
         double time_spent = 0.0;
         clock_t begin = clock();
         int Cn=0,Mn=0;
         Noe *aux=(*lista);
         *lista=(*lista)->proximo;
         aux->proximo=NULL;
         Mn=Mn+2;
         printf("Numero de comparacoes: 0\n");
         printf("Numero de movimentacoes: %d\n", Mn);
         clock_t end = clock();
         time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
         printf("\nTempo de execucao:%f segundos\n", time_spent);

}
void retira_Fim_Encadeado(Noe **lista){
   double time_spent = 0.0;
   clock_t begin = clock();
   int Cn=0,Mn=0;
   Noe * retira = *lista;
   Noe * anterior = *lista;
   while(retira->proximo!=NULL)
   {
       Cn++;
       anterior = retira;
       retira=retira->proximo;
   }
       Mn++;
       anterior->proximo=NULL;
       printf("Numero de comparacoes: %d\n", Cn);
       printf("Numero de movimentacoes: %d\n", Mn);
       clock_t end = clock();
       time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
       printf("\nTempo de execucao:%f segundos\n", time_spent);
}
void retira_Qualquer_Encadeado(Noe **lista){
       double time_spent = 0.0;
       clock_t begin = clock();
       int Cn=0,Mn=0;
       int posi, i, j, k;
       Noe *pos= *lista;
       Noe *atual= *lista;
       Noe *anterior= NULL;
       printf(" digite a posição a ser retirada");
       scanf(" %d", &posi);
       for(i=0;i<posi-1;i++)
       {
           Cn++;
           anterior = atual;
           atual=atual->proximo;

       }
       Mn=Mn+3;
      anterior->proximo=atual->proximo;
      printf("Numero de comparacoes: %d\n", Cn);
      printf("Numero de movimentacoes: %d\n", Mn);
      clock_t end = clock();
      time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
      printf("\nTempo de execucao:%f segundos\n", time_spent);

}
void procura_No_Encadeado(Noe **lista){
      double time_spent = 0.0;
      clock_t begin = clock();
      int rg;
      int cont;
      int Cn=0,Mn=0;
      Noe * atual = *lista;
      printf("digite o rg a ser procurado");
      scanf(" %d", &rg);
      while(atual!=NULL){
            Cn++;
      if(rg==atual->rge)
      {
          Cn++;
          printf("Nome: %sRg: %d", atual->name,atual->rge);
          break;
      }
       atual=atual->proximo;
       cont++;
      }
      Mn++;
      printf("\nPosicao: %d\n", cont+1);
      printf("Numero de comparacoes: %d\n", Cn);
      printf("Numero de movimentacoes: %d\n", Mn);
      clock_t end = clock();
      time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
      printf("\nTempo de execucao:%f segundos\n", time_spent);
}
void salvar_Lista_Encadeada(Noe **lista){
     double time_spent = 0.0;
     clock_t begin = clock();
     Noe* atual = (*lista);
     int Cn=0,Mn=0;
     FILE* encadeada = fopen("lista_encadeada","w");
     if(encadeada==NULL)
     {
         Cn++;
         printf("erro ao salvar a lista");
     }
     while(atual!=NULL)
     {
         Cn++;
         fprintf(encadeada, "%s, %d\n",atual->name,atual->rge);
         atual=atual->proximo;
     }
     Mn++;
     fclose(encadeada);
     printf("Numero de comparacoes: %d\n", Cn);
     printf("Numero de movimentacoes: %d\n", Mn);
     clock_t end = clock();
     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
     printf("\nTempo de execucao:%f segundos\n", time_spent);
}

