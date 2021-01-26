///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///            Projeto Um Caderno  Virtual de Receitas Culinárias           ///
///                Developed by  @R.Rabi - Jan, 2021                        ///
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

void menuPrincipal (void);

void menuSobre(void);
int main(void) {
    menuSobre();
    return 0;
}
void menuSobre(void) {
   system("cls");
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
        printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
        printf("///               Departamento de Computação e Tecnologia                   ///\n");
        printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
        printf("///            Projeto Um Caderno Virtual de Receitas Culinárias            ///\n");
        printf("///              = == ==       RECIPES       = == ==                        ///\n");
        printf("///                Developed by  @Renildo Rabi - Jan, 2021                  ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///  = == == SIG-Recipes: Um Caderno Virtual de Receitas Culinárias == == = ///\n");
        printf("///                                                                         ///\n");
        printf("///  Fábricas de produtos alimentícios, restaurantes, lanchonetes,          ///\n");
        printf("///  padarias, ou até mesmo usuários domésticos necessitam de receita       ///\n");
        printf("///  para conduzir a preparação de determinados alimentos.                  ///\n");
        printf("///  A principio o objetivo do projeto é adicionar receitas de comidas,     ///\n");
        printf("///  procurar os tipos de pratos por ingrediente,saber os custos e          ///\n");
        printf("///  quantidades de ingredientes,a otimização do estoque e a categorização  ///\n");
        printf("///  das receitas.                                                          ///\n");
        printf("///                                                                         ///\n");
        printf("///      Em desenvolvimento pelo aluno Renildo Rabi Vale Dos Santos         ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
}