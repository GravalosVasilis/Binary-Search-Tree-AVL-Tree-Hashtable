#ifndef TREENODE_H
#define TREENODE_H
#include <cstring>
#include <iostream>
using namespace std;


class TreeNode///ΚΛΑΣΗ TreeNode ΠΟΥ ΑΝΑΠΑΡΙΣΤΑ ΕΝΑΝ ΚΟΜΒΟ ΔΕΝΤΡΟΥ
{
    public:

        string str;///ΔΕΙΚΤΗΣ ΠΟΥ ΔΕΣΜΕΥΕΙ ΔΥΝΑΜΙΚΑ ΜΝΗΜΗ ΓΙΑ ΝΑ ΑΠΟΘΗΚΕΤΣΕΙ ΤΗΝ ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΚΟΜΒΟΥ
        TreeNode *leftstr;///ΔΕΙΚΤΗΣ Ο ΟΠΟΙΟΣ ΔΕΙΧΝΕΙ ΣΤΟΝ ΑΡΙΣΤΕΡΟ ΚΟΜΒΟ ΤΟΥ ΠΡΟΗΓΟΥΜΕΝΟΥ ΚΟΜΒΟΥ
        TreeNode *rightstr;///ΔΕΙΚΤΗΣ Ο ΟΠΟΙΟΣ ΔΕΙΧΝΕΙ ΣΤΟΝ ΔΕΞΙΟ ΚΟΜΒΟ ΤΟΥ ΠΡΟΗΓΟΥΜΕΝΟΥ ΚΟΜΒΟΥ
        int height;///ΜΕΤΑΒΛΗΤΗ Η ΟΠΟΙΑ ΓΙΑ ΚΑΘΕ ΚΟΜΒΟ ΑΠΟΘΗΚΕΥΕΙ ΤΟ ΥΨΟΣ ΤΟΥ(ΧΡΕΙΑΖΕΤΑΙ ΣΤΟ ΔΕΝΤΡΟ AVL)
        int pl;///ΜΕΤΑΒΛΗΤΗ Η ΟΠΟΙΑ ΑΠΟΘΗΚΕΥΕΙ ΤΟ ΠΛΗΘΟΣ ΤΗΣ ΚΑΘΕ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΟΤΑΝ ΕΙΣΑΓΕΤΑΙ ΚΑΙ ΟΤΑΝ  ΔΙΑΓΡΑΦΕΤΑΙ ΑΠΟ ΤΟ ΔΕΝΤΡΟ

        TreeNode();
        TreeNode(char *);
        virtual ~TreeNode();

    protected:

    private:




};

#endif // TREENODE_H
