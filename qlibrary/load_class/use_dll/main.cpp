#include "Interface.h"
#include <QLibrary>
#include <QDebug>

int main(){
    typedef Interface *(*vender_add)();

    QLibrary library("./libVenderAdd.so");
    if(library.load()){
        vender_add VenderAdd = (vender_add)library.resolve("GetInstance");
        if(VenderAdd){
            Interface *vender = VenderAdd();
            qDebug() << vender->Add(100);
        }
        else{
            qWarning() << library.errorString() << " func error";
        }
    }
    else{
      qWarning() << library.errorString() << " fail to load lib";
    }

    return 0;
}