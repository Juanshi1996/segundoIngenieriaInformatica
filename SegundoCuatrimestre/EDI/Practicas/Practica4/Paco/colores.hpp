#define DEFAULT 	<<"\E[1m\e[0m"<<

//Text colors
#define tblack "\E[30m" // Texto color negro
#define tred "\E[31m" // Texto color rojo
#define twhite "\E[37m" // Texto color blanco
#define tnormal "\e[0m" // Texto predeterminado

//Back colors
#define fred "\E[41m" // Fondo color rojo
#define fblue "\E[44m" // Fondo color azul

//text attributes
#define restaurar "\E[m" // Resetiar todo
#define bold "\E[1m" // negrita
#define italic "\E[3m" // cursiva
#define underline "\E[4m" // subrayado
#define nunderline "\E[24m" // no subrayado
#define LUGAR(x,y)   printf("\033[%d;%dH",x,y)
#define BORRAR       printf("\33[2J") 
#define APAGA        printf("%c[0m",27)
#define INVERSO      printf("%c[7m",27)
#define SUBRAYADO    printf("%c[4m",27)
#define INTENSIDAD   printf("%c[1m",27)
