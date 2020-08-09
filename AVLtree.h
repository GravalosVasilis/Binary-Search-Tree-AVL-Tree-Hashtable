#ifndef AVLTREE_H
#define AVLTREE_H

#include "TreeNode.h"
#include "BTS.h"


class AVLtree : public BTS///ΚΛΑΣΗ ΔΥΑΔΙΚΟΥ ΔΕΝΤΡΟΥ ΑΝΑΖΗΤΗΣΗΣ AVL
{
    public:
        TreeNode *head_AVL;///ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ
        AVLtree();


        virtual ~AVLtree();

        TreeNode *rightRotate(TreeNode *);///Η ΣΥΝΑΡΤΗΣΗ ΤΗΣ ΔΕΞΙΑΣ ΠΕΡΙΣΤΡΟΦΗΣ ΤΟΥ ΚΟΜΒΟΥ ΠΟΥ ΔΕΧΕΤΑΙ
        TreeNode *leftRotate(TreeNode *);///г ΣΥΝΑΡΤΗΣΗ ΤΗΣ ΑΡΙΣΤΕΡΗΣ ΠΕΡΙΣΤΡΟΦΗΣ ΤΟΥ ΚΟΜΒΟΥ ΠΟΥ ΔΕΧΕΤΑΙ
        int height(TreeNode *);///Η ΣΥΝΑΡΤΗΣΗ ΠΟΥ ΚΑΤΑΓΡΑΦΕΙ ΤΟ ΥΨΟΣ ΤΟΥ ΚΑΘΕ ΔΕΙΚΤΗ ΚΟΜΒΟΥ
        int getBalance(TreeNode *);///Η ΣΥΝΑΡΤΗΣΗ ΠΟΥ ΒΡΙΣΚΕΙ ΤΗ ΔΙΑΦΟΡΑ ΥΨΟΥΣ ΤΟΥ ΔΕΞΙΟΥ ΚΑΙ ΑΡΙΣΤΕΡΟΥ ΥΠΟΔΕΝΤΡΟΥ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΠΟΥ ΔΕΧΕΤΑΙ ΣΑΝ ΟΡΙΣΜΑ
        TreeNode *insert(string,TreeNode *);///Η ΣΥΝΑΡΤΗΣΗ ΠΟΥ ΕΙΣΑΓΕΙ ΣΥΜΒΟΛΟΣΕΙΡΕΣ ΣΤΗ ΔΟΜΗ ΤΟΥ ΔΥΑΔΙΚΟΥ ΔΕΝΤΡΟΥ ΑΝΑΖΗΤΗΣΗΣ AVL
        TreeNode *deleter(TreeNode *,string);///Η ΣΥΝΑΡΤΗΣΗ ΔΙΑΓΡΑΦΗΣ ΜΙΑΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΑΠΟ ΤΟ ΔΥΑΔΙΚΟ ΔΕΝΤΡΟ ΑΝΑΖΗΤΗΣΗΣ AVL

    protected:

    private:




};

#endif // AVLTREE_H
