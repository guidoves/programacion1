int validarInt(char buffer[],int min,int max);
int cadena_entero(char numero[]);
int menu(char texto[],int,int);
void flush_in();
int validarString(char buffer[],int min,int max,int largo);
void setArray(x array[],int largo,int valor);
int validarChar(char buffer[], char x,char y);
int obtenerEspacioLibre(x array[],int largo);
int chequearActivos(x array[],int largo);
x* findById(x* pArray, int length,int id);
int esNumericoFlotante(char str[]);
int esSoloLetras(char str[]);
int esTelefono(char str[]);
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
void cleanStdin(void);
int getStringNumeros(char mensaje[],char input[]);
void getString(char mensaje[],char input[]);
int esNumerico(char str[]);


