#ifndef vend_H_INCLUDED
#define vend_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int nivel;
    int prodVendidos;
    float montoVendido;
    float comision;
} vend;

vend* vend_new();
vend* vend_newParametros(char* idStr,char* nombreStr,char* NivelStr, char* prodVendidosStr, char* montoVendidoStr);
int vend_delete(vend* this);

int vend_getNextId();
// vend* vend_IdGen(char* nombre,int horasTrabajadas,int sueldo);

int vend_setId(vend* this,int id);
int vend_getId(vend* this,int* id);

int vend_setLevel(vend* this,int nivel);
int vend_getLevel(vend* this,int* nivel);

int vend_setName(vend* this,char* nombre);
int vend_getName(vend* this,char* nombre);

int vend_setSold(vend* this, int prodVendidos);
int vend_getSold(vend* this, int* prodVendidos);

int vend_setCash(vend* this, float montoVendido);
int vend_getCash(vend* this, float* montoVendido);

int vend_getComi(vend* this, float* comision);
int vend_setComi(vend* this, float comision);

int vend_getAll(vend* this,char* nombre,int* nivel,int* prodVendidos,float* montoVendido,int* id);
int vend_getAllC(vend* this,char* nombre,int* nivel,int* prodVendidos,float* montoVendido,float* comision,int* id);

int calcComision(void* vendA);

int vend_filtroJr(vend* this);
int vend_filtroSt(vend* this);
int vend_filtroEx(vend* this);

int vend_sortByName(void* thisA,void* thisB);
int vend_sortByCom(void* thisA,void* thisB);



#endif // vend_H_INCLUDED
