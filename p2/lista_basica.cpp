#include <stdio.h> //traz printf, scanf...(entrada/saida)
#include <stdlib.h> //traz malloc, free, exit...(funçoes utilitarias, alocação dinamica)

//definição da célula da lista
typedef struct cel { // cria uma struct chama cel que reprensta uma celula da lista
    int conteudo; //é o dado que eu quero guardar, pode ser int ou outros
    struct cel *seg; //é um ponteiro para outra struct do mesmo tipo (ou seja, aponta para outra struct do mesmo tipo(isso é o encadeada de lista encadeada))
} celula; //typedef cria um apelido de tipo, entao em vez de escrever struct cel, agr escrevo so celula

//criar a lista vazia com celula-cabeça
celula *cria_lista_com_cabeca() { //declara uma função que retorna um ponteiro para celula, ou seja, vaidevolver o endereço da cabeça
    celula *cabeca = (celula *) malloc(sizeof(celula)); //malloc(sizeof(celula)); = reserva na memoria o espeço exato de uma celula, retorna um void *(ponteiro generico), a gente faz o cast para (celula *).cabeça é um ponteiro que aora aponta para essa celula nova na memoria.
    if (cabeca == NULL) { // semalloc falhar, ele devolve NULL, checamos isso pra nao usar memoria invalida.
        printf("Erro de alocacao\n");
        exit(1); // encerra o programacom codigo de erro
    }
    cabeca->seg = NULL; //acessa o campo seg da struct apontada por cabeça, o NULL significa "lista vazia"
    return cabeca; // devolve o ponteiro pra cabeça, quem chamar essa função va guardar isso numa variavel e usar como "começo da lista"
}

//insere no inicio da lista (essa é a operação padrao de lista encadeada com cabeça)
void insere_inicio(celula *cabeca, int x) { //parametros = celula *cabeca: ponteiro para a celula-cabeça(sempre o inicio logico) e int x: valor que quero inserir
    celula *nova = (celula *) malloc(sizeof(celula)); //aloca uma nova celula, nova vai ser o novo nó da lista
    if (nova == NULL) {
        printf("Erro de alocacao\n");
        exit(1);
    }
    nova->conteudo = x; //salva o valor passado (x) dentro do campo conteudo da nova celula
    nova->seg = cabeca->seg; //faz a nova celula apontar para o antigo primeiro elemento, se a lista estava vazia cabeça->seg era NULL, entao nova->seg=NULL
    cabeca->seg = nova; // agora a cabeça aponta para a nova celula, resultado = antes: cabeca->(antigo primeiro) e depois: cabeca->nova-> (antigo primeiro)
}

void imprime_lista(celula *cabeca) {
    celula *p = cabeca->seg;
    while (p != NULL) {
        printf("%d ", p->conteudo);
        p = p->seg;
    }
    printf("\n");
}

int main() {
    celula *lista = cria_lista_com_cabeca();

    insere_inicio(lista, 10);
    insere_inicio(lista, 20);
    insere_inicio(lista, 30);

    imprime_lista(lista);

    return 0;
}