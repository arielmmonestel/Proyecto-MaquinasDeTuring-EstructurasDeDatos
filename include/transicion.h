#ifndef TRANSICION_H
#define TRANSICION_H


class transicion
{
    public:
        transicion(string pSiguienteEstado, string pSimboloAPoner; string pDireccion) {
        siguienteEstado = pSiguienteEstado;
        simboloAPoner = pSimboloAPoner;
        direccion = pDireccion;
        }
        virtual ~transicion() {}
    protected:
    private:
        string siguienteEstado;
        string simboloAPoner;
        string direccion;
};

#endif // TRANSICION_H
