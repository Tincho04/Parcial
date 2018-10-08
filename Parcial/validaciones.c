#include "validaciones.h"

int validarFloat(float x)
{
    int retorno;
    retorno=0;
    if(x>0)
    {
    retorno=1;
    }
    return retorno;
}

int getStr(char* stringb, int limit)
{
    int retorno=-1;
    char bufferStr[500];
    int tamanoDelBuffer;
    if(stringb != NULL && limit > 0)
    {
        fflush(stdin);
        gets(bufferStr);
        tamanoDelBuffer=strlen(bufferStr);
        if(tamanoDelBuffer != limit - 1 || bufferStr[limit - 2] == '\n')
        {
            bufferStr[tamanoDelBuffer-1]= '\0';
        }
        strncpy(stringb,bufferStr,limit);
        retorno=0;
    }
    return retorno;
}

int validarName(char* stringb, int limite)
{
    int retorno=0;
    int i;
    if(stringb != NULL && limite > 0)
    {
        retorno=1;
        for(i=0; i<limite && stringb[i]!= '\0'; i++)
        {
            if(tolower(stringb[i])<'a' || tolower(stringb[i])>'z')
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int validarImporte(char* valuer, int limite)
{
    int retorno=0;
    int i;
    if(valuer != NULL && limite > 0)
    {
        retorno=1;
        for( i = 0 ; i < limite && valuer[i] != '\0'; i++)
        {
            if(valuer[i] >= 'a' && valuer[i] <= 'z')
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
