#include "charaktermanager.h"
#include "charakter.h"

CharakterManager::CharakterManager(){

}

Charakter& CharakterManager::findCharakter(int key){
    return charaktere.find(key).value();
}

void CharakterManager::insert(Charakter &charakter)
{
    int key = getNewKey();
    charakter.setId(key);
    charaktere.insert(key,charakter);
}

void CharakterManager::update(Charakter &charakter)
{
    charaktere.insert(charakter.getId(),charakter);
}

void CharakterManager::drop(Charakter &charakter)
{
    charaktere.remove(charakter.getId());
}

void CharakterManager::commit(){
    // speichern der Helden in eine Datei
}


int CharakterManager::getNewKey()
{
    return charaktere.size();
}

QHash<int, Charakter> *CharakterManager::getCharaktere()
{
    return &charaktere;
}
