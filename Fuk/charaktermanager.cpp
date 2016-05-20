#include "charaktermanager.h"
#include "charakter.h"

CharakterManager::CharakterManager()
{

}

void CharakterManager::insert(Charakter &charakter)
{
    charaktere.insert(getNewKey(),charakter);
}

void CharakterManager::update(Charakter &charakter)
{

}

void CharakterManager::drop(Charakter &charakter)
{

}

void CharakterManager::commit(){

}



int CharakterManager::getNewKey()
{
    return charaktere.size();
}

QHash<int, Charakter> *CharakterManager::getCharaktere()
{
    return &charaktere;
}
