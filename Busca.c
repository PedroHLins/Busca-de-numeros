#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int verificar(char *parametro,int *err){

  int cont;
  
  for (cont=0;parametro[cont]!='\0';cont++) {
      if (!isdigit(parametro[cont])) {
          (*err)++;
      }
  }

  return *err;
}

//err = se houver algum erro ele retorna nessa variável, incrementando em 1
//nume = numero a ser procurado                               }   São todos strings para passar pela verificação, se fossem um
//inic = apartir desse número será feito a busca              >   inteiro a execução iria parar no momento em 
//fina = esse número será o último número a passar pela busca }   que qualquer dado que não fosse inteiro fosse inserido
//acert = vê quantas vezes o número apareceu no intervalo
//ini = inic convertido para int
//fin = fina convertido para int  

int main(void) {
  
  int err,ini,fin,acert=0;
  char nume[20],inic[20],fina[20], stringConvertida[10];

  printf("O CÓDIGO VAI SOMENTE ATÉ 99999!!!");

  do{
    err=0;
    printf("\n\n\nDigite o numero a ser pocurado: ");
    scanf("%s", nume);
    printf("\nInicio da contagem: ");
    scanf("%s", inic);
    printf("\nFinal da contagem: ");
    scanf("%s", fina);

    //inicio das verificações
    verificar(nume, &err);
    verificar(inic, &err);
    verificar(fina, &err);

    if (err!=0){
        printf("\nSomente numeros sao permitidos\n tente novamente");
        err++;
    } 
    else if (nume[0]=='-' || inic[0]=='-' || fina[0]=='-'){
        printf("\n\nSomente numeros positivos sao permitidos");
        err++;
    }
    else{
        ini=atoi(inic);
        fin=atoi(fina);

        if(ini>fin){
            printf("\n\nO numero inicial é maior que o numero final\n tente novamente");
            err++;
        }
        else if(ini>99999 || fin>99999){
            printf("\n\nO numuro Inicial ou Final excede o limite informado");
            err++;
        }
    }
    //fim das verificações

  }while(err!=0);

	int i;

  for(i=ini;i<=fin;i++){ // começa pelo número inicial fornecido pelo usuário e termina ao chegar ao número final
    sprintf(stringConvertida, "%i", i); //o contador i é convertido para um string (stringConvertida)
    char *result = strstr(stringConvertida, nume); //vemos se o número a ser procurado esta presente no indice i, com uma função para localizar substrings
    if(result){ 
        printf("%i ", i);  //Se o result não for nulo ele vai imprimir o número
        acert++;
    }
  }

    if(acert){
      printf("\n\nO numero %s apareceu %i vezes no intervalo entre [%i-%i]", nume, acert, ini, fin);
    }else{
        printf("\n\nO numero nao se encontra no intervalo");
    }
  
  return 0;
}
