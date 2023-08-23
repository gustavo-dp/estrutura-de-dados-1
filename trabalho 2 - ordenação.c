#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 20

#define OI "NomeRG10K.txt"

int cm=0, cn=0;
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
///lista simples ------------------------------
void inserir_Novo_Inicio(No *vet, int *cont);
void inserir_Novo_Final(No *vet, int *cont);
void inserir_Novo_N(No *vet, int *cont);
void retirar_No_Inicio(No *vet, int *cont);
void retirar_No_Fim(No *vet, int *cont);
void retirar_No_N(No *vet, int *cont);
void procura_No(No *vet, int *cont);
void imprime_Lista_Sequencial(No *vet, int *cont);
///--------------------------------lista encadeada
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
///----------------------------------------ordenação
void selection_Sort_Sequencial(No *vet, int *cont);
void selection_Sort_Encadeada(Noe **lista);
void insertion_Sort_Sequencial(No *vet,int *cont);
void insertion_Sort_Encadeado(Noe **lista);
void bubble_Sort_Sequencial(No *vet, int *cont);
void bubble_Sort_Encadeado(Noe **lista);
void shell_Sort_Sequencial(No *vet, int * n);
void mergesortSequencial(No *x, int inicio, int fim);
void merge_s(No *x, int inicio, int fim);
void quick_sort_Sequencial(No *x, int inicio, int fim);
void quick_s(No *x, int inicio, int fim, int* menores, int* maiores);
void PesquisaBinaria(No vet[], int *cont);
//---------------------------------------merge sort
void merge_Sort_Sequencial(No *vet, int *cont);
void merge_Sort_Recursao_Sequencial(No *vet, int l, int r);
void merge_Sorted_Arrays_Sequencial(No *vet, int l, int m, int r);
void inserir_inicio(Noe **head_ref, char *nome, int rg);
void merge_sort_lista(Noe **head_ref);
void merge_listas(Noe **head_ref, Noe *esquerda, Noe *direita);

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
      printf("\ndigite 1 para inserir um no no comeco\n 2 para inserir no final\n 3 para inserir em qualquer posicao\n 4 para retirar um no do comeco\n 5 para retirar um no do final\n 6 para retirar de qualquer posicao\n 7 para procurar um no\ndigite 8 para sair do programa\n9 para imprimir a listadigite 10: para selection sort\ndigite 11: para insertion sort\ndigite 12: para bubble sort\ndigite 13: para shell sort\ndigite 14:para quick sort\ndigite 15: para merge sort\ndigite 16: para pesquisa binária");
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
      case 10:
          cn=0;
          cm=0;
          selection_Sort_Sequencial(vet,&cont);
          printf("Numero de comparações:%d\nNumero de movimentações:%d\n", cn, cm);
          break;
      case 11:
          cn=0;
          cm=0;
          insertion_Sort_Sequencial(vet,&cont);
          printf("Numero de comparações:%d\nNumero de movimentações:%d\n", cn, cm);
          break;
      case 12:
          cn=0;
          cm=0;
          bubble_Sort_Sequencial(vet,&cont);
          printf("Numero de comparações:%d\nNumero de movimentações:%d\n", cn, cm);
          break;
      case 13:
          cn=0;
          cm=0;
        shell_Sort_Sequencial(vet,&cont);
        printf("Numero de comparações:%d\nNumero de movimentações:%d\n", cn, cm);
          break;
      case 14:
          cn=0;
          cm=0;
          double time_spent = 0.0;
          clock_t begin = clock();
        quick_sort_Sequencial(vet,0,cont-1);
        printf("Numero de comparações:%d\nNumero de movimentações:%d\n", cn, cm);
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
        printf("\nTempo de execucao:%f segundos\n", time_spent);
          break;
      case 15:
          cn=0;
          cm=0;
          double time_spent1 = 0.0;
          clock_t begin1 = clock();
        mergesortSequencial(vet,0,cont-1);
        printf("Numero de comparações:%d\nNumero de movimentações:%d\n", cn, cm);
        clock_t end1 = clock();
        time_spent1 += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
        printf("\nTempo de execucao:%f segundos\n", time_spent);
        break;
      case 16:
          cn=0;
          cm=0;
        PesquisaBinaria(vet,&cont);
        printf("Numero de comparações:%d\nNumero de movimentações:%d\n", cn, cm);
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
              case 11:
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
       anterior->proximo=novo;
       novo->proximo=atual;
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

//----------------------------------------------------------
void selection_Sort_Sequencial(No *vet, int *cont) {
    double time_spent = 0.0;
    clock_t begin = clock();
    int i, j, min, aux2;
    char aux[100];
    for (i = 0; i < *cont - 1; i++) {
        min = i;
        cn++;
        cm++;
        for (j = i + 1; j < *cont; j++) {
                cn++;
            if (vet[j].rg < vet[min].rg) {
                min = j;
                cn++;
                cm++;
            }
        }
        if (min != i) {
                cn++;
            strcpy(aux, vet[i].nome);
            strcpy(vet[i].nome, vet[min].nome);
            strcpy(vet[min].nome, aux);
            aux2 = vet[min].rg;
            vet[min].rg = vet[i].rg;
            vet[i].rg = aux2;
        cm = cm+6;
        }
    }
     clock_t end = clock();
     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
     printf("\nTempo de execucao:%f segundos\n", time_spent);
}
void selection_Sort_Encadeada(Noe **lista){
      double time_spent = 0.0;
      clock_t begin = clock();

      Noe * atual=*lista;

      char aux[100];
      while(atual!=NULL)
      {

          Noe *min = atual;
          Noe * depois=atual->proximo;
          while(depois!=NULL)
          {
             if(strcmp(depois->name,min->name)< 0)
             {
                 min = depois;
             }

             if(min!=atual)
             {
                 strcpy(aux, atual->name);
                 strcpy(atual->name, min->name);
                 strcpy(min->name, aux);
                 int aux2 = atual->rge;
                 atual->rge=min->rge;
                 min->rge=aux2;
             }
             depois=depois->proximo;

          }
         atual=atual->proximo;
      }
     clock_t end = clock();
     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
     printf("\nTempo de execucao:%f segundos\n", time_spent);
}
void insertion_Sort_Sequencial(No *vet,int *cont){
      double time_spent = 0.0;
      clock_t begin = clock();
      char chave[100];
      int i, j, chave2;
      for(i=1;i<*cont;i++)
      {
          cn++;
          strcpy(chave,vet[i].nome);
          chave2= vet[i].rg;
          j=i-1;
          cm=cm+3;
          while(j>=0 && vet[j].rg>chave2)
          {
              cn++;
              strcpy(vet[j+1].nome,vet[j].nome);
              vet[j+1].rg=vet[j].rg;
              j=j-1;
              strcpy(vet[j+1].nome,chave);
              vet[j+1].rg=chave2;
              cm=cm+5;

          }
      }
     clock_t end = clock();
     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
     printf("\nTempo de execucao:%f segundos\n", time_spent);
}
void insertion_Sort_Encadeado(Noe **lista){
   double time_spent = 0.0;
   clock_t begin = clock();
   char chave[100];
   int chave2;
   Noe * atual = *lista;
   Noe *depois= atual->proximo;
   while(depois!=NULL)
   {
       strcpy(chave,depois->name);
       chave2 = depois->rge;
       while(atual!=NULL )
       {
           if(strcmp(atual->name,depois->name)>0)
           {
                   strcpy(depois->name,atual->name);
                   strcpy(atual->name,chave);
                   depois->rge=atual->rge;
                   atual->rge=chave2;
           }
           atual=atual->proximo;
       }
       depois=depois->proximo;
   }
     clock_t end = clock();
     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
     printf("\nTempo de execucao:%f segundos\n", time_spent);
}
void bubble_Sort_Sequencial(No *vet, int *cont){
    double time_spent = 0.0;
    clock_t begin = clock();
    int i, j;
    char aux[100];
    int aux1 = 0;
    for(j=0;j<(*cont-1);j++){
        cn++;
       for(i=0;i<(*cont-1-j);i++){
            cn++;

           if(vet[i].rg>vet[i+1].rg)
           {
               cn++;
               strcpy(aux,vet[i+1].nome);
               strcpy(vet[i+1].nome,vet[i].nome);
               strcpy(vet[i].nome,aux);
               aux1 = vet[i+1].rg;
               vet[i+1].rg=vet[i].rg;
               vet[i].rg=aux1;
               cm=cm+3;
           }
       }
    }
     clock_t end = clock();
     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
     printf("\nTempo de execucao:%f segundos\n", time_spent);
}
void bubble_Sort_Encadeado(Noe **lista){
   double time_spent = 0.0;
   clock_t begin = clock();
   char aux[100];
   int y =0;
   Noe * atual = *lista;
   while (atual != NULL) {
    Noe *depois = atual->proximo;
    while (depois != NULL) {
        if (strcmp(atual->name, depois->name) > 0) {
            strcpy(aux, depois->name);
            strcpy(depois->name, atual->name);
            strcpy(atual->name, aux);
        }
        depois = depois->proximo;
    }
    atual = atual->proximo;
}

     clock_t end = clock();
     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
     printf("\nTempo de execucao:%f segundos\n", time_spent);



}
void mergesortSequencial(No *x, int inicio, int fim)
{
    if(inicio!=fim){
            cn++;
        mergesortSequencial(x, inicio, ((fim-inicio)/2)+inicio);//primeira metade
        mergesortSequencial(x, ((fim-inicio)/2)+inicio+1, fim);//segunda metade
        merge_s(x, inicio, fim);
        }
}

///função suporte///(pra não ocupar tanta memória)
void merge_s(No *x, int inicio, int fim)
{

    int elementos = fim-inicio+1, meio = ((fim-inicio)/2)+inicio;           //último da primeira metade se intervalo for par, ou posição do meio se for ímpar
    int index_1 = inicio, index_2 = meio+1, i=0;                            //os contadores para cada uma das metades enquanto adicionamos

    No *temp = (No*)malloc(sizeof(No)*elementos);
    cm++;


    while(index_1 < meio+1 && index_2 < fim+1)
    {
        cn++;
        if(x[index_1].rg<=x[index_2].rg){
                cn++;
            strcpy(temp[i].nome,x[index_1].nome);
            temp[i].rg = x[index_1].rg;
            cm = cm +2;
            index_1++;
        }
        else{
            cn++;
            temp[i] = x[index_2];
            cm++;
            index_2++;
        }
        i++;
    }

    if(index_1 == meio+1){  //se todos da primeira metade foram adicionados
        cn++;
        while(i < elementos)
        {
            cn++;
            temp[i] = x[index_2];
            cm++;
            index_2++;
            i++;
        }
    }
    else{                              //se todos da segunda metade foram adicionados
       cn++;
        while(i < elementos)
        {
            cn++;
            temp[i] = x[index_1];
            cm++;
            index_1++;
            i++;
        }
    }

    for(i=0; i<elementos; i++)
    {
        cn++;
        x[inicio+i] = temp[i];
        cm++;
    }
    free(temp);
}


void shell_Sort_Sequencial(No *vet, int *n) {
    double time_spent = 0.0;
    clock_t begin = clock();
    int i, j, h = 1;
    int aux;
    int x = *n;
    char aux2[100];

    while (h < x / 3)
        {
        h = 3 * h + 1;
        cn++;
        }
    while (h > 0) {
            cn++;
        for (i = h; i < x; i++) {
            cn++;
            for (j = i; j - h >= 0; j -= h) {
                cn++;
                if (vet[j].rg<vet[j-h].rg) {
                    cn++;
                    strcpy(aux2, vet[j - h].nome);
                    strcpy(vet[j - h].nome, vet[j].nome);
                    strcpy(vet[j].nome, aux2);
                    aux = vet[j - h].rg;
                    vet[j - h].rg = vet[j].rg;
                    vet[j].rg = aux;
                } else {
                    cn++;
                    break;
                }
            }
        }
        h = (h - 1) / 3;
        cm++;
    }
     clock_t end = clock();
     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
     printf("\nTempo de execucao:%f segundos\n", time_spent);
}
void quick_sort_Sequencial(No *x, int inicio, int fim)
{
    int menores = 0, maiores = 0;
    quick_s(x, inicio, fim, &menores, &maiores);

    if(menores > 1 && maiores != 0)
    {
         quick_sort_Sequencial(x, inicio, (inicio+menores)-1);
         cn ++;
    }
    if(maiores > 1 && menores != 0)
    {
         quick_sort_Sequencial(x, inicio+menores, fim);
         cn ++;
    }
}

void quick_s(No *x, int inicio, int fim, int* menores, int* maiores)
{
    int i, pivo;
    No aux;
    char aux2[100], teste1,teste2,teste3;

    pivo  = (x[inicio].rg + x[((fim-inicio)/2)+inicio].rg + x[fim].rg)/3;
    cm++;
    for(i=inicio;i<=fim;i++)
    {
        cn++;
        if(x[i].rg>pivo)
            {
            (*maiores)++;
             cn++;
            }
        else
        {
            //strcpy(aux2,x[i].nome);
            //strcpy(x[i].nome,x[inicio+(*menores)].nome);
            //strcpy(x[inicio+(*menores)].nome,aux.nome);
            aux = x[i];
            x[i] = x[inicio+(*menores)];
            x[inicio+(*menores)]= aux;
            (*menores)++;
            cn++;
            cm =cm+3;
        }
    }
}
void PesquisaBinaria(No vet[], int *cont) {

    double time_spent = 0.0;
    clock_t begin = clock();
    int l = 0, rg, posi = *cont;// posicao inicial
    //r = contador// numero de posicoes
    printf("\niniciando busca binaria\n");

    printf("\nInsira o Rg: ");
    scanf("%d", &rg);
    while (l <= posi) {
        int meio = l+(posi - l) / 2; // meio do vetor
        cm++;

        // Verifica se o elemento está no meio do vetor
        if (vet[meio].rg == rg){

                printf("*********************\n");
                printf("%-10s \n", vet[meio].nome);
                printf("Rg: %d \n", vet[meio].rg);
                printf("Posi: %d \n",meio);
                printf("*********************\n");
                cn++;


        }

        // Se o elemento for menor do que o mei8o, procura na metade inferior do vetor
        if (vet[meio].rg > rg){
            posi = meio - 1;
            cn++;
            cm++;
        }
        // Se o elemento for maior do que o meio, procura na metade superior do vetor
        else{
            l = meio + 1;
            cn++;
            cm++;
        }
    }

     clock_t end = clock();
     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;  // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
     printf("\nTempo de execucao:%f segundos\n", time_spent);

}




