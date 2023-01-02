#include <iostream>
#include <string.h>
#include "InterfaceClass.h"
#include "ClassicToy.h"
#include "EducativeToy.h"
#include "ElectronicToy.h"
#include "ModernToy.h"
#include "MyExceptions.h"
InterfaceMenu *InterfaceMenu::singleTone = nullptr;
InterfaceMenu *InterfaceMenu::getInstance()
{
    if (singleTone == nullptr)
        singleTone = new InterfaceMenu();
    return singleTone;
}
void InterfaceMenu::printMessage()
{
    std::cout << "Tema numarul 3 \n Virtopeanu Sebastian-Filip\n CTI, GRUPA 264\n";
    std::cout << "In aceasta aplicatie puteti configura cadouri pentru diferite persoane. Un cadou poate contone mai multe jucarii, fiecare jucarie este de un tip anume.";
    std::cout << "\n Tipurile de jucarii sunt:\n ClassicToy- pentru acest tip de jucarie se cunoaste in plus materialul si culoarea";
    std::cout << "\n ElectronicToy - pentru acest tip de jucarie se cunoaste in plus numarul de baterii";
    std::cout << "\n EducativeToy - pentru acest tip de jucarie se cunoaste in plus abilitatea dezvoltata";
    std::cout << "\n ModernToy - un ModernToy este atat un ElectronicToy cat si un EducativeToy, in plus se cunoaste si brandul\n";
}
void InterfaceMenu::start()
{

    std::cout << "*******************************************CONFIGURARE CADOU*******************************************" << endl;
    do
    {
        std::cout << "1.Start configurare cadou\n2.Printare cadou\n3.Creeaza un cadou default pe care il poti alege mai tarziu in configurare\n4.Adaugare cadou nou\n5.Stergere cadou\n6.Modificare cadou existent\n7.Afisare informatii generale\n8.Printare toate cadourile\n9.Clear\n0.Exit\n";
        std::cin >> i;
        switch (i)
        {
        case 10:
        {
            const bool x = (*allGifts[0] == *allGifts[1]);
            std::cout << x;

            break;
        }
        case 0:
            std::cout << "Iesire interfata";
            break;

        case 1:
        { // Start configurare cadou
            if (allGifts.size() == 0)
            {

                allGifts.push_back(std::make_unique<Gift>());
                std::cin >> *(allGifts[0]);
                // dynamic_cast<ClassicToy *>((*allGifts[0]).getToys()[0].get())->playSound();
                // cout << "Jucarie:" << *dynamic_cast<ClassicToy *>(allGifts[0]->getToys()[0]) << endl;
                // ElectronicToy *x = dynamic_cast<ElectronicToy *>((*allGifts[0]).getToys()[0]->clone());
                // x->setAge(20000);
                // std::cout << "Jucarie:" << x->getAge() << endl;
                // std::cout << (*allGifts[0]).getToys()[0]->getAge();
            }
            else
                std::cout << "Ati configurat deja primul cadou" << endl;
            break;
        }

        case 2:
        { // Printare cadou
            if (allGifts.size() == 0)
                std::cout << "Configurati primul cadou\n";
            else
            {
                int j;
                std::cout << "Ce cadou vrei sa afisezi?\n";
                std::cin >> j;

                if (j > allGifts.size())
                    throw GiftNotFound();
                std::cout << *allGifts[j - 1];
            }

            break;
        }
        case 3:
        { // Creeaza un cadou default pe care il poti alege mai tarziu in configurare
            string aux;
            int i, numarJucarii;
            ToyType toyType;
            std::vector<shared_ptr<BToyClass>>
                _toys;
            std::cout
                << "Ce nume ar trb sa aiba cadoul default?\n";
            std::cin >> aux;
            giftBuilder.setName(aux);
            cout << "Ce destinatie ar trb sa aiba cadoul default?\n";
            std::cin >> aux;
            giftBuilder.setDestination(aux);
            std::cout << "Pentru cine ar trb sa aiba cadoul default?\n";
            cin >> aux;
            giftBuilder.setPersonName(aux);
            std::cout << "Cate jucarii vrei sa adaugi?\n";
            std::cin >> numarJucarii;
            for (int k = 0; k < numarJucarii; k++)
            {

                std::cout << "Ce jucarie vrei sa adaugi?\n1.ClassicToy\n2.ElectronicToy\n3.EducativeToy\n4.ModernToy\n";
                std::cin >> i;
                switch (i)
                {
                case 1:
                    toyType = ToyType::Classic;
                    break;
                case 2:
                    toyType = ToyType::Electronic;
                    break;
                case 3:
                    toyType = ToyType::Educative;
                    break;
                case 4:
                    toyType = ToyType::Modern;
                    break;
                default:
                    throw ToyTypeExceptions();
                }
                switch (toyType)
                {
                case ToyType::Classic:
                {
                    _toys.push_back(make_shared<ClassicToy>());
                    _toys[k]->read(cin);
                    break;
                }
                case ToyType::Electronic:
                {
                    _toys.push_back(make_shared<ElectronicToy>());
                    _toys[k]->read(cin);
                    break;
                }
                case ToyType::Educative:
                {
                    _toys.push_back(make_shared<EducativeToy>());
                    _toys[k]->read(cin);
                    break;
                }
                case ToyType::Modern:
                {
                    _toys.push_back(make_shared<ModernToy>());
                    _toys[k]->read(cin);
                    break;
                }

                default:
                    throw ToyTypeExceptions();
                    break;
                }
            }
            giftBuilder.setToys(_toys, numarJucarii); // adaugare jucarii
            break;
        }
        case 4:
        { // Adaugare cadou nou
            int i;
            std::cout << "Vreti sa utilizati cadoul default?\n1.Da\n2.Nu\n ";
            std::cin >> i;
            if (i == 1)
            {
                allGifts.push_back(make_unique<Gift>(giftBuilder.build()));
            }
            else // adaugare cadou nou
            {
                allGifts.push_back(make_unique<Gift>());
                std::cin >> *(allGifts[allGifts.size() - 1]);
            }
            break;
        }

        case 5:
        { // Stergere cadou
            int j;
            std::cout << "Ce cadou doriti sa stergeti?\n";
            std::cin >> j;
            if (j > allGifts.size())
                throw GiftNotFound();

            allGifts.erase(allGifts.begin() + j - 1);

            break;
        }
        case 6:
        { // Modificare cadou existent
            int giftNumber;
            std::cout << "Ce cadou vreti sa modificati?\n";
            std::cin >> giftNumber;
            if (giftNumber > allGifts.size())
                throw GiftNotFound();
            allGifts[giftNumber - 1]->updateGift();
            break;
        }
        case 7:
        { // Afisare informatii generale
            int j;
            std::cout << "Pentru ce cadou vreti afisate informatiile generalizat?\n";
            std::cin >> j;
            if (j > allGifts.size())
                throw GiftNotFound();
            allGifts[j - 1]->summariseGift();
            break;
        }
        case 8:
        { // Printare toate cadourile
            for (int i = 0; i < allGifts.size(); i++)
            {
                std::cout << *allGifts[i];
                std::cout << endl;
            }
            break;
        }
        case 9:
        { // Clear
            system("clear");
            break;
        }
        default:
            break;
        }
    } while (i != 0);
}