#include "BTS.h"
#include "TreeNode.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
BTS::BTS()
{
    head=NULL;///ΟΤΑΝ ΠΑΡΑΓΕΤΑΙ Ο ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ ΑΡΧΙΚΑ ΔΕΙΧΝΕΙ ΣΕ NULL
}
void BTS::inOrder(TreeNode *head)///ΕΝΔΟΔΙΑΤΑΞΗ(ΑΤΙΣΤΕΡΑ , ΚΕΝΤΡΟ , ΔΕΞΙΑ) , ΔΕΧΕΤΑΙ ΕΝΑΝ ΚΟΜΒΟ ΣΑΝ ΟΡΙΣΜΑ
{

    if(head==NULL  )///ΑΝ Ο ΚΟΜΒΟΣ ΔΕΙΧΝΕΙ ΣΕ NULL ΤΟΤΕ
        return;///Η ΑΝΑΔΡΟΜΙΚΗ ΣΥΝΑΡΤΗΣΗ ΞΕΚΙΝΑΕΙ ΤΗΝ ΑΝΑΔΡΟΜΗ ΑΦΟΥ ΕΦΤΑΣΕ ΣΤΑ ΦΥΛΛΑ ΤΟΥ ΔΥΑΔΙΚΟΥ ΔΕΝΤΡΟΥ ΑΝΑΖΗΤΗΣΗΣ ΚΑΙ ΕΠΙΣΤΡΕΦΕΙ ΠΡΟΣ ΤΗΝ ΡΙΖΑ
    inOrder(head->leftstr);///ΑΝΑΔΡΟΜΙΚΗ ΚΛΗΣΗ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΚΟΜΒΟΥ ,ΤΟΥ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
    cout<<head->str<<" "<<head->pl<<endl;///ΕΜΦΑΝΙΣΗ ΤΗΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΤΟΥ ΚΟΜΒΟΥ ΜΕ ΤΟΝ ΟΠΟΙΟ ΕΧΕΙ ΚΛΗΘΕΙ Η ΑΝΑΔΡΟΜΗ
    inOrder(head->rightstr);///ΑΝΑΔΡΟΜΙΚΗ ΚΛΗΣΗ ΤΟΥ ΔΕΞΙΟΥ ΚΟΜΒΟΥ ,ΤΟΥ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
}

void BTS::preOrder(TreeNode *head)///ΠΡΟΔΙΑΤΑΞΗ(ΚΕΝΤΡΟ , ΑΡΙΣΤΕΡΑ , ΔΕΞΙΑ) , ΔΕΧΕΤΑΙ ΕΝΑΝ ΚΟΜΒΟ ΣΑΝ ΟΡΙΣΜΑ
{

    if(head==NULL  )///ΑΝ Ο ΚΟΜΒΟΣ ΔΕΙΧΝΕΙ ΣΕ NULL ΤΟΤΕ
        return;///Η ΑΝΑΔΡΟΜΙΚΗ ΣΥΝΑΡΤΗΣΗ ΞΕΚΙΝΑΕΙ ΤΗΝ ΑΝΑΔΡΟΜΗ ΑΦΟΥ ΕΦΤΑΣΕ ΣΤΑ ΦΥΛΛΑ ΤΟΥ ΔΥΑΔΙΚΟΥ ΔΕΝΤΡΟΥ ΑΝΑΖΗΤΗΣΗΣ ΚΑΙ ΕΠΙΣΤΡΕΦΕΙ ΠΡΟΣ ΤΗΝ ΡΙΖΑ
    cout<<head->str<<" "<<head->pl<<endl;///ΕΜΦΑΝΙΣΗ ΤΗΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΤΟΥ ΚΟΜΒΟΥ ΜΕ ΤΟΝ ΟΠΟΙΟ ΕΧΕΙ ΚΛΗΘΕΙ Η ΑΝΑΔΡΟΜΗ
    preOrder(head->leftstr);///ΑΝΑΔΡΟΜΙΚΗ ΚΛΗΣΗ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΚΟΜΒΟΥ ,ΤΟΥ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
    preOrder(head->rightstr);///ΑΝΑΔΡΟΜΙΚΗ ΚΛΗΣΗ ΤΟΥ ΔΕΞΙΟΥ ΚΟΜΒΟΥ ,ΤΟΥ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
}

void BTS::postOrder(TreeNode *head)///ΜΕΤΑΔΙΑΤΑΞΗ(ΑΡΙΣΤΕΡΑ , ΔΕΞΙΑ , ΚΕΝΤΡΟ) , ΔΕΧΕΤΑΙ ΕΝΑΝ ΚΟΜΒΟ ΣΑΝ ΟΡΙΣΜΑ
{
    if(head==NULL)///ΑΝ Ο ΚΟΜΒΟΣ ΔΕΙΧΝΕΙ ΣΕ NULL ΤΟΤΕ
        return;///Η ΑΝΑΔΡΟΜΙΚΗ ΣΥΝΑΡΤΗΣΗ ΞΕΚΙΝΑΕΙ ΤΗΝ ΑΝΑΔΡΟΜΗ ΑΦΟΥ ΕΦΤΑΣΕ ΣΤΑ ΦΥΛΛΑ ΤΟΥ ΔΥΑΔΙΚΟΥ ΔΕΝΤΡΟΥ ΑΝΑΖΗΤΗΣΗΣ ΚΑΙ ΕΠΙΣΤΡΕΦΕΙ ΠΡΟΣ ΤΗΝ ΡΙΖΑ
    postOrder(head->leftstr);///ΑΝΑΔΡΟΜΙΚΗ ΚΛΗΣΗ ΤΟΥ ΑΡΙΣΤΕΡΟΥ ΚΟΜΒΟΥ ,ΤΟΥ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
    postOrder(head->rightstr);///ΑΝΑΔΡΟΜΙΚΗ ΚΛΗΣΗ ΤΟΥ ΔΕΞΙΟΥ ΚΟΜΒΟΥ ,ΤΟΥ ΚΟΜΒΟΥ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
    cout<<head->str<<" "<<head->pl<<endl;///ΕΜΦΑΝΙΣΗ ΤΗΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΤΟΥ ΚΟΜΒΟΥ ΜΕ ΤΟΝ ΟΠΟΙΟ ΕΧΕΙ ΚΛΗΘΕΙ Η ΑΝΑΔΡΟΜΗ
}

void BTS::insert(string newstr)///Η ΣΥΝΑΡΤΗΣΗ insert, ΣΑΝ ΟΡΙΣΜΑ ΔΕΧΕΤΑΙ ΜΙΑ ΣΥΜΒΟΛΟΣΕΙΡΑ
{
    if(newstr[0]!=' ')///ΕΠΕΙΔΗ ΣΤΟΝ ΠΙΝΑΚΑ ΥΠΑΡΧΟΥΝ ΚΑΙ ΚΕΝΕΣ ΣΥΜΒΟΛΟΣΕΙΡΕΣ ΟΙ ΟΠΟΙΕΣ ΔΕΝ ΕΚΧΩΡΟΥΝΤΑΙ ΣΤΙΣ ΔΟΜΕΣ
    {



    TreeNode *newTreeNode= new TreeNode;///ΔΗΜΙΟΥΡΓΟΥΜΕ ΕΝΑΝ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΠΟΥ ΑΝΑΦΕΡΕΤΑΙ ΣΤΟ ΣΤΟΙΧΕΙΟ ΠΟΥ ΕΠΙΘΥΜΟΥΜΕ ΝΑ ΕΙΣΑΓΟΥΜΕ
    newTreeNode->pl+=1;
    newTreeNode->str=newstr;///ΑΝΤΙΓΡΑΦΟΥΜΕ ΣΤΟ ΔΕΙΚΤΗ ΤΗΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΑΥΤΟΥ ΤΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΗΝ ΣΥΜΒΟΛΟΣΕΙΡΑ ΠΟΥ ΕΙΣΑΓΑΜΕ

    TreeNode *parent;///ΔΗΜΙΟΥΡΓΟΥΜΕ ΕΝΑΝ ΔΕΙΚΤΗ ΚΟΜΒΟΥ(ΒΟΗΘΙΤΙΚΟ)
    parent=NULL;///Ο ΟΠΟΙΟΣ ΔΕΙΧΝΕΙ ΣΤΟ NULL
    if(head==NULL)///ΑΝ Ο ΑΡΧΙΚΟΣ ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ (Η ΡΙΖΑ) ΔΕΙΧΝΕΙ ΣΤΟ NULL ΤΟΤΕ
    {
        ///ΘΑ ΕΚΤΕΛΕΣΤΕΙ ΜΟΝΟ ΓΙΑ ΤΗΝ ΠΡΩΤΗ ΣΥΜΒΟΛΟΣΕΙΡΑ ΠΟΥ ΘΑ ΕΙΣΑΓΟΥΜΕ
        head=newTreeNode;///ΣΤΗ ΡΙΖΑ ΕΚΧΩΡΟΥΜΕ ΤΟΝ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΠΟΥ ΑΝΑΦΕΡΕΤΑΙ ΣΤΟ ΣΤΟΙΧΕΙΟ ΠΟΥ ΕΠΙΘΥΜΟΥΜΕ ΝΑ ΕΙΣΑΓΟΥΜΕ
    }
    else///ΑΝ Ο ΑΡΧΙΚΟΣ ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ (Η ΡΙΖΑ) ΔΕ ΔΕΙΧΝΕΙ ΣΤΟ NULL ΤΟΤΕ
    {
        TreeNode *parent_treenode=head;///ΔΗΜΙΟΥΡΓΩ ΕΝΑΝ ΠΡΟΣΩΡΙΝΟ ΔΕΙΚΤΗ ΚΟΜΒΟ ΚΑΙ ΕΚΧΩΡΩ ΣΕ ΑΥΤΟΝ ΤΑ ΣΤΟΙΧΕΙΑ ΤΗΣ ΡΙΖΑΣ
        while(parent_treenode!=NULL)///ΟΣΟ Ο ΠΡΟΣΩΡΙΝΟΣ ΚΟΜΒΟΣ ΔΕ ΔΕΙΧΝΕΙ ΣΕ NULL
        {
            parent=parent_treenode;///ΕΚΧΩΡΩ ΤΑ ΠΕΡΙΕΧΟΜΕΝΑ ΤΟΥ ΠΡΟΣΩΡΙΝΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΣΤΝ ΒΟΗΘΗΤΙΚΟ(ΠΑΤΕΡΑ) ΔΕΙΚΤΗ ΚΟΜΒΟΥ
            if(newstr>parent_treenode->str)///ΑΝ Η ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΕΙΝΑΙ ΜΕΓΑΛΥΤΕΡΗ ΤΗΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΤΟΥ ΠΡΟΣΩΡΙΝΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΤΕ
                parent_treenode=parent_treenode->rightstr;///ΣΤΟΝ ΠΡΟΣΩΡΙΝΟ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΚΑΤΑΧΩΡΕΙΤΕ Ο ΔΕΞΙΟΣ ΤΟΥ ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ
            else if(newstr<parent->str)///ΑΝ Η ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΕΙΝΑΙ ΜΙΚΡΟΤΕΡΗ ΤΗΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΤΟΥ ΠΡΟΣΩΡΙΝΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΤΕ
                parent_treenode=parent_treenode->leftstr;///ΣΤΟΝ ΠΡΟΣΩΡΙΝΟ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΚΑΤΑΧΩΡΕΙΤΕ Ο ΤΟΥ ΤΟΥ ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ
            else///ΑΝ Η ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΕΙΝΑΙ ΙΣΗ ΜΕ ΤΗΝ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΤΟΥ ΠΡΟΣΩΡΙΝΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΤΕ
            {
                parent->pl+=1;
                return;///ΕΠΙΣΤΡΕΦΩ ΕΚΕΙ ΑΠΟ ΟΠΟΥ ΚΛΗΘΗΚΕ Η ΣΥΝΑΡΤΗΣΗ ΧΩΡΙΣ ΚΑΜΙΑ ΤΡΟΠΟΠΟΙΗΣΗ
            }
        }
        ///ΣΤΟ ΤΕΛΟΣ ΑΥΤΗΣ ΤΗΣ ΕΠΑΝΑΛΗΨΗΣ ΘΑ ΕΧΟΥΜΕ
        ///ΤΟΝ ΠΡΟΣΩΡΙΝΟ ΔΕΙΚΤΗ ΚΟΜΒΟΥ(parent_treenode) Ο ΟΠΟΙΟΣ ΘΑ ΒΟΗΘΗΣΕΙ ΤΟΝ ΒΟΗΘΗΤΙΚΟ ΔΕΙΚΤΗ ΚΟΜΒΟΥ(parent) ΝΑ ΚΑΘΟΔΗΓΗΣΕΙ ΚΑΤΑΛΛΗΛΑ ΤΗΝ ΣΥΜΒΟΛΟΣΕΙΡΑ
        ///Ο ΒΟΗΘΗΤΙΚΟΣ ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ ΔΕΙΧΝΕΙ ΟΥΣΙΑΣΤΙΚΑ ΣΕ ΕΝΑ ΦΥΛΛΟ ΠΟΥ ΕΧΕΙ ΜΕΣΑ ΤΗΝ ΣΥΜΒΟΛΟΣΕΙΡΑ ΚΑΙ Ο ΔΕΙΚΤΗΣ ΚΟΜΒΟΥ ΠΟΥ ΜΑΣ ΕΝΔΙΑΦΕΡΕΙ ,ΑΦΟΥ ΕΚΕΙ ΘΑ ΚΑΤΑΧΩΡΗΘΕΙ Η ΛΕΞΗ ΜΕΤΑ, ΔΕΙΧΝΕΙ ΣΕ NULL

        if(newstr<parent->str)///ΑΝ Η ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΒΟΗΘΙΤΙΚΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ (parent) ΕΙΝΑΙ ΜΕΓΑΛΥΤΕΡΗ ΤΗΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
            parent->leftstr=newTreeNode;///ΕΚΧΩΡΩ ΣΤΟΝ ΑΡΙΣΤΕΡΟ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΒΟΗΘΙΤΙΚΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ (parent), ΤΟΝ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΠΟΥ ΑΝΑΦΕΡΕΤΑΙ ΣΤΟ ΣΤΟΙΧΕΙΟ ΠΟΥ ΕΠΙΘΥΜΟΥΜΕ ΝΑ ΕΙΣΑΓΟΥΜΕ(newTreeNode)
        else if(newstr>parent->str)///ΑΝ Η ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΒΟΗΘΙΤΙΚΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ (parent) ΕΙΝΑΙ ΜΙΚΡΟΤΕΡΗ ΤΗΣ ΣΥΜΒΟΛΟΣΕΙΡΑΣ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
            parent->rightstr=newTreeNode;///ΕΚΧΩΡΩ ΣΤΟΝ ΔΕΞΙ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΤΟΥ ΒΟΗΘΙΤΙΚΟΥ ΔΕΙΚΤΗ ΚΟΜΒΟΥ (parent) ΤΟΝ, ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΠΟΥ ΑΝΑΦΕΡΕΤΑΙ ΣΤΟ ΣΤΟΙΧΕΙΟ ΠΟΥ ΕΠΙΘΥΜΟΥΜΕ ΝΑ ΕΙΣΑΓΟΥΜΕ(newTreeNode)
    }
    }
}

bool BTS::search(TreeNode *temp,string search_str)///Η ΣΥΝΑΡΤΗΣΗ SEARCH , ΔΕΧΕΤΑΙ ΕΝΑΝ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΚΑΙ ΜΙΑ ΣΥΜΒΟΛΟΣΕΙΡΑ
{
    if(temp==NULL)///ΑΝ Ο ΚΟΜΒΟΣ ΔΕΙΧΝΕΙ ΣΕ NULL ΤΟΤΕ
        return 0;/// ΕΠΙΣΤΡΕΦΕΙ FALSE ΩΣ BOOL ΣΥΝΑΡΤΗΣΗ
    else if(temp->str==search_str)///ΑΝ Η ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΚΟΜΒΟΥ ΚΑΙ Η ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΕΙΝΑΙ ΙΣΕΣ ΤΟΤΕ
        return 1;/// ΕΠΙΣΤΡΕΦΕΙ TRUE ΩΣ BOOL ΣΥΝΑΡΤΗΣΗ
    else if(temp->str>search_str)/// ΑΝ Η ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΚΟΜΒΟΥ ΕΙΝΑΙ ΜΕΓΑΛΥΤΕΡΗ ΑΠΟ ΤΗΝ ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΤΟΤΕ
        search(temp->leftstr,search_str);///ΕΚΤΕΛΕΙΤΕ ΞΑΝΑ Η ΣΥΝΑΡΤΗΣΗ ΓΙΑ ΤΟΝ ΑΡΙΣΤΕΡΟ ΚΟΜΒΟ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
    else if(temp->str<search_str)/// ΑΝ Η ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΚΟΜΒΟΥ ΕΙΝΑΙ ΜΙΚΡΟΤΕΡΗ ΑΠΟ ΤΗΝ ΣΥΜΒΟΛΟΣΕΙΡΑ ΤΟΥ ΟΡΙΣΜΑΤΟΣ ΤΟΤΕ
        search(temp->rightstr,search_str);///ΕΚΤΕΛΕΙΤΕ ΞΑΝΑ Η ΣΥΝΑΡΤΗΣΗ ΓΙΑ ΤΟΝ ΔΕΞΙΟ ΚΟΜΒΟ ΤΟΥ ΟΡΙΣΜΑΤΟΣ
}

TreeNode* BTS::deleter(TreeNode *root, string delete_str)///Η ΣΥΝΑΡΤΗΣΗ deleter , ΔΕΧΕΤΑΙ ΣΑΝ ΟΡΙΣΜΑΤΑ ΕΝΑΝ ΔΕΙΚΤΗ ΚΟΜΒΟΥ ΚΑΙ ΜΙΑ ΣΥΜΒΟΛΟΣΕΙΡΑ
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
    return root;///ΟΤΑΝ ΑΠΟΜΕΝΕΙ ΜΟΝΟ ΕΝΑΣ ΚΟΜΒΟΣ

}


BTS::~BTS()
{
    //dtor
}


