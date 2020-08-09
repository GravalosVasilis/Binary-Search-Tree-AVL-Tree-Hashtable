#ifndef HT_H
#define HT_H
#include <iostream>
#include <cstring>
using namespace std;

class HT
{
    public:
        HT();///<-Ενα κενος κατασκευαστης
        HT(int );///<-Ο κατασκευαστης οπου περναμε σαν ορισμα τον αριθμο των λεξεω που υπαρχουν εχωντας αφεραισει της διπλες και ουτο καθε εξης
        virtual ~HT(); ///<-Κατασροφεας
        void setcounter(int value){ counter = value; }
        void settemp1(int value){ temp1 = value; }
        void settemp2(int value){ temp2 = value; }

        void Insert(string); ///<-Η συναρτηση Insert που εκχωρουμε μια μια της λεξης απο την main ετσι ωστε να μπουν στον πινακα κατακερματισμου
        bool Search(string); ///<-Η συναρτηση Search οπου ερχονται η λεξης μια μια για να δουμε ααν υπαρχουν στον πινακα

    protected:

    private:
        int temp1,temp2,counter;
        string *ht;///<-Ο πινακας κατακερματισμου οπυ θα αποθηκεονατι η λεξης
        int h;
        int fragmentation(char );///<-Η συναρτησβ οπου θα κατακερματιζονται η λεξης με σκοπο να μπουν στον πινακα στην σωστη θεση
};

#endif // HT_H
