#include "AVLtree.h"
#include <cstring>
#include<iostream>
using namespace std;
AVLtree::AVLtree()
{
    head_AVL=NULL;///ΟΤΑΝ ΠΑΡΑΓΕΤΑΙ Ο ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ ΑΡΧΙΚΑ ΔΕΙΧΝΕΙ ΣΕ NULL
}

TreeNode *AVLtree::rightRotate(TreeNode *y)
{
    TreeNode *x=y->leftstr;///ΔΗΜΙΟΥΡΓΩ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΣΤΟΝ ΟΠΟΙΟ ΕΚΧΩΡΩ ΤΟ ΑΡΙΣΤΕΡΟ ΥΠΟΔΕΝΤΡΟ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
    TreeNode *t2=x->rightstr;///ΔΗΜΙΟΥΡΓΩ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΣΤΟΝ ΟΠΟΙΟ ΕΚΧΩΡΩ ΤΟ ΔΕΞΙΟ ΥΠΟΔΕΝΤΡΟ , ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΥΠΟΔΕΝΤΡΟΥ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ

    x->rightstr=y;///ΣΤΟΝ ΔΕΞΙ ΔΕΙΚΤΗ ΚΟΜΒΟΥ, ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ,ΕΚΧΩΡΩ ΤΟΝ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΑΤΟΣ
    y->leftstr=t2;///ΣΤΟΝ ΑΡΙΣΤΕΡΟ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ,ΕΚΧΩΡΩ ΤΟ ΔΕΞΙΟ ΥΠΟΔΕΝΤΡΟ , ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΥΠΟΔΕΝΤΡΟΥ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ

    if(height(y->leftstr)>height(y->rightstr))///ΕΚΧΩΡΩ ΣΤΟ ΥΨΟΣ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΤΟ ΜΕΓΑΛΥΤΕΡΟ ΑΠΟ ΤΑ ΥΨΗ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΚΑΙ ΤΟΥ ΔΕΞΙΟΥ ΥΠΟΔΕΝΤΡΟΥ(ΤΑ ΥΠΟΔΕΝΤΡΑ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ)
        y->height=height(y->leftstr)+1;
    else
        y->height=height(y->rightstr)+1;

    if(height(x->leftstr)>height(x->rightstr))///ΕΚΧΩΡΩ ΣΤΟ ΥΨΟΣ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ , ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ, ΤΟ ΜΕΓΑΛΥΤΕΡΟ ΑΠΟ ΤΑ ΥΨΗ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΚΑΙ ΤΟΥ ΔΕΞΙΟΥ ΥΠΟΔΕΝΤΡΟΥ(ΤΑ ΥΠΟΔΕΝΤΡΑ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ)
        x->height=height(x->leftstr)+1;
    else
        x->height=height(x->rightstr)+1;

    return x;///ΕΠΙΣΤΡΕΦΩ ΤΟΝ ΔΕΙΚΤΗ ΚΟΜΒΟΥ Χ

    ///ΟΥΣΙΑΣΤΙΚΑ Η ΔΕΞΙΑ ΠΕΡΙΣΤΡΟΦΗ ΔΕΧΕΤΑΙ ΕΝΑΝ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΠΟΥ ΧΡΕΙΑΖΕΤΑΙ ΠΕΡΙΣΤΡΟΦΗ ΕΞΑΙΤΙΑΣ ΤΟΥ ΥΨΟΥΣ ΤΟΥ
    ///ΑΠΟΘΗΚΕΥΕΙ ΤΟ ΔΕΞΙ ΥΠΟΔΕΝΤΡΟ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΥΠΟΔΕΝΤΡΟΥ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
    ///ΘΕΤΕΙ ΣΑΝ ΑΡΧΙΚΟ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΝ ΑΡΙΣΤΕΡΟ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
    ///ΚΑΙ ΣΕ ΑΥΤΟΝ ΤΟΝ ΔΕΙΚΤΗ ΕΚΧΩΡΕΙ ΣΑΝ ΑΡΙΣΤΕΡΟ ΥΠΟΔΕΝΤΡΟ ΤΟ ΑΡΙΣΤΕΡΟ ΥΠΟΔΕΝΤΡΟ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΥΠΟΔΕΝΤΡΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ, ΚΑΙ ΣΑΝ ΔΕΞΙ ΥΠΟΔΕΝΤΡΟ ΟΛΟ ΤΟ ΔΕΞΙ ΥΠΟΔΕΝΤΡΟ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΣΤΟ ΟΠΟΙΟ ΕΧΕΙ ΚΑΤΑΧΩΡΗΘΕΙ ΣΤΑ ΑΡΙΣΤΕΡΑ ΤΗΣ ΡΙΖΑΣ ΤΟΥ ΤΟ ΔΕΞΙ ΥΠΟΔΕΝΤΡΟ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΥΠΟΔΕΝΤΡΟΥ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ

}
TreeNode *AVLtree::leftRotate(TreeNode *x)
{

    TreeNode *y=x->rightstr;///ΔΗΜΙΟΥΡΓΩ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΣΤΟΝ ΟΠΟΙΟ ΕΚΧΩΡΩ ΤΟ ΔΕΞΙΟ ΥΠΟΔΕΝΤΡΟ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
    TreeNode *t2=y->leftstr;///ΔΗΜΙΟΥΡΓΩ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΣΤΟΝ ΟΠΟΙΟ ΕΚΧΩΡΩ ΤΟ ΑΡΙΣΤΕΡΟ ΥΠΟΔΕΝΤΡΟ , ΤΟΥ ΔΕΞΙΟΥ ΥΠΟΔΕΝΤΡΟΥ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ

    y->leftstr=x;///ΣΤΟΝ ΑΡΙΣΤΕΡΟ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΔΕΞΙΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ,ΕΚΧΩΡΩ TON ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
    x->rightstr=t2;///ΣΤΟΝ ΔΕΞΙ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ,ΕΚΧΩΡΩ ΤΟ ΑΡΙΣΤΕΡΟ ΥΠΟΔΕΝΤΡΟ ΤΟΥ ΔΕΞΙΟΥ ΥΠΟΔΕΝΤΡΟΥ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΑΤΟΣ

    if(height(y->leftstr)>height(y->rightstr))///ΕΚΧΩΡΩ ΣΤΟ ΥΨΟΣ ΤΟΥ ΔΕΞΙΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ , ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ, ΤΟ ΜΕΓΑΛΥΤΕΡΟ ΑΠΟ ΤΑ ΥΨΗ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΚΑΙ ΤΟΥ ΔΕΞΙΟΥ ΥΠΟΔΕΝΤΡΟΥ(ΤΑ ΥΠΟΔΕΝΤΡΑ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΔΕΞΙΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ)
        y->height=height(y->leftstr)+1;
    else
        y->height=height(y->rightstr)+1;

    if(height(x->leftstr)>height(x->rightstr))///ΕΚΧΩΡΩ ΣΤΟ ΥΨΟΣ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΤΟ ΜΕΓΑΛΥΤΕΡΟ ΑΠΟ ΤΑ ΥΨΗ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΚΑΙ ΤΟΥ ΔΕΞΙΟΥ ΥΠΟΔΕΝΤΡΟΥ(ΤΑ ΥΠΟΔΕΝΤΡΑ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ)
        x->height=height(x->leftstr)+1;
    else
        x->height=height(x->rightstr)+1;

    return y;///ΕΠΙΣΤΡΕΦΩ ΤΟΝ ΔΕΙΚΤΗ ΚΟΜΒΟΥ Υ

    ///ΟΥΣΙΑΣΤΙΚΑ Η ΑΡΙΣΤΕΡΗ ΠΕΡΙΣΤΡΟΦΗ ΔΕΧΕΤΑΙ ΕΝΑΝ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΠΟΥ ΧΡΕΙΑΖΕΤΑΙ ΠΕΡΙΣΤΡΟΦΗ ΕΞΑΙΤΙΑΣ ΤΟΥ ΥΨΟΥΣ ΤΟΥ
    ///ΑΠΟΘΗΚΕΥΕΙ ΤΟ ΑΡΙΣΤΕΡΟ ΥΠΟΔΕΝΤΡΟ ΤΟΥ ΔΕΞΙΟΥ ΥΠΟΔΕΝΤΡΟΥ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
    ///ΘΕΤΕΙ ΣΑΝ ΑΡΧΙΚΟ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΝ ΔΕΞΙΟ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
    ///ΚΑΙ ΣΕ ΑΥΤΟΝ ΤΟΝ ΔΕΙΚΤΗ ΕΚΧΩΡΕΙ ΣΑΝ ΔΕΞΙ ΥΠΟΔΕΝΤΡΟ ΤΟ ΑΡΙΣΤΕΡΟ ΥΠΟΔΕΝΤΡΟ ΤΟΥ ΔΕΞΙΟΥ ΥΠΟΔΕΝΤΡΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ, ΚΑΙ ΣΑΝ ΑΡΙΣΤΕΡΟ ΥΠΟΔΕΝΤΡΟ ΟΛΟ ΤΟ ΑΡΙΣΤΕΡΟ ΥΠΟΔΕΝΤΡΟ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΣΤΟ ΟΠΟΙΟ ΕΧΕΙ ΚΑΤΑΧΩΡΗΘΕΙ ΣΤΑ ΔΕΞΙΑ ΤΗΣ ΡΙΖΑΣ ΤΟΥ ΤΟ ΑΡΙΣΤΕΡΟ ΥΠΟΔΕΝΤΡΟ ΤΟΥ ΔΕΞΙΟΥ ΥΠΟΔΕΝΤΡΟΥ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ


}

int AVLtree::height(TreeNode *N)///Η ΣΥΝΑΡΤΗΣΗ ΠΟΥ ΚΑΤΑΓΡΑΦΕΙ ΤΟ ΥΨΟΣ ΤΟΥ ΚΑΘΕ ΔΕΙΚΤΗ ΚΟΜΒΟΥ
{
    if (N == NULL)///ΑΝ Ο ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΔΕΙΧΝΕΙ ΣΕ NULL
        return 0;///ΕΠΙΣΤΡΕΦΕΙ 0
    return N->height;///ΑΛΛΙΩΣ ΕΠΙΣΤΡΕΦΕΙ ΤΟ ΥΨΟΣ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
}

TreeNode* AVLtree::insert(string newstr, TreeNode *t_node)///Η ΣΥΝΑΡΤΗΣΗ ΠΟΥ ΕΙΣΑΓΕΙ ΣΥΜΒΟΛΟΣΕΙΡΕΣ ΣΤΗ ΔΟΜΗ ΤΟΥ ΔΥΑΔΙΚΟΥ ΔΕΝΤΡΟΥ ΑΝΑΖΗΤΗΣΗΣ AVL
{
    if(newstr[0]!=' ')///ΕΠΕΙΔΗ ΣΤΟΝ ΠΙΝΑΚΑ ΥΠΑΡΧΟΥΝ ΚΑΙ ΚΕΝΕΣ ΣΥΜΒΟΛΟΣΕΙΡΕΣ ΟΙ ΟΠΟΙΕΣ ΔΕΝ ΕΚΧΩΡΟΥΝΤΑΙ ΣΤΙΣ ΔΟΜΕΣ
    {


        if(t_node == NULL)///ΑΝ Ο ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΔΕΙΧΝΕΙ ΣΕ NULL ΤΟΤΕ
        {
            t_node = new TreeNode;///ΔΗΜΙΟΥΡΓΩ ΕΝΑΝ ΠΡΟΣΩΡΙΝΟ ΔΕΙΚΤΗ ΚΟΜΒΟΥ
            t_node->str = newstr;///ΑΝΤΙΓΡΑΦΩ ΣΤΟΝ ΔΕΙΚΤΗ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΑΥΤΟΥ ΤΟΥ ΠΡΟΣΩΡΙΝΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΗΝ ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
            t_node->height = 0;///ΓΙΑ ΥΨΟΣ ΤΟΥ ΠΡΟΣΩΡΙΝΟΥ ΚΟΜΒΟΥ ΑΡΧΙΚΟΠΟΙΩ ΣΕ ΜΗΔΕΝ
            t_node->leftstr = t_node->rightstr = NULL;///Ο ΑΡΙΣΤΕΡΟΣ ΚΑΙ Ο ΔΕΞΙΟΣ ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ ΔΕΙΧΝΟΥΝ ΣΕ NULL
            t_node->pl+=1;
        }
        else if(newstr < t_node->str)///ΑΝ Η ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΕΙΝΑΙ ΜΙΚΡΟΤΕΡΗ ΤΗΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΤΟΤΕ
        {
            t_node->leftstr = insert(newstr, t_node->leftstr);
            if(height(t_node->leftstr) - height(t_node->rightstr) == 2)///ΑΝ Η ΔΙΑΦΟΡΑ ΥΨΟΥΣ ΤΩΝ ΥΠΟΔΕΝΤΡΩΝ ΕΙΝΑΙ 2 ΤΟΤΕ
            {
                if(newstr < t_node->leftstr->str)///ΑΝ Η ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΕΙΝΑΙ ΜΙΚΡΟΤΕΡΗ ΤΗΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΚΟΜΒΟΥ
                    t_node = rightRotate(t_node);/// ΚΑΝΩ ΜΙΑ Left Left ΠΕΡΙΣΤΡΟΦΗ ΤΟΥ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
                else
                {
                    /// ΚΑΝΩ ΜΙΑ Left Right ΠΕΡΙΣΤΡΟΦΗ ΤΟΥ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
                    t_node->leftstr = leftRotate(t_node->leftstr);
                    t_node = rightRotate(t_node);
                }
            }
        }
        else if(newstr > t_node->str)///ΑΝ Η ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΕΙΝΑΙ ΜΕΓΑΛΥΤΕΡΗ ΤΗΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΤΟΤΕ
        {
            t_node->rightstr = insert(newstr, t_node->rightstr);
            if(height(t_node->leftstr) - height(t_node->rightstr) == -2)///ΑΝ Η ΔΙΑΦΟΡΑ ΥΨΟΥΣ ΤΩΝ ΥΠΟΔΕΝΤΡΩΝ ΕΙΝΑΙ 2 ΤΟΤΕ
            {
                if(newstr > t_node->rightstr->str)///ΑΝ Η ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΕΙΝΑΙ ΜΕΓΑΛΥΤΕΡΗ ΤΗΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΤΟΥ ΔΕΞΙΟΥ ΚΟΜΒΟΥ
                    t_node = leftRotate(t_node);/// ΚΑΝΩ ΜΙΑ Right Right ΠΕΡΙΣΤΡΟΦΗ ΤΟΥ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
                else
                {
                    /// ΚΑΝΩ ΜΙΑ Right Left  ΠΕΡΙΣΤΡΟΦΗ ΤΟΥ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
                    t_node->rightstr = rightRotate(t_node->rightstr);
                    t_node = leftRotate(t_node);
                }
            }
        }
        else///ΑΝ Η ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΕΙΝΑΙ ΙΣΗ ΜΕ ΤΗΝ ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΤΟΤΕ
        {
            t_node->pl+=1;
        }

        if(height(t_node->leftstr)> height(t_node->rightstr))///ΚΑΤΑΓΡΑΦΩ ΣΑΝ ΥΨΟΣ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΤΟ ΜΕΓΑΛΥΤΕΡΟ ΑΠΟ ΤΑ ΥΨΗ ΤΟΥ ΑΡΙΣΤΡΕΡΟΥ ΤΟΥ ΚΑΙ ΔΕΞΙΟΥ ΤΟΥ ΥΠΟΔΕΝΤΡΟΥ , ΚΑΙ ΤΟ ΑΥΞΑΝΩ ΚΑΤΑ 1
            t_node->height=height(t_node->leftstr) +1;
        else
            t_node->height=height(t_node->rightstr) +1;
    }
    return t_node;


}



int AVLtree::getBalance(TreeNode *N)///Η ΣΥΝΑΡΤΗΣΗ ΠΟΥ ΒΡΙΣΚΕΙ ΤΗ ΔΙΑΦΟΡΑ ΥΨΟΥΣ ΤΟΥ ΔΕΞΙΟΥ ΚΑΙ ΑΡΙΣΤΕΡΟΥ ΥΠΟΔΕΝΤΡΟΥ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΠΟΥ ΠΕΡΝΑΙ ΣΑΝ ΟΡΙΣΜΑ
{
    if (N == NULL)///ΑΝ Ο ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΔΕΙΧΝΕΙ ΣΕ NULL
        return 0;///ΕΠΙΣΤΡΕΦΕΙ 0
    return height(N->leftstr) -  height(N->rightstr);///ΑΛΛΙΩΣ ΕΠΙΣΤΡΕΦΕΙ ΤΗ ΔΙΑΦΟΡΑ ΤΟΥ ΥΨΟΥΣ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΥΠΟΔΕΝΤΡΟΥ ΜΕ ΤΟ ΔΕΞΙΟ ΥΠΟΔΕΝΤΡΟ
}
TreeNode* AVLtree::deleter(TreeNode *root, string delete_str)///Η ΣΥΝΑΡΤΗΣΗ deleter , ΔΕΧΕΤΑΙ ΣΑΝ ΟΡΙΣΜΑΤΑ ΕΝΑΝ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΚΑΙ ΜΙΑ ΣΥΜΒΟΛΟΣΕΙΡΑ
{

    if (root == NULL)///ΑΝ Ο ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ ΔΕΙΧΝΕΙ ΣΕ NULL ΤΟΤΕ
        return root;///ΕΠΙΣΤΡΕΦΩ Ο ΔΕΙΚΤΗΣ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
    if(root->str>delete_str)///ΑΝ Η ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΚΟΜΒΟΥ ΕΙΝΑΙ ΜΕΓΑΛΥΤΕΡΗ ΑΠΟ ΤΗΝ ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΤΟΤΕ
        root->leftstr = deleter(root->leftstr, delete_str);///ΚΑΛΕΙΤΕ ΑΝΑΔΡΟΜΙΚΑ Η ΣΥΝΑΡΤΗΣΗ ΜΕ ΟΡΙΣΜΑΤΑ, ΤΟΝ ΔΕΙΚΤΗ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΚΟΜΒΟΥ ΤΟΥ ΠΡΟΗΓΟΥΜΕΝΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΚΑΙ ΤΗΝ ΣΥΜΒΟΛΟΣΕΙΡΑ ΠΟΥ ΘΕΛΟΥΜΕ ΝΑ ΔΙΑΓΡΑΨΟΥΜΕ,ΚΑΙ ΤΟ ΑΠΟΤΕΛΕΣΜΑ ΤΟ ΑΠΟΘΗΚΕΥΟΥΜΕ ΣΤΟΝ ΔΕΙΚΤΗ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΚΟΜΒΟΥ
    else if(root->str<delete_str)///ΑΝ Η ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΚΟΜΒΟΥ ΕΙΝΑΙ ΜΙΚΡΟΤΕΡΗ ΑΠΟ ΤΗΝ ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΤΟΤΕ
        root->rightstr = deleter(root->rightstr, delete_str);///ΚΑΛΕΙΤΕ ΑΝΑΔΡΟΜΙΚΑ Η ΣΥΝΑΡΤΗΣΗ ΜΕ ΟΡΙΣΜΑΤΑ, ΤΟΝ ΔΕΙΚΤΗ ΤΟΥ ΔΕΞΙΟΥ ΚΟΜΒΟΥ ΤΟΥ ΠΡΟΗΓΟΥΜΕΝΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΚΑΙ ΤΗΝ ΣΥΜΒΟΛΟΣΕΙΡΑ ΠΟΥ ΘΕΛΟΥΜΕ ΝΑ ΔΙΑΓΡΑΨΟΥΜΕ,ΚΑΙ ΤΟ ΑΠΟΤΕΛΕΣΜΑ ΤΟ ΑΠΟΘΗΚΕΥΟΥΜΕ ΣΤΟΝ ΔΕΙΚΤΗ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΚΟΜΒΟΥ
    else///ΑΝ Η ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΚΟΜΒΟΥ ΕΙΝΑΙ ΙΣΗ ΜΕ ΤΗΝ ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΤΟΤΕ
    {
        if( (root->leftstr == NULL) ||(root->rightstr == NULL) )///ΑΝ Ο ΑΡΙΣΤΕΡΟΣ Η Ο ΔΕΞΙΟΣ ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ ΔΕΙΧΝΕΙ ΣΕ NULL (ΔΗΛΑΔΗ ΕΧΟΥΜΕ ΠΡΟΣΠΕΛΑΣΕΙ ΤΟ ΔΕΝΤΡΟ ΚΑΙ ΒΡΙΣΚΟΜΑΣΤΕ ΣΕ ΤΕΛΕΥΤΑΙΟ ΚΟΜΒΟ ΠΡΙΝ ΤΑ ΦΥΛΛΑ) ΤΟΤΕ
        {
            TreeNode *temp;///ΔΗΜΙΟΥΡΓΟΥΜΕ ΕΝΑΝ ΠΡΟΣΩΡΙΝΟ ΔΕΙΚΤΗ ΚΟΜΒΟΥ
            if(root->leftstr!=NULL)///ΑΝ Ο ΑΡΙΣΤΕΡΟΣ ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ ΔΕ ΔΕΙΧΝΕΙ ΣΕ NULL ΤΟΤΕ
                temp=root->leftstr;///ΣΤΟΝ ΠΡΟΣΩΡΙΝΟ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΕΚΧΩΡΟΥΜΕ ΤΟΝ ΑΡΙΣΤΕΡΟ ΚΟΜΒΟ ΤΟΥ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
            else///ΑΛΛΙΩΣ ΑΝ Ο ΑΡΙΣΤΕΡΟΣ ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ ΔΕΙΧΝΕΙ ΣΕ NULL ΤΟΤΕ
                temp=root->rightstr;///ΣΤΟΝ ΠΡΟΣΩΡΙΝΟ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΕΚΧΩΡΟΥΜΕ ΤΟΝ ΔΕΞΙΟ ΚΟΜΒΟ ΤΟΥ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
            if (temp == NULL)///ΑΝ Ο ΠΡΟΣΩΡΙΝΟΣ ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ ΔΕΙΧΝΕΙ ΣΕ NULL ΤΟΤΕ
                root = NULL;///Ο ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΘΑ ΔΕΙΧΝΕΙ ΣΤΟ NULL
            else ///ΑΝ Ο ΠΡΟΣΩΡΙΝΟΣ ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ ΔΕ ΔΕΙΧΝΕΙ ΣΕ NULL(ΔΗΛΑΔΗ ΥΠΑΡΧΕΙ ΕΝΑ ΠΑΙΔΙ) ΤΟΤΕ
                *root = *temp; ///ΑΠΟΘΗΚΕΥΩ ΤΑ ΠΕΡΙΕΧΟΜΕΝΑ ΤΟΥ ΠΡΟΣΩΡΙΝΟΥ ΚΟΜΒΟΥ ΣΤΟΝ ΚΟΜΒΟ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
            //delete temp;///ΔΙΑΓΡΑΦΩ ΤΟΝ ΠΡΟΣΩΡΙΝΟ ΚΟΜΒΟ

        }
        else///ΑΝ ΟΥΤΕ Ο ΑΡΙΣΤΕΡΟΣ ΟΥΤΕ Ο ΔΕΞΙΟΣ ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ ΔΕΙΧΝΕΙ ΣΕ NULL(ΔΗΛΑΔΗ ΕΧΟΥΜΕ ΚΟΜΒΟ ΜΕ 2 ΠΑΙΔΙΑ) ΤΟΤΕ
        {
            TreeNode *temp=root->rightstr;///ΔΗΜΙΟΥΡΓΩ ΕΝΑΝ ΠΡΟΣΩΡΙΝΟ ΔΕΙΚΤΗ ΚΟΜΒΟΥ Ο ΟΠΟΙΟΣ ΔΕΙΧΝΕΙ ΣΤΟΝ ΔΕΞΙΟ ΚΟΜΒΟ ΤΟΥ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
            while(temp->leftstr!=NULL)///ΟΣΟ Ο ΑΡΙΣΤΕΡΟΣ ΚΟΜΒΟΣ ΤΟΥ ΠΡΟΣΩΡΙΝΟΥ ΔΕ ΔΕΙΧΝΕΙ ΣΕ NULL
                temp=temp->leftstr;///ΕΚΧΩΡΩ ΣΥΝΕΧΩΣ ΣΤΟΝ ΠΡΟΣΩΡΙΝΟ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΝ ΑΡΙΣΤΕΡΟ ΤΟΥ(ΠΡΟΣΩΡΙΝΟΥ) ΔΕΙΚΤΗ ΚΟΜΒΟΥ(ΓΙΑ ΝΑ ΒΡΩ ΤΟ ΜΙΚΡΟΤΕΡΟ ΣΤΟΙΧΕΙΟ-ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΔΕΞΙΟΥ ΥΠΟΔΕΝΤΡΟΥ )
            root->str = temp->str;///ΑΝΤΙΓΡΑΦΩ ΤΗ ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΠΡΟΣΩΡΙΝΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΣΤΗ ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
            ///ΣΤΗΝ ΟΥΣΙΑ ΚΑΝΟΥΜΕ ΜΙΑ INORDER ΠΡΟΣΠΕΛΑΣΗ.Ο ΛΟΓΟΣ ΕΙΝΑΙ ΟΤΙ ΟΤΑΝ ΔΙΑΓΡΑΦΕΤΑΙ ΕΝΑΣ ΚΟΜΒΟΣ ΤΟ ΠΙΟ ΑΡΙΣΤΕΡΟ ΣΤΟΙΧΕΙΟ ΤΟΥ ΔΕΞΙΟΥ ΥΠΟΔΕΝΤΡΟΥ ΜΠΟΡΕΙ ΝΑ ΤΟ ΑΝΤΙΚΑΤΑΣΤΗΣΕΙ ΧΩΡΙΣ ΤΟ ΔΥΑΔΙΚΟ ΔΕΝΤΡΟ ΑΝΑΖΗΤΗΣΗΣ ΝΑ ΧΑΣΕΙ ΤΙΣ ΙΔΙΟΤΗΤΕΣ ΤΟΥ
            root->rightstr = deleter(root->rightstr,temp->str);///ΔΙΑΓΡΑΦΗ ΤΟΥ ΠΡΟΣΩΡΙΝΟΥ ΚΟΜΒΟΥ
        }
    }

    if (root == NULL)///ΟΤΑΝ ΑΠΟΜΕΝΕΙ ΜΟΝΟ ΕΝΑΣ ΚΟΜΒΟΣ
        return root;///ΤΟΝ ΕΠΙΣΤΡΕΦΩ

    if(height(root->leftstr)>height(root->rightstr))///ΚΑΤΑΓΡΑΦΩ ΤΟ ΥΨΟΣ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΣΤΟ ΟΠΟΙΟ ΕΚΧΩΡΩ ΤΟ ΜΕΓΑΛΥΤΕΡΟ ΑΠΟ ΤΑ ΥΨΗ ΤΟΥ ΔΕΞΙΟΥ ΚΑΙ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΥΠΟΔΕΝΤΡΟΥ ΚΑΙ ΑΥΞΑΝΩ ΚΑΤΑ 1
        root->height=height(root->leftstr)+1;
    else
        root->height=height(root->rightstr)+1;

    int balance=getBalance(root);///ΑΠΟΘΗΚΕΥΩ ΤΗ ΔΙΑΦΟΡΑ ΥΨΟΥΣ ΤΟΥ ΔΕΞΙΟΥ ΚΑΙ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΥΠΟΔΕΝΤΡΟΥ ΣΕ ΜΙΑ ΜΕΤΑΒΛΗΤΗ

    if (balance > 1 &&  getBalance(root->leftstr) >= 0)///ΑΝ Η ΔΙΑΦΟΡΑ ΥΨΟΥΣ ΤΩΝ ΥΠΟΔΕΝΤΡΩΝ ΕΙΝΑΙ >1 ΚΑΙ Η ΔΙΑΦΟΡΑ ΥΨΟΥΣ ΤΩΝ ΥΠΟΔΕΝΤΡΩΝ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΥΠΟΔΕΝΤΡΟΥ ΕΙΝΑΙ>=0
        return rightRotate(root); /// ΚΑΝΩ ΜΙΑ Left Left ΠΕΡΙΣΤΡΟΦΗ ΤΟΥ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΚΑΙ ΕΠΙΣΤΡΕΦΩ ΤΟΝ ΚΑΤΑΛΛΗΛΑ ΔΙΑΜΟΡΦΩΜΕΝΟ ΚΟΜΒΟ

    if (balance > 1 &&  getBalance(root->leftstr) < 0)///ΑΝ Η ΔΙΑΦΟΡΑ ΥΨΟΥΣ ΤΩΝ ΥΠΟΔΕΝΤΡΩΝ ΕΙΝΑΙ >1 ΚΑΙ Η ΔΙΑΦΟΡΑ ΥΨΟΥΣ ΤΩΝ ΥΠΟΔΕΝΤΡΩΝ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΥΠΟΔΕΝΤΡΟΥ ΕΙΝΑΙ<0
    {
        /// ΚΑΝΩ ΜΙΑ Left Right ΠΕΡΙΣΤΡΟΦΗ ΤΟΥ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΚΑΙ ΕΠΙΣΤΡΕΦΩ ΤΟΝ ΚΑΤΑΛΛΗΛΑ ΔΙΑΜΟΡΦΩΜΕΝΟ ΚΟΜΒΟ
        root->leftstr = leftRotate(root->leftstr);
        return rightRotate(root);
    }

    if (balance < -1 &&  getBalance(root->rightstr) <= 0)///ΑΝ Η ΔΙΑΦΟΡΑ ΥΨΟΥΣ ΤΩΝ ΥΠΟΔΕΝΤΡΩΝ ΕΙΝΑΙ<-1ΚΑΙ Η ΔΙΑΦΟΡΑ ΥΨΟΥΣ ΤΩΝ ΥΠΟΔΕΝΤΡΩΝ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΥΠΟΔΕΝΤΡΟΥ ΕΙΝΑΙ<=0
            return leftRotate(root); /// ΚΑΝΩ ΜΙΑ Right Right ΠΕΡΙΣΤΡΟΦΗ ΤΟΥ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΚΑΙ ΕΠΙΣΤΡΕΦΩ ΤΟΝ ΚΑΤΑΛΛΗΛΑ ΔΙΑΜΟΡΦΩΜΕΝΟ ΚΟΜΒΟ

    if (balance < -1 &&  getBalance(root->rightstr) > 0)///ΑΝ Η ΔΙΑΦΟΡΑ ΥΨΟΥΣ ΤΩΝ ΥΠΟΔΕΝΤΡΩΝ ΕΙΝΑΙ<-1 ΚΑΙ Η ΔΙΑΦΟΡΑ ΥΨΟΥΣ ΤΩΝ ΥΠΟΔΕΝΤΡΩΝ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΥΠΟΔΕΝΤΡΟΥ ΕΙΝΑΙ>0
    {
        /// ΚΑΝΩ ΜΙΑ Right Left  ΠΕΡΙΣΤΡΟΦΗ ΤΟΥ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΚΑΙ ΕΠΙΣΤΡΕΦΩ ΤΟΝ ΚΑΤΑΛΛΗΛΑ ΔΙΑΜΟΡΦΩΜΕΝΟ ΚΟΜΒΟ
        root->rightstr = rightRotate(root->rightstr);
        return leftRotate(root);
    }

    return root;///ΕΠΙΣΤΡΕΦΩ ΤΟΝ ΔΕΙΚΤΗ ΚΟΜΒΟΥ


}

AVLtree::~AVLtree()
{
    //dtor
}
