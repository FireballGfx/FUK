#include "charaktermanager.h"
#include "charakter.h"

CharakterManager::CharakterManager()
{

}

void CharakterManager::add(Charakter &charakter)
{
    charaktere.insert(getNewKey(),charakter);
}

void CharakterManager::update(Charakter &charakter)
{

}

void CharakterManager::drop(Charakter &charakter)
{

}



int CharakterManager::getNewKey()
{
    return charaktere.size();
}

QHash<int, Charakter> *CharakterManager::getCharaktere()
{
    return &charaktere;
}
