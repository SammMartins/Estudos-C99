#include <stdio.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include<time.h>//necessário p/ função time()
#include <unistd.h>

void tabuada(void);
void calc_imp(void);
void calc_num_int(void);
void outro(void);
void calc_med(void);
void calc_troco(void);
void calc_sal_anual(void);
void farkle(void);
void string_aula(void);

int main(void) {
  char opc='s';
  do 
  {
    printf("\n\tMENU PRINCIPAL\n\n");
    printf("\tEscolha uma opção: \n(F) Farkle\n(A) Calculadora do salário Anual\n(T) String aula\n(I) Calculadora de Impostos sobre o Salário\n(N) Calculadora dos Nº inteiros\n(M) Calculadora de Médias\n(R) Calculadora de Troco\n(S) Sair - Finalizar Programa\n ->\t"); scanf(" %c",&opc);
    
    switch(opc)
    {
      case 't':
      case 'T': printf("Opção String escolhida.\n"); string_aula(); break;
      case 'i':
      case 'I': printf("Opção Calculadora de impostos escolhida.\n"); calc_imp(); break;
      case 'n':
      case 'N': printf("Opção Calculadora dos Nº inteiros escolhida.\n"); calc_num_int(); break;
      case 'm':
      case 'M': printf("Opção Calculadora de Médias escolhida.\n"); calc_med(); break;
      case 'r':
      case 'R': printf("Opção calculadora de troco escolhida.\n"); calc_troco(); break;
      case 'a':
      case 'A': printf("Opção calculadora de salário anual escolhida.\n"); calc_sal_anual(); break;
      case 'f':
      case 'F': printf("Farkle inicializado\n"); farkle(); break;
      case 'z':
      case 'Z': printf("Programa oculto ativado.\n"); outro(); break;
      case 's':
      case 'S': printf(" \n"); break;
      default: printf("\nOpção Inválida ou não implementada.\n");
    }
    
  }  while (opc!='s' && opc!='S'); puts("Finalizando programa...");
  puts("\n/FIM");
  return 0;
}

void tabuada(void)
{
  int i, num;
  printf("\nDigite um número para a tabuada: "); scanf("%d",&num);
  for(i=1;i<=10;i++)
  {
    printf("%d x %2d = %2d\n",num,i,num*i);
  }
}

void calc_imp(void) 
{
  float sal,taxa;
  printf("Qual o salário? \nSalário R$"); scanf("%f",&sal); 
  if (sal<1000) {
    taxa= .05;
  } 
  else {
    if (sal<5000){
      taxa= .11;
    } else taxa= .35;
  }
  printf("\tO imposto total: R$%.2f\n\tSalário Líquido: R$%.2f\n",sal*taxa,sal-(sal*taxa));
}

void calc_num_int(void)
{
  int soma,prod,n,i; prod=1;
  printf("\nQual o número inteiro limitador? "); scanf("%d",&n);
  soma=(n*(n+1))/2; printf("\nSoma = %d",soma);
  for(i=1;i<=n;i++)
  {
    prod=prod*i;
  }
  printf("\nProduto = %d\n",prod);
}

char avalidor_notas(float a, float b, float c, float d)
{
  float nota_tot;
  if (a>100 || b>100 || c>100 || d>100) {return 'I';} 
  else {
    nota_tot=(a+b+c+d)/4; 
    if (nota_tot>=70) 
    {return 'A';} else return 'R';}
}

void calc_med(void) 
{
  float nota1,nota2,nota3,nota4;
  int resp=1;
  do {
    printf("\nDigite a primeira nota:\t"); scanf("%f",&nota1);
    printf("Digite a segunda nota:\t"); scanf("%f",&nota2);
    printf("Digite a terceira nota:\t"); scanf("%f",&nota3);
    printf("Digite a quarta nota:\t"); scanf("%f",&nota4);
    
    if (avalidor_notas(nota1,nota2,nota3,nota4)== 'I') 
      {printf("\nAlguma nota inserida foi maior que o limite  100\n");}
    else {
      if (avalidor_notas(nota1,nota2,nota3,nota4) == 'A') {
        printf("\nCaro aluno, você está APROVADO\n");} 
        
      else printf("\nCaro aluno, você está REPROVADO\n");}
    
    printf("\nDeseja calcular mais médias?\n");
    printf("\nInsira 0 para finalizar a calculadora de médias,\nou, insira 1 para continuar:\t");
    scanf("%d",&resp);
  } while (resp);
}

void troc_espe(float troc)
{
  enum{nota100,nota50,nota20,nota10,nota5,nota2};
  enum{moeda1,moeda50,moeda25,moeda10,moeda05};

  int quant_nota[6];
  int quant_moeda[5];

  {quant_nota[nota100]= (int)troc/100; printf("\nNotas de 100: %d",quant_nota[nota100]);
  troc= troc-(quant_nota[nota100]*100);

  quant_nota[nota50]= (int)troc/50; printf("\nNotas de  50: %d",quant_nota[nota50]);
  troc= troc-(quant_nota[nota50]*50);

  quant_nota[nota20]= (int)troc/20; printf("\nNotas de  20: %d",quant_nota[nota20]);
  troc= troc-(quant_nota[nota20]*20);

  quant_nota[nota10]= (int)troc/10; printf("\nNotas de  10: %d",quant_nota[nota10]);
  troc= troc-(quant_nota[nota10]*10);

  quant_nota[nota5]= (int)troc/5; printf("\nNotas de   5: %d",quant_nota[nota5]);
  troc= troc-(quant_nota[nota5]*5);

  quant_nota[nota2]= (int)troc/2; printf("\nNotas de   2: %d\n",quant_nota[nota2]);
  troc= troc-(quant_nota[nota2]*2);}
  printf("_______________");
  {quant_moeda[moeda1]= (int)(troc/1); printf("\nMoedas de 1,00: %d",quant_moeda[moeda1]);
  troc= troc-(quant_moeda[moeda1]*1);

  quant_moeda[moeda50]= (int)(troc/0.5); printf("\nMoedas de 0,50: %d",quant_moeda[moeda50]);
  troc= troc-(quant_moeda[moeda50]*0.5);

  quant_moeda[moeda25]= (int)(troc/0.25); printf("\nMoedas de 0,25: %d",quant_moeda[moeda25]);
  troc= troc-(quant_moeda[moeda25]*0.25);

  quant_moeda[moeda10]= (int)(troc/0.10); printf("\nMoedas de 0,10: %d",quant_moeda[moeda10]);
  troc= troc-(quant_moeda[moeda10]*0.10);

  quant_moeda[moeda05]= (int)(troc/0.05); printf("\nMoedas de 0,05: %d",quant_moeda[moeda05]);
  troc= troc-(quant_moeda[moeda05]*0.05);}
  
}

void calc_troco(void) 
{
  float prod=1,valor_tot,pag,troco,prodvsquant; int resp=1,cont=0,quant=1;
  do
  {
    while (prod!=0 || prod<0)
    {
      cont+=1;
      printf("\n%dº produto R$",cont); scanf("%f",&prod); printf("\tQuantidade: "); scanf("%d",&quant); prodvsquant=prod*quant;
      valor_tot+=prodvsquant;
    }
    printf("\nValor total: R$%.2f",valor_tot);
    printf("\nValor pago:  R$"); scanf("%f",&pag); troco=pag-valor_tot;
    printf("\nTroco R$%.2f\n",troco);
    printf("_____________"); troc_espe(troco);
    
    valor_tot=0; troco=0; cont=0; prod=1; quant=1;
    
    printf("\n\nInsira 0 para finalizar,\nou, insira 1 para continuar: ");
    scanf("%d",&resp);
    
  } while (resp);
}

void calc_sal_anual(void)
{
  int mes;
  float total;
  float ano[12];
  for(mes=0;mes<=11;mes++)
  {
    printf("Salário %dº Mês  R$",mes+1); scanf("%f",&ano[mes]);
  }
  puts(" Mês      Valor ");
  for (mes=0,total=0.0;mes<12;mes++)
  {
    printf(" %3d %12.2f\n",mes+1,ano[mes]);
    total+=ano[mes];
  }
  printf("Total: %7.2f\n",total);
  printf("Média: %7.2f\n",total/12);
}

void farkle(void)
{

  int i,forc,selec=10,count=0,score_rod=0,score_tot=0;
  int count_face1,count_face5,count_face2,count_face3,count_face4,count_face6;
  int count_sequen1,count_sequen2,count_sequenC,count_selec=0;
  enum{dado_1,dado_2,dado_3,dado_4,dado_5,dado_6};
  int dados[6]; 
  int dados_selec[6]={0,0,0,0,0,0};
  srand(time(NULL));


    for(i=0;i<=5;i++)
      if(dados_selec[i]==0)
        count_selec+=1;

    switch (count_selec)
      {
      case 6: printf("\t\nRolagem com 6 dados\n");
      case 0: 
      {
        dados[dado_1]=(rand() % 6)+1; sleep(1); printf("1º Dado:%5d \n",dados[dado_1]);
        dados[dado_2]=(rand() % 6)+1; sleep(3/2); printf("2º Dado:%3d \n",dados[dado_2]);
        dados[dado_3]=(rand() % 6)+1; sleep(1); printf("3º Dado:%5d \n",dados[dado_3]);
        dados[dado_4]=(rand() % 6)+1; sleep(3/2); printf("4º Dado:%3d \n",dados[dado_4]);
        dados[dado_5]=(rand() % 6)+1; sleep(1); printf("5º Dado:%5d \n",dados[dado_5]);
        dados[dado_6]=(rand() % 6)+1; sleep(3/2); printf("6º Dado:%3d \n",dados[dado_6]);
        
        {for(i=0;i<=5;i++) 
          {
      printf(" - Selecione os dados: "); scanf("%d",&selec);
      if (selec==0)
        break;
      switch(selec) 
      {
        case 1: 
          dados_selec[count]=dados[dado_1]; 
          printf("1º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 2: 
          dados_selec[count]=dados[dado_2]; 
          printf("2º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 3: 
          dados_selec[count]=dados[dado_3]; 
          printf("3º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 4: 
          dados_selec[count]=dados[dado_4]; 
          printf("4º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 5: 
          dados_selec[count]=dados[dado_5]; 
          printf("5º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 6: 
          dados_selec[count]=dados[dado_6]; 
          printf("6º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 0: break;
        default: printf("\nOpção Inválida\n"); i-=1; 
      }
      
    }
        
        {count_face1=0; count_face5=0; count_face2=0; count_face3=0; count_face4=0; count_face6=0;
    count_sequen1=0; count_sequen2=0; count_sequenC=0;}

        for(i=0;i<=5;i++) 
          {
      
      if (dados_selec[i]!=0)
      {
        switch(dados_selec[i]) 
        {
          case 1: count_face1+=1; break;
          case 2: count_face2+=1; break;
          case 3: count_face3+=1; break;
          case 4: count_face4+=1; break;
          case 5: count_face5+=1; break;
          case 6: count_face6+=1; break;
        }
        printf("\nDado face '%d' selecionado. ",dados_selec[i]);
      } 
      else break;
    } 
          
        score_rod=0;
        switch(count_face1)
          {
      case 1: score_rod+=100; count_sequen1+=1; count_sequenC+=1; break;
      case 2: score_rod+=200; break;
      case 3: score_rod+=1000; break;
      case 4: score_rod+=2000; break;
      case 5: score_rod+=4000; break;
      case 6: score_rod+=8000; break;
      default: break;
    }
        switch(count_face2)
          {
      case 1: count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=200; break;
      case 4: score_rod+=400; break;
      case 5: score_rod+=800; break;
      case 6: score_rod+=1600; break;
      default: break;
    }
        switch(count_face3)
          {
      case 1: count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=300; break;
      case 4: score_rod+=600; break;
      case 5: score_rod+=1200; break;
      case 6: score_rod+=2400; break;
      default: break;
    }
        switch(count_face4)
          {
      case 1: count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=400; break;
      case 4: score_rod+=800; break;
      case 5: score_rod+=1600; break;
      case 6: score_rod+=3200; break;
      default: break;
    }
        switch(count_face5)
          {
      case 1: score_rod+=50; count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 2: score_rod+=100; break;
      case 3: score_rod+=500; break;
      case 4: score_rod+=1000; break;
      case 5: score_rod+=2000; break;
      case 6: score_rod+=4000; break;
      default: break;
    }
        switch(count_face6)
          {
      case 1: count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=600; break;
      case 4: score_rod+=1200; break;
      case 5: score_rod+=3200; break;
      case 6: score_rod+=6400; break;
      default: break;
    }
    
        if(count_sequenC==6)
          score_rod+=1500-50-100;
        else
          if(count_sequen1==5)
            score_rod+=500-50-100;
          else
            if(count_sequen2==5)
              score_rod+=750-50-100;
        
        printf("\nPontuação rodada: '%d' ",score_rod);
        puts("\n"); break;}
        
      }
      case 1: 
      {
        printf("\t\nRolagem com 5 dados\n");
        dados[dado_1]=(rand() % 6)+1; sleep(1); printf("1º Dado:%5d \n",dados[dado_1]);
        dados[dado_2]=(rand() % 6)+1; sleep(3/2); printf("2º Dado:%3d \n",dados[dado_2]);
        dados[dado_3]=(rand() % 6)+1; sleep(1); printf("3º Dado:%5d \n",dados[dado_3]);
        dados[dado_4]=(rand() % 6)+1; sleep(3/2); printf("4º Dado:%3d \n",dados[dado_4]);
        dados[dado_5]=(rand() % 6)+1; sleep(1); printf("5º Dado:%5d \n",dados[dado_5]);
        
      { for(i=0;i<=5;i++) 
          {
      printf(" - Selecione os dados: "); scanf("%d",&selec);
      if (selec==0)
        break;
      switch(selec) 
      {
        case 1: 
          dados_selec[count]=dados[dado_1]; 
          printf("1º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 2: 
          dados_selec[count]=dados[dado_2]; 
          printf("2º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 3: 
          dados_selec[count]=dados[dado_3]; 
          printf("3º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 4: 
          dados_selec[count]=dados[dado_4]; 
          printf("4º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 5: 
          dados_selec[count]=dados[dado_5]; 
          printf("5º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 6: 
          dados_selec[count]=dados[dado_6]; 
          printf("6º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 0: break;
        default: printf("\nOpção Inválida\n"); i-=1; 
      }
      
    }
        
        {count_face1=0; count_face5=0; count_face2=0; count_face3=0; count_face4=0; count_face6=0;
    count_sequen1=0; count_sequen2=0; count_sequenC=0;}

        for(i=0;i<=5;i++) 
          {
      
      if (dados_selec[i]!=0)
      {
        switch(dados_selec[i]) 
        {
          case 1: count_face1+=1; break;
          case 2: count_face2+=1; break;
          case 3: count_face3+=1; break;
          case 4: count_face4+=1; break;
          case 5: count_face5+=1; break;
          case 6: count_face6+=1; break;
        }
        printf("\nDado face '%d' selecionado. ",dados_selec[i]);
      } 
      else break;
    } 
          
        score_rod=0;
        switch(count_face1)
          {
      case 1: score_rod+=100; count_sequen1+=1; count_sequenC+=1; break;
      case 2: score_rod+=200; break;
      case 3: score_rod+=1000; break;
      case 4: score_rod+=2000; break;
      case 5: score_rod+=4000; break;
      case 6: score_rod+=8000; break;
      default: break;
    }
        switch(count_face2)
          {
      case 1: count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=200; break;
      case 4: score_rod+=400; break;
      case 5: score_rod+=800; break;
      case 6: score_rod+=1600; break;
      default: break;
    }
        switch(count_face3)
          {
      case 1: count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=300; break;
      case 4: score_rod+=600; break;
      case 5: score_rod+=1200; break;
      case 6: score_rod+=2400; break;
      default: break;
    }
        switch(count_face4)
          {
      case 1: count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=400; break;
      case 4: score_rod+=800; break;
      case 5: score_rod+=1600; break;
      case 6: score_rod+=3200; break;
      default: break;
    }
        switch(count_face5)
          {
      case 1: score_rod+=50; count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 2: score_rod+=100; break;
      case 3: score_rod+=500; break;
      case 4: score_rod+=1000; break;
      case 5: score_rod+=2000; break;
      case 6: score_rod+=4000; break;
      default: break;
    }
        switch(count_face6)
          {
      case 1: count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=600; break;
      case 4: score_rod+=1200; break;
      case 5: score_rod+=3200; break;
      case 6: score_rod+=6400; break;
      default: break;
    }
    
        if(count_sequenC==6)
          score_rod+=1500-50-100;
        else
          if(count_sequen1==5)
            score_rod+=500-50-100;
          else
            if(count_sequen2==5)
              score_rod+=750-50-100;
        
        printf("\nPontuação rodada: '%d' ",score_rod);
        puts("\n"); break;}
        
      }
      case 2: 
      {
        printf("\t\nRolagem com 4 dados\n");
        dados[dado_1]=(rand() % 6)+1; sleep(1); printf("1º Dado:%5d \n",dados[dado_1]);
        dados[dado_2]=(rand() % 6)+1; sleep(3/2); printf("2º Dado:%3d \n",dados[dado_2]);
        dados[dado_3]=(rand() % 6)+1; sleep(1); printf("3º Dado:%5d \n",dados[dado_3]);
        dados[dado_4]=(rand() % 6)+1; sleep(3/2); printf("4º Dado:%3d \n",dados[dado_4]);
        
        { for(i=0;i<=5;i++) 
          {
      printf(" - Selecione os dados: "); scanf("%d",&selec);
      if (selec==0)
        break;
      switch(selec) 
      {
        case 1: 
          dados_selec[count]=dados[dado_1]; 
          printf("1º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 2: 
          dados_selec[count]=dados[dado_2]; 
          printf("2º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 3: 
          dados_selec[count]=dados[dado_3]; 
          printf("3º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 4: 
          dados_selec[count]=dados[dado_4]; 
          printf("4º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 5: 
          dados_selec[count]=dados[dado_5]; 
          printf("5º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 6: 
          dados_selec[count]=dados[dado_6]; 
          printf("6º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 0: break;
        default: printf("\nOpção Inválida\n"); i-=1; 
      }
      
    }
        
        {count_face1=0; count_face5=0; count_face2=0; count_face3=0; count_face4=0; count_face6=0;
    count_sequen1=0; count_sequen2=0; count_sequenC=0;}

        for(i=0;i<=5;i++) 
          {
      
      if (dados_selec[i]!=0)
      {
        switch(dados_selec[i]) 
        {
          case 1: count_face1+=1; break;
          case 2: count_face2+=1; break;
          case 3: count_face3+=1; break;
          case 4: count_face4+=1; break;
          case 5: count_face5+=1; break;
          case 6: count_face6+=1; break;
        }
        printf("\nDado face '%d' selecionado. ",dados_selec[i]);
      } 
      else break;
    } 
          
        score_rod=0;
        switch(count_face1)
          {
      case 1: score_rod+=100; count_sequen1+=1; count_sequenC+=1; break;
      case 2: score_rod+=200; break;
      case 3: score_rod+=1000; break;
      case 4: score_rod+=2000; break;
      case 5: score_rod+=4000; break;
      case 6: score_rod+=8000; break;
      default: break;
    }
        switch(count_face2)
          {
      case 1: count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=200; break;
      case 4: score_rod+=400; break;
      case 5: score_rod+=800; break;
      case 6: score_rod+=1600; break;
      default: break;
    }
        switch(count_face3)
          {
      case 1: count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=300; break;
      case 4: score_rod+=600; break;
      case 5: score_rod+=1200; break;
      case 6: score_rod+=2400; break;
      default: break;
    }
        switch(count_face4)
          {
      case 1: count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=400; break;
      case 4: score_rod+=800; break;
      case 5: score_rod+=1600; break;
      case 6: score_rod+=3200; break;
      default: break;
    }
        switch(count_face5)
          {
      case 1: score_rod+=50; count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 2: score_rod+=100; break;
      case 3: score_rod+=500; break;
      case 4: score_rod+=1000; break;
      case 5: score_rod+=2000; break;
      case 6: score_rod+=4000; break;
      default: break;
    }
        switch(count_face6)
          {
      case 1: count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=600; break;
      case 4: score_rod+=1200; break;
      case 5: score_rod+=3200; break;
      case 6: score_rod+=6400; break;
      default: break;
    }
    
        if(count_sequenC==6)
          score_rod+=1500-50-100;
        else
          if(count_sequen1==5)
            score_rod+=500-50-100;
          else
            if(count_sequen2==5)
              score_rod+=750-50-100;
        
        printf("\nPontuação rodada: '%d' ",score_rod);
        puts("\n"); break;}
        
      }
      case 3: 
      {
        printf("\t\nRolagem com 3 dados\n");
        dados[dado_1]=(rand() % 6)+1; sleep(1); printf("1º Dado:%5d \n",dados[dado_1]);
        dados[dado_2]=(rand() % 6)+1; sleep(3/2); printf("2º Dado:%3d \n",dados[dado_2]);
        dados[dado_3]=(rand() % 6)+1; sleep(1); printf("3º Dado:%5d \n",dados[dado_3]);
        
        { for(i=0;i<=5;i++) 
          {
      printf(" - Selecione os dados: "); scanf("%d",&selec);
      if (selec==0)
        break;
      switch(selec) 
      {
        case 1: 
          dados_selec[count]=dados[dado_1]; 
          printf("1º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 2: 
          dados_selec[count]=dados[dado_2]; 
          printf("2º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 3: 
          dados_selec[count]=dados[dado_3]; 
          printf("3º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 4: 
          dados_selec[count]=dados[dado_4]; 
          printf("4º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 5: 
          dados_selec[count]=dados[dado_5]; 
          printf("5º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 6: 
          dados_selec[count]=dados[dado_6]; 
          printf("6º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 0: break;
        default: printf("\nOpção Inválida\n"); i-=1; 
      }
      
    }
        
        {count_face1=0; count_face5=0; count_face2=0; count_face3=0; count_face4=0; count_face6=0;
    count_sequen1=0; count_sequen2=0; count_sequenC=0;}

        for(i=0;i<=5;i++) 
          {
      
      if (dados_selec[i]!=0)
      {
        switch(dados_selec[i]) 
        {
          case 1: count_face1+=1; break;
          case 2: count_face2+=1; break;
          case 3: count_face3+=1; break;
          case 4: count_face4+=1; break;
          case 5: count_face5+=1; break;
          case 6: count_face6+=1; break;
        }
        printf("\nDado face '%d' selecionado. ",dados_selec[i]);
      } 
      else break;
    } 
          
        score_rod=0;
        switch(count_face1)
          {
      case 1: score_rod+=100; count_sequen1+=1; count_sequenC+=1; break;
      case 2: score_rod+=200; break;
      case 3: score_rod+=1000; break;
      case 4: score_rod+=2000; break;
      case 5: score_rod+=4000; break;
      case 6: score_rod+=8000; break;
      default: break;
    }
        switch(count_face2)
          {
      case 1: count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=200; break;
      case 4: score_rod+=400; break;
      case 5: score_rod+=800; break;
      case 6: score_rod+=1600; break;
      default: break;
    }
        switch(count_face3)
          {
      case 1: count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=300; break;
      case 4: score_rod+=600; break;
      case 5: score_rod+=1200; break;
      case 6: score_rod+=2400; break;
      default: break;
    }
        switch(count_face4)
          {
      case 1: count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=400; break;
      case 4: score_rod+=800; break;
      case 5: score_rod+=1600; break;
      case 6: score_rod+=3200; break;
      default: break;
    }
        switch(count_face5)
          {
      case 1: score_rod+=50; count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 2: score_rod+=100; break;
      case 3: score_rod+=500; break;
      case 4: score_rod+=1000; break;
      case 5: score_rod+=2000; break;
      case 6: score_rod+=4000; break;
      default: break;
    }
        switch(count_face6)
          {
      case 1: count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=600; break;
      case 4: score_rod+=1200; break;
      case 5: score_rod+=3200; break;
      case 6: score_rod+=6400; break;
      default: break;
    }
    
        if(count_sequenC==6)
          score_rod+=1500-50-100;
        else
          if(count_sequen1==5)
            score_rod+=500-50-100;
          else
            if(count_sequen2==5)
              score_rod+=750-50-100;
        
        printf("\nPontuação rodada: '%d' ",score_rod);
        puts("\n"); break;}
        
      }
      case 4: 
      {
        printf("\t\nRolagem com 2 dados\n");
        dados[dado_1]=(rand() % 6)+1; sleep(1); printf("1º Dado:%5d \n",dados[dado_1]);
        dados[dado_2]=(rand() % 6)+1; sleep(3/2); printf("2º Dado:%3d \n",dados[dado_2]);
        
        { for(i=0;i<=5;i++) 
          {
      printf(" - Selecione os dados: "); scanf("%d",&selec);
      if (selec==0)
        break;
      switch(selec) 
      {
        case 1: 
          dados_selec[count]=dados[dado_1]; 
          printf("1º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 2: 
          dados_selec[count]=dados[dado_2]; 
          printf("2º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 3: 
          dados_selec[count]=dados[dado_3]; 
          printf("3º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 4: 
          dados_selec[count]=dados[dado_4]; 
          printf("4º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 5: 
          dados_selec[count]=dados[dado_5]; 
          printf("5º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 6: 
          dados_selec[count]=dados[dado_6]; 
          printf("6º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 0: break;
        default: printf("\nOpção Inválida\n"); i-=1; 
      }
      
    }
        
        {count_face1=0; count_face5=0; count_face2=0; count_face3=0; count_face4=0; count_face6=0;
    count_sequen1=0; count_sequen2=0; count_sequenC=0;}

        for(i=0;i<=5;i++) 
          {
      
      if (dados_selec[i]!=0)
      {
        switch(dados_selec[i]) 
        {
          case 1: count_face1+=1; break;
          case 2: count_face2+=1; break;
          case 3: count_face3+=1; break;
          case 4: count_face4+=1; break;
          case 5: count_face5+=1; break;
          case 6: count_face6+=1; break;
        }
        printf("\nDado face '%d' selecionado. ",dados_selec[i]);
      } 
      else break;
    } 
          
        score_rod=0;
        switch(count_face1)
          {
      case 1: score_rod+=100; count_sequen1+=1; count_sequenC+=1; break;
      case 2: score_rod+=200; break;
      case 3: score_rod+=1000; break;
      case 4: score_rod+=2000; break;
      case 5: score_rod+=4000; break;
      case 6: score_rod+=8000; break;
      default: break;
    }
        switch(count_face2)
          {
      case 1: count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=200; break;
      case 4: score_rod+=400; break;
      case 5: score_rod+=800; break;
      case 6: score_rod+=1600; break;
      default: break;
    }
        switch(count_face3)
          {
      case 1: count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=300; break;
      case 4: score_rod+=600; break;
      case 5: score_rod+=1200; break;
      case 6: score_rod+=2400; break;
      default: break;
    }
        switch(count_face4)
          {
      case 1: count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=400; break;
      case 4: score_rod+=800; break;
      case 5: score_rod+=1600; break;
      case 6: score_rod+=3200; break;
      default: break;
    }
        switch(count_face5)
          {
      case 1: score_rod+=50; count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 2: score_rod+=100; break;
      case 3: score_rod+=500; break;
      case 4: score_rod+=1000; break;
      case 5: score_rod+=2000; break;
      case 6: score_rod+=4000; break;
      default: break;
    }
        switch(count_face6)
          {
      case 1: count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=600; break;
      case 4: score_rod+=1200; break;
      case 5: score_rod+=3200; break;
      case 6: score_rod+=6400; break;
      default: break;
    }
    
        if(count_sequenC==6)
          score_rod+=1500-50-100;
        else
          if(count_sequen1==5)
            score_rod+=500-50-100;
          else
            if(count_sequen2==5)
              score_rod+=750-50-100;
        
        printf("\nPontuação rodada: '%d' ",score_rod);
        puts("\n"); break;}
        
      }
      case 5: 
      {
        printf("\t\nRolagem com 1 dado\n");
        dados[dado_1]=(rand() % 6)+1; sleep(1); printf("1º Dado:%5d \n",dados[dado_1]);
        
        { for(i=0;i<=5;i++) 
          {
      printf(" - Selecione os dados: "); scanf("%d",&selec);
      if (selec==0)
        break;
      switch(selec) 
      {
        case 1: 
          dados_selec[count]=dados[dado_1]; 
          printf("1º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 2: 
          dados_selec[count]=dados[dado_2]; 
          printf("2º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 3: 
          dados_selec[count]=dados[dado_3]; 
          printf("3º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 4: 
          dados_selec[count]=dados[dado_4]; 
          printf("4º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 5: 
          dados_selec[count]=dados[dado_5]; 
          printf("5º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 6: 
          dados_selec[count]=dados[dado_6]; 
          printf("6º Dado selecionado (Face: %d)\n",dados_selec[count]); count+=1; break;
        case 0: break;
        default: printf("\nOpção Inválida\n"); i-=1; 
      }
      
    }
        
        {count_face1=0; count_face5=0; count_face2=0; count_face3=0; count_face4=0; count_face6=0;
    count_sequen1=0; count_sequen2=0; count_sequenC=0;}

        for(i=0;i<=5;i++) 
          {
      
      if (dados_selec[i]!=0)
      {
        switch(dados_selec[i]) 
        {
          case 1: count_face1+=1; break;
          case 2: count_face2+=1; break;
          case 3: count_face3+=1; break;
          case 4: count_face4+=1; break;
          case 5: count_face5+=1; break;
          case 6: count_face6+=1; break;
        }
        printf("\nDado face '%d' selecionado. ",dados_selec[i]);
      } 
      else break;
    } 
          
        score_rod=0;
        switch(count_face1)
          {
      case 1: score_rod+=100; count_sequen1+=1; count_sequenC+=1; break;
      case 2: score_rod+=200; break;
      case 3: score_rod+=1000; break;
      case 4: score_rod+=2000; break;
      case 5: score_rod+=4000; break;
      case 6: score_rod+=8000; break;
      default: break;
    }
        switch(count_face2)
          {
      case 1: count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=200; break;
      case 4: score_rod+=400; break;
      case 5: score_rod+=800; break;
      case 6: score_rod+=1600; break;
      default: break;
    }
        switch(count_face3)
          {
      case 1: count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=300; break;
      case 4: score_rod+=600; break;
      case 5: score_rod+=1200; break;
      case 6: score_rod+=2400; break;
      default: break;
    }
        switch(count_face4)
          {
      case 1: count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=400; break;
      case 4: score_rod+=800; break;
      case 5: score_rod+=1600; break;
      case 6: score_rod+=3200; break;
      default: break;
    }
        switch(count_face5)
          {
      case 1: score_rod+=50; count_sequen1+=1; count_sequen2+=1; count_sequenC+=1; break;
      case 2: score_rod+=100; break;
      case 3: score_rod+=500; break;
      case 4: score_rod+=1000; break;
      case 5: score_rod+=2000; break;
      case 6: score_rod+=4000; break;
      default: break;
    }
        switch(count_face6)
          {
      case 1: count_sequen2+=1; count_sequenC+=1; break;
      case 3: score_rod+=600; break;
      case 4: score_rod+=1200; break;
      case 5: score_rod+=3200; break;
      case 6: score_rod+=6400; break;
      default: break;
    }
    
        if(count_sequenC==6)
          score_rod+=1500-50-100;
        else
          if(count_sequen1==5)
            score_rod+=500-50-100;
          else
            if(count_sequen2==5)
              score_rod+=750-50-100;
        
        printf("\nPontuação rodada: '%d' ",score_rod);
        puts("\n"); break;}
        
      }
    }

  

}

int conta_string(char s[])
{
  int i=0;
  while(s[i]!='\0')
  {
    i++;
  }
  return i;
}

void string_aula(void)
{
  char Nome[100];
  while (1)
  {
    printf("Nome:");
    gets(Nome);
    if (Nome[0]=='\0')
      break;
    else
      printf("Letras totais %d\n",conta_string(Nome));
      printf("Nome: %s\n",Nome);
  }
}

void outro(void)
{
  
}