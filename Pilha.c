#include <stdio.h>
#include <stdlib.h>

struct no {
  int info;
  struct no *prox;
};

void push(struct no **P,int v){
  struct no *n;

  n = (struct no *) malloc(sizeof(struct no));
  n->info = v;
  n->prox = *P;
  *P = n;

}//Fim push()

int pop(struct no **P){
  struct no *p;
  int v;

  p=*P; //aponta p para o no do TOPO
  v = p->info; //Peguei a informacao do no a ser removido
  *P = p->prox; //Faz o Pilha apontar p/ o proximo no
  free(p); //Libera memoria do no a ser removido
  return v; //retorna o valor do no removido

}//Fim pop()

void mostrarPilha(struct no **Pilha){
  struct no *Paux=NULL;
  int v;

  if (*Pilha==NULL){
    printf("Pilha Vazia!");
    return;
  }
  //O primeiro estou removendo fora do while
  // para ficar na direcao certa quando imprimir
  v=pop(Pilha);  //Retirei da Pilha Original
  printf(" %i\n",v); //Mostrei na tela
  push(&Paux,v); //Guarda na Pilha Auxiliar
  while(*Pilha!=NULL){
    v=pop(Pilha);  //Retirei da Pilha Original
    printf("        %i\n",v); //Mostrei na tela
    push(&Paux,v); //Guarda na Pilha Auxiliar
  }

  while (Paux!=NULL){
    v=pop(&Paux);  //Retira da Pilha Auxiliar
    push(Pilha,v); //Coloca na Pilha Original
  }

}//Fim mostrarPilha()

int QtdeMaioresMedia (struct no **PilhaQTD){
    struct no *Paux = NULL;
    float media;
    int val,soma =0, cont = 0;

    while (*PilhaQTD!=NULL){
        val = pop(PilhaQTD); //Remove da pilha original
        soma = soma + val;
        cont ++;
        push(&Paux,val);//guarda o valor da pilha auxiliar

    }
    media  = (float) soma/cont;

    cont = 0;
    while(Paux!=NULL){
        val = pop(&Paux); //remove da pilha auxiliar
        if (val > media) //verifica se é maior que a media
            cont++;
        push(PilhaQTD,val);     //guarda na pilha original
    }
    return cont;


}//Fim QtdeMairoresMedia

int consultarPosicao(struct no **Pilha,int v){
struct no *Paux = NULL;
int val,posicao=0, achou=0;

    while((!achou)&&(*Pilha!=NULL)){
        val = pop(Pilha);
        push(&Paux,val);
        posicao++;
        if(val==v){
            achou = posicao;
        }
    }

    //voltar elementos para a pilha original
    while(Paux!=NULL){
        push(Pilha,pop(&Paux));//retira da Paux e insere na Pilha
    }
    return achou;
}//fim do existe


int main(){
  struct no *Pilha;
  int op, op1, val, ret;

  Pilha = NULL; //Inicializa Pilha Vazia

  do{
    printf("\n\n==== P I L H A =====");
    printf("\n1) Push() - Inserir na Pilha");
    printf("\n2) Pop() - Remover da Pilha");
    printf("\n3) Mostrar Pilha");
    printf("\n4) exercicio 2 Conta maiores que a media");
    printf("\n5 exercicio 4 Verificar item na pilha");
    printf("\n0) Sair");

    printf("\nOpcao-> ");
    fflush(stdin); scanf("%i",&op);

    switch(op){
        case 1: //push() - Inserir no TOPO da Pilha
            printf("\n Digite o valor: ");
            fflush(stdin); scanf("%i",&val);
            push(&Pilha,val);
            break;
        case 2: //pop() - Remove o valor do TOPO da Pilha
            if(Pilha==NULL)
                  printf("\nPilha Vazia. Impossivel remover.");
            else
                  printf("\nValor Removido: %i", pop(&Pilha));
            break;
        case 3: //Mostra a Pilha
            printf("\nPilha->");
            mostrarPilha(&Pilha);
            break;
        case 4: //conta quantos elementos são maiores que a media
            printf("\nQtde maiores que a media: %i",QtdeMaioresMedia(&Pilha));
            break;
        case 5: // consulta se existe ium valor na pilha e retorna sua posição
            printf("\nDigite o valor a ser localizado");
            fflush(stdin); scanf("%i",&val);
            ret = consultarPosicao(&Pilha, val);
            if (ret==0)
                printf("\nO valor %i não foi localizado na pilha",val);
            else
                printf("\nO valor %i foi localizado na posicao %i da Pilha",val,ret);
            break;
    }

  }while (op!=0);

  return 0;
}//Fim main
