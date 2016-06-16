#include "charaktermanager.h"
#include "charakter.h"
#include "charakterrepository.h"

CharakterManager::CharakterManager(){
    loadCharakterFromFile();
}

CharakterManager::~CharakterManager(){
}

Charakter& CharakterManager::findCharakter(int key){
    return charaktere.find(key).value();
}

void CharakterManager::addCharakterBeschreibung(QString name, QString beschreibung){
    currentCharakter = Ptr<Charakter>(new Charakter(name, beschreibung));
}

void CharakterManager::insert(Charakter &charakter){
    int key = getNewKey();
    charakter.setId(key);
    charaktere.insert(key,charakter);
    charakterRepository.saveCharakter(&charakter);
}

void CharakterManager::update(Charakter &charakter){
    charaktere.remove(charakter.getId());
    charaktere.insert(charakter.getId(),charakter);
    charakterRepository.saveCharakter(&charakter);
}

void CharakterManager::remove(Charakter &charakter){
    charaktere.remove(charakter.getId());
    charakterRepository.deleteCharakter(&charakter);
}

QHash<int,Charakter>* CharakterManager::read(){
    charakterRepository.readAllCharakters(&charaktere);
    return getCharaktere();
}

int CharakterManager::getNewKey(){
    return charaktere.size();
}

void CharakterManager::loadCharakterFromFile()
{

}

void CharakterManager::saveCharakterToFile()
{

}

QHash<int, Charakter> *CharakterManager::getCharaktere(){
    return &charaktere;
}

WeakPtr<Charakter> CharakterManager::getCurrentCharakter(){
    return currentCharakter;
}
