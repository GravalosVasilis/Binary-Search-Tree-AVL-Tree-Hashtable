#ifndef BTS_H
#define BTS_H
#include "TreeNode.h"
using namespace std;


class BTS///ΚΛΑΣΗ ΔΥΑΔΙΚΟΥ ΔΕΝΤΡΟΥ ΑΝΑΖΗΤΗΣΗΣ
{
    public:
        TreeNode *head;///ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ

        BTS();
        virtual ~BTS();

        virtual void insert(string);///Η ΣΥΝΑΡΤΗΣΗ ΠΟΥ ΕΙΣΑΓΕΙ ΣΥΜΒΟΛΟΣΕΙΡΕΣ ΣΤΗ ΔΟΜΗ ΤΟΥ ΔΥΑΔΙΚΟΥ ΔΕΝΤΡΟΥ ΑΝΑΖΗΤΗΣΗΣ
        void inOrder(TreeNode *);///Η ΣΥΝΑΡΤΗΣΗ ΕΝΔΟΔΙΑΤΑΞΗΣ ΤΟΥ ΔΥΑΔΙΚΟΥ ΔΕΝΤΡΟΥ ΑΝΑΖΗΤΗΣΗΣ
        void preOrder(TreeNode *);///Η ΣΥΝΑΡΤΗΣΗ ΠΡΟΔΙΑΤΑΞΗΣ ΤΟΥ ΔΥΑΔΙΚΟΥ ΔΕΝΤΡΟΥ ΑΝΑΖΗΤΗΣΗΣ
        void postOrder(TreeNode *);///Η ΣΥΝΑΡΤΗΣΗ ΜΕΤΑΔΙΑΤΑΞΗΣ ΤΟΥ ΔΥΑΔΙΚΟΥ ΔΕΝΤΡΟΥ ΑΝΑΖΗΤΗΣΗΣ
        bool search(TreeNode *,string);///Η ΣΥΝΑΡΤΗΣΗ ΑΝΑΖΗΤΗΣΗΣ ΜΙΑΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΤΟΥ ΔΥΑΔΙΚΟΥ ΔΕΝΤΡΟΥ ΑΝΑΖΗΤΗΣΗΣ
        virtual TreeNode *deleter(TreeNode *,string);///Η ΣΥΝΑΡΤΗΣΗ ΔΙΑΓΡΑΦΗΣ ΜΙΑΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΑΠΟ ΤΟ ΔΥΑΔΙΚΟ ΔΕΝΤΡΟ ΑΝΑΖΗΤΗΣΗΣ




    protected:

    private:



};
#endif // BTS_H
