#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define NUMEROS_DE_TENTATIVAS 5
int veceenumero(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}                

int main()
{
    printf("--------------\n");
    printf("Seja Bem vindo\n");
    printf("--------------\n");
   int reset; 
   while (reset != 2){
   
        printf("Qual dificuldade voce deseja se arriscar: \n");
        printf("1-Facil\n2-Medio\n3-Dificil\n");
        
        char dificultLetra[100] = "10";
        
          scanf("%s",&dificultLetra);
        
            if (!veceenumero(dificultLetra))
            {
                printf("erro,Digite apenas numeros ou numeros positivos\n");
                continue;
            }
        int dificult;
        dificult = atoi(dificultLetra);
      
        if(dificult < 0 || dificult > 3){
            printf("Opcao invalida\n");
            continue;
        }
            int escolhe;
            switch (dificult)
                {

                case 1:
                    escolhe = 10;
                    break;
                case 2: 
                    escolhe = 100;
                    break;
                case 3: 
                    escolhe = 1000; 
                    break;
                }

        srand(time(NULL));
        int secreto = rand() %escolhe;
        char userletra[100];
           for (int i = 0; i <= NUMEROS_DE_TENTATIVAS; i++)
           {
                if (i == 0)
                {
                    printf("Tente a sorte: \n");
                }else{
                    printf("tente novamente: \n");
                }
                scanf("%s", userletra);
                    if (!veceenumero(userletra))
                    {
                        printf("erro,Digite apenas numeros ou numeros positivos\n");
                        i--;      
                        continue;
                    } 

                int user;
                user = atoi(userletra);
                int maior = user < secreto;
                
                if (secreto!= user)
                {
                    if (maior)
                        {      
                            printf("Maior\n");  
                        }else{   
                             printf("Menor\n");  
                        }           
                }
                if (i <= NUMEROS_DE_TENTATIVAS)
                {
                    printf("Tentativa %d de %d\n",NUMEROS_DE_TENTATIVAS , i);
                }
                int acerto = user == secreto;    
                    if (i >= 5 || acerto )
                    {  
                        if(acerto){
                            printf("----------------------------\n");
                            printf("Parabens!!!!!Voce ganhou!!!!\n");
                            printf("----------------------------\n");
                            break;
                        }else{
                            printf("------------------------------------------\n");
                            printf("Voce perdeu,mas voce pode tentar novamente\n");
                            printf("O numero secreto era: %d\n", secreto);
                            printf("------------------------------------------\n");
                            break;
                        }
                    }
            } 
            
                printf("-----------------------\n");
                printf("Quer continuar ou sair?\n");
                printf("1-Continuar\n2-Sair\n");
                printf("-----------------------\n");
                char resetLetra[100];
                scanf("%s", resetLetra);
                while(!veceenumero(resetLetra))
                {
                    if (!veceenumero(resetLetra))
                    {
                    printf("erro,Digite apenas numeros ou numeros positivos\n");
                    }
                }    
                reset = atoi(resetLetra);
                if (reset == 2 )
                {
                printf("saindoo...");
                }
    } 
}
