#ifndef envio_H_INCLUDED
#define envio_H_INCLUDED

typedef struct
{
    int idEnvio;
    char producto[128];
    int idCamion;
    char destino[128];
    int kmRecorridos;
    int tipoEntrega;
    int costo;
} envio;

envio* envio_new();
envio* envio_newParametros(char* idStr,char* nombreStr,char* idCamionStr, char* destinoStr, char* kmRecorridosStr, char* entregaStr);

int envio_getNextId();

int envio_setName(envio* this, char* producto);
int envio_getName(envio* this, char* producto);

int envio_setIdC(envio* this,int idCam);
int envio_getIdC(envio* this, int* idCam);

int envio_setDestino(envio* this, char* destino);
int envio_getDestino(envio* this, char* destino);

int envio_setKmRec(envio* this, int kmRec);
int envio_getKmRec(envio* this, int* kmRec);

int envio_setEntregas(envio* this, int entregas);
int envio_getEntregas(envio* this, int* entregas);

int envio_getcosto(envio* this, float* costo);
int envio_setcosto(envio* this, float costo);

int envio_setId(envio* this,int id);
int envio_getId(envio* this, int* id);

int envio_getAll(envio* this, int* id,char* nombre,int* idCamion,char* destino,int* kmRec, int* entregas);
int envio_getAllE(envio* this, int* id,char* nombre,int* idCamion,char* destino,int* kmRec, int* entregas, float* costo);

int calcMonto(void* envioA);

int envio_filtroLan(envio* this);
int envio_filtroAve(envio* this);
int envio_filtroCaba(envio* this);
int envio_filtroBand(envio* this);
int envio_filtroQui(envio* this);

int envio_sortByZone(void* thisA,void* thisB);


#endif // envio_H_INCLUDED
